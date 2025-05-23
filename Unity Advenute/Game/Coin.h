#pragma once
#include "sound/SoundSource.h"
class Player;
class Coin :public IGameObject
{
public:
    Coin();
    ~Coin();
    //更新処理
    void Update();
    //描画処理
    void Render(RenderContext& rc);
    //移動処理。
    void Move();
    //回転処理
    void Rotation();

    ModelRender modelRender; //モデルレンダ―。
    Vector3 position; //座標。
    int moveState = 0; //上に移動か下に移動
    Vector3 firstPosition; //最初の座標。
    Quaternion rotation; //クォータニオン
    Player* player; //プレイヤー
    FontRender m_fontRender;
};
