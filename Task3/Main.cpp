#define _CRT_SECURE_NO_WARNINGS
#include"QueueAndLibrary.h"

int main() {
	setlocale(0, "RUS");

	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY); //���� ������ ���������
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	SetConsoleTitle(L"STUDENT");
	ConsoleCursorVisible(false, 100); //������� ������ � �������
	Queue<STUDENT> queueStudent;
	while (true)
	{
		CLEAN
			menu();
		pointer(queueStudent);
	}
	return 0;
}