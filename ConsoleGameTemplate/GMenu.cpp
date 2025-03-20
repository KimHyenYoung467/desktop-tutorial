#include "GMenu.h"

void GMenu::Initialize()
{
	GManager::SceneCurrent = GManager::GMENU_SCENE; 
	GManager::SceneNext = NULL; 
	ConsoleRenderer::ScreenFlipping(); // ���� ������ �ε��� ���� ���� �غ� ��Ų��. 
}

char GMenu::update()
{
	GManager::GetKeyInput();  // Ű �Է� �ޱ� ���� �Է� ���� Ű�� ���� ������ Ű �Է� ���� ����. prevState = State; 
	if (GManager::prevState == NULL) return 'F';

	ConsoleRenderer::ScreenInit();
	if (GManager::prevState == GetAsyncKeyState(VK_SPACE) && !(GManager::prevState & 0x8000))
	{
		GManager::SceneNext = GManager::GPLAY_SCENE; // ���� ���� �÷��� ������ ���� 
		// ���� �ÿ� ȭ�� ���� �ʱ�ȭ 
		ConsoleRenderer::ScreenClear();
		ConsoleRenderer::ScreenRelease(); // ȭ�� ��ũ�� ���� �ݱ� 

	}

	return GManager::SceneNext;
}

void GMenu::Render()
{
	// ���� ���� ���� ���� ���� ����� ����� ���� 
	// 
	// ���� ��ũ�� ���� ��� (�ʱ�ȭ) 
	ConsoleRenderer::ScreenInit();

	//���� ��ũ���� ���� ���� ���� ��� 
	ConsoleRenderer::ScreenHeight();
	ConsoleRenderer::ScreenWidth();
	ConsoleRenderer::ScreenDrawString(0, 0, "GMenu_Scene", FG_PINK_DARK);

	if (GManager::SceneCurrent == GManager::GMENU_SCENE)
	{
		// ����� ��ũ�� ������ �ڵ� ���� �� ȭ�鿡 ��� 
		// ȭ���� �ٲ���� �� ȭ���� �����, �ʱ�ȭ �Ѵ�. 
		ConsoleRenderer::ScreenClear();
		GMenu::Initialize(); //�ʱ�ȭ 
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
