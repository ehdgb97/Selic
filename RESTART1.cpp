#include "RESTART1.h"
#include "func.h"
#include "GameLogic.h"
#include "MapChangeButton.h"
#include "BackGround.h"
#include "MainTime.h"
#include "ScenePlayer.h"
#include "SoundManager.h"

void RESTART1::M_Enter()
{
	//���ȭ��
	BackGround* backgroundStage1 = new BackGround;
	backgroundStage1->M_Set_Position(Vec2(0.f, 0.f));
	//backgroundStage1->M_Set_Scale(Vec2(1000.f, 200.f));
	backgroundStage1->M_SetFileName(L"Resources\\BG\\RESTMAP.bmp");
	CreateObject(backgroundStage1, GROUPTYPE::DEFAULT);


	MainTime* main_timer = new MainTime;
	main_timer->M_Set_Position(Vec2(0.f, 60.f));
	main_timer->M_Set_NextScene(SCENETYPE::STAGE1);
	main_timer->M_Set_Image(Gdiplus::Image::FromFile(L""));
	main_timer->M_Set_Timer(4);
	main_timer->M_Set_Name(L"Main_timer");
	CreateObject(main_timer, GROUPTYPE::DEFAULT);

	ScenePlayer* sceneplayer = new ScenePlayer;
	sceneplayer->M_Set_Position(Vec2(0.f, 600.f));
	sceneplayer->M_Set_Name(L"RestartScenePlayer");
	sceneplayer->M_Set_CurrentImage(Gdiplus::Image::FromFile(L"Resources\\UI\\Restart.png"));
	CreateObject(sceneplayer, GROUPTYPE::PLAYER);
	SoundManager::GetInstance()->M_STOPBGM(3);
}

void RESTART1::M_Exit()
{
	HWND hEdit = GetWindow(GameLogic::GetInstance()->M_Get_MainWindow(), GW_CHILD);
	DestroyWindow(hEdit);
	M_DelateAll();
}

void RESTART1::M_Update()
{
	SCENE::M_Update();
}

void RESTART1::M_Render(HDC hdc)
{

}

RESTART1::RESTART1()
{

}

RESTART1::~RESTART1()
{

}

