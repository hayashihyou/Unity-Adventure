#pragma once
class Timer : public IGameObject
{

public:
	Timer();
	~Timer();
	//更新処理。
	void Update();
	void Render(RenderContext& rc);
	

	FontRender m_fontRender;
	float timer = 300.0f;
};

