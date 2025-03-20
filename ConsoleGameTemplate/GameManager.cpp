#include "GameManager.h"
#include <stdio.h>
#include <windows.h>
#include "ConsoleRenderer.h"

void GManager::Initialize()		 // Scene ó�� ������ �� ���� �� �Լ� 
{
	SceneCurrent = Scenes::GIDLE_STAY;					// ���� ���� ��� ���·� ���� 
	SceneNext = NULL; 					// ���� ���� ����д�. 


	// SceneNext �� ���� ���� ������ �Լ�
}

void GManager::update()			 // ��Ȳ(�Է� �Ǵ� �ð� ����) �� ���� SceneNext ���� 
{ 
	GManager::GetKeyInput();	 // Ű �Է� �ޱ� ���� �Է� ���� Ű�� ���� ������ Ű �Է� ���� ����. prevState = State; 

	// �Է¿� ���� ���������� ������ �� �ֵ��� �Ѵ�.
	// ���� ���� ���� �´� ���� �����Լ� ȣ��. 
	// 
	// ���� ������ �ٸ� ������ �Ѿ ���� : ���� ���� ���� ���� �ƴ� ��, Ű �Է��� space �� �� 
	// ���� ���� �ʱ�ȭ �Լ�(Intialize) ȣ�� �� ���� ���� �����Ѵ�. 

	if (prevState == GetAsyncKeyState(VK_SPACE) && SceneCurrent != SceneNext)
	{
		switch (SceneCurrent != SceneNext) // ���� ���� ���� ���� �ƴ� ��, ���� ���� ��� ���³� �޴� �̳� �� ���� ���� ���� ���� 
		{
		case GIDLE_STAY :
			
			break; 
		case GMENU_SCENE : 
			GMenu::Initialize();  // �޴� â �ʱ�ȭ 
			GMenu::update();	  // ���� ������ ���� �ϱ�. 
			GMenu::Render();	  // �޴� â �׸��� 
			break; 
		case GPLAY_SCENE : 
			GPLAY::Initialize();  // �޴� â �ʱ�ȭ 
			GPLAY::update();	  // ���� ������ ���� �ϱ�. 
			GPLAY::Render();	  // �޴� â �׸��� 
			break; 
		case GEND_SCENE : 
			GEND::Initialize();  // �޴� â �ʱ�ȭ 
			GEND::update();	  // ���� ������ ���� �ϱ�. 
			GEND::Render();	  // �޴� â �׸��� 
			break; 
		}
	}
	if (prevState == GetAsyncKeyState(VK_ESCAPE))
	{
		// ���� 
		printf("ESC Ű �Է�! ���α׷� ����\n");
		return; 
	}
}

void GManager::Render(char SceneCurrent, char Scenenext)		 // �׸��� 
{
	// ���� ���� ���� ���� ���� ����� ����� ���� 
	// 
	// ���� ��ũ�� ���� ��� (�ʱ�ȭ) 
	ConsoleRenderer::ScreenInit();

	//���� ��ũ���� ���� ���� ���� ��� 
	ConsoleRenderer::ScreenHeight();
	ConsoleRenderer::ScreenWidth();
	ConsoleRenderer::ScreenDrawString(0, 0, "GMenu_Scene", FG_PINK_DARK);

	if (SceneCurrent == GManager::GMENU_SCENE)
	{
		// ����� ��ũ�� ������ �ڵ� ���� �� ȭ�鿡 ��� 
		ConsoleRenderer::ScreenFlipping(); 

		// ȭ���� �ٲ���� �� ȭ���� �����, �ʱ�ȭ �Ѵ�.
		if (GManager::SceneCurrent == GManager::SceneNext)
		{
			ConsoleRenderer::ScreenClear();
			GMenu::Initialize(); //�ʱ�ȭ 
		}
	}
	else if (SceneCurrent == GManager::GPLAY_SCENE)
	{
		ConsoleRenderer::ScreenFlipping(); 

		// ȭ���� �ٲ���� �� ȭ���� �����, �ʱ�ȭ �Ѵ�.
		if (GManager::SceneCurrent == GManager::SceneNext)
		{
			ConsoleRenderer::ScreenClear();
			GPLAY::Initialize(); //�ʱ�ȭ 
		}
	}
	else if (SceneCurrent == GManager::GPLAY_SCENE)
	{
		ConsoleRenderer::ScreenFlipping();

		// ȭ���� �ٲ���� �� ȭ���� �����, �ʱ�ȭ �Ѵ�.
		if (GManager::SceneCurrent == GManager::SceneNext)
		{
			ConsoleRenderer::ScreenClear();
			GEND::Initialize(); //�ʱ�ȭ 

		}
	}
	
}

void GManager::GetKeyInput()
{
	while (1)
	{
		SHORT state = GetAsyncKeyState(VK_SPACE); // �����̽� �� ���� �������� 

		if ((state & 0x8000) && !(prevState & 0x8000))
		{
			printf("�����̽� �� Down\n");
		}

		else if (!(state & 0x8000) && (prevState & 0x8000)) {
			printf("�����̽��� �� (Key Up)\n");
			
		}

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			printf("ESC Ű �Է�! ���α׷� ����\n");
			ConsoleRenderer::ScreenClear(); 
			ConsoleRenderer::ScreenRelease(); // ���� ȭ���� ��ũ�� ���۸� �ݴ´�.
			break;
		}

		prevState = state; // ���� Ű ���� ���� 
	}
	return; 
}
