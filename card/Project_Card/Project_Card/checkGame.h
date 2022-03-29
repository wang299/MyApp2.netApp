#pragma once
#include "common.h"
class Widget;
class Card;
class CheckGame
{
public:
	CheckGame();			// 构造函数
	void initGame();		// 初始化游戏
	void Show();			// 
	void DrawMap();
	int  ClickCard(ExMessage& msg);// 点击卡片
	void MouseEvent(ExMessage& msg);// 鼠标事件
	void isClear();					// 清除画面
	bool GameOver();
protected:
	array<array<int, 8>, 4> map;	// 二维数组，4行8列
	Widget* pWidget;				// 窗口
	vector<Card*> pCard;			// 一维数组，存放卡片的数组4*8个
	vector<int> isOpen;				// 一维数组，存放点开卡片的序号
};



