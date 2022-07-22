#pragma once
#include "Mecro.h"
#include "Word.h"

class WordManager // 단어들 관리 Class //단어는 파일입출력으로 가져옴
{
private :
	vector<string> m_Words;
	vector<Word*> m_Word;
	vector<Word*> m_item;
	MapDraw m_DrawManager;
	int m_item_count;
public:
	
	void Load();
	void Clear();
	void Make();
	void Drop(bool Check_Blank); // 떨구기
	bool Die(); // 떨어지고 나면 없애는거
	ITEM_TYPE Catch(string strWord); // 단어 맞추는거
	
	WordManager();
};

// Draw Drop나누기 : ??