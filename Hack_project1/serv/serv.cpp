#define _CRT_SECURE_NO_WARNINGS 1 
//服务器，用来监听
//socket 套接字，用来进行网络通信
#include<stdio.h>
#include<winsock2.h>	 //windows的套接字头文件
#pragma comment(lib,"ws2_32.lib") //库文件

int main()
{
	// windows 网络套接字。
	// 需要初始化window套接字版本
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2,2),&wsadata);//2.2版本

	//打电话机
	//1.安装电话机，相当于管理员
	SOCKET hServSock = socket(PF_INET, SOCK_STREAM, 0); //第一个参数是是协议族，PF_INET是ipv4，PF_INET6是ipv6，流式套接字，tcp或者udp，第三个是细分的
	//2.给电话机分配电话卡，号码。 分机号：
	//IP地址，端口号
	SOCKADDR_IN servAddr;
	servAddr.sin_family = AF_INET;	//协议族,使用ipv4
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);		//自动获取本机的地址,htonl将主机的无符号长整形数转换成网络字节顺序。　
	servAddr.sin_port = htons(6280);		//端口号，不要给0到1000，这些是系统专用的,    hton函数将一个无符号短整型数值转换为网络字节序
	bind(hServSock, (SOCKADDR*)&servAddr, sizeof(servAddr));	//绑定
	
    //3.接入电话网络，开始监听
	listen(hServSock, 5);// 5是线程数

	//4.接电话
	SOCKET hclntSock; //接待的
	SOCKADDR_IN clntAddr;//对方的来电显示，保存对方的ip地址和端口号
	int clntAddrSize = sizeof(clntAddr);//大小
	hclntSock = accept(hServSock,(SOCKADDR*)&clntAddr,&clntAddrSize);
	
	printf("%s 连接成功", inet_ntoa(clntAddr.sin_addr));//inet_ntoa功能是将网络地址转换成“.”点隔的字符串格式。
	/*int choice;
	char buf[1000];*/
	//传数据一般都是数值
	/*while (1)
	{
		system("cls");
		printf("等待连接中...\n");
		hclntSock = accept(hServSock, (SOCKADDR*)&clntAddr, &clntAddrSize);
		if (hclntSock == INVALID_SOCKET)
		{

		}
	}*/
	//while (1)
	//{
	//	system("cls");
	//	printf("1.关机\n");
	//	printf("2.注销\n");
	//	printf("3.重启\n");
	//	printf("4.恶搞\n");
	//	printf("5.来\n");
	//	printf("6.关闭对方的客户端\n");
	//	
	//	scanf("%d", &choice);
	//	if (choice < 1 || choice>6)
	//		continue;
	//	//输入1，将1转换成字符串
	//	_itoa(choice, buf, 10);
		send(hclntsock, buf, 1024, 0);//传输

		recv(hclntsock, buf, 1024, 0);//接收
	//	if(!strcmp)
	//}
	system("pause");

	closesocket(hclntSock);
	closesocket(hServSock);


	WSACleanup();	// 回收socket资源
	return 0;
}




// 练习
//#include<winsock2.h>
//#include<stdio.h>
//#pragma comment(lib,"ws2_32.lib")
//
//int main()
//{
//	//初始化
//	WSADATA wsadata;
//	WSAStartup(MAKEWORD(2, 2), &wsadata);
//
//	//1.电话机
//	SOCKET hServ = socket(PF_INET, SOCK_STREAM, 0);
//
//	//2.电话卡
//	SOCKADDR_IN ServAddr;
//	ServAddr.sin_family = AF_INET;
//	ServAddr.sin_addr.s_addr = htonl(ADDR_ANY);
//	ServAddr.sin_port = htons(5055);
//
//	bind(hServ, (SOCKADDR*)&ServAddr, sizeof(ServAddr));
//
//	//监听
//	listen(hServ, 5);
//
//	// 目标机器
//	SOCKET hclnt;
//	SOCKADDR_IN clnt;
//
//	int size = sizeof(clnt);
//	hclnt = accept(hServ, (SOCKADDR*)&clnt, &size);
//	printf("%s 成功连接", inet_ntoa(clnt.sin_addr));
//	system("pause");
//
//	closesocket(hServ);
//	closesocket(hclnt);
//
//	WSACleanup();
//
//}
//
