#pragma once
#include "Level3DRender/LevelRender.h"
#include "sound/SoundSource.h"
#include "Coin.h"
#include "Star.h"
#include "Timer.h"

class Player;
class GameCamera;
class BackGround;
class MoveBox;

//Gameシーンを管理するクラス。
class Game : public IGameObject
{
public:
	Game();
	~Game();
	//更新処理。
	void Update();
	//描画処理
	void Render(RenderContext& rc);

	Player* player;			                //プレイヤー。
	GameCamera* m_gameCamera;			    //ゲームカメラ。
	BackGround* m_backGround;               //バックグラウンド
 	LevelRender m_levelRender;				//レベルレンダー。
	MoveBox* m_moveBox;                     //moveボックス
	std::vector<MoveBox*> m_MoveBoxs;		//moveボックス。
	MoveBox* box;
	Coin* m_coin;                           //コインクラス
	Timer* m_timer;
	SkyCube* m_skyCube;
	Star* m_star = nullptr;                 //星

	//マイナスの判定用変数
	int select;
	//コインのｘ座標の設定用変数
	float coinPositionX[5];
	//コインのｙ座標の設定用変数
	float coinPositionZ[5];
	//コイン
	float coin;

private:
	//メンバ変数
	ModelRender m_modelRender;
	Vector3 m_pos;
	SpriteRender spriteRender;
	SoundSource* gameBGM;
	SoundSource* ruleBGM;
	SoundSource* titleBGM;
	FontRender fontRender;
};

