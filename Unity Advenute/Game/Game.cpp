#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "GameCamera.h"
#include "BackGround.h"
#include "Title.h"
#include "GameClear.h"
#include "GameOver.h"
#include "Timer.h"
#include "MoveBox.h"
#include "Coin.h"
#include "Star.h"
#include "Rule.h"
#include "sound/SoundEngine.h"
#include <time.h>   // おまじない1

Game::Game()
{
	
	m_timer = NewGO<Timer>(0,"timer");

	//プレイヤーのオブジェクトを作る。
	player = NewGO<Player>(0, "player");

	//ゲームカメラのオブジェクトを作る。
	m_gameCamera = NewGO<GameCamera>(0, "gamecamera");

	//背景のオブジェクトを作る。
	m_backGround = NewGO<BackGround>(0);
	//ゲーム中のBGMを読み込む。
    g_soundEngine->ResistWaveFileBank(5, "Assets/sound/Stage.wav");
	//ゲーム中のBGMを再生する。
	gameBGM = NewGO<SoundSource>(0);
	gameBGM->Init(5);
	gameBGM->Play(true);


	srand(time(nullptr));    // おまじない2

	//コインのx座標5つをランダムで決める
	for (int i = 1; i <= 5; i++) {
		//0～3000の間から決める
		coinPositionX[i] = rand() % 3000;

		//マイナス座標にするかの判定
		select = rand() % 2;
		if (select == 0) {
			coinPositionX[i] *= -1;
		}
	}

	//コインのz座標5つをランダムで決める
	for (int i = 1; i <= 5; i++) {
		//0～3000の間から決める
		coinPositionZ[i] = rand() % 3000;

		//マイナス座標にするかの判定
		select = rand() % 2;
		if (select == 0) {
			coinPositionZ[i] *= -1;
		}
	}	

	for (int i = 1.0f; i <= 5.0f; i++) {
		m_coin = NewGO<Coin>(0, "coin");
		m_coin->position = { coinPositionX[i], 300.0f,coinPositionZ[i] };
		m_coin->firstPosition = m_coin->position;
	}
	
	//レベルを構築する。
	m_levelRender.Init("Assets/level/moveboxtest.tkl", [&](LevelObjectData& objData) {
		if (objData.EqualObjectName(L"movebox") == true)
		{
			box = NewGO<MoveBox>(0);
			//配置座標、スケール、回転を取得する。
			box->m_position = objData.position;
			box->m_scale = objData.scale;
			box->m_rotation = objData.rotation;
			//後で削除するために、ボックスをプッシュしておく。
			m_MoveBoxs.push_back(box);

			//trueにすると、レベルの方でモデルが読み込まれない。
			return true;
		}

	});

}

Game::~Game()
{
	//プレイヤーを削除する。
	DeleteGO(player);

	//ゲームカメラを削除する。
	DeleteGO(m_gameCamera);

	//タイトルのBGMを削除する。
	DeleteGO(titleBGM);

	//ルール説明のBGMを削除する
	DeleteGO(ruleBGM);

	//ゲーム中のBGMを削除する。
	DeleteGO(gameBGM);

	//タイマーを削除する
	DeleteGO(m_timer);

	//スカイキューブを削除する
	DeleteGO(m_skyCube);

	//背景を削除する。
	DeleteGO(m_backGround);

	//コインを削除する
	DeleteGO(m_coin);

	//星を削除する
	DeleteGO(m_star);

	//設定したBox分削除してくれる
	for (auto box : m_MoveBoxs)
	{
		DeleteGO(box);
	};
};


//更新処理。
void Game::Update()
{

	//Starクラスのオブジェクトを作る。
	if (player->coinCount == 5)
	{
		m_star = NewGO<Star>(0, "star");
		//m_star->position = { 500.0f,0.0f,10.0f };
		m_star->position = { 0.0f,1800.0f,0.0f };
		m_star->firstPosition = m_star->position;
		player->coinCount++;

		wchar_t star[256];
		swprintf_s(star, 256, L"星を見つけろ！！", int(player->coinCount));

		//表示するテキストを設定。
		fontRender.SetText(star);
		//フォントの位置を設定。
		fontRender.SetPosition(Vector3(200.0f, 400.0f, 0.0f));
		//フォントの大きさを設定。
		fontRender.SetScale(2.0f);
		//フォントの色を設定。
		fontRender.SetColor({ 1.0f,1.0f,0.0f,1.0f });
	}


	//コインを5枚集めるとクリア
	if (player-> starCount==1)
	{
		NewGO<GameClear>(0, "gameClear");
		DeleteGO(this);
	}

	//ｙ座標に-800fまで落ちるか、タイマーが0になるとゲームオーバー
	if (player->position.y <= -800.0f || m_timer->timer == 0.0f)
	{
		NewGO<GameOver>(0, "gameover");
		DeleteGO(this);
	}

}
void Game::Render(RenderContext& rc)
{
	fontRender.Draw(rc);
}