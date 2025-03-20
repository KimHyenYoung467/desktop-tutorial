#include "GPlay.h"

void GPLAY::Initialize()
{
}

char GPLAY::update()
{
	GManager::GetKeyInput();  // 키 입력 받기 이전 입력 받은 키에 현재 상태의 키 입력 정보 저장. prevState = State; 

	if (GManager::prevState == NULL) return 'F';

	if (GManager::prevState == GetAsyncKeyState(VK_SPACE) && !(GManager::prevState & 0x8000))
	{
		GManager::SceneNext = GManager::GEND_SCENE;
	}

	return GManager::SceneNext;
}

void GPLAY::Render()
{
}
