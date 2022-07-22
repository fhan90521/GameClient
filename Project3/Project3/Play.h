#pragma once
#include "MapDraw.h"
#include "WordManager.h"
#include "Rank.h"
class Play
{
private:
	MapDraw m_DrawManager;
	
	WordManager m_WordManager;
	int m_iLife;
	
	int m_iScore;
	string m_strName;
	Rank m_Rank;
	vector<string>m_strBenechia; // 캐릭터 포인트 하면 오류가 뜸
public:
	Play();
	void Player_Draw(); // 이름 및 생명 그림
	
	void Reset();
	void Setplayer_name();
	void Game_Menu();
	void Game_Play();
	void StoryTelling(); // 베네치아 스토리
	//~Play();
};
//게임시작 화면 만들기->배경이야기 스크롤 만들기->단어 떨어트리기->단어 맞추기(점수증가)->Stage기능 만들기->Rank시스템 만들기
//->아이템기능 추가

// 아이템 기능 + 단어 틀리면 딜레이 기능 + 랭킹 등록 기능