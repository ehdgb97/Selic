#pragma once
#include "pc.h"

//������ ����ȭ
//���� ������ ������ ���� Ű��  ����, ������ �̺�Ʈ�� ��������

//Ű �Է� �̺�Ʈ ó��
//tap hold away

enum class KEYSTATE
{
	NONE,//�������� �ʾҰ�, �������� �ȴ���
	TAP,//�� ���� ����
	HOLD,//������ �ִ�
	AWAY//�� �� ����
	
};

enum class KEY
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	SPACE,
	ENTER,
	BACK,
	ESCAPE,

	LAST
};

struct KEYINFO
{
	KEYSTATE keystate;	//Ű ����
	bool is_KeyDown;	//���� �����ӿ� ���ȴ���
};


class KeyManager
{
	SINGLE(KeyManager);
private:
	std::vector<KEYINFO> m_key;

public:
	void M_Init();
	void M_Update();

	wchar_t m_copytext[TEXTMAXLENGTH];
	// ���ڿ� �迭
	wchar_t* storedSTR[20];

public:
	KEYSTATE M_Get_KeyState(KEY key);
	//��� ���°�?
	wchar_t* Get_m_copytext() { return m_copytext; }
	void M_Reset_m_copytext();
};

