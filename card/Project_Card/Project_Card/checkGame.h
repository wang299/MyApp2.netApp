#pragma once
#include "common.h"
class Widget;
class Card;
class CheckGame
{
public:
	CheckGame();			// ���캯��
	void initGame();		// ��ʼ����Ϸ
	void Show();			// 
	void DrawMap();
	int  ClickCard(ExMessage& msg);// �����Ƭ
	void MouseEvent(ExMessage& msg);// ����¼�
	void isClear();					// �������
	bool GameOver();
protected:
	array<array<int, 8>, 4> map;	// ��ά���飬4��8��
	Widget* pWidget;				// ����
	vector<Card*> pCard;			// һά���飬��ſ�Ƭ������4*8��
	vector<int> isOpen;				// һά���飬��ŵ㿪��Ƭ�����
};



