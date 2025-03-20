#pragma once
#include "GameManager.h"




namespace GMenu 
{
	void Initialize(); // Scene 처음 진입할 때 시작 할 함수 

	char update();	   // 상황(입력 또는 시간 변경) 에 따라 SceneNext 설정 

	void Render();	   // 콘솔창에 텍스트로 그리기 
	// 다른 씬의 상태를 받아서 콘솔창에 띄울 수 있도록 하기 

}