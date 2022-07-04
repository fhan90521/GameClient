#include "GameManager.h"
void GameManager::MainLoop()
{
	int select = 0;
	while (1)
	{
		Interface::GetInstance()->DrawBackGround();
		Interface::GetInstance()->ShowMenu();
		select=Interface::GetInstance()->GetMenuInput();
		switch (select)
		{
		case 1:
			system("cls");
			break;
		case 2:
			break;
		case 3:
			return;
		}

	}
}