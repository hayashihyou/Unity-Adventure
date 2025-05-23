#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "Rule.h"
#include "sound/SoundEngine.h"


Title::Title()
{
    //�摜��ǂݍ��ށB
    spriteRender.Init("Assets/sprite/Title.DDS", 1920, 1080);

    //�^�C�g����BGM��ǂݍ��ށB
    g_soundEngine->ResistWaveFileBank(0, "Assets/sound/Title.wav");
    //�^�C�g����BGM���Đ�����B
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
    //�摜��`�悷��B
    spriteRender.Draw(rc);
}