#include "stdafx.h"
#include "Timer.h"
#include "Game.h"

Timer::Timer()
{
	
}

Timer::~Timer()
{

}

void Timer::Update()
{
	wchar_t wcsbuf[256];
	swprintf_s(wcsbuf, 256, L"�������Ԏc��%d�b", int(timer));

	//�\������e�L�X�g��ݒ�B
	m_fontRender.SetText(wcsbuf);
	//�t�H���g�̈ʒu��ݒ�B
	m_fontRender.SetPosition(Vector3(200.0f, 500.0f, 0.0f));
	//�t�H���g�̑傫����ݒ�B
	m_fontRender.SetScale(2.0f);
	//�t�H���g�̐F��ݒ�B
	m_fontRender.SetColor({ 1.0f,0.0f,0.0f,1.0f });
	
	timer -= g_gameTime->GetFrameDeltaTime();
	if (timer <= 0.0f) {
		timer = 0.0f;
	}
}

void Timer::Render(RenderContext& rc)
{
	m_fontRender.Draw(rc);
}