#pragma once

class Player;

class MoveBox : public IGameObject
{
public:
	MoveBox();
	~MoveBox();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	ModelRender				m_modelRender;				                    //モデルレンダラー。
	Vector3					m_position = {0.0f,50.0f,0.0f};					//座標。
	Vector3					m_scale = Vector3(0.5f,0.5f,0.5f);				//大きさ。
	Quaternion				m_rotation;					                    //回転。
	PhysicsStaticObject		m_physicsStaticObject;		                    //静的物理オブジェクト。

	CharacterController m_testCon;
	Vector3 m_testMoveSpeed = Vector3::Zero;
	Vector3 moveDir;

	Vector3					m_defPosition;				                    //初期座標。
	const float				m_move = 200.0f;				                //上下移動量の上限。
	bool					m_moveflag = false;			                    //上下移動のフラグ。
	CollisionObject* m_collisionObject = nullptr;							//コリジョン
	Vector3	m_firstPosition;										        //生成された座標
	Player* m_player = nullptr;									            //プレイヤー
	
};
