#include "stdafx.h"
#include "GameOver.h"
#include "Player.h"
#include "Title.h"
#include "Game.h"
#include "sound/SoundEngine.h"

GameOver::GameOver()
{
	//�Q�[���I�[�o�[�̉摜��ǂݍ���
	spriteRender.Init("Assets/sprite/gameover.dds", 1920.0f, 1080.0f);

	g_soundEngine->ResistWaveFileBank(4, "Assets/sound/GameOver.wav");
	//SoundSource�̃I�u�W�F�N�g���쐬����B
	gameoverBGM = NewGO<SoundSource>(4);
	//WaveFileBank����o�^���ꂽwave�t�@�C���̃f�[�^�i4�ԁj�������Ă���B
	gameoverBGM->Init(4);
	//true�ɂ���ƁA�������[�v����B
	gameoverBGM->Play(false);
}

GameOver::~GameOver()
{
	DeleteGO(gameoverBGM);
}

//�X�V�����B
void GameOver::Update()
{
	//A�{�^���������ꂽ��B
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		// �^�C�g���̃I�u�W�F�N�g������B
		NewGO<Title>(0, "title");
		//���g���폜����B
		DeleteGO(this);
	}
}


//�`�揈���B
void GameOver::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}
