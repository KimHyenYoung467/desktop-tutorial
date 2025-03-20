#pragma once
#include <stdio.h>
#include <windows.h>
#include "GEnd.h"
#include "GMenu.h"
#include "GPlay.h"
#include <time.h>
#include "ConsoleRenderer.h"

// 게임 첫 플레이 시에, 게임을 처음 시작할 때, 현재 씬 상태가 대기 씬이어야 하며, 
// 엔딩에 들어갈 때 10초 뒤에 복구 

namespace GManager
{

	HANDLE hScreenBuffer[1];
	int nScreenBufferIndex = 0;


enum Scenes
{
	GIDLE_STAY ,			// 대기 상태
	GEND_SCENE ,			// 게임 엔딩 씬 
	GPLAY_SCENE,			// 게임 플레이 씬 
	GMENU_SCENE				// 게임 메뉴 씬 
};

char SceneCurrent;  // 현재 씬 
char SceneNext;	    // 다음 씬 
SHORT prevState = 0; 

	void Initialize(); // Scene 처음 진입할 때 시작 할 함수 

	void update();	   // 상황(입력 또는 시간 변경) 에 따라 SceneNext 설정 

	void Render(char SceneCurrent, char Scenenext);	   // 콘솔창에 텍스트로 그리기 

	void GetKeyInput(); // 키입력 확인 함수 

}
	