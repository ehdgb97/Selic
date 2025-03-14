#pragma once
#include <windows.h>
#include "TimeManager.h"
#include "KeyManager.h"
#include "pc.h"

class GameLogic
{
	SINGLE(GameLogic);
public:
	//������ �������� ��� ���� �ʱ�ȭ
	int M_Init(HWND g_hWnd, POINT Resolution);

	//���� ���� ����
	void M_Game_Loop();
private:
	HWND m_hWnd;			//���� ������ �ڵ�
	POINT m_Resolution;		//���� ������ �ػ�
	HDC	m_hDC;				//���� ������ DC

	HBITMAP m_BackBuffer;	//backbuffer BitMap
	HDC	m_BackBuffer_DC;	//backbuffer BitMap�� DC
public:
	//ĳ�� ����
	int OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam);

	//���� ������ �ڵ� �ޱ�
	HWND M_Get_MainWindow() { return m_hWnd; }

	//BackBuffer�� BitMap �ޱ�
	HBITMAP M_Get_BackBuffer() { return m_BackBuffer; }

	//���� ������ DC �ޱ�
	HDC M_Get_DC() { return m_hDC; }

	//���� ������ �ػ�
	POINT M_Get_Resolution() { return m_Resolution; }
};



