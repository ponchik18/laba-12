#include"function.h"
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	system("color 4f");
	List<int> Main;
	while (DoMenuTask(Main)) { std::cout << std::endl; system("pause"); }
	return 0;
}