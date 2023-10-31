#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <Windows.h>
#include <iostream>
#include <string>


using namespace std;
int main()
{
	char lpszComLine[500] = "process1.exe ";
	char lpszHandle[20];
	wchar_t wComLine[180];

	STARTUPINFO si[2];
	PROCESS_INFORMATION pi[2];

	ZeroMemory(&si[0], sizeof(STARTUPINFO));
	si[0].cb = sizeof(STARTUPINFO);


	strcat(lpszComLine, lpszHandle);
	MultiByteToWideChar(CP_ACP, 0, lpszComLine, strlen(lpszComLine), wComLine, 160);

	CreateProcess(NULL, wComLine, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si[0], &pi[0]);

	WaitForSingleObject(pi[0].hProcess, INFINITE);

	ZeroMemory(&si[1], sizeof(STARTUPINFO));
	si[1].cb = sizeof(STARTUPINFO);

	char lpszComLine2[500] = "process2.exe ";

	strcat(lpszComLine2, lpszHandle);
	MultiByteToWideChar(CP_ACP, 0, lpszComLine2, strlen(lpszComLine2), wComLine, 160);

	CreateProcess(NULL, wComLine, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si[1], &pi[1]);

	WaitForSingleObject(pi[1].hProcess, INFINITE);

	CloseHandle(pi[0].hProcess);
	CloseHandle(pi[0].hThread);
	CloseHandle(pi[1].hProcess);
	CloseHandle(pi[1].hThread);

	return 0;
}