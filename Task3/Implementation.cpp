#include"QueueAndLibrary.h"
extern HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // �������� ���������� �������
static int ActiveMenu = 4;


//////////// ������� ��� ����
static char* CoutString() {

	char c;
	int len = 1;
	char* str = new char[0];
	while ((c = cin.get()) != '\n')
	{
		char* temp = new char[len + 1];

		for (int i = 0; i < len - 1; i++) {
			temp[i] = str[i];
		}
		temp[len - 1] = c;
		temp[len] = '\0';
		delete[] str;
		str = temp;
		len++;
	}
	return str;
}
static void InfoClassification() {
	CLEAN
		cout.width(30);
	cout << "������� � ��������";
	cout.width(24);
	cout << "����� ������";
	cout.width(29);
	cout << "5 ������ ��������" << endl;
	for (register int i = 0; i < 85; i++)
		cout << "_";
	cout << endl;
}

static void GotoY(short y, short x = 25) {
	SetConsoleCursorPosition(hStdOut, { x,y });
}
extern void ConsoleCursorVisible(bool show, short size) {
	CONSOLE_CURSOR_INFO CursorInfo;
	CursorInfo.bVisible = show;
	CursorInfo.dwSize = size;
	SetConsoleCursorInfo(hStdOut, &CursorInfo);
}
static void ConsoleTextColor(int& n) {
	if (n++ == ActiveMenu) {
		SetConsoleTextAttribute(hStdOut, 80);
	}
	else {
		SetConsoleTextAttribute(hStdOut, 15);
	}
}
static void ConsoleTextColorSort(int& n, int am) {
	if (n++ == am) {
		SetConsoleTextAttribute(hStdOut, 80);
	}
	else {
		SetConsoleTextAttribute(hStdOut, 15);
	}
}

extern void pointer(Queue<STUDENT>& queueStudent) {
	char ch;
	ch = _getch();
	STUDENT first;
	if (ch == -32) ch = _getch(); // ����������� ���������
	switch (ch)
	{
	case ESC:
		exit(0);
	case DOWN:
		if (ActiveMenu < 10)
			ActiveMenu++;
		break;
	case UP:
		if (ActiveMenu > 4)
			ActiveMenu--;
		break;
	case ENTRY:
		switch (ActiveMenu) {
		case 4:
			CLEAN
				CinInfoAboutStudent(queueStudent);
			ClEANCONSOLE
				PAUSE
				break;
		case 5:
			CLEAN
				if (queueStudent.isEmpty()) {
					cout << "� ������� ������ ���;" << endl;
					PAUSE
					return;
				}
				PrintInfoAboutStudent(queueStudent);
			PAUSE
				break;
		case 6:
			CLEAN
				if (queueStudent.isEmpty()) {
					cout << "� ������� ������ ���!" << endl;
					PAUSE
					return;
				}
				first = queueStudent.front();
				InfoClassification();
				first.Info();
				cout << endl << "������ ������� �������� �� �������" << endl;
				queueStudent.Delete();
			PAUSE
				break;
		case 7:
			CLEAN
				queueStudent.initialize();
			cout << "������� ��������!" << endl;
			PAUSE
				break;
		case 8:
			CLEAN

			cout << "���������� ��������� � �������: "<<queueStudent.GetSize() << endl;
			PAUSE
				break;
		case 9:
			CLEAN

				ReadInfoFromFile(queueStudent);
			PAUSE
				break;
		case 10:
			CLEAN

				WriteInfoInFile(queueStudent);
			PAUSE
				break;
		}

		break;
	default:
		break;
	}
}
extern void menu() {
	int n = 4; // ��� �������� �� ������� ����
	//////////
	CLEAN
		cout << "+-----------------------------------------------------------------------------------------+" << endl << "|";
	cout.width(50);
	cout << "����";
	cout.setf(ios::right);
	cout.width(40);
	cout << "|" << endl;
	cout << "+-----------------------------------------------------------------------------------------+" << endl;
	GotoY(n);
	ConsoleTextColor(n);
	cout << "1. ���� ������ � �������� � ���������;" << endl;
	GotoY(n);
	ConsoleTextColor(n);
	cout << "2. ����� ������ � ���������;" << endl;
	GotoY(n);
	ConsoleTextColor(n);
	cout << "3. ������� �� ������� ������ ��������;" << endl;
	GotoY(n);
	ConsoleTextColor(n);
	cout << "4. ��������� �������;" << endl;
	GotoY(n);
	ConsoleTextColor(n);
	cout << "5. ���������� ��������� � �������" << endl;
	GotoY(n);
	ConsoleTextColor(n);
	cout << "6. ��������� ������ � �����" << endl;
	GotoY(n);
	ConsoleTextColor(n);
	cout << "7. �������� ������ � �����" << endl;

	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
}

///////////// ��������������� �������


static char* FindEndSymbol(char* str, int s) {
	char* p = NULL;
	while (*str != '\0') {
		if (*str == s) {
			p = str;
		}
		str++;
	}
	return p;
}
static bool FileExtension(char* str, int* s) {
	char* p = FindEndSymbol(str, 92); //    ' / '
	int i = 0;

	if (p != NULL) {
		i = p - str + 1;
	}

	int flag = 0;
	for (i; i < strlen(str); i++) {
		if (str[i] == '.') {
			flag = i;
			i = strlen(str);
		}
	}

	*s = flag;
	if (flag == 0) {

		return false;
	}
	return true;

}
static char* AddExtension(char* str) {
	int i = 0;
	if (FileExtension(str, &i) == true) { // �������� �� ��� ��������� ����� '.' � � ���� 
		char* tmp = new char[i + 1];
		for (int j = 0; j < i; j++) {
			tmp[j] = str[j];
		}
		tmp[i] = '\0';
		delete[] str;
		str = tmp;
	}
	char* tmp = new char[strlen(str) + 1];
	int j = 0;
	for (j; j < strlen(str); j++) {
		tmp[j] = str[j];
	}
	tmp[j++] = '.';
	tmp[j++] = 't';
	tmp[j++] = 'x';
	tmp[j++] = 't';
	tmp[j] = '\0';
	delete[] str;
	str = tmp;
	return str;
}
//////////////// �������� �������

extern void CinInfoAboutStudent(Queue<STUDENT>& quequStudent) {
	STUDENT undergraduate;
	/// <summary>
	/// /
	/// </summary>
	cout << "������� ������� " << quequStudent.GetSize() + 1 << "-��� ��������: " << endl;
	undergraduate.LastName = CoutString();
	cout << "������� ��� " << quequStudent.GetSize() + 1 << "-��� ��������: " << endl;
	undergraduate.FirstName = CoutString();
	cout << "������� �������� " << quequStudent.GetSize() + 1 << "-��� ��������: " << endl;
	undergraduate.Surname = CoutString();
	cout << "������� ������ " << quequStudent.GetSize() + 1 << "-��� ��������: " << endl;
	undergraduate.GroupeNumber = getValue(undergraduate.GroupeNumber);
	cout << "������� 5 ������ " << quequStudent.GetSize() + 1 << "-��� ��������: " << endl;
	for (register short unsigned i = 0; i < 5; i++) {
		cout << "\t" << i + 1 << ": ";
		undergraduate.Marks[i] = getValue(undergraduate.Marks[i]);
	}
	quequStudent.Add(undergraduate);
}
extern void PrintInfoAboutStudent(Queue<STUDENT>& quequStudent) {
	if (quequStudent.GetSize() == 0) {
		cout << "������� ����� ������ ������" << endl;
		return;
	}
	InfoClassification();
	quequStudent.PrintQueue();

}


extern void WriteInfoInFile(Queue<STUDENT>& quequStudent) {

	int CountStudent = quequStudent.GetSize();
	if (CountStudent == 0) {
		cout << "������� ����� ������ ������" << endl;
		return;
	}
	cout << "������� �������� �����(����� ��� ����������)" << endl;
	char* str = CoutString();
	str = AddExtension(str);
	quequStudent.PrintInFile(str);

}
extern void ReadInfoFromFile(Queue<STUDENT>& quequStudent) {
	cout << "������� �������� �����(����� ��� ����������)" << endl;
	char* str = CoutString();
	str = AddExtension(str);
	quequStudent.ReadFromFile(str);
}