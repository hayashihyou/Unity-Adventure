#pragma once


class Rule: public IGameObject
{
public :
	Rule();
	~Rule();
	//�X�V����
	void Update();
	//�`�揈��
	void Render(RenderContext& rc);

private:
	//�X�v���C�g�����_�[
	SpriteRender spriteRender;
	SoundSource* ruleBGM; //���[��������BGM�B
};

