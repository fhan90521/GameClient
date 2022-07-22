#include "Play.h"
Play::Play()
{
	m_iLife = 9;
	m_iScore = 0;
	m_strName = "? ? ?";
}

void Play::Game_Menu()
{
	bool Check_first = false;
	while (1)
	{
		BLUE	
				m_DrawManager.BoxDraw(0, 0, WIDTH, HEIGHT - 2);
		m_DrawManager.DrawMidText("☆ ★베 네 치 아★ ☆", (WIDTH + 66) * 0.5f, HEIGHT * 0.25f);
		m_DrawManager.DrawMidText("1.Game Start", (WIDTH + 66) * 0.5f, HEIGHT * 0.25f + 5);
		m_DrawManager.DrawMidText("2.Rank", (WIDTH + 66) * 0.5f, HEIGHT * 0.25f + 8);
		m_DrawManager.DrawMidText("3.Exit", (WIDTH + 66) * 0.5f, HEIGHT * 0.25f + 11);
		Player_Draw();
		
		
			switch (m_DrawManager.MenuSelectCursor(3, 3, WIDTH * 0.45f - 2, HEIGHT * 0.25f + 5))
			{
			case 1: // 게임 시작
				m_WordManager.Load();
				StoryTelling();
				Setplayer_name();
				Game_Play();
				
				break;
			case 2: // 랭킹
				m_Rank.Load();
				m_Rank.RankDraw();
				break;
			case 3: // 종료
				return;
			}
		ORIGINAL
	}
}

void Play::Setplayer_name()
{
	BLUE
		char ch;
	string name;
	m_DrawManager.BoxErase(15, 5, WIDTH * 0.6f, HEIGHT * 0.5f);
	m_DrawManager.BoxDraw(WIDTH * 0.73f, HEIGHT * 0.65f, BOXWIDTH, BOXHEIGHT);
	m_DrawManager.DrawMidText("이름 입력", WIDTH, HEIGHT * 0.6f);
	
	while (1)
	{
		ch = getch();
		switch (ch)
		{
		case 8: // 8 = Backspace

			m_DrawManager.gotoxy(40 + BOXWIDTH, 26);
			cout << "                ";
			name = name.substr(0, name.length() - 1);
			m_DrawManager.DrawMidText(name, 48 + BOXWIDTH, 26);
			if (name.length() < 10)
				m_DrawManager.DrawMidText("             ", WIDTH, HEIGHT * 0.6f + 1);
			break;
		case 13:
			m_strName = name;
			return;
		default:
			if (name.length() < 10)
			{
				name += ch;
				m_DrawManager.DrawMidText(name, 48 + BOXWIDTH, 26);
				break;
			}
			else	//if (name.length() >= 10)
				m_DrawManager.DrawMidText("10글자 초과!!", WIDTH, HEIGHT * 0.6f + 1);

		}
	}
	ORIGINAL
}



void Play::Player_Draw() // 나중에 score 수정 할 것.
{
	string strscore = to_string(m_iScore);
	m_DrawManager.gotoxy(2, HEIGHT - 1);
	RED
		cout << "Life : ";
	for (int i = 1; i <= m_iLife; i++)
	{
		m_DrawManager.gotoxy(6 + (2 + i * 2), HEIGHT - 1);
		cout << "♥";
	}
	m_DrawManager.DrawMidText("score = " + strscore, (WIDTH + 66) * 0.5f, HEIGHT - 1);
	m_DrawManager.gotoxy((WIDTH + 50), HEIGHT - 1);
	cout << "Name : " << "          ";
	m_DrawManager.gotoxy((WIDTH + 50), HEIGHT - 1);
	cout << "Name : " << m_strName;
}

void Play::StoryTelling()
{
	int Height = 0;
	string LoadStory;
	vector<string>story_page;
	ifstream LoadBenechia;
	LoadBenechia.open("베네치아_스토리.txt");
	if (LoadBenechia.is_open())
	{
		while (!LoadBenechia.eof())
		{
			getline(LoadBenechia, LoadStory);
			m_strBenechia.push_back(LoadStory);
		}
		LoadBenechia.close();
	}

	BLUE

		
		m_DrawManager.BoxErase(15, 5 ,WIDTH * 0.5f, HEIGHT * 0.5f);
	m_DrawManager.BoxDraw(WIDTH * 0.73f, HEIGHT * 0.65f, BOXWIDTH, BOXHEIGHT);
	m_DrawManager.DrawMidText("Skip  : s", WIDTH, HEIGHT * 0.72f);


	srand(time(NULL));
	int start;
	int end = clock();
	int startindex = 0;
	int x = 0, y = 0;
	int index = 0;
	int page_count = 1;
	int page = 0; // i를 count함
	char ch;
	

		while(1)
		{ 
			if (kbhit())
			{
				ch = getch();
				if (ch == 's' || ch == 'S')
					return;
			}
			start = clock();
			if (start - end >= 100)
			{
				for(int page = 0; page < (page_count - startindex); page++)
				{
					x = (WIDTH + 66) * 0.5f; 
					y = (HEIGHT * 0.3f) + (page + 1);

					m_DrawManager.DrawMidText("                                                 ", x, y);
					m_DrawManager.DrawMidText(m_strBenechia[startindex + page].c_str(), x, y);
				}

				end = start;

				page_count++;
				if (10 <= page_count) startindex++;
				if (page_count > m_strBenechia.size())
					break;
			}
		}

}


void Play::Game_Play()
{
	srand(time(NULL));
	int stage = 1;
	string strWord;
	string strstage;
	BLUE
	m_DrawManager.BoxErase(15, 5, WIDTH * 0.5f + 2, HEIGHT * 0.7f);
	
	Player_Draw();
	BLUE

	int start, enddraw, enddrop, stage_end, start_item, end_item, start_Error, end_Error;
	int iscore = 0;
	enddraw = clock();
	stage_end = clock();
	enddrop = clock();
	end_item = clock();
	end_Error = clock();
	string strname;
	string strscore;
	bool check_Stage = true;
	bool Catch_Check = false;
	bool Check_Letter = true;
	bool Check_item = false;
	bool Check_Blank = false;
	bool isDrawStageText = false;
	char ch;
	int Letter_time = 0;
	int time = 0;
	while (1)
	{
		if (iscore >= 500)
		{
			stage++;
			m_iScore += iscore;
			
			iscore = 0;
			strscore = to_string(iscore);
			RED
				m_DrawManager.DrawMidText("            ", (WIDTH + 66) * 0.5f, HEIGHT - 1);
			m_DrawManager.DrawMidText("score = " + strscore, (WIDTH + 66) * 0.5f, HEIGHT - 1);
			BLUE
				m_WordManager.Clear();
			check_Stage = true;
		}

		if (check_Stage == true)
		{
			if (!isDrawStageText)
			{
				isDrawStageText = true;
				m_DrawManager.DrawMidText("                    ", (WIDTH + 66) * 0.5f, HEIGHT * 0.5f);
				strstage = to_string(stage);
				m_DrawManager.DrawMidText("★ Stage" + strstage + " ★", (WIDTH + 66) * 0.5f, HEIGHT * 0.5f);
			}

			if (clock() - stage_end >= 3000)
			{
				check_Stage = false;
				isDrawStageText = false;
				Check_Blank = false;
				m_DrawManager.BoxErase(15, 5, WIDTH * 0.6f, HEIGHT * 0.7f);
				m_DrawManager.BoxDraw(WIDTH * 0.73f, HEIGHT * 0.65f, BOXWIDTH, BOXHEIGHT);
			}
		}
		else 
		{
			start = clock();
			if (start - enddraw >= (3000 - (stage * 10)))
			{
				m_WordManager.Make();
				enddraw = start;
			}
			if (start - enddrop >= (500 - (stage * 10)) + time)
			{
				m_WordManager.Drop(Check_Blank);
				enddrop = start;

				if (Check_item == true)
				{
					start_item = clock();
					if (start_item - end_item >= 2000)
					{
						time = 0;
						Check_Blank = false;
						Check_item = false;
					}
				}
			}
		
			
				start_Error = clock();
				if (start_Error - end_Error >= Letter_time)
				{
					if (Letter_time != 0)
					{
						m_DrawManager.TextDraw("                          ", 38 + BOXWIDTH, 26);
						Letter_time = 0;
					}
					if (kbhit())
					{
						ch = _getch();
						switch (ch)
						{
						case 8: // 8 = Backspace
							m_DrawManager.TextDraw("                          ", 38 + BOXWIDTH, 26);
							strname = strname.substr(0, strname.length() - 1);
							m_DrawManager.DrawMidText(strname, 48 + BOXWIDTH, 26);
							if (strname.length() < 20)
								m_DrawManager.DrawMidText("                     ", WIDTH, HEIGHT * 0.6f + 1);
							break;
						case 13:
							m_DrawManager.TextDraw("                          ", 38 + BOXWIDTH, 26);
							switch (m_WordManager.Catch(strname))
							{
							case ITEM_TYPE_SPEED_UP:
								Catch_Check = true;
								Check_item = true;  
								time = -100;
								end_item = clock();
								break;
							case ITEM_TYPE_SPEED_DOWN:
								Catch_Check = true;
								Check_item = true;
								time = 1000;
								end_item = clock();
								break;
							case ITEM_TYPE_STOP:
								Catch_Check = true;
								Check_item = true;
								time = 6000;
								end_item = clock();
								break;
							case ITEM_TYPE_CLEAR:
								Catch_Check = true;
								Check_item = true;
								time = 0;
								end_item = clock();
								m_WordManager.Clear();
								break;
							case ITEM_TYPE_HIDE:
								time = 0;
								Check_item = true;
								Catch_Check = true;
								Check_Blank = true;
								end_item = clock();
								break;
							case ITEM_TYPE_NON:
								Catch_Check = true;
								break;
							default:
								Catch_Check = false;
								break;
							}

							if (Catch_Check == true)
							{
								iscore += 100;
								// 
								RED
									strscore = to_string(iscore);
								m_DrawManager.DrawMidText("             ", (WIDTH + 66) * 0.5f, HEIGHT - 1);
								m_DrawManager.DrawMidText("score = " + strscore, (WIDTH + 66) * 0.5f, HEIGHT - 1);
								Catch_Check = false;
							}
							else
							{
								Letter_time = 3000;
								RED
									m_DrawManager.DrawMidText("Fail", WIDTH, HEIGHT * 0.72f);
								BLUE
							}
							strname = "";
							BLUE
								break;
						default:
							if (strname.length() < 20)
							{
								strname += ch;
								m_DrawManager.DrawMidText(strname, 48 + BOXWIDTH, 26);
							}
							else	//if (name.length() >= 10)
								m_DrawManager.DrawMidText("20글자 초과!!", WIDTH, HEIGHT * 0.6f + 1);
							break;
						}
					}
					end_Error = start_Error;
				}
			
		}

		if (m_WordManager.Die() == true)
		{
			m_DrawManager.TextDraw("  ",6 + (2 + m_iLife * 2), HEIGHT - 1); // 26
			m_iLife = 0; // 
			RED
				if (m_iLife == 0)
				{
					m_iScore += iscore;
					m_DrawManager.DrawMidText("♨ Game Over ♨", (WIDTH * 2) * 0.5f, HEIGHT * 0.5f);
					_getch();
					m_Rank.Set_Player(m_strName, stage, m_iScore);
					m_Rank.Save();
					Reset();
					return;
				}
			BLUE
		}
	}
}


void Play::Reset()
{
	m_iLife = 9;
	m_iScore = 0;
	m_strName = "? ? ?";
	m_WordManager.Clear();
}