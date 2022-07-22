#include "Word.h"
Word::Word()
{
	position.x = NULL;
	position.y = NULL;
	
}

void Word::SetWord(ITEM_TYPE Type, int x, int y, string wordname)
{
	m_Type = Type;
	position.x = x;
	position.y = y;
	m_strWord = wordname;
}


void Word::Drop(bool Check_Blank)
{
		if(m_Type != ITEM_TYPE_NON)
			PUPPLE
		if (((position.x > 42 && position.x < 86) && (position.y > 22 && position.y < 29)) == false)
		{
			m_DrawManager.gotoxy(position.x, position.y);
			for (int i = 0; i < m_strWord.length(); i++)
				cout << " ";
			if (position.y >= HEIGHT - 4) // y축 끝부분
				position.y++;
			else
			{
				position.y++;
				if (Check_Blank == true)
				{
					m_DrawManager.gotoxy(position.x, position.y);
					for (int i = 0; i < m_strWord.length(); i++)
						cout << "=";
				}
				else
				m_DrawManager.TextDraw(m_strWord,position.x, position.y);
			}
		}
		else
		{
			if (position.y == 23 || position.y == 29)
			{
				m_DrawManager.gotoxy(position.x, position.y);
				for (int i = 0; i < m_strWord.length(); i++)
					cout << " ";
				position.y++;
			}
			else
				position.y++;
		}
		
	BLUE
}

void Word::Blank()
{
	m_DrawManager.gotoxy(position.x, position.y);
	for (int i = 0; i < m_strWord.length(); i++)
		cout << "=";
	position.y++;
}

void Word::Erase()
{
	m_DrawManager.gotoxy(position.x, position.y);
	for (int i = 0; i < m_strWord.length(); i++)
		cout << " ";
}