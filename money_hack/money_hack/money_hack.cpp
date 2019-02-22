#include "pch.h"
#include <iostream>
#include <Windows.h>

int main()
{
	int new_value{ 15999 };
	HWND hwnd = FindWindowA(NULL, "Counter-Strike");
	if (hwnd == NULL)
	{
		std::cout << "Window not found!" << std::endl;
		Sleep(3000);
		exit(-1);
	}
	else
	{
		std::cout << "Window found, obtaining process.." << std::endl;
		DWORD process_ID;
		GetWindowThreadProcessId(hwnd, &process_ID);
		HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, process_ID);
		if (process_ID == NULL)
		{
			std::cout << "Could not obtain process." << std::endl;
			exit(-2);
		}
		else
		{
			std::cout << "Obtained process, executing hack.." << std::endl;
			int money_addy = 0x0; // You need to find the adress where money is stored in memory eg. 0x283501D4 or 0x01A17C78 
			WriteProcessMemory(handle, (LPVOID)money_addy, &new_value, sizeof(new_value), 0);
			//WriteProcessMemory(handle, (LPVOID)0x01A17C78, &new_value, sizeof(new_value), 0);
			std::cout << "Hack executed successfully!" << std::endl;
		}
		CloseHandle(handle);
	}
	return 0;
}