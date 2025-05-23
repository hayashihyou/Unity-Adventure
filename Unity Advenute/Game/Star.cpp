#include "stdafx.h"
#include "Star.h"
#include "Game.h"
#include "Player.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Star::Star()
{
    //☆のモデルを読み込む。
    modelRender.Init("Assets/modelData/star.tkm");

    g_soundEngine->ResistWaveFileBank(2, "Assets/sound/GetStar.wav");
    //プレイヤーのオブジェクトを探して持ってくる
    player = FindGO<Player>("player");
}

Star::~Star()
{

}

void Star::Update()
{
    //移動処理
    Move();

    //回転処理
    Rotation();

    //絵描きさんの更新処理
    modelRender.Update();

    //プレイヤーから☆に向かうベクトルを計算。
    Vector3 diff = player->position - position;

    //ベクトルの長さが120.0fより小さかったら。
    if (diff.Length() <= 120.0f)
    {
        //カウントを+1する。
        player->starCount += 1;
        SoundSource* se = NewGO<SoundSource>(2);
        se->Init(2);
        //効果音はループさせないので、falseにする。
        se->Play(false);
        //音量を上げる。
        se->SetVolume(3.5f);

        //自身を削除する。
        DeleteGO(this);

    }
}

void Star::Move()
{
    //moveStateが0の時。
    if (moveState == 0)
    {
        //上に移動する。
        position.y += 1.0f;
    }

    //moveStateが1の時。
    else if (moveState == 1)
    {
        //下に移動する。
        position.y -= 1.0f;
    }

    //y座標が100.0fを超えたら。
    if (position.y >= firstPosition.y + 50.0f)
    {
        //moveStateを1にする(下に移動するようにする)。
        moveState = 1;
    }

    //y座標が-100.0fより下になったら。
    else if (position.y <= firstPosition.y - 50.0f)
    {
        //moveStateを0にする(上に移動するようにする)。
        moveState = 0;
    }

    //絵描きさんに座標を教える
    modelRender.SetPosition(position);
}

//回転処理。
void Star::Rotation()
{
    //回転を加算する。
    rotation.AddRotationDegY(2.0f);

    //絵描きさんに回転を教える。
    modelRender.SetRotation(rotation);
}

void Star::Render(RenderContext& rc)
{
    //☆を描画する
    modelRender.Draw(rc);
}