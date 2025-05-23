#include "stdafx.h"
#include "Coin.h"
#include "player.h"
#include "Game.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Coin::Coin()
{
    //コインのモデルを読み込む。
    modelRender.Init("Assets/sprite/coin.tkm");
    g_soundEngine->ResistWaveFileBank(1, "Assets/sound/GetCoin.wav");
    //プレイヤーのオブジェクトを探して持ってくる
    player = FindGO<Player>("player");
}

Coin::~Coin()
{

}

void Coin::Update()
{
    //移動処理
    Move();

    //回転処理
    Rotation();

    //絵描きさんの更新処理
    modelRender.Update();

    //プレイヤーからコインに向かうベクトルを計算。
    Vector3 diff = player->position - position;

    //ベクトルの長さが120.0fより小さかったら。
    if (diff.Length() <= 120.0f)
    {
        //カウントを+1する。
        player->coinCount += 1;
        SoundSource* se = NewGO<SoundSource>(1);
        se->Init(1);
        //効果音はループさせないので、falseにする。
        se->Play(false);
        //音量を上げる。
        se->SetVolume(3.5f);
        //自身を削除する。
        DeleteGO(this);


    }

    wchar_t coin[256];
    swprintf_s(coin, 256, L"獲得コイン%d/5枚", int(player->coinCount));

    //表示するテキストを設定。
    m_fontRender.SetText(coin);
    //フォントの位置を設定。
    m_fontRender.SetPosition(Vector3(200.0f, 400.0f, 0.0f));
    //フォントの大きさを設定。
    m_fontRender.SetScale(2.0f);
    //フォントの色を設定。
    m_fontRender.SetColor({ 0.0f,0.0f,1.0f,1.0f });

}

void Coin::Move()
{
    //絵描きさんに座標を教える
    modelRender.SetPosition(position);
}

//回転処理。
void Coin::Rotation()
{
    //回転を加算する。
    rotation.AddRotationDegY(2.0f);

    //絵描きさんに回転を教える。
    modelRender.SetRotation(rotation);
}

void Coin::Render(RenderContext& rc)
{
    //コインを描画する
    modelRender.Draw(rc);
    m_fontRender.Draw(rc);

}