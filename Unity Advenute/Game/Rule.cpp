#include "stdafx.h"
#include "Title.h"
#include "Rule.h"
#include "Game.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Rule::Rule()
{
    //画像を読み込む。
    spriteRender.Init("Assets/sprite/Rule.DDS", 1920, 1080);
    //タイトルのBGMを読み込む。
    g_soundEngine->ResistWaveFileBank(6, "Assets/sound/Rule.wav");
    //タイトルのBGMを再生する。
    ruleBGM = NewGO<SoundSource>(6);
    ruleBGM->Init(6);
    ruleBGM->Play(true);
};

Rule::~Rule()
{
    DeleteGO(ruleBGM);
};

void Rule::Update() 
{
    if (g_pad[0]->IsTrigger(enButtonA))
    {
        NewGO<Game>(0);
        DeleteGO(this);
    }
}

void Rule::Render(RenderContext& rc)
{ 
    //画像を描画する。
    spriteRender.Draw(rc);
}