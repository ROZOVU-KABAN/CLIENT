#include <iostream>
#pragma comment(lib,"ws2_32.lib")
#pragma warning(disable: 4996)
#include<iostream>
#include<fstream>
#include<WinSock2.h> // библиотека сокетов
#include<Windows.h>
#include<cstring>

SOCKET Connection;

int main()
{
	// WSASStartup - загрузка библиотеки для сетевого подключения
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1); // запрашиваемая версия библиотеки
	if (WSAStartup(DLLVersion, &wsaData) != 0)
	{
		std::cout << "ERROR\n";
		exit(1);

	}

	//ЗАполнение информации об адресе сокета:

	SOCKADDR_IN addr;
	addr.sin_addr.s_addr = inet_addr("46.242.14.137");
	addr.sin_port = htons(80);
	addr.sin_family = AF_INET;


	Connection = socket(AF_INET, SOCK_STREAM, NULL);

	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0)
	{
		std::cout << "ERROR3\n";
		return 1;
	}
	//while (true)
	//{
		char msg[256] = "data.txt";
		send(Connection, msg, sizeof(msg), NULL);
	//}

	system("pause");
	return 0;
}