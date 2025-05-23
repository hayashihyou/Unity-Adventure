#include "stdafx.h"
#include "Title.h"
#include "Rule.h"
#include "Game.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Rule::Rule()
{
    //�摜��ǂݍ��ށB
    spriteRender.Init("Assets/sprite/Rule.DDS", 1920, 1080);
    //�^�C�g����BGM��ǂݍ��ށB
    g_soundEngine->ResistWaveFileBank(6, "Assets/sound/Rule.wav");
    //�^�C�g����BGM���Đ�����B
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
    //�摜��`�悷��B
    spriteRender.Draw(rc);
}