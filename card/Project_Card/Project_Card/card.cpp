#include "card.h"
#include"timer.hpp"
// 卡片的实现。（小的那个）
Card::Card(int x, int y, string imgURL, string imgyURL)
{
    //    初始化小卡片的各类属性
    this->x = x;
    this->y = y;
    this->imgURL = imgURL;                    
    this->imgyURL = imgyURL;                  
    this->state = CardState::Close;           // 刚开始的每张图片开始是关闭的
    
    img = new IMAGE[2];   // 开辟两张图片的空间
    
    loadimage(img, imgyURL.c_str(), width, height);  // 加载第一张图片，背景图，第0张
    loadimage(img+1, imgURL.c_str(), width, height);  // 加载第二张图片，美女图，第1张
}

void Card::SetState(CardState state)
{
    this->state = state;        // 设置此时的状态
}

// 获取卡片的Url
string Card::getURL()
{
    return imgURL;  //返回路径
}

bool Card::MouseInCard(ExMessage msg)
{
    // 相当于要让鼠标点在小卡片内才能有反应，否则不会作出回应
    if (this->state!=CardState::No&&
        this->state != CardState::Open &&msg.x >= this->x && msg.x <= this->x + this->width &&
        msg.y >= this->y && msg.y <= this->y + this->height)
        return true;
    return false;
}

bool Card::ClickCard(ExMessage msg)
{
    // 如果卡片的状态不是no并且鼠标在小卡片上，并且点了下去。
    if (this->state != CardState::No && MouseInCard(msg) && msg.message == WM_LBUTTONDOWN&&
        MyTimer::Timer(200,2))
    {
        this->state = CardState::Open;  // 修改state的值为Open
        return true;

    }
    return false;
}

void Card::Show()
{
    
    switch (this->state)
    {
    case Card::CardState::Close:        // 关闭，贴覆盖的图片
        putimage(x, y, img);    
        break;
    case Card::CardState::Open:         // 打开，贴美女图片    
        putimage(x, y, img+1);
        break;
    case Card::CardState::No:           // 消除状态，也就是空白
        break;
    }
}

Card::~Card()
{
}
