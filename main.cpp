#include "header.h"
#include <Windows.h>
//#include <iostream>
int main(int argc, char** argv) {
	SetConsoleOutputCP(1251);
	

	//int mode;
	//std::cout << "Выберите режим работы: " << std::endl;
	//std::cout << "1 - Консолный режим" << std::endl;
	//std::cout << "2 - Консольный режим с курсором" << std::endl;
	//std::cout << "3 - Визуальный режим в отдельном окне (бета)" << std::endl;
	//std::cin >> mode;

	//if (mode == 1)
	//	consolemenu();
	
	consolemenu();

	return 0;
}
