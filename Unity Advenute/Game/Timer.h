#pragma once
class Timer : public IGameObject
{

public:
	Timer();
	~Timer();
	//XVˆ—B
	void Update();
	void Render(RenderContext& rc);
	

	FontRender m_fontRender;
	float timer = 300.0f;
};

