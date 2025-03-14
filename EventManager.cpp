#include  "pc.h"
#include "EventManager.h"
#include "GameObject.h"

#include "Scene.h"
#include "SceneManager.h"


void EventManager::update()
{
	//===============================================
	//���� �����ӿ��� ����ص� Dead Object ���� �����Ѵ�.
	//===============================================
	for(size_t i=0;i<m_vecDead.size();++i)
	{
		delete m_vecDead[i];
	}
	m_vecDead.clear();


	//==========================================
	//1�����ӿ� �Ͼ �̺�Ʈ���� �� �Բ� ó���Ѵ�.
	//==========================================

	for (size_t i = 0; i < m_vecEvent.size(); ++i)
	{
		Excute(m_vecEvent[i]);
	}
	m_vecEvent.clear();


}


void EventManager::Excute(const TEVENT& _eve)
{
	_eve.eEven;

	switch (_eve.eEven)
	{
	case EVENT_TYPE::CREATE_OBJECT:
		{
			//lParam:Object Adress
			//wParam: Group Type

		GameObject* pNewObj = (GameObject*)_eve.lParam;
		GROUPTYPE eType = (GROUPTYPE)_eve.wParam;
		SCENEMANAGER::GetInstance()->M_Get_CurrentScene()->M_AddObject(pNewObj, eType);
		}
		break;
	case EVENT_TYPE::DELETE_OBJECT:
		{
			//���� ������ �͵��� �־��ְ� ���� �������� �Ѿ�� �� ����

			//lParam:Object Adress
			//wParam: Group Type
			//Object�� Dead���·� ����
			//���� ���� ������Ʈ���� ��Ƶд�.

		GameObject* p_Deadobject = (GameObject*)_eve.lParam;
		p_Deadobject->M_SetDead();
		m_vecDead.push_back(p_Deadobject);


		}
		break;
	case EVENT_TYPE::SCENE_CHANGE:
		{
			//lParam: Next Scene Type
		SCENEMANAGER::GetInstance()->M_ChangeScene((SCENETYPE)_eve.lParam);
		}
		break;
	}

}



void EventManager::AddEvnet(const TEVENT& _eve)
{
	m_vecEvent.push_back(_eve);
}

EventManager::EventManager()
{
	
}

EventManager::~EventManager()
{
	
}
