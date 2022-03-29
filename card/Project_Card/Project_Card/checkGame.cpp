#include "checkGame.h"
#include "card.h"
#include "widget.h"
#include "timer.hpp"
// 调用构造函数的同时，初始化pwidget的对象，创建窗口
CheckGame::CheckGame() // 旁边有空隙
{
    pWidget = new Widget(WIDTH * 8 + 10 * 2, HEIGHT * 4 + 10 * 2, "img2/background.jpg");

    //地图处理
    int start = 0;
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j += 2)
        {
            map[i][j] = start;       //0  //2  //4  //6 //8
            map[i][j + 1] = start;   //1  //3
            start++;
        }
        random_shuffle(map[i].begin(), map[i].end());
    }
    //random_shuffle(map.begin(), map.end());
    random_shuffle(map.begin(), map.end());

}

void CheckGame::initGame()
{
    // 图片加载，批量加载，卡片的路径会变，而覆盖的不会变
    string imgURL;
    string coverURL;
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            // 根据数组里的值去创建卡片
            int x = WIDTH * j + 10;//宽
            int y = HEIGHT * i + 10;//高
            imgURL = "img2/" + to_string(map[i][j]) + ".jpg";// 加载数组里的数字所对应的图片，to_string直接转换成字符串
            coverURL = "img2/cover.jpg";
            pCard.push_back(new Card(x, y, imgURL, coverURL));//卡的类
        }
    }

    pWidget->Show();// 展示窗口
}
void CheckGame::Show()
{
    pWidget->Refresh();// 刷新一下
    for (auto i : pCard) //v是一个可遍历的容器或流，例如：vector<int> v={1,2,3,4};，for(auto i:v)
    {
        i->Show();
    }
}

int CheckGame::ClickCard(ExMessage& msg)
{
    for (int i = 0; i < pCard.size(); i++)
    {
        if (pCard[i]->ClickCard(msg) == true) // 点击当前序号
        {
            return i;// 返回当前的序号
        }
    }
    return -1;
}

void CheckGame::MouseEvent(ExMessage& msg)
{
    if (isOpen.size() < 2)
    {
        int result = ClickCard(msg);// 返回点的图片序号
        if (result != -1)
        {
            // 设置状态
            pCard[result]->SetState(Card::CardState::Open);
            isOpen.push_back(result);// 打开的下标存进去
        }
    }
    if (MyTimer::Timer(50, 0)) //要控制速度
    {
        isClear();
    }
}

void CheckGame::isClear()
{
    if (isOpen.size() == 2) // =2相当于点开了2张
    {
        // 容器中1和2不能是同一个地方，其次是这两个卡片的url相等，就可以做消除动作
        if (isOpen[0] != isOpen[1] && pCard[isOpen[0]]->getURL() == pCard[isOpen[1]]->getURL())
        {
            pCard[isOpen[0]]->SetState(Card::CardState::No);
            pCard[isOpen[1]]->SetState(Card::CardState::No);
        }
        else
        {
            // 将原来打开的状态变成关闭
            pCard[isOpen[0]]->SetState(Card::CardState::Close);
            pCard[isOpen[1]]->SetState(Card::CardState::Close);
        }
        // 只要打开了2张后，就清除
        isOpen.clear();
    }
}

bool CheckGame::GameOver()
{
    return false;
}
