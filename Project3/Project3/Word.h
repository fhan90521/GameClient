#pragma once
#include "MapDraw.h"
enum ITEM_TYPE
{
	ITEM_TYPE_NULL,
	ITEM_TYPE_SPEED_UP = 1,
	ITEM_TYPE_SPEED_DOWN = 2,
	ITEM_TYPE_STOP = 3,
	ITEM_TYPE_CLEAR = 4,
	ITEM_TYPE_HIDE = 5,
	ITEM_TYPE_NON = 6,
};
class Word // drop
{
private :
	string m_strWord;
	MapDraw m_DrawManager;
	POINT position;
	ITEM_TYPE m_Type;
public:
	Word();
	ITEM_TYPE getType() { return m_Type; }
	void SetWord(ITEM_TYPE Type, int x, int y, string wordname);
	int get_y() { return position.y; }
	string getWord() { return m_strWord; }
	void Erase();
	void Drop(bool Check_Blank); // ¶³±¸±â
	void Blank();
};
