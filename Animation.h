#pragma once
#include "pc.h"

class Animation
{
private:

	//�ִϸ��̼��� �帣�� �ð�
	float m_flowing_time = 0;
	//������ 
	int m_currentFrame = 0;
	//��������Ʈ �̹��� �����Ӻ� ��ġ
	std::vector<POINT> m_framePose_List;
	//������ �ִϸ��̼� ����
	ANIMESTATUS m_current_status;
	//�ִϸ��̼� ����: ������/�ɸ��ð�
	float m_imageInfo[DATA_LIST::DATA_LIST_END][(UINT)ANIMESTATUS::ANIMESTATUS_END];
	//�̹��� ������ġ.
	Gdiplus::Image * m_pTestImage[(UINT)ANIMESTATUS::ANIMESTATUS_END];
	float m_frametime;
	int m_lastframe;
	//���� �ý���
	LOOPSTATUS  m_loop;


	//����ó��
	bool m_aniFinished;


public:

	//Player ���� �ִϸ��̼��� �ʿ��� �͵��� ������ ��. �� �߰��ϱ�. ���ϸ�,�����Ӽ�(��������Ʈ����),�ɸ��½ð�,����
	void M_AddAnimation(const wchar_t* _filename, int _frame, float _time, ANIMESTATUS _status);
	//������ �ִϸ��̼� ����: ANIMESTATUS enum
	void M_SetAnimation(ANIMESTATUS _status, LOOPSTATUS _LOOPSTATUS);
	//�ִϸ��̼� ����: x��ġ, y��ġ, hdc
	void M_PlayAnimation(int _initX, int _initY, HDC _hdc);
	ANIMESTATUS M_Get_m_current_status() { return m_current_status; }
	int M_Get_Current_Frame() {return m_currentFrame;}
	float M_Get_Current_m_imageInfo(DATA_LIST _DATA_LIST) {return m_imageInfo[_DATA_LIST][(UINT)m_current_status];}
	


	Animation();
	~Animation();

};

