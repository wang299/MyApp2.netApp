#pragma once
#include"common.h"
/*
1.每张卡片都有不同的状态。
2.比较用的是每张图片的名字，也就是路径
*/

class Card
{
public:
	// 状态枚举出来，强制枚举类
	enum class CardState{Close,Open,No};
	// close:关闭状态
	// open:打开
	// No:做消除状态

	Card(int x, int y, string imgURL, string imgyURL);
	void SetState(CardState state);		// 提供外部的接口来设置卡片的状态
	string getURL();					// 获取卡片的路径，用来比较
	bool MouseInCard(ExMessage msg);	// 鼠标是否在按钮上，ExMessage是此时的状态
	bool ClickCard(ExMessage msg);		// 判断点击当前卡片
	void Show();
	~Card();

protected:
	int x;					//图片坐标
	int y;
	int width = WIDTH;
	int height = HEIGHT;
	string imgURL;			// 普通色图
	string imgyURL;			// 覆盖的图片
	IMAGE* img;
	CardState state;		//当前卡片的状态
};
