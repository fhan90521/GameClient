#pragma once
#include "MapDraw.h"
#define WIDTH 66
#define HEIGHT 37
class Interface // �������� ��� �׸� ���� Class
{
private:
	int m_ix;
	int m_iy;
	MapDraw m_DrawManager;
public:
	void Menu();
};

