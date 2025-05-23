#include "stdafx.h"
#include "BackGround.h"
#include "Game.h"

BackGround::BackGround()
{
	//コメントアウトする。
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	modelRender.Init("Assets/sprite/stage.tkm");
	modelRender.Update();
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());
}

BackGround::~BackGround()
{

}

void BackGround::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}