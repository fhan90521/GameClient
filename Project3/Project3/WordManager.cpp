#include "WordManager.h"
WordManager::WordManager() : m_item_count(0)
{
}

void WordManager::Load()
{
	string strWord;
	ifstream LoadWord;
	LoadWord.open("Word.txt");
	if (LoadWord.is_open())
	{
		while (!LoadWord.eof())
		{
			getline(LoadWord, strWord);
			m_Words.push_back(strWord);
		}
		LoadWord.close();
	}
}


void WordManager::Make()
{
	ITEM_TYPE Item;
	int Random_item;
	int iRandom_Word = rand() % m_Words.size();
	int ix = rand() % ((WIDTH * 2 - 12)- 1 + 2) + 2;
	Random_item = rand() % 6;
	Item = (ITEM_TYPE)Random_item;
	Word* word = new Word;
	word->SetWord(Item, ix, 1, m_Words[iRandom_Word]);
	m_Word.push_back(word);
}



void WordManager::Drop(bool Check_Blank)
{
	for (vector<Word*>::iterator iter = m_Word.begin(); iter != m_Word.end(); iter++)
	{
		(*iter)->Drop(Check_Blank);
	}
}



bool WordManager::Die()
{
	//Word* word;
	for (vector<Word*>::iterator iter = m_Word.begin(); iter != m_Word.end(); iter++)
	{
		if ((*iter)->get_y() == HEIGHT - 3)
		{
			m_Word.erase(iter);
			delete (*iter);

			return true;
		}
	}
	return false;
}

void WordManager::Clear()
{
	for (vector<Word*>::iterator iter = m_Word.begin(); iter != m_Word.end(); iter++)
	{
		(*iter)->Erase();
		delete (*iter);
	}
	m_Word.clear();
}

ITEM_TYPE WordManager::Catch(string strWord)
{
	for (vector<Word*>::iterator iter = m_Word.begin(); iter != m_Word.end(); iter++)
	{
		if ((*iter)->getWord() == strWord)
		{
			(*iter)->Erase();
			m_Word.erase(iter);
			delete (*iter);

			switch ((*iter)->getType())
			{
			case ITEM_TYPE_NON:
			case ITEM_TYPE_NULL:
				return ITEM_TYPE_NON;
			default: return (*iter)->getType();
			}
		}
	}

	return ITEM_TYPE_NULL;
}
