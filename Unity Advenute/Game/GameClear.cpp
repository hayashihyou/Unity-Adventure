#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include"Game.h"
#include "sound/SoundEngine.h"


GameClear::GameClear()
{
    //�Q�[���N���A�̉摜��ǂݍ��ށB
    spriteRender.Init("Assets/sprite/GAMECLEAR.DDS", 1920.0f, 1080.0f);

    g_soundEngine->ResistWaveFileBank(3, "Assets/sound/GameClear.wav");
    //SoundSource�̃I�u�W�F�N�g���쐬����B
    gameclearBGM = NewGO<SoundSource>(3);
    //WaveFileBank����o�^���ꂽwave�t�@�C���̃f�[�^�i3�ԁj�������Ă���B
    gameclearBGM->Init(3);
    //true�ɂ���ƁA�������[�v����B
    gameclearBGM->Play(false);
}



GameClear::~GameClear()
{
    DeleteGO(gameclearBGM);
}



//�X�V�����B
void GameClear::Update()
{
    //A�{�^���������ꂽ��B
    if (g_pad[0]->IsTrigger(enButtonA))
    {
        //�^�C�g���̃I�u�W�F�N�g������B
        NewGO<Title>(0, "title");
        //���g���폜����B
        DeleteGO(this);
    }

}



//�`�揈���B
void GameClear::Render(RenderContext& rc)
{
    spriteRender.Draw(rc);
}
