#include"LinkedList.h"
#include"function.h"
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int menu() {
	system("cls");
	std::valarray<std::string> menuName{
			"Ввести одно число в конец",
			"Ввести одно число в начало",
			"Ввести элемент в проризвольный индекс",
			"Пустой ли лист?",
			"Размер листа?",
			"Отчистить сожержимое листа",
			"Удалить элемент последний",
			"Удалить элемент первый",
			"Удалить элемент под 'n' индексом",
			"Распечать лист",
			"Найти максимальный элемент",
			"Найти максимальный элемент",
			"Удалить все числа = 'n'",
			"Удалить все повторения числа 'n",
			"Завершить работу", };

	SetConsoleCursorPosition(hConsole, { 25,0 });
	for (int i = 0; i < 45; i++) {
		std::cout << "#";
	}
	for (int i = 0; i < menuName.size(); i++) {
		COORD position = { 25,i + 1 };
		SetConsoleCursorPosition(hConsole, position);
		std::cout << "#";
		position = { 28,(short)(i + 1) };
		SetConsoleCursorPosition(hConsole, position);
		std::cout << i + 1 << ") " << menuName[i];
		position = { 69,(short)(i + 1) };
		SetConsoleCursorPosition(hConsole, position);
		std::cout << "#";
	}
	COORD position = { 25,menuName.size() + 1 };
	SetConsoleCursorPosition(hConsole, position);
	for (int i = 0; i < 45; i++) {
		std::cout << "#";
	}
	position = { 50,(short)(menuName.size() + 3) };
	SetConsoleCursorPosition(hConsole, position);
	std::cout << "Ваш выбор: ";
	int n;
	std::cin >> n;
	return n;
}
bool DoMenuTask(List<int>& copy) {
	int n = 0, index = 0;
	switch (menu())
	{
	case 1:
		std::cout << std::endl << "Введите число: ";
		std::cin >> n;
		copy.PushBack(n);
		std::cout << std::endl << "Процесс завершён успешно!";
		break;
	case 2:
		std::cout << std::endl << "Введите число: ";
		std::cin >> n;
		copy.PushFront(n);
		std::cout << std::endl << "Процесс завершён успешно!";
		break;
	case 3:
		std::cout << std::endl << "Введите число: ";
		std::cin >> n;
		std::cout << std::endl << "Введите индекс: ";
		std::cin >> index;
		copy.Insert(n, index);
		std::cout << std::endl << "Процесс завершён успешно!";
		break;
	case 4:
		if (copy.isEmpty()) {
			std::cout << std::endl << "Список пуст";
		}
		else std::cout << std::endl << "В списке есть елементы";
		break;
	case 5:
		std::cout << std::endl << "В списке есть '" << copy.getSize() << "' елементы";
		break;
	case 6:
		copy.Clear();
		std::cout << std::endl << "Процесс завершён успешно!";
		break;
	case 7:
		if (copy.PopBack()) {
			std::cout << std::endl << "Процесс завершён успешно!";
		}
		else std::cout << std::endl << "Процесс завершён c ошибкой!";
		break;
	case 8:
		if (copy.PopFront()) {
			std::cout << std::endl << "Процесс завершён успешно!";
		}
		else std::cout << std::endl << "Процесс завершён c ошибкой!";
		break;
	case 9:
		std::cout << std::endl << "Введите индекс: ";
		std::cin >> index;
		if (copy.RemomeAt(index)) {
			std::cout << std::endl << "Процесс завершён успешно!";
		}
		else std::cout << std::endl << "Процесс завершён c ошибкой!";
		break;
	case 10:
		copy.print();
		std::cout << std::endl << "Процесс завершён успешно!";
		break;
	case 11:
		std::cout << std::endl << "Максимальный элемент равен '" << copy.FindMax() << "'";
		std::cout << std::endl << "Процесс завершён успешно!";
		break;
	case 12:
		std::cout << std::endl << "Минимальный элемент равен '" << copy.FindMin() << "'";
		std::cout << std::endl << "Процесс завершён успешно!";
		break;
	case 13:
		std::cout << std::endl << "Введите число: ";
		std::cin >> n;
		if (copy.DeleteElements(n)) {
			std::cout << std::endl << "Процесс завершён успешно!";
		}
		else std::cout << std::endl << "Процесс завершён c ошибкой!";
		break;
	case 14:
		std::cout << std::endl << "Введите число: ";
		std::cin >> n;
		if (copy.DeleteRepeter(n)) {
			std::cout << std::endl << "Процесс завершён успешно!";
		}
		else std::cout << std::endl << "Процесс завершён c ошибкой!";
		break;
	case 15:
		return false;
	default:
		std::cout << std::endl << "Выберите правильный пункт";
		break;
	}
	return true;
}