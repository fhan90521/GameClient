#pragma once
#include "MapDraw.h"
#define WIDTH 66
#define HEIGHT 37
class Interface // 전반적인 배경 그림 관리 Class
{
private:
	int m_ix;
	int m_iy;
	MapDraw m_DrawManager;
public:
	void Menu();
};

