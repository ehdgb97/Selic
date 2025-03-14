#include "KeyManager.h"
#include <windows.h>
#include "GameLogic.h"
#include "STAGE1.h"


int g_KeyArray[(int)KEY::LAST] =
{
	VK_LEFT,
	VK_RIGHT,
	VK_UP,
	VK_DOWN,
	VK_SPACE,
	VK_RETURN,
	VK_BACK,
	VK_ESCAPE
};

KeyManager::KeyManager()
{
}

KeyManager::~KeyManager()
{}

void KeyManager::M_Init()
{
	for (int i = 0; i < (int)KEY::LAST; ++i)
	{
		m_key.push_back(KEYINFO{ KEYSTATE::NONE,false });
	}
}

void KeyManager::M_Update()
{
	//���� ��Ŀ�� �˾Ƴ���
	HWND hWnd = GetFocus();

	//��Ŀ�� ���϶� Ű �̺�Ʈ
	if (hWnd != nullptr)
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			//Ű�� �����ִ�
			if (GetAsyncKeyState(g_KeyArray[i]) & 0x8000)
			{
				//�������� ���ȴ�
				if (m_key[i].is_KeyDown)
				{
					m_key[i].keystate = KEYSTATE::HOLD;
				}
				else
				{
					//�������� �ȴ����־���
					m_key[i].keystate = KEYSTATE::TAP;
				}

				m_key[i].is_KeyDown = true;
			}
			//�ȴ��ȴ�
			else
			{
				if (m_key[i].is_KeyDown)
				{
					//������ �����־���
					m_key[i].keystate = KEYSTATE::AWAY;
				}
				else
				{
					//�������� �ȴ����־���
					m_key[i].keystate = KEYSTATE::NONE;
				}
				m_key[i].is_KeyDown = false;
			}
		}
	}
	else
	{
		for (int i = 0; i < (int)KEY::LAST; ++i)
		{
			m_key[i].is_KeyDown = false;

			if (KEYSTATE::TAP == m_key[i].keystate || KEYSTATE::HOLD == m_key[i].keystate)
			{
				m_key[i].keystate = KEYSTATE::AWAY;
			}
			else if (KEYSTATE::AWAY == m_key[i].keystate)
			{
				m_key[i].keystate = KEYSTATE::NONE;
			}
		}
	}
}



KEYSTATE KeyManager::M_Get_KeyState(KEY key)
{
	return m_key[(int)key].keystate;
}

void KeyManager::M_Reset_m_copytext()
{
	for (size_t i = 0; i < 40; i++)
	{
		m_copytext[i] = '\0';

	}
}
