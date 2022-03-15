//#include"LinkedList.h"
//#include"2List.h"
//#include "Stack.h"
#include"Queues.h"
int main() {
	Queue<int> First;
	for (int i = 0; i < 10; i++) {
		First.Add(i);
	}
	for (int i = 0; i < 5; i++) {
		std::cout << First.front() << "    " << First.back() << std::endl;
		First.Delete();
	}
	Queue<int> two(First);
	for (int i = 0; i < two.GetSize(); i++) {
		std::cout << two.front() << "    " << two.back() << std::endl;
	}

	return 0;
}