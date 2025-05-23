#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "Rule.h"
#include "sound/SoundEngine.h"


Title::Title()
{
    //画像を読み込む。
    spriteRender.Init("Assets/sprite/Title.DDS", 1920, 1080);

    //タイトルのBGMを読み込む。
    g_soundEngine->ResistWaveFileBank(0, "Assets/sound/Title.wav");
    //タイトルのBGMを再生する。
    titleBGM = NewGO<SoundSource>(0);
    titleBGM->Init(0);
    titleBGM->Play(true);
}

Title::~Title()
{
    DeleteGO(titleBGM);
}

void Title::Update()
{
    if (g_pad[0]->IsTrigger(enButtonA))
    {
        NewGO<Rule>(0,"rule");
        DeleteGO(this);
    }


}

void Title::Render(RenderContext& rc)
{
    //画像を描画する。
    spriteRender.Draw(rc);
}