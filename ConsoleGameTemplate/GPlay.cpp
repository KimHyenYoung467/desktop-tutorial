#include "GPlay.h"

void GPLAY::Initialize()
{
}

char GPLAY::update()
{
	GManager::GetKeyInput();  // Ű �Է� �ޱ� ���� �Է� ���� Ű�� ���� ������ Ű �Է� ���� ����. prevState = State; 

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
