#include "Interface.h"

void Interface::Menu()
{
	BLUE
	m_DrawManager.BoxDraw(0, 0, WIDTH, HEIGHT - 2);
	m_DrawManager.DrawMidText("☆ ★베 네 치 아★ ☆", (WIDTH + 66) * 0.5f, HEIGHT * 0.25f);
	m_DrawManager.DrawMidText("1.Game Start", (WIDTH + 66) * 0.5f, HEIGHT * 0.25f + 5);
	m_DrawManager.DrawMidText("2.Rank", (WIDTH + 66) * 0.5f, HEIGHT * 0.25f + 8);
	m_DrawManager.DrawMidText("3.Exit", (WIDTH + 66) * 0.5f, HEIGHT * 0.25f + 11);
	switch (m_DrawManager.MenuSelectCursor(3, 3, WIDTH * 0.45f - 2, HEIGHT * 0.25f + 5))
	{
	case 1:
	
		break;
	case 2:
		break;
	case 3:
		return;
	}
	ORIGINAL
}