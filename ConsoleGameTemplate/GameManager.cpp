#include "GameManager.h"
#include <stdio.h>
#include <windows.h>
#include "ConsoleRenderer.h"

void GManager::Initialize()		 // Scene 처음 진입할 때 시작 할 함수 
{
	SceneCurrent = Scenes::GIDLE_STAY;					// 현재 씬을 대기 상태로 저장 
	SceneNext = NULL; 					// 다음 씬은 비워둔다. 


	// SceneNext 에 다음 씬을 저장할 함수
}

void GManager::update()			 // 상황(입력 또는 시간 변경) 에 따라 SceneNext 설정 
{ 
	GManager::GetKeyInput();	 // 키 입력 받기 이전 입력 받은 키에 현재 상태의 키 입력 정보 저장. prevState = State; 

	// 입력에 따라서 다음씬으로 변경할 수 있도록 한다.
	// 현재 씬에 따라서 맞는 씬의 렌더함수 호출. 
	// 
	// 현재 씬에서 다른 씬으로 넘어갈 조건 : 현재 씬이 다음 씬이 아닐 때, 키 입력이 space 일 때 
	// 다음 씬의 초기화 함수(Intialize) 호출 후 현재 씬을 변경한다. 

	if (prevState == GetAsyncKeyState(VK_SPACE) && SceneCurrent != SceneNext)
	{
		switch (SceneCurrent != SceneNext) // 현재 씬이 다음 씬이 아닐 때, 현재 씬이 대기 상태냐 메뉴 이냐 에 따라 현재 씬을 변경 
		{
		case GIDLE_STAY :
			
			break; 
		case GMENU_SCENE : 
			GMenu::Initialize();  // 메뉴 창 초기화 
			GMenu::update();	  // 다음 씬으로 연결 하기. 
			GMenu::Render();	  // 메뉴 창 그리기 
			break; 
		case GPLAY_SCENE : 
			GPLAY::Initialize();  // 메뉴 창 초기화 
			GPLAY::update();	  // 다음 씬으로 연결 하기. 
			GPLAY::Render();	  // 메뉴 창 그리기 
			break; 
		case GEND_SCENE : 
			GEND::Initialize();  // 메뉴 창 초기화 
			GEND::update();	  // 다음 씬으로 연결 하기. 
			GEND::Render();	  // 메뉴 창 그리기 
			break; 
		}
	}
	if (prevState == GetAsyncKeyState(VK_ESCAPE))
	{
		// 종료 
		printf("ESC 키 입력! 프로그램 종료\n");
		return; 
	}
}

void GManager::Render(char SceneCurrent, char Scenenext)		 // 그리기 
{
	// 현재 씬과 다음 씬에 따라서 출력을 지우고 변경 
	// 
	// 현재 스크린 정보 얻기 (초기화) 
	ConsoleRenderer::ScreenInit();

	//현재 스크린의 가로 세로 길이 얻기 
	ConsoleRenderer::ScreenHeight();
	ConsoleRenderer::ScreenWidth();
	ConsoleRenderer::ScreenDrawString(0, 0, "GMenu_Scene", FG_PINK_DARK);

	if (SceneCurrent == GManager::GMENU_SCENE)
	{
		// 사용할 스크린 버퍼의 핸들 설정 해 화면에 출력 
		ConsoleRenderer::ScreenFlipping(); 

		// 화면이 바뀌었을 때 화면을 지우고, 초기화 한다.
		if (GManager::SceneCurrent == GManager::SceneNext)
		{
			ConsoleRenderer::ScreenClear();
			GMenu::Initialize(); //초기화 
		}
	}
	else if (SceneCurrent == GManager::GPLAY_SCENE)
	{
		ConsoleRenderer::ScreenFlipping(); 

		// 화면이 바뀌었을 때 화면을 지우고, 초기화 한다.
		if (GManager::SceneCurrent == GManager::SceneNext)
		{
			ConsoleRenderer::ScreenClear();
			GPLAY::Initialize(); //초기화 
		}
	}
	else if (SceneCurrent == GManager::GPLAY_SCENE)
	{
		ConsoleRenderer::ScreenFlipping();

		// 화면이 바뀌었을 때 화면을 지우고, 초기화 한다.
		if (GManager::SceneCurrent == GManager::SceneNext)
		{
			ConsoleRenderer::ScreenClear();
			GEND::Initialize(); //초기화 

		}
	}
	
}

void GManager::GetKeyInput()
{
	while (1)
	{
		SHORT state = GetAsyncKeyState(VK_SPACE); // 스페이스 바 상태 가져오기 

		if ((state & 0x8000) && !(prevState & 0x8000))
		{
			printf("스페이스 바 Down\n");
		}

		else if (!(state & 0x8000) && (prevState & 0x8000)) {
			printf("스페이스바 뗌 (Key Up)\n");
			
		}

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			printf("ESC 키 입력! 프로그램 종료\n");
			ConsoleRenderer::ScreenClear(); 
			ConsoleRenderer::ScreenRelease(); // 현재 화면의 스크린 버퍼를 닫는다.
			break;
		}

		prevState = state; // 현재 키 상태 저장 
	}
	return; 
}
