#pragma once
#include "Mecro.h"
#include "Word.h"

class WordManager // �ܾ�� ���� Class //�ܾ�� ������������� ������
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
	void Drop(bool Check_Blank); // ������
	bool Die(); // �������� ���� ���ִ°�
	ITEM_TYPE Catch(string strWord); // �ܾ� ���ߴ°�
	
	WordManager();
};

// Draw Drop������ : ??