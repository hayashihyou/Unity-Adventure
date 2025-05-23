#pragma once
#include "sound/SoundSource.h"
class Player;
class Star :public IGameObject
{
public:
    Star();
    ~Star();
    //�X�V����
    void Update();
    //�`�揈��
    void Render(RenderContext& rc);
    //�ړ������B
    void Move();
    //��]����
    void Rotation();

    //�������烁���o�ϐ��B
    ModelRender modelRender; //���f�������_�\�B
    Vector3 position; //���W�B
    int moveState = 0; //��Ɉړ������Ɉړ�
    Vector3 firstPosition; //�ŏ��̍��W�B
    Quaternion rotation; //�N�H�[�^�j�I��
    Player* player; //�v���C���[
};

