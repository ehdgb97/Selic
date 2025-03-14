#pragma once
#include "GameObject.h"
#include "pc.h"

class PlayerHP :
    public GameObject
{
private:
	//�ʱ� Ÿ�̸� ���� ��
	float m_Timer_Second;

	//�帣�� �ð�
	float m_Flowing_Time;
	float m_GaugePercent;

	//�ʱ� �ڽ� ũ��
	Vec2 m_InitScale;

	Gdiplus::Image* m_TimerImage;
	Gdiplus::Image* m_HpProgressBarImage;
	Gdiplus::Image* m_HPfenceImage;

public:
	//Ÿ�̸Ӱ� 1�� �۵��ϰ� ������� ���� ����
	int m_is_reset;
	SCENETYPE m_NextScene;
	virtual void M_Reset();
	void M_Set_Timer(float _time);
	void M_Set_NextScene(SCENETYPE _NextScene);
	void M_SetFileName(const wchar_t* _filename);

public:
	virtual void M_Render(HDC hdc);
	virtual void M_Update();

	PlayerHP();
	~PlayerHP();

};

