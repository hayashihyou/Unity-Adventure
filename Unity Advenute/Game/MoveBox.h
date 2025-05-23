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

	ModelRender				m_modelRender;				                    //���f�������_���[�B
	Vector3					m_position = {0.0f,50.0f,0.0f};					//���W�B
	Vector3					m_scale = Vector3(0.5f,0.5f,0.5f);				//�傫���B
	Quaternion				m_rotation;					                    //��]�B
	PhysicsStaticObject		m_physicsStaticObject;		                    //�ÓI�����I�u�W�F�N�g�B

	CharacterController m_testCon;
	Vector3 m_testMoveSpeed = Vector3::Zero;
	Vector3 moveDir;

	Vector3					m_defPosition;				                    //�������W�B
	const float				m_move = 200.0f;				                //�㉺�ړ��ʂ̏���B
	bool					m_moveflag = false;			                    //�㉺�ړ��̃t���O�B
	CollisionObject* m_collisionObject = nullptr;							//�R���W����
	Vector3	m_firstPosition;										        //�������ꂽ���W
	Player* m_player = nullptr;									            //�v���C���[
	
};
