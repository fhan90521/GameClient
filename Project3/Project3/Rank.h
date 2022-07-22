#pragma once
#include "MapDraw.h"
struct Player
{
	string m_strname;
	int m_iscore;
	int m_istage;
};

class Rank // Rank 시스템 관리 Class
{
private:
	Player m_Player;
	vector<Player> m_Players;
	int m_ix;
	int m_iy;
	MapDraw m_DrawManager;
public:
	void Set_Player(string name, int stage, int score);
	void Load();
	void Save();
	void RankDraw();
};