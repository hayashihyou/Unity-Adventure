#pragma once
#include "sound/SoundSource.h"

class Title :public IGameObject
{
public:
	Title();
	~Title();
	//�`��֐�
	void Render(RenderContext& rc);
	//�X�V����
	void Update();
	//�X�v���C�g�����_�[
	SpriteRender spriteRender;
	SoundSource* titleBGM; //�^�C�g����BGM�B
};


