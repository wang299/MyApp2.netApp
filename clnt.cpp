//#define _CRT_SECURE_NO_WARNINGS 1 
//// ��绰��
////socket �׽��֣�������������ͨ��
//#include<stdio.h>
//#include<winsock2.h>	 //windows���׽���ͷ�ļ�
//#pragma comment(lib,"ws2_32.lib") //���ļ�
//
//int main()
//{
//	WSADATA wsadata;
//	WSAStartup(MAKEWORD(2, 2), &wsadata);//2.2�汾
//
//	//1.׼��һ���绰��
//	SOCKET hClntSock = socket(PF_INET, SOCK_STREAM, 0);
//	//2.��ȡ�Է����룬�˿ں��Ƕ���
//
//	//3.ֱ�Ӳ���
//	SOCKADDR_IN servAddr;
//	servAddr.sin_family = AF_INET;	//Э����,ʹ��ipv4
//	//servAddr.sin_addr.s_addr =inet_addr("172.20.31.120");	
//	servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");	//�����ػ�ip
//	servAddr.sin_port = htons(6280);		//�˿ںţ���Ҫ��0��1000����Щ��ϵͳר�õ�
//	connect(hClntSock,(SOCKADDR*)&servAddr, sizeof(servAddr));
//	
//
//	system("pause");
//	WSACleanup();
//}


#include<stdio.h>
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib")

int main()
{
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);

	SOCKET hclnt = socket(PF_INET, SOCK_STREAM,0);
	SOCKADDR_IN ServAddr;
	ServAddr.sin_family = AF_INET;
	ServAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	ServAddr.sin_port = htons(5055);
	connect(hclnt, (SOCKADDR*)&ServAddr, sizeof(ServAddr));

	system("pause");

	WSACleanup();	

}