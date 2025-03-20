#include "GMenu.h"

void GMenu::Initialize()
{
	GManager::SceneCurrent = GManager::GMENU_SCENE; 
	GManager::SceneNext = NULL; 
	ConsoleRenderer::ScreenFlipping(); // 다음 버퍼의 인덱스 증가 시켜 준비 시킨다. 
}

char GMenu::update()
{
	GManager::GetKeyInput();  // 키 입력 받기 이전 입력 받은 키에 현재 상태의 키 입력 정보 저장. prevState = State; 
	if (GManager::prevState == NULL) return 'F';

	ConsoleRenderer::ScreenInit();
	if (GManager::prevState == GetAsyncKeyState(VK_SPACE) && !(GManager::prevState & 0x8000))
	{
		GManager::SceneNext = GManager::GPLAY_SCENE; // 다음 씬을 플레이 씬으로 변경 
		// 변경 시에 화면 정보 초기화 
		ConsoleRenderer::ScreenClear();
		ConsoleRenderer::ScreenRelease(); // 화면 스크린 버퍼 닫기 

	}

	return GManager::SceneNext;
}

void GMenu::Render()
{
	// 현재 씬과 다음 씬에 따라서 출력을 지우고 변경 
	// 
	// 현재 스크린 정보 얻기 (초기화) 
	ConsoleRenderer::ScreenInit();

	//현재 스크린의 가로 세로 길이 얻기 
	ConsoleRenderer::ScreenHeight();
	ConsoleRenderer::ScreenWidth();
	ConsoleRenderer::ScreenDrawString(0, 0, "GMenu_Scene", FG_PINK_DARK);

	if (GManager::SceneCurrent == GManager::GMENU_SCENE)
	{
		// 사용할 스크린 버퍼의 핸들 설정 해 화면에 출력 
		// 화면이 바뀌었을 때 화면을 지우고, 초기화 한다. 
		ConsoleRenderer::ScreenClear();
		GMenu::Initialize(); //초기화 
	}
	else if (GManager::SceneCurrent == GManager::GPLAY_SCENE)
	{
		ConsoleRenderer::ScreenFlipping();
	}
	else if (GManager::SceneCurrent == GManager::GPLAY_SCENE)
	{
		ConsoleRenderer::ScreenFlipping();
	}

}
