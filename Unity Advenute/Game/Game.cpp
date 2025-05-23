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
#include <time.h>   // ���܂��Ȃ�1

Game::Game()
{
	
	m_timer = NewGO<Timer>(0,"timer");

	//�v���C���[�̃I�u�W�F�N�g�����B
	player = NewGO<Player>(0, "player");

	//�Q�[���J�����̃I�u�W�F�N�g�����B
	m_gameCamera = NewGO<GameCamera>(0, "gamecamera");

	//�w�i�̃I�u�W�F�N�g�����B
	m_backGround = NewGO<BackGround>(0);
	//�Q�[������BGM��ǂݍ��ށB
    g_soundEngine->ResistWaveFileBank(5, "Assets/sound/Stage.wav");
	//�Q�[������BGM���Đ�����B
	gameBGM = NewGO<SoundSource>(0);
	gameBGM->Init(5);
	gameBGM->Play(true);


	srand(time(nullptr));    // ���܂��Ȃ�2

	//�R�C����x���W5�������_���Ō��߂�
	for (int i = 1; i <= 5; i++) {
		//0�`3000�̊Ԃ��猈�߂�
		coinPositionX[i] = rand() % 3000;

		//�}�C�i�X���W�ɂ��邩�̔���
		select = rand() % 2;
		if (select == 0) {
			coinPositionX[i] *= -1;
		}
	}

	//�R�C����z���W5�������_���Ō��߂�
	for (int i = 1; i <= 5; i++) {
		//0�`3000�̊Ԃ��猈�߂�
		coinPositionZ[i] = rand() % 3000;

		//�}�C�i�X���W�ɂ��邩�̔���
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
	
	//���x�����\�z����B
	m_levelRender.Init("Assets/level/moveboxtest.tkl", [&](LevelObjectData& objData) {
		if (objData.EqualObjectName(L"movebox") == true)
		{
			box = NewGO<MoveBox>(0);
			//�z�u���W�A�X�P�[���A��]���擾����B
			box->m_position = objData.position;
			box->m_scale = objData.scale;
			box->m_rotation = objData.rotation;
			//��ō폜���邽�߂ɁA�{�b�N�X���v�b�V�����Ă����B
			m_MoveBoxs.push_back(box);

			//true�ɂ���ƁA���x���̕��Ń��f�����ǂݍ��܂�Ȃ��B
			return true;
		}

	});

}

Game::~Game()
{
	//�v���C���[���폜����B
	DeleteGO(player);

	//�Q�[���J�������폜����B
	DeleteGO(m_gameCamera);

	//�^�C�g����BGM���폜����B
	DeleteGO(titleBGM);

	//���[��������BGM���폜����
	DeleteGO(ruleBGM);

	//�Q�[������BGM���폜����B
	DeleteGO(gameBGM);

	//�^�C�}�[���폜����
	DeleteGO(m_timer);

	//�X�J�C�L���[�u���폜����
	DeleteGO(m_skyCube);

	//�w�i���폜����B
	DeleteGO(m_backGround);

	//�R�C�����폜����
	DeleteGO(m_coin);

	//�����폜����
	DeleteGO(m_star);

	//�ݒ肵��Box���폜���Ă����
	for (auto box : m_MoveBoxs)
	{
		DeleteGO(box);
	};
};


//�X�V�����B
void Game::Update()
{

	//Star�N���X�̃I�u�W�F�N�g�����B
	if (player->coinCount == 5)
	{
		m_star = NewGO<Star>(0, "star");
		//m_star->position = { 500.0f,0.0f,10.0f };
		m_star->position = { 0.0f,1800.0f,0.0f };
		m_star->firstPosition = m_star->position;
		player->coinCount++;

		wchar_t star[256];
		swprintf_s(star, 256, L"����������I�I", int(player->coinCount));

		//�\������e�L�X�g��ݒ�B
		fontRender.SetText(star);
		//�t�H���g�̈ʒu��ݒ�B
		fontRender.SetPosition(Vector3(200.0f, 400.0f, 0.0f));
		//�t�H���g�̑傫����ݒ�B
		fontRender.SetScale(2.0f);
		//�t�H���g�̐F��ݒ�B
		fontRender.SetColor({ 1.0f,1.0f,0.0f,1.0f });
	}


	//�R�C����5���W�߂�ƃN���A
	if (player-> starCount==1)
	{
		NewGO<GameClear>(0, "gameClear");
		DeleteGO(this);
	}

	//�����W��-800f�܂ŗ����邩�A�^�C�}�[��0�ɂȂ�ƃQ�[���I�[�o�[
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