#include "Interface.h"
Interface* Interface::interfaceManager = NULL;
Interface::Interface()
{

}
void Interface::DrawBackGround()
{
	MapDraw::GetInstance()->BoxDraw(0, 0, MENUBOXWIDTH, MENUBOXHEIGHT);
}
void Interface::ShowMenu()
{
	MapDraw::GetInstance()->DrawMidText("========배네치아=========", MENUBOXWIDTH, MENUBOXHEIGHT / 5);
	MapDraw::GetInstance()->DrawMidText("========1.GameStart=====", MENUBOXWIDTH, MENUBOXHEIGHT / 5*2);
	MapDraw::GetInstance()->DrawMidText("========2.Rank==========", MENUBOXWIDTH, MENUBOXHEIGHT / 5 * 3);
	MapDraw::GetInstance()->DrawMidText("========3.Exit==========", MENUBOXWIDTH, MENUBOXHEIGHT / 5 * 4);
	 
}
void Interface::ShowStory()
{
	string story;
	ifstream load;
	load.open(STORYFILE);
	if (load.is_open())
	{
		load.seekg(0, ios::end);
		int size = load.tellg();
		story.resize(size);
		load.seekg(0, ios::beg);
		load.read(&story[0], size);
		load.close();
	}
}
int Interface::GetMenuInput()
{
	return MapDraw::GetInstance()->MenuSelectCursor(MENULENGTH, MENUBOXHEIGHT / 5, MENUBOXWIDTH / 3, MENUBOXHEIGHT / 5 * 2);
}