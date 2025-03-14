#pragma once
#include <windows.h>
#include "pc.h"


class TimeManager
{
	SINGLE(TimeManager);

private:
	LARGE_INTEGER m_Current_Count;
	LARGE_INTEGER m_Prev_Count;
	LARGE_INTEGER m_Frequency_Count;

	double		m_FrameTime;	//������ ���� �ð�, ������ 1�� �ɸ��� �ð�
	double		m_AccumTime;	//1�� Ȯ���� ���� ���� �ð�
	UINT		m_CallCount;	//�ʴ� ȣ�� Ƚ��
	UINT		m_FPS;			//�ʴ� ������
public:
	void M_Init();
	void M_Update();

public:
	double M_Get_Frame_Time() { return m_FrameTime; }
	float M_Get_Frame_Time_Float() { return (float)m_FrameTime; }

};

