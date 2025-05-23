#include "stdafx.h"
#include "Coin.h"
#include "player.h"
#include "Game.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Coin::Coin()
{
    //�R�C���̃��f����ǂݍ��ށB
    modelRender.Init("Assets/sprite/coin.tkm");
    g_soundEngine->ResistWaveFileBank(1, "Assets/sound/GetCoin.wav");
    //�v���C���[�̃I�u�W�F�N�g��T���Ď����Ă���
    player = FindGO<Player>("player");
}

Coin::~Coin()
{

}

void Coin::Update()
{
    //�ړ�����
    Move();

    //��]����
    Rotation();

    //�G�`������̍X�V����
    modelRender.Update();

    //�v���C���[����R�C���Ɍ������x�N�g�����v�Z�B
    Vector3 diff = player->position - position;

    //�x�N�g���̒�����120.0f��菬����������B
    if (diff.Length() <= 120.0f)
    {
        //�J�E���g��+1����B
        player->coinCount += 1;
        SoundSource* se = NewGO<SoundSource>(1);
        se->Init(1);
        //���ʉ��̓��[�v�����Ȃ��̂ŁAfalse�ɂ���B
        se->Play(false);
        //���ʂ��グ��B
        se->SetVolume(3.5f);
        //���g���폜����B
        DeleteGO(this);


    }

    wchar_t coin[256];
    swprintf_s(coin, 256, L"�l���R�C��%d/5��", int(player->coinCount));

    //�\������e�L�X�g��ݒ�B
    m_fontRender.SetText(coin);
    //�t�H���g�̈ʒu��ݒ�B
    m_fontRender.SetPosition(Vector3(200.0f, 400.0f, 0.0f));
    //�t�H���g�̑傫����ݒ�B
    m_fontRender.SetScale(2.0f);
    //�t�H���g�̐F��ݒ�B
    m_fontRender.SetColor({ 0.0f,0.0f,1.0f,1.0f });

}

void Coin::Move()
{
    //�G�`������ɍ��W��������
    modelRender.SetPosition(position);
}

//��]�����B
void Coin::Rotation()
{
    //��]�����Z����B
    rotation.AddRotationDegY(2.0f);

    //�G�`������ɉ�]��������B
    modelRender.SetRotation(rotation);
}

void Coin::Render(RenderContext& rc)
{
    //�R�C����`�悷��
    modelRender.Draw(rc);
    m_fontRender.Draw(rc);

}