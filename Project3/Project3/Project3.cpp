#include "Play.h"
void main()
{
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", HEIGHT + 1, WIDTH * 2);
	system(buf);
	Play play;
	play.Game_Menu();
}


