#pragma once
#include"Mecro.h"
#include"MapDraw.h"
#define MENUBOXWIDTH 50
#define MENUBOXHEIGHT 40
#define MENULENGTH 3
#define STORYFILE "베네치아_스토리.txt"
class Interface
{
	static Interface* interfaceManager;

public:
	static Interface* GetInstance()
	{
		if (interfaceManager == NULL) interfaceManager = new Interface();
		return interfaceManager;
	}
	Interface(); 
	void DrawBackGround();
	void ShowMenu();
	void ShowStory();
	int GetMenuInput();
};

