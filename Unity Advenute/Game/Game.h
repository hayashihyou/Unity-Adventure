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

//Game�V�[�����Ǘ�����N���X�B
class Game : public IGameObject
{
public:
	Game();
	~Game();
	//�X�V�����B
	void Update();
	//�`�揈��
	void Render(RenderContext& rc);

	Player* player;			                //�v���C���[�B
	GameCamera* m_gameCamera;			    //�Q�[���J�����B
	BackGround* m_backGround;               //�o�b�N�O���E���h
 	LevelRender m_levelRender;				//���x�������_�[�B
	MoveBox* m_moveBox;                     //move�{�b�N�X
	std::vector<MoveBox*> m_MoveBoxs;		//move�{�b�N�X�B
	MoveBox* box;
	Coin* m_coin;                           //�R�C���N���X
	Timer* m_timer;
	SkyCube* m_skyCube;
	Star* m_star = nullptr;                 //��

	//�}�C�i�X�̔���p�ϐ�
	int select;
	//�R�C���̂����W�̐ݒ�p�ϐ�
	float coinPositionX[5];
	//�R�C���̂����W�̐ݒ�p�ϐ�
	float coinPositionZ[5];
	//�R�C��
	float coin;

private:
	//�����o�ϐ�
	ModelRender m_modelRender;
	Vector3 m_pos;
	SpriteRender spriteRender;
	SoundSource* gameBGM;
	SoundSource* ruleBGM;
	SoundSource* titleBGM;
	FontRender fontRender;
};

