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
	vector<string>m_strBenechia; // ĳ���� ����Ʈ �ϸ� ������ ��
public:
	Play();
	void Player_Draw(); // �̸� �� ���� �׸�
	
	void Reset();
	void Setplayer_name();
	void Game_Menu();
	void Game_Play();
	void StoryTelling(); // ����ġ�� ���丮
	//~Play();
};
//���ӽ��� ȭ�� �����->����̾߱� ��ũ�� �����->�ܾ� ����Ʈ����->�ܾ� ���߱�(��������)->Stage��� �����->Rank�ý��� �����
//->�����۱�� �߰�

// ������ ��� + �ܾ� Ʋ���� ������ ��� + ��ŷ ��� ���