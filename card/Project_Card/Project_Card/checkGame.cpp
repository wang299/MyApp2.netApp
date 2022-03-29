#include "checkGame.h"
#include "card.h"
#include "widget.h"
#include "timer.hpp"
// ���ù��캯����ͬʱ����ʼ��pwidget�Ķ��󣬴�������
CheckGame::CheckGame() // �Ա��п�϶
{
    pWidget = new Widget(WIDTH * 8 + 10 * 2, HEIGHT * 4 + 10 * 2, "img2/background.jpg");

    //��ͼ����
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
    // ͼƬ���أ��������أ���Ƭ��·����䣬�����ǵĲ����
    string imgURL;
    string coverURL;
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            // �����������ֵȥ������Ƭ
            int x = WIDTH * j + 10;//��
            int y = HEIGHT * i + 10;//��
            imgURL = "img2/" + to_string(map[i][j]) + ".jpg";// �������������������Ӧ��ͼƬ��to_stringֱ��ת�����ַ���
            coverURL = "img2/cover.jpg";
            pCard.push_back(new Card(x, y, imgURL, coverURL));//������
        }
    }

    pWidget->Show();// չʾ����
}
void CheckGame::Show()
{
    pWidget->Refresh();// ˢ��һ��
    for (auto i : pCard) //v��һ���ɱ������������������磺vector<int> v={1,2,3,4};��for(auto i:v)
    {
        i->Show();
    }
}

int CheckGame::ClickCard(ExMessage& msg)
{
    for (int i = 0; i < pCard.size(); i++)
    {
        if (pCard[i]->ClickCard(msg) == true) // �����ǰ���
        {
            return i;// ���ص�ǰ�����
        }
    }
    return -1;
}

void CheckGame::MouseEvent(ExMessage& msg)
{
    if (isOpen.size() < 2)
    {
        int result = ClickCard(msg);// ���ص��ͼƬ���
        if (result != -1)
        {
            // ����״̬
            pCard[result]->SetState(Card::CardState::Open);
            isOpen.push_back(result);// �򿪵��±���ȥ
        }
    }
    if (MyTimer::Timer(50, 0)) //Ҫ�����ٶ�
    {
        isClear();
    }
}

void CheckGame::isClear()
{
    if (isOpen.size() == 2) // =2�൱�ڵ㿪��2��
    {
        // ������1��2������ͬһ���ط����������������Ƭ��url��ȣ��Ϳ�������������
        if (isOpen[0] != isOpen[1] && pCard[isOpen[0]]->getURL() == pCard[isOpen[1]]->getURL())
        {
            pCard[isOpen[0]]->SetState(Card::CardState::No);
            pCard[isOpen[1]]->SetState(Card::CardState::No);
        }
        else
        {
            // ��ԭ���򿪵�״̬��ɹر�
            pCard[isOpen[0]]->SetState(Card::CardState::Close);
            pCard[isOpen[1]]->SetState(Card::CardState::Close);
        }
        // ֻҪ����2�ź󣬾����
        isOpen.clear();
    }
}

bool CheckGame::GameOver()
{
    return false;
}
