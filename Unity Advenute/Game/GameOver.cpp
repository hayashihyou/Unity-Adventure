#include "stdafx.h"
#include "GameOver.h"
#include "Player.h"
#include "Title.h"
#include "Game.h"
#include "sound/SoundEngine.h"

GameOver::GameOver()
{
	//ゲームオーバーの画像を読み込む
	spriteRender.Init("Assets/sprite/gameover.dds", 1920.0f, 1080.0f);

	g_soundEngine->ResistWaveFileBank(4, "Assets/sound/GameOver.wav");
	//SoundSourceのオブジェクトを作成する。
	gameoverBGM = NewGO<SoundSource>(4);
	//WaveFileBankから登録されたwaveファイルのデータ（4番）を持ってくる。
	gameoverBGM->Init(4);
	//trueにすると、音がループする。
	gameoverBGM->Play(false);
}

GameOver::~GameOver()
{
	DeleteGO(gameoverBGM);
}

//更新処理。
void GameOver::Update()
{
	//Aボタンが押されたら。
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		// タイトルのオブジェクトをつくる。
		NewGO<Title>(0, "title");
		//自身を削除する。
		DeleteGO(this);
	}
}


//描画処理。
void GameOver::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
