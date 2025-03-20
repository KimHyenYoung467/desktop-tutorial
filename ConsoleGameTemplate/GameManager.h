#pragma once
#include <stdio.h>
#include <windows.h>
#include "GEnd.h"
#include "GMenu.h"
#include "GPlay.h"
#include <time.h>
#include "ConsoleRenderer.h"

// ���� ù �÷��� �ÿ�, ������ ó�� ������ ��, ���� �� ���°� ��� ���̾�� �ϸ�, 
// ������ �� �� 10�� �ڿ� ���� 

namespace GManager
{

	HANDLE hScreenBuffer[1];
	int nScreenBufferIndex = 0;


enum Scenes
{
	GIDLE_STAY ,			// ��� ����
	GEND_SCENE ,			// ���� ���� �� 
	GPLAY_SCENE,			// ���� �÷��� �� 
	GMENU_SCENE				// ���� �޴� �� 
};

char SceneCurrent;  // ���� �� 
char SceneNext;	    // ���� �� 
SHORT prevState = 0; 

	void Initialize(); // Scene ó�� ������ �� ���� �� �Լ� 

	void update();	   // ��Ȳ(�Է� �Ǵ� �ð� ����) �� ���� SceneNext ���� 

	void Render(char SceneCurrent, char Scenenext);	   // �ܼ�â�� �ؽ�Ʈ�� �׸��� 

	void GetKeyInput(); // Ű�Է� Ȯ�� �Լ� 

}
	