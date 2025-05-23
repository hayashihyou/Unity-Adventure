#include "stdafx.h"
#include "MoveBox.h"
#include "Player.h"
#include "collision/CollisionObject.h"

namespace
{
	Vector3 COLLISION_HEIGHT = Vector3(-10.5f, 80.0f, 14.0f);
	Vector3 COLLISION_SIZE_X = Vector3(250.0f, 150.0f, 250.0f);
}

MoveBox::MoveBox()
{

}

MoveBox::~MoveBox()
{

}

bool MoveBox::Start()
{
	m_modelRender.Init("Assets/level/movebox.tkm");
	//m_modelRender.Init("Assets/modelData/UnityChan.tkm");
	m_modelRender.SetScale(m_scale);
	m_modelRender.SetRotation(m_rotation);

	m_modelRender.Update();
	m_modelRender.SetPosition(m_position);

	m_defPosition = m_position;	//初期座標を設定。

	m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());
	m_physicsStaticObject.GetbtCollisionObject()->setUserIndex(enCollisionAttr_movebox);

	//キャラコンを初期化する。
	m_testCon.Init(10.0f, 10.0f, m_position);
	
	m_firstPosition = m_position;

	m_player = FindGO<Player>("player");

	return true;


}

void MoveBox::Update()
{
 	m_testMoveSpeed.x = 0.0f;
	m_testMoveSpeed.y = 0.0f;
	m_testMoveSpeed.z = 0.0f;

	moveDir = Vector3::Up;

	if (m_moveflag == true)
	{
		moveDir *= -1.0f;
	}

	moveDir *= 100.0f;

	m_testMoveSpeed = moveDir;

	m_position = m_testCon.Execute(m_testMoveSpeed, 1.0f / 60.0f);

	m_position.y += 90.0f;

	//ボックスを移動させる。
	//if (m_moveflag == false) {
	//	m_position.y += 2.0f;
	//}
	//else {
	//	m_position.y -= 2.0f;
	//}

	if (m_position.y <= m_defPosition.y - m_move) {
		m_moveflag = false;
	}
	else if (m_position.y >= m_defPosition.y + m_move) {
		m_moveflag = true;
	}

	//m_physicsStaticObject.SetPosition(m_position);
	//m_collisionObject->SetPosition(m_position);
	m_modelRender.SetPosition(m_position);

	m_physicsStaticObject.m_rigidBody.SetPositionAndRotation(m_position, m_rotation);

	m_modelRender.Update();
	
}

void MoveBox::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}