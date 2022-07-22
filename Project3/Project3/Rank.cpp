#include "Rank.h"

void Rank::Load()
{
	ifstream Load;
	Player player;

	Load.open("Rank.txt");
	if (m_Players.size() != NULL)
		m_Players.clear();
	
		if (Load.is_open())
		{
			while (!Load.eof())
			{
				Load >> player.m_strname;
				Load >> player.m_istage;
				Load >> player.m_iscore;
				m_Players.push_back(player);
			}
			Load.close();
		}
}

void Rank::Set_Player(string name, int stage, int score)
{
	m_Player.m_strname = name;
	m_Player.m_istage = stage;
	m_Player.m_iscore = score;
}

void Rank::Save()
{
	ofstream Save;
	Save.open("Rank.txt", ios::app);
	if (Save.is_open())
	{
		Save << endl << m_Player.m_strname << " ";
		Save << m_Player.m_istage << " ";
		Save << m_Player.m_iscore;
	}
	Save.close();
}


void Rank::RankDraw()
{
	Player player;
	
	BLUE
		int count = 0;
	int ilength = 1;
	system("cls");
	m_DrawManager.BoxErase(15, 5, WIDTH * 0.5f, HEIGHT * 0.5f);
	m_DrawManager.BoxDraw(WIDTH * 0.73f, 4, BOXWIDTH, BOXHEIGHT);
	m_DrawManager.DrawMidText("Ranking", (WIDTH * 2) * 0.5f, 6);
	for (int i = 2; i < (WIDTH * 2) - 2; i++)
	{
		m_DrawManager.gotoxy(i, HEIGHT - 27);
		cout << "=";
	}

	
	m_DrawManager.DrawMidText("name                 score                 stage", (WIDTH * 2) * 0.5f, HEIGHT - 25);
	for(int i = 0; i < m_Players.size() - 1; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (m_Players[j].m_iscore < m_Players[j + 1].m_iscore)
			{
				player = m_Players[j + 1];
				m_Players[j + 1] = m_Players[j];
				m_Players[j] = player;
			}
		}
	}

	count = min(m_Players.size(), 11);
	for (int i = 0; i < count - 1; i++)
	{
		m_DrawManager.gotoxy((WIDTH * 2) * 0.35f - 4, HEIGHT - 25 + ilength);
		cout << m_Players[i].m_strname;
		m_DrawManager.gotoxy((WIDTH * 2) * 0.5f - 3, HEIGHT - 25 + ilength);
		cout << m_Players[i].m_iscore;
		m_DrawManager.gotoxy((WIDTH * 2) * 0.65f + 2, HEIGHT - 25 + ilength);
		cout << m_Players[i].m_istage;
		ilength += 2;
	}
			
	getch();
	ORIGINAL
}