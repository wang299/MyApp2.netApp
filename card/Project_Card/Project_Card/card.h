#pragma once
#include"common.h"
/*
1.ÿ�ſ�Ƭ���в�ͬ��״̬��
2.�Ƚ��õ���ÿ��ͼƬ�����֣�Ҳ����·��
*/

class Card
{
public:
	// ״̬ö�ٳ�����ǿ��ö����
	enum class CardState{Close,Open,No};
	// close:�ر�״̬
	// open:��
	// No:������״̬

	Card(int x, int y, string imgURL, string imgyURL);
	void SetState(CardState state);		// �ṩ�ⲿ�Ľӿ������ÿ�Ƭ��״̬
	string getURL();					// ��ȡ��Ƭ��·���������Ƚ�
	bool MouseInCard(ExMessage msg);	// ����Ƿ��ڰ�ť�ϣ�ExMessage�Ǵ�ʱ��״̬
	bool ClickCard(ExMessage msg);		// �жϵ����ǰ��Ƭ
	void Show();
	~Card();

protected:
	int x;					//ͼƬ����
	int y;
	int width = WIDTH;
	int height = HEIGHT;
	string imgURL;			// ��ͨɫͼ
	string imgyURL;			// ���ǵ�ͼƬ
	IMAGE* img;
	CardState state;		//��ǰ��Ƭ��״̬
};
