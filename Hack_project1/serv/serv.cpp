#define _CRT_SECURE_NO_WARNINGS 1 
//����������������
//socket �׽��֣�������������ͨ��
#include<stdio.h>
#include<winsock2.h>	 //windows���׽���ͷ�ļ�
#pragma comment(lib,"ws2_32.lib") //���ļ�

int main()
{
	// windows �����׽��֡�
	// ��Ҫ��ʼ��window�׽��ְ汾
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2,2),&wsadata);//2.2�汾

	//��绰��
	//1.��װ�绰�����൱�ڹ���Ա
	SOCKET hServSock = socket(PF_INET, SOCK_STREAM, 0); //��һ����������Э���壬PF_INET��ipv4��PF_INET6��ipv6����ʽ�׽��֣�tcp����udp����������ϸ�ֵ�
	//2.���绰������绰�������롣 �ֻ��ţ�
	//IP��ַ���˿ں�
	SOCKADDR_IN servAddr;
	servAddr.sin_family = AF_INET;	//Э����,ʹ��ipv4
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);		//�Զ���ȡ�����ĵ�ַ,htonl���������޷��ų�������ת���������ֽ�˳�򡣡�
	servAddr.sin_port = htons(6280);		//�˿ںţ���Ҫ��0��1000����Щ��ϵͳר�õ�,    hton������һ���޷��Ŷ�������ֵת��Ϊ�����ֽ���
	bind(hServSock, (SOCKADDR*)&servAddr, sizeof(servAddr));	//��
	
    //3.����绰���磬��ʼ����
	listen(hServSock, 5);// 5���߳���

	//4.�ӵ绰
	SOCKET hclntSock; //�Ӵ���
	SOCKADDR_IN clntAddr;//�Է���������ʾ������Է���ip��ַ�Ͷ˿ں�
	int clntAddrSize = sizeof(clntAddr);//��С
	hclntSock = accept(hServSock,(SOCKADDR*)&clntAddr,&clntAddrSize);
	
	printf("%s ���ӳɹ�", inet_ntoa(clntAddr.sin_addr));//inet_ntoa�����ǽ������ַת���ɡ�.��������ַ�����ʽ��
	/*int choice;
	char buf[1000];*/
	//������һ�㶼����ֵ
	/*while (1)
	{
		system("cls");
		printf("�ȴ�������...\n");
		hclntSock = accept(hServSock, (SOCKADDR*)&clntAddr, &clntAddrSize);
		if (hclntSock == INVALID_SOCKET)
		{

		}
	}*/
	//while (1)
	//{
	//	system("cls");
	//	printf("1.�ػ�\n");
	//	printf("2.ע��\n");
	//	printf("3.����\n");
	//	printf("4.���\n");
	//	printf("5.��\n");
	//	printf("6.�رնԷ��Ŀͻ���\n");
	//	
	//	scanf("%d", &choice);
	//	if (choice < 1 || choice>6)
	//		continue;
	//	//����1����1ת�����ַ���
	//	_itoa(choice, buf, 10);
		send(hclntsock, buf, 1024, 0);//����

		recv(hclntsock, buf, 1024, 0);//����
	//	if(!strcmp)
	//}
	system("pause");

	closesocket(hclntSock);
	closesocket(hServSock);


	WSACleanup();	// ����socket��Դ
	return 0;
}




// ��ϰ
//#include<winsock2.h>
//#include<stdio.h>
//#pragma comment(lib,"ws2_32.lib")
//
//int main()
//{
//	//��ʼ��
//	WSADATA wsadata;
//	WSAStartup(MAKEWORD(2, 2), &wsadata);
//
//	//1.�绰��
//	SOCKET hServ = socket(PF_INET, SOCK_STREAM, 0);
//
//	//2.�绰��
//	SOCKADDR_IN ServAddr;
//	ServAddr.sin_family = AF_INET;
//	ServAddr.sin_addr.s_addr = htonl(ADDR_ANY);
//	ServAddr.sin_port = htons(5055);
//
//	bind(hServ, (SOCKADDR*)&ServAddr, sizeof(ServAddr));
//
//	//����
//	listen(hServ, 5);
//
//	// Ŀ�����
//	SOCKET hclnt;
//	SOCKADDR_IN clnt;
//
//	int size = sizeof(clnt);
//	hclnt = accept(hServ, (SOCKADDR*)&clnt, &size);
//	printf("%s �ɹ�����", inet_ntoa(clnt.sin_addr));
//	system("pause");
//
//	closesocket(hServ);
//	closesocket(hclnt);
//
//	WSACleanup();
//
//}
//
