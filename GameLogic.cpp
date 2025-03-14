#include "GameLogic.h"

#include "EventManager.h"
#include "KeywordManager.h"
#include "SceneManager.h"
#include "PathManager.h"
#include "SoundManager.h"
#include "pc.h"


int GameLogic::M_Init(HWND g_hWnd, POINT Resolution)
{
	m_hWnd = g_hWnd;
	m_Resolution = Resolution;


	RECT ClientRect;
	GetClientRect(m_hWnd, &ClientRect);


	int ClientWidth = 1920;	//
	int ClientHeight = 1080;

	//�ػ󵵿� �°� ������ ũ�� ����
	RECT window_size = { 0,0,Resolution.x,Resolution.y };
	//�����츦 window_size ũ��� ����
	AdjustWindowRect(&window_size,WS_EX_TOPMOST| WS_EX_APPWINDOW | WS_EX_WINDOWEDGE,true);
	//������ �츮�� ����� ������ ����
	SetWindowPos(m_hWnd, NULL, m_Resolution.x / 2 - ClientWidth / 2, m_Resolution.y / 2 - ClientHeight / 2, ClientWidth, ClientHeight, 0);

	m_hDC = GetDC(m_hWnd);

	//���� ���۸� �뵵�� ��Ʈ�ʰ� DC�� �����
	m_BackBuffer = CreateCompatibleBitmap(m_hDC, m_Resolution.x, m_Resolution.y);
	m_BackBuffer_DC = CreateCompatibleDC(m_hDC);

	HBITMAP hOldBitMap = (HBITMAP)SelectObject(m_BackBuffer_DC, m_BackBuffer);
	DeleteObject(hOldBitMap);


	//�Ŵ��� �ʱ�ȭ
	PathManager::GetInstance()->M_Init();
	TimeManager::GetInstance()->M_Init();
	KeyManager::GetInstance()->M_Init();
	SCENEMANAGER::GetInstance()->M_Init();
	KeywordManager::GetInstance()->M_Init();
	SoundManager::GetInstance()->M_Init();

	return S_OK;
}

void GameLogic::M_Game_Loop()
{
	srand(time(NULL));

	TimeManager::GetInstance()->M_Update();
	KeyManager::GetInstance()->M_Update();
	SCENEMANAGER::GetInstance()->M_Update();
	SoundManager::GetInstance()->M_Update();

	//ȭ�� Ŭ����
	Rectangle(m_BackBuffer_DC, -1, -1, m_Resolution.x + 1, m_Resolution.y + 1);

	SCENEMANAGER::GetInstance()->M_Render(m_BackBuffer_DC);

	//���� ��Ʈ�ʿ��� ���� ���� ��Ʈ������ ����
	BitBlt(m_hDC, 0, 0, m_Resolution.x, m_Resolution.y, m_BackBuffer_DC, 0, 0, SRCCOPY);

	//frame�� ���� ��
	//object ����+����
	//SceneChange�� ���� ����, Render �Ǵ� Update�� ������ �ʵ��� ����! �߿�!!!!

	EventManager::GetInstance()->update();

}

GameLogic::GameLogic() : m_hWnd(0), m_Resolution{}, m_hDC(0), m_BackBuffer(0), m_BackBuffer_DC(0)
{
}

GameLogic::~GameLogic()
{
	ReleaseDC(m_hWnd, m_hDC);
	DeleteDC(m_BackBuffer_DC);
	DeleteObject(m_BackBuffer);
}


int GameLogic::OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	CreateCaret(hWnd, NULL, 2, 17);
	ShowCaret(hWnd);

	return 1;
}


