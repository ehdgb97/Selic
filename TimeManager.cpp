#include "TimeManager.h"

#ifdef _DEBUG
#include "GameLogic.h"
#endif // DEBUG

TimeManager::TimeManager() 
	: m_Current_Count{},
	m_Prev_Count{},
	m_Frequency_Count{},
	m_FrameTime(0),
	m_AccumTime(0),
	m_CallCount(0)
{

}

TimeManager::~TimeManager()
{

}

void TimeManager::M_Init()
{
	//���� ī��Ʈ
	QueryPerformanceCounter(&m_Current_Count);
	//�ʴ� ī��Ʈ Ƚ��
	QueryPerformanceFrequency(&m_Frequency_Count);
}

void TimeManager::M_Update()
{
	QueryPerformanceCounter(&m_Current_Count);

	//���� �������� ī���ð� ���� ������ ī���� ���� ����
	m_FrameTime = (float)(m_Current_Count.QuadPart - m_Prev_Count.QuadPart) / (double)m_Frequency_Count.QuadPart;

	m_Prev_Count = m_Current_Count;

	++m_CallCount;
	m_AccumTime += m_FrameTime;	//������ �ð� ����

	if (m_AccumTime >= 1.)
	{
		m_FPS = m_CallCount;
		m_AccumTime = 0.;
		m_CallCount = 0;

#ifdef _DEBUG
		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS : %d, FramTime : %f", m_FPS, m_FrameTime);
		SetWindowText(GameLogic::GetInstance()->M_Get_MainWindow(), szBuffer);
#endif
	}
}