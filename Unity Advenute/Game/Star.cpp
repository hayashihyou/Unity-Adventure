#include "stdafx.h"
#include "Star.h"
#include "Game.h"
#include "Player.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Star::Star()
{
    //���̃��f����ǂݍ��ށB
    modelRender.Init("Assets/modelData/star.tkm");

    g_soundEngine->ResistWaveFileBank(2, "Assets/sound/GetStar.wav");
    //�v���C���[�̃I�u�W�F�N�g��T���Ď����Ă���
    player = FindGO<Player>("player");
}

Star::~Star()
{

}

void Star::Update()
{
    //�ړ�����
    Move();

    //��]����
    Rotation();

    //�G�`������̍X�V����
    modelRender.Update();

    //�v���C���[���灙�Ɍ������x�N�g�����v�Z�B
    Vector3 diff = player->position - position;

    //�x�N�g���̒�����120.0f��菬����������B
    if (diff.Length() <= 120.0f)
    {
        //�J�E���g��+1����B
        player->starCount += 1;
        SoundSource* se = NewGO<SoundSource>(2);
        se->Init(2);
        //���ʉ��̓��[�v�����Ȃ��̂ŁAfalse�ɂ���B
        se->Play(false);
        //���ʂ��グ��B
        se->SetVolume(3.5f);

        //���g���폜����B
        DeleteGO(this);

    }
}

void Star::Move()
{
    //moveState��0�̎��B
    if (moveState == 0)
    {
        //��Ɉړ�����B
        position.y += 1.0f;
    }

    //moveState��1�̎��B
    else if (moveState == 1)
    {
        //���Ɉړ�����B
        position.y -= 1.0f;
    }

    //y���W��100.0f�𒴂�����B
    if (position.y >= firstPosition.y + 50.0f)
    {
        //moveState��1�ɂ���(���Ɉړ�����悤�ɂ���)�B
        moveState = 1;
    }

    //y���W��-100.0f��艺�ɂȂ�����B
    else if (position.y <= firstPosition.y - 50.0f)
    {
        //moveState��0�ɂ���(��Ɉړ�����悤�ɂ���)�B
        moveState = 0;
    }

    //�G�`������ɍ��W��������
    modelRender.SetPosition(position);
}

//��]�����B
void Star::Rotation()
{
    //��]�����Z����B
    rotation.AddRotationDegY(2.0f);

    //�G�`������ɉ�]��������B
    modelRender.SetRotation(rotation);
}

void Star::Render(RenderContext& rc)
{
    //����`�悷��
    modelRender.Draw(rc);
}