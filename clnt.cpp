//#define _CRT_SECURE_NO_WARNINGS 1 
//// 打电话的
////socket 套接字，用来进行网络通信
//#include<stdio.h>
//#include<winsock2.h>	 //windows的套接字头文件
//#pragma comment(lib,"ws2_32.lib") //库文件
//
//int main()
//{
//	WSADATA wsadata;
//	WSAStartup(MAKEWORD(2, 2), &wsadata);//2.2版本
//
//	//1.准备一个电话机
//	SOCKET hClntSock = socket(PF_INET, SOCK_STREAM, 0);
//	//2.获取对方号码，端口号是多少
//
//	//3.直接拨打
//	SOCKADDR_IN servAddr;
//	servAddr.sin_family = AF_INET;	//协议族,使用ipv4
//	//servAddr.sin_addr.s_addr =inet_addr("172.20.31.120");	
//	servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");	//本机回环ip
//	servAddr.sin_port = htons(6280);		//端口号，不要给0到1000，这些是系统专用的
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