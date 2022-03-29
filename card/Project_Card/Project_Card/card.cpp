#include "card.h"
#include"timer.hpp"
// ��Ƭ��ʵ�֡���С���Ǹ���
Card::Card(int x, int y, string imgURL, string imgyURL)
{
    //    ��ʼ��С��Ƭ�ĸ�������
    this->x = x;
    this->y = y;
    this->imgURL = imgURL;                    
    this->imgyURL = imgyURL;                  
    this->state = CardState::Close;           // �տ�ʼ��ÿ��ͼƬ��ʼ�ǹرյ�
    
    img = new IMAGE[2];   // ��������ͼƬ�Ŀռ�
    
    loadimage(img, imgyURL.c_str(), width, height);  // ���ص�һ��ͼƬ������ͼ����0��
    loadimage(img+1, imgURL.c_str(), width, height);  // ���صڶ���ͼƬ����Ůͼ����1��
}

void Card::SetState(CardState state)
{
    this->state = state;        // ���ô�ʱ��״̬
}

// ��ȡ��Ƭ��Url
string Card::getURL()
{
    return imgURL;  //����·��
}

bool Card::MouseInCard(ExMessage msg)
{
    // �൱��Ҫ��������С��Ƭ�ڲ����з�Ӧ�����򲻻�������Ӧ
    if (this->state!=CardState::No&&
        this->state != CardState::Open &&msg.x >= this->x && msg.x <= this->x + this->width &&
        msg.y >= this->y && msg.y <= this->y + this->height)
        return true;
    return false;
}

bool Card::ClickCard(ExMessage msg)
{
    // �����Ƭ��״̬����no���������С��Ƭ�ϣ����ҵ�����ȥ��
    if (this->state != CardState::No && MouseInCard(msg) && msg.message == WM_LBUTTONDOWN&&
        MyTimer::Timer(200,2))
    {
        this->state = CardState::Open;  // �޸�state��ֵΪOpen
        return true;

    }
    return false;
}

void Card::Show()
{
    
    switch (this->state)
    {
    case Card::CardState::Close:        // �رգ������ǵ�ͼƬ
        putimage(x, y, img);    
        break;
    case Card::CardState::Open:         // �򿪣�����ŮͼƬ    
        putimage(x, y, img+1);
        break;
    case Card::CardState::No:           // ����״̬��Ҳ���ǿհ�
        break;
    }
}

Card::~Card()
{
}
