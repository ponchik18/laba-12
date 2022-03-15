//1.2.cpp           ФАЙЛ С ФУНКЦИЯМИ
#include"1.2.h"


////////// Переменные
//static STUDENT* undergraduate; // структура для хранения данных о студентах
//static STUDENT* tmp; // структура для хранения временных данных(нужно для сортировки)
//static int CountStudent = 0; // Количество студентов
extern HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); // Получаем дескриптор консоли
static int ActiveMenu = 4;
static int ActiveMenuSearch = 4;
static char* CoutString() {

	char c;
	int len = 1;
	char* str = new char[0];
	while ((c = cin.get()) != '\n')
	{
		if (c == ' ') {
			break;
		}
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
	cout << "Фамилия и Инициалы";
	cout.width(24);
	cout << "Номер группы";
	cout.width(29);
	cout << "5 оценок студента" << endl;
	for (register int i = 0; i < 85; i++)
		cout << "_";
	cout << endl;
}
//////////// Функции для меню

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
static void ConsoleTextColorSearch(int& n) {
	if (n++ == ActiveMenuSearch) {
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
bool pointerSearch(List<STUDENT>& listStudent) {
	char ch;
	char* str;
	int n;
	ch = _getch();
	if (ch == -32) ch = _getch(); // Отлавливаем стрелочки
	switch (ch)
	{
	case ESC:
		return false;
	case DOWN:
		if (ActiveMenuSearch < 7)
			ActiveMenuSearch++;
		break;
	case UP:
		if (ActiveMenuSearch > 4)
			ActiveMenuSearch--;
		break;
	case ENTRY:
		switch (ActiveMenuSearch) {
		case 4:
			CLEAN
				cout << "Введите фамилию: ";
			str = CoutString();
			CLEAN
				InfoClassification();
			if (!listStudent.SearchByLastName(str))
				cout << "По данному параметру ничего не найдено!" << endl;
			PAUSE
				break;
		case 5:
			CLEAN
				cout << "Введите отчество: ";
			n = getValue(n);
			CLEAN
				InfoClassification();
			if (!listStudent.SearchByGroup(n))
				cout << "По данному параметру ничего не найдено!" << endl;
			PAUSE
				break;
		case 6:
			CLEAN
				cout << "Введите имя: ";
			str = CoutString();
			CLEAN
				InfoClassification();
			if (!listStudent.SearchByFirstName(str))
				cout << "По данному параметру ничего не найдено!" << endl;
			PAUSE
				break;
		case 7:
			CLEAN
				cout << "Введите отчество: ";
			str = CoutString();
			CLEAN
				InfoClassification();
			if (!listStudent.SearchBySurname(str))
				cout << "По данному параметру ничего не найдено!" << endl;
			PAUSE
				break;
		}

		break;
	default:
		break;
	}
	return true;
}
static void menuSearch() {
	int n = 4; // для перехода по строкам меню
	//////////
	CLEAN
		cout << "+-----------------------------------------------------------------------------------------+" << endl << "|";
	cout.width(50);
	cout << "Меню";
	cout.setf(ios::right);
	cout.width(40);
	cout << "|" << endl;
	cout << "+-----------------------------------------------------------------------------------------+" << endl;
	GotoY(n,40);
	ConsoleTextColorSearch(n);
	cout << "1. Фамилия;" << endl;
	GotoY(n,40);
	ConsoleTextColorSearch(n);
	cout << "2. Группа;" << endl;
	GotoY(n, 40);
	ConsoleTextColorSearch(n);
	cout << "3. Имя;" << endl;
	GotoY(n, 40);
	ConsoleTextColorSearch(n);
	cout << "4. Отчество;" << endl;
	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
}
extern void pointer(List<STUDENT> &listStudent) {
	char ch;
	ch = _getch();
	if (ch == -32) ch = _getch(); // Отлавливаем стрелочки
	switch (ch)
	{
	case ESC:
		exit(0);
	case DOWN:
		if (ActiveMenu < 11)
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
				CinInfoAboutStudent(listStudent);
			ClEANCONSOLE
				PAUSE
				break;
		case 5:
			CLEAN
				PrintInfoAboutStudent(listStudent);
			PAUSE
				break;


		case 6:
			CLEAN
				DeleteInfoAboutStedent(listStudent);
			PAUSE
				break;
		case 7:
			CLEAN
				DeleteInfoAboutOneStudent(listStudent);
			PAUSE
				break;
		case 8:
			CLEAN
			ReadInfoFromFile(listStudent);
			PAUSE
				break;
		case 9:
			CLEAN
				WriteInfoInFile(listStudent);
			PAUSE
				break;
		case 10:
			CLEAN
				cout << "Количество созданных элементов: " << listStudent.getSize() << endl;
			PAUSE
				break;
		case 11:
			CLEAN
				SarchElementByFiled(listStudent);
				break;
		
		}

		break;
	default:
		break;
	}
}
extern void menu() {
	int n = 4; // для перехода по строкам меню
	//////////
	CLEAN
		cout << "+-----------------------------------------------------------------------------------------+" << endl << "|";
	cout.width(50);
	cout << "Меню";
	cout.setf(ios::right);
	cout.width(40);
	cout << "|" << endl;
	cout << "+-----------------------------------------------------------------------------------------+" << endl;
	GotoY(n);
	ConsoleTextColor(n);
	cout << "1. Ввод данных о студенте с клавитуре;" << endl;
	GotoY(n);
	ConsoleTextColor(n);
	cout << "2. Вывод данных о студентах;" << endl;
	GotoY(n);
	ConsoleTextColor(n);
	cout << "3. Удалить данные об студенте ;" << endl;
	GotoY(n);
	ConsoleTextColor(n);
	cout << "4. Удалить данные об одном студенте ;" << endl;
	GotoY(n);
	ConsoleTextColor(n);
	cout << "5. Прочитать данные о студентах с файла;" << endl;
	GotoY(n);
	ConsoleTextColor(n);
	cout << "6. Записать данные о студентах в файл" << endl;
	GotoY(n);
	ConsoleTextColor(n);
	cout << "7. Количество созданных элементов" << endl;
	GotoY(n);
	ConsoleTextColor(n);
	cout << "8. Поиск по элементу" << endl;
	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
}

///////////// Вспомогательные функции



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
	if (FileExtension(str, &i) == true) { // стрираем всё что находится после '.' и её тоже 
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
//////////////// основные функции

extern void CinInfoAboutStudent(List<STUDENT>& listStudent) {
	STUDENT undergraduate;
	/// <summary>
	/// /
	/// </summary>
	cout << "Введите фамилию " << listStudent.getSize()+1 << "-ого студента: " << endl;
	undergraduate.LastName = CoutString();
	cout << "Введите имя " << listStudent.getSize() + 1 << "-ого студента: " << endl;
	undergraduate.FirstName = CoutString();
	cout << "Введите отчество " << listStudent.getSize() + 1 << "-ого студента: " << endl;
	undergraduate.Surname = CoutString();

	cout << "Введите группу " << listStudent.getSize() + 1 << "-ого студента: " << endl;
	
	undergraduate.GroupeNumber = getValue(undergraduate.GroupeNumber);
	cout << "Введите 5 оценок " << listStudent.getSize() + 1 << "-ого студента: " << endl;
	for (register short unsigned i = 0; i < 5; i++) {
		cout << "\t" << i + 1 << ": ";
		undergraduate.Marks[i] = getValue(undergraduate.Marks[i]);
	}
	listStudent.InsertAlpabet(undergraduate);
}
extern void PrintInfoAboutStudent(List<STUDENT>& listStudent) {
	if (listStudent.getSize() == 0) {
		cout << "Сначало нужно ввести данные" << endl;
		return;
	}
	InfoClassification();
	listStudent.PrintList();
	//for (register int i = 0; i < listStudent.getSize(); i++) {
	//	cout << i + 1 << ":";
	//	.Info();
	//}
}
extern void DeleteInfoAboutStedent(List<STUDENT>& listStudent) {

	listStudent.Clear();
	std::cout <<"Удаление завершено" << std::endl;
}

extern void DeleteInfoAboutOneStudent(List<STUDENT>& listStudent) {
	int n;
	std::cout << "Введите индекс элемента, который хотите удалить: ";
	std::cin >> n;
	ClEANCONSOLE
	std::cout << std::endl;

	if (listStudent.RemomeAt(n)) {
		std::cout << "Удаление завершено" << std::endl;
	}
	else 
		std::cout << "Удаление завершено c ошибкой..." << std::endl;
}
extern void WriteInfoInFile(List<STUDENT>& listStudent) {

	int CountStudent = listStudent.getSize();
	if (CountStudent == 0) {
		cout << "Сначало нужно ввести данные" << endl;
		return;
	}
	cout << "Введите название файла(можно без расширения)" << endl;
	char* str = CoutString();
	str = AddExtension(str);
	FILE* out = fopen(str, "wb");

	if (out == NULL) {
		cout << "ФАЙЛ НЕ МОЖЕТ БЫТЬ ОТКРЫТ!!!" << endl;
		exit(0);
	}
	fwrite(&CountStudent, sizeof(int), 1, out);
	STUDENT undergraduate;
	for (int i = 0; i < CountStudent; i++) {
		undergraduate = listStudent[i];
		undergraduate.PrintInFile(out);
	}
	cout << "Запись успешно завершена!" << endl;
	fclose(out);

}
extern void ReadInfoFromFile(List<STUDENT>& listStudent) {
	cout << "Введите название файла(можно без расширения)" << endl;
	char* str = CoutString();
	str = AddExtension(str);
	FILE* in = fopen(str, "rb");
	if (in == NULL) {
		cout << "ДАННЫЙ ФАЙЛ НЕ НАЙДЕН!!!" << endl;
		return;
	}
	STUDENT* undergraduate=new STUDENT;
	int CountStudent=0;
	fread(&CountStudent, sizeof(int), 1, in);
	for (int i = 0; i < CountStudent; i++) {
		undergraduate->ReadFromFile(in);
		listStudent.InsertAlpabet(*undergraduate);
	}
	cout << "Чтение успешно завершено!" << endl;
	fclose(in);
	delete undergraduate;
}
extern void SarchElementByFiled(List<STUDENT>& listStudent) {
	while (true)
	{
		CLEAN
		menuSearch();
		if (!pointerSearch(listStudent)) {
			break;
		}
	}
}