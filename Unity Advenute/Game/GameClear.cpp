#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include"Game.h"
#include "sound/SoundEngine.h"


GameClear::GameClear()
{
    //ゲームクリアの画像を読み込む。
    spriteRender.Init("Assets/sprite/GAMECLEAR.DDS", 1920.0f, 1080.0f);

    g_soundEngine->ResistWaveFileBank(3, "Assets/sound/GameClear.wav");
    //SoundSourceのオブジェクトを作成する。
    gameclearBGM = NewGO<SoundSource>(3);
    //WaveFileBankから登録されたwaveファイルのデータ（3番）を持ってくる。
    gameclearBGM->Init(3);
    //trueにすると、音がループする。
    gameclearBGM->Play(false);
}



GameClear::~GameClear()
{
    DeleteGO(gameclearBGM);
}



//更新処理。
void GameClear::Update()
{
    //Aボタンが押されたら。
    if (g_pad[0]->IsTrigger(enButtonA))
    {
        //タイトルのオブジェクトをつくる。
        NewGO<Title>(0, "title");
        //自身を削除する。
        DeleteGO(this);
    }

}



//描画処理。
void GameClear::Render(RenderContext& rc)
{
    spriteRender.Draw(rc);
}
