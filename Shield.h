#pragma once
#include "GameObject.h"

class Shield :
    public GameObject
{
private:


public:
	//Ÿ�̸Ӱ� 1�� �۵��ϰ� ������� ���� ����

public:
	virtual void M_Render(HDC hdc);
	virtual void M_Update();

	Shield();
	~Shield();

};

