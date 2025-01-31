#include "header.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;


#define cls system("cls")
#define pause system("pause>nul")

#define NULL_FRACTION { 0, 0, 0, 0}

#define WCF writecalcfrac(vcshowtext, first, operation, second, result)

int x = 0, y = 0;
bool runningvcmode = true;

bool vcshowtext = true;
bool profent = false;

void gotoxy(int x, int y) {
	COORD p;
	p.X = x; p.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void doubleinput(double& number, int x, int y) {
	double temp;
	gotoxy(x, y);
	std::cin >> temp;
	number = temp;
}

void charinput(char& number, int x, int y) {
	char temp;
	gotoxy(x, y);
	std::cin >> temp;
	number = temp;
}

void intinput(int& number, int x, int y) {
	int temp;
	gotoxy(x, y);
	std::cin >> temp;
	number = temp;
}
//Текст для всех функций
void writefunctions() {
	cout << " Калькулятор <- calc" << endl;									//Сделано
	cout << " Калькулятор процентов <- calcperc" << endl;					//Сделано
	cout << " Калькулятор дробей <- calcfrac" << endl;						//Сделано

	cout << " Найти квадратный корень <- sqrt" << endl;						//Сделано
	cout << " Найти кубический корень <- cbrt" << endl;						//Сделано
	cout << " Найти заданный корень <- rt" << endl;							//Сделано

	cout << " Превратить дробь в десятичную и проценты <- tdap" << endl;	//Сделано
	cout << " Из десятичной дроби в обыкновенную <- dtf" << endl;			//Сделано
	cout << " Из неправильной дроби в обыкновенную <- itm" << endl;			//Сделано
	cout << " Из правильной дроби в неправильную <- tif" << endl;			//Сделано
	cout << " Из дроби с плавающей запятой в обыкновенную <- ftf" << endl;	//Сделано
	cout << " Найти пропорцию зная три дроби <- prop3" << endl;				//Сделано

	cout << " Вывести делители числа <- fd" << endl;						//Сделано
	cout << " Проверить на простое число <- fp" << endl;					//Сделано
	cout << " Найти числа кратные заданному <- mo" << endl;					//Сделано
	cout << " Найти НОД <- gcd" << endl;									//Сделано
	cout << " Найти НОК <- lcm" << endl;									//Сделано
	cout << " Информация о числе <- ian" << endl;							//Сделано
	cout << " Сложить числа <- sod" << endl;								
	cout << " Выйти" << endl;
	//21
}

void writesod(bool showtext, double number) {
	cout << " Сложить цифры" << endl << endl;

	if (showtext) cout << " Число:";
	cout << " " << number << endl;

	cout << " Выйти" << endl;

	if (showtext) cout << " Сумма цифр:";
	cout << " " << sumOfDigits(number);

}

void vcsod() {
	double number = 0;

	if (profent) {
		cls;
		if (vcshowtext) cout << "Введите число: ";
		cin >> number;
		cout << sumOfDigits(number) << endl;
		pause;
		cls;
	}
	else {
		cls;
		writesod(vcshowtext, number);
		x = 0; y = 2;
		gotoxy(x, y);
		bool runningsod = 1;
		while (runningsod) {
			gotoxy(x, y);
			int ch = _getch();
			if (CH_sS)
				y++;
			if (CH_wW)
				y--;
			if (y <= 2)
				y = 2;
			if (y >= 3)
				y = 3;

			if (y == 2 && ch == CH_enter) {
				number = 0;
				cls;
				writesod(vcshowtext, number);
				if (vcshowtext)
					doubleinput(number, 8, 2);
				else
					doubleinput(number, 1, 2);
				cls;
				writesod(vcshowtext, number);
			}

			if (y == 3 && ch == CH_enter)
				runningsod = 0;
		}
	}
}

void writeian(bool showtext, double number) {
	vector<int> divisors = Divisors(number);

	cout << " Информация о числе" << endl << endl;


	if (vcshowtext) cout << " Число:";
	cout << " " << number << endl;

	cout << " Выйти" << endl;

	if (vcshowtext) cout << " Число в квадрате:";
	cout << " " << number * number << endl;
	
	if (vcshowtext) cout << " Число в кубе:";
	cout << " " << number * number * number << endl;

	if (vcshowtext) cout << " Квадратный корень числа:";
	cout << " " << sqrt(number) << endl;

	if (vcshowtext) cout << " Кубический корень числа:";
	cout << " " << cbrt(number) << endl;

	if (vcshowtext) cout << " Корень на себя:";
	cout << " " << rt(number, number) << endl;

	if (vcshowtext) cout << " Степень на себя:";
	cout << " " << pow(number, number) << endl;

	if (vcshowtext) cout << " Сложение чисел:";
	cout << " " << sumOfDigits(number) << endl;

	if (vcshowtext) cout << " Делители числа:";
	cout << " ";
	for (int div : divisors)
		cout << div << " ";
	cout << endl;
}

void vcian() {
	double number = 0;
	if (profent){
		cls;
		if (vcshowtext) cout << "Введите число: ";
		cin >> number;

		if (vcshowtext) cout << "Квадрат числа: \t\t\t";
		cout << number * number << endl;

		if (vcshowtext) cout << "Куб числа: \t\t\t";
		cout << number * number * number << endl;

		if (vcshowtext) cout << "Квадратный корень числа: \t";
		cout << pow(number, 0.5) << endl;

		if (vcshowtext) cout << "Кубический корень числа: \t";
		cout << pow(number, 0.33333333333333333333333333) << endl;

		if (vcshowtext) cout << "Степень на себя: \t\t";
		cout << pow(number, number) << endl;

		if (vcshowtext) cout << "Сложение чисел: \t\t";
		cout << sumOfDigits(number) << endl;

		if (vcshowtext) cout << "Делители числа: \t\t";
		vector<int> divisors = Divisors(number);
		for (int div : divisors) {
			cout << div << " ";
		}
		cout << endl;

		if (vcshowtext) cout << "Корень самого себя: \t\t";
		cout << pow(number, 1.0 / number) << endl;

		if (vcshowtext) cout << "1 Делённый на число: \t\t";
		cout << 1 / number << endl;

		if (vcshowtext) cout << "1 / (a / 100): \t\t\t";
		cout << 1 / (number / 100) << endl;
		pause;
		cls;
	}
	else {
		cls;
		writeian(vcshowtext, number);
		x = 0; y = 2;
		gotoxy(x, y);
		bool runningian = 1;
		while (runningian) {
			gotoxy(x, y);
			int ch = _getch();
			if (CH_sS)
				y++;
			if (CH_wW)
				y--;
			if (y <= 2)
				y = 2;
			if (y >= 3)
				y = 3;



			if (y == 2 && ch == CH_enter) {
				number = 0;
				cls;
				writeian(vcshowtext, number);
				if (vcshowtext)
					doubleinput(number, 8, 2);
				else
					doubleinput(number, 1, 2);
				cls;
				writeian(vcshowtext, number);
			}
			if (y == 3 && ch == CH_enter)
				runningian = 0;

		}
	}

}

void writelcm(bool showtext, int first, int second, int lcmval) {
	cout << " Наименьшее общее кратное" << endl << endl;
	
	if (showtext) cout << " Первое число:";
	cout << " " << first << endl;

	if (showtext) cout << " Второе число:";
	cout << " " << second << endl;

	cout << " Вычислить" << endl;

	cout << " Выйти" << endl;

	if (showtext) cout << " НОК:";
	cout << " " << lcmval << endl;

	cout << " ";
	if (showtext) cout << lcmval << " / " << first << " = ";
	cout << (double)lcmval / (double)first << endl;

	cout << " ";
	if (showtext) cout << lcmval << " / " << second << " = ";
	
	cout << (double)lcmval / (double)second << endl;
}

void vclcm() {
	int first = 1, second = 1, lcmval = 1;
	if (profent) {
		cls;
		if (vcshowtext) cout << "Введите первое число: ";
		cin >> first;
		if (vcshowtext) cout << "Введите второе число: ";
		cin >> second;
		lcmval = lcm(first, second);

		if (vcshowtext) cout << "НОК: ";
		cout << lcmval << endl;

		cout << lcmval << " / " << first << " = " << lcmval / first << endl;
		cout << lcmval << " / " << second << " = " << lcmval / second << endl;
		pause;
		cls;
	}
	else {
		cls;
		writelcm(vcshowtext, first, second, lcmval);
		x = 0; y = 2;
		gotoxy(x, y);
		bool runninglcm = 1;
		while (runninglcm) {
			gotoxy(x, y);
			int ch = _getch();
			if (CH_sS)
				y++;
			if (CH_wW)
				y--;
			if (y <= 2)
				y = 2;
			if (y >= 5)
				y = 5;

			if (y == 2 && ch == CH_enter) {
				first = 1;
				cls;
				writelcm(vcshowtext, first, second, lcmval);
				if (vcshowtext)
					intinput(first, 15, 2);
				else
					intinput(first, 1, 2);
				cls;
				writelcm(vcshowtext, first, second, lcmval);
			}

			if (y == 3 && ch == CH_enter) {
				second = 1;
				cls;
				writelcm(vcshowtext, first, second, lcmval);
				if (vcshowtext)
					intinput(second, 15, 3);
				else
					intinput(second, 1, 3);
				cls;
				writelcm(vcshowtext, first, second, lcmval);
			}

			if (y == 4 && ch == CH_enter) {
				lcmval = lcm(first, second);
				cls;
				writelcm(vcshowtext, first, second, lcmval);
			}

			if (y == 5 && ch == CH_enter)
				runninglcm = 0;

		}
	}
}
 
void writegcd(bool showtext, int first, int second, int gcdval) {
	cout << " Наибольший общий делитель" << endl << endl;

	if (showtext) cout << " Первое число:";
	cout << " " << first << endl;

	if (showtext) cout << " Второе число:";
	cout << " " << second << endl;

	cout << " Обновить НОД" << endl;

	cout << " Выйти" << endl;
	if (showtext) cout << " НОД:";
	cout << " " << gcdval << endl;

	if (gcdval != 1) {
		if (showtext) cout << " " << first << " / " << gcdval << ":";
		cout << " " << first / gcdval << endl;

		if (showtext) cout << " " << second << " / " << gcdval << ":";
		cout << " " << (double)second / (double)gcdval << endl;
	}
}

void vcgcd() {
	int first = 1, second = 1, _gcdval = 1;
	if (profent) {
		cls;
		if (vcshowtext) cout << "Введите первое число: ";
		cin >> first;
		if (vcshowtext) cout << "Введите второе число: ";
		cin >> second;
		_gcdval = gcd(first, second);
		cout << "НОД: " << _gcdval << endl;
		cout << first << " / " << _gcdval << " = " << first / _gcdval << endl;
		cout << second << " / " << _gcdval << " = " << second / _gcdval << endl;
		pause;
		cls;
	}
	else {
		cls;
		writegcd(vcshowtext, first, second, _gcdval);
		x = 0; y = 2;
		gotoxy(x, y);
		bool runninggcd = 1;
		while (runninggcd) {
			gotoxy(x, y);
			int ch = _getch();
			if (CH_sS)
				y++;
			if (CH_wW)
				y--;
			if (y <= 2)
				y = 2;
			if (y >= 5)
				y = 5;

			if (y == 2 && ch == CH_enter) {
				first = 0;
				cls;
				writegcd(vcshowtext, first, second, _gcdval);
				if (vcshowtext)
					intinput(first, 15, 2);
				else
					intinput(first, 1, 2);
				cls;
				writegcd(vcshowtext, first, second, _gcdval);
			}

			if (y == 3 && ch == CH_enter) {
				second = 0;
				cls;
				writegcd(vcshowtext, first, second, _gcdval);
				if (vcshowtext)
					intinput(second, 15, 3);
				else
					intinput(second, 1, 3);
				cls;
				writegcd(vcshowtext, first, second, _gcdval);
			}

			if (y == 4 && ch == CH_enter) {
				_gcdval = gcd(first, second);
				cls;
				writegcd(vcshowtext, first, second, _gcdval);
			}



			if (y == 5 && ch == CH_enter)
				runninggcd = 0;
		}
	}
}

void writemo(bool showtext, int number, int count) {
	cout << " Числа кратные заданному" << endl << endl;

	if (showtext) cout << " Число:";
	cout << " " << number << endl;

	if (showtext) cout << " Количество:";
	cout << " " << count << endl;

	cout << " Вычислить" << endl;

	cout << " Выйти" << endl;

	if (showtext) cout << " Числа кратные вашему числу:";
	cout << " ";
}

void vcmo() {
	int number = 1, count = 1;
	if (profent) {
		cls;
		if (vcshowtext) cout << "Введите число: ";
		cin >> number;
		if (vcshowtext) cout << "Количество чисел: ";
		cin >> count;
		int i = 1;
		while (i != count + 1) {
			cout << number * i << " ";
			i++;
		}
		cout << endl;
		pause;
		cls;
	}
	else {
		cls;
		writemo(vcshowtext, number, count);
		x = 0; y = 2;
		gotoxy(x, y);
		bool runningmo = 1;
		while (runningmo) {
			gotoxy(x, y);
			int ch = _getch();
			if (CH_sS)
				y++;
			if (CH_wW)
				y--;
			if (y <= 2)
				y = 2;
			if (y >= 5)
				y = 5;

			if (y == 2 && ch == CH_enter) {
				number = 0;
				cls;
				writemo(vcshowtext, number, count);
				if (vcshowtext)
					intinput(number, 8, 2);
				else
					intinput(number, 1, 2);
				cls;
				writemo(vcshowtext, number, count);
			}

			if (y == 3 && ch == CH_enter) {
				count = 0;
				cls;
				writemo(vcshowtext, number, count);
				if (vcshowtext)
					intinput(count, 13, 3);
				else
					intinput(count, 1, 3);
				cls;
				writemo(vcshowtext, number, count);
			}

			if (y == 4 && ch == CH_enter) {
				int i = 1;
				if (vcshowtext)
					gotoxy(29, 6);
				else
					gotoxy(1, 6);
				while (i != count + 1) {
					cout << number * i << " ";
					i++;
				}
			}

			if (y == 5 && ch == CH_enter)
				runningmo = 0;

		}
	}
}

void writefp(bool showtext, int number, bool prime) {
	cout << " Проверить на простое число" << endl << endl;

	if (showtext) cout << " Ваше число:";
	cout << " " << number << endl;

	cout << " Вычислить" << endl;
	cout << " Число ";
	if (prime)
		cout << "простое" << endl;
	else
		cout << "не простое" << endl;
	cout << " Выйти" << endl;
}

void vcfp() {
	int number = 1;
	bool prime = isPrime(number);

	if (profent){
		cls;
		if (vcshowtext) cout << "Введите число: ";
		cin >> number;
		prime = isPrime(number);
		if (prime)
			cout << "Число простое" << endl;
		else
			cout << "Число не простое" << endl;
		pause;
		cls;
	
	}
	else {
		cls;
		writefp(vcshowtext, number, prime);
		x = 0; y = 2;
		gotoxy(x, y);
		bool runningfp = 1;
		while (runningfp) {
			gotoxy(x, y);
			int ch = _getch();
			if (CH_sS)
				y++;
			if (CH_wW)
				y--;
			if (y <= 2)
				y = 2;
			if (y >= 5)
				y = 5;

			if (y == 2 && ch == CH_enter) {
				number = 0;
				cls;
				writefp(vcshowtext, number, prime);
				if (vcshowtext)
					intinput(number, 13, 2);
				else
					intinput(number, 1, 2);
				cls;
				writefp(vcshowtext, number, prime);
			}

			if (y == 3 && ch == CH_enter) {
				prime = isPrime(number);
				cls;
				writefp(vcshowtext, number, prime);
			}

			if (y == 5 && ch == CH_enter)
				runningfp = 0;
		}

	}
}

void writefd(bool showtext, int number, vector<int> divisors) {
	cout << " Найти делители числа " << endl << endl;

	if (showtext) cout << " Число:";
	cout << " " << number << endl;

	cout << " Вычислить" << endl;
	
	cout << " Выйти" << endl;

	if (showtext) cout << " Делители числа:";
	cout << " ";
	for (int div : divisors)
		cout << div << " ";
	cout << endl;
}

void vcfd() {
	int number = 0;
	vector<int> divisors = Divisors(number);
	
	if (profent) {
		cls;
		if (vcshowtext) cout << "Введите число: ";
		cin >> number;
		divisors = Divisors(number);
		for (int div : divisors) {
			cout << div <<  " ";
		}
		cout << endl;
		pause;
		cls;
	}
	else {
		cls;
		writefd(vcshowtext, number, divisors);
		x = 0; y = 2;
		gotoxy(x, y);
		bool runningfd = 1;
		while (runningfd) {
			gotoxy(x, y);
			int ch = _getch();
			if (CH_sS)
				y++;
			if (CH_wW)
				y--;
			if (y <= 2)
				y = 2;
			if (y >= 4)
				y = 4;

			//Ввод числа
			if (y == 2 && ch == CH_enter) {
				number = 0;
				cls;
				writefd(vcshowtext, number, divisors);
				if (vcshowtext)
					intinput(number, 8, 2);
				else
					intinput(number, 1, 2);
				cls;
				writefd(vcshowtext, number, divisors);
			}

			if (y == 3 && ch == CH_enter) {
				divisors = Divisors(number);
				cls;
				writefd(vcshowtext, number, divisors);
			}


			if (y == 4 && ch == CH_enter)
				runningfd = 0;
		}
	}
}

void writeprop3(bool showtext, Fraction frac1, Fraction frac2, Fraction frac3, Fraction result) {
	cout << " Найти дробную пропорцию" << endl << endl;

	if (showtext) cout << " Целая часть первой дроби:";
	cout << " " << frac1.fullpart << endl;

	if (showtext) cout << " Числитель первой дроби:";
	cout << " " << frac1.numerator << endl;

	if (showtext) cout << " Знаменатель первой дроби:";
	cout << " " << frac1.denominator << endl;

	if (showtext) cout << " Целая часть второй дроби:";
	cout << " " << frac2.fullpart << endl;

	if (showtext) cout << " Числитель второй дроби:";
	cout << " " << frac2.numerator << endl;

	if (showtext) cout << " Знаменатель второй дроби:";
	cout << " " << frac2.denominator << endl;

	if (showtext) cout << " Целая часть третьей дроби:";
	cout << " " << frac3.fullpart << endl;

	if (showtext) cout << " Числитель третьей дроби:";
	cout << " " << frac3.numerator << endl;

	if (showtext) cout << " Знаменатель третьей дроби:";
	cout << " " << frac3.denominator << endl;

	cout << " Вычислить" << endl;

	if (showtext) cout << " Целая часть результата:";
	cout << " " << result.fullpart << endl;

	if (showtext) cout << " Числитель результата:";
	cout << " " << result.numerator << endl;

	if (showtext) cout << " Знаменатель результата:";
	cout << " " << result.denominator << endl;

	cout << " Выйти" << endl;
}

void vcprop3() {
	Fraction frac1 = NULL_FRACTION, frac2 = NULL_FRACTION, frac3 = NULL_FRACTION, result = NULL_FRACTION;

	if (profent) {
		cls;
		if (vcshowtext) cout << "Введите целую часть первой дроби: ";
		cin >> frac1.fullpart;
		if (vcshowtext) cout << "Введите числитель первой дроби: ";
		cin >> frac1.numerator;
		if (vcshowtext) cout << "Введите знаменатель первой дроби: ";
		cin >> frac1.denominator;
		if (vcshowtext) cout << "Введите целую часть второй дроби: ";
		cin >> frac2.fullpart;
		if (vcshowtext) cout << "Введите числитель второй дроби: ";
		cin >> frac2.numerator;
		if (vcshowtext) cout << "Введите знаменатель второй дроби: ";
		cin >> frac2.denominator;
		if (vcshowtext) cout << "Введите целую часть третьей дроби: ";
		cin >> frac3.fullpart;
		if (vcshowtext) cout << "Введите числитель третьей дроби: ";
		cin >> frac3.numerator;
		if (vcshowtext) cout << "Введите знаменатель третьей дроби: ";
		cin >> frac3.denominator;
		result = prop3(frac1, frac2, frac3);
		result.print();
		pause;
		cls;

	}
	else {
		cls;
		writeprop3(vcshowtext, frac1, frac2, frac3, result);
		x = 0; y = 2; 
		gotoxy(x, y);
		bool runningprop3 = 1;
		while (runningprop3) {
			gotoxy(x, y);
			int ch = _getch();
			if (CH_sS)
				y++;
			if (CH_wW)
				y--;
			if (y <= 2)
				y = 2;
			if (y >= 15)
				y = 15;


			//Ввод целой части первой дроби
			if (y == 2 && ch == CH_enter) {
				frac1.fullpart = 0;
				cls;
				writeprop3(vcshowtext, frac1, frac2, frac3, result);
				if (vcshowtext)
					intinput(frac1.fullpart, 27, 2);
				else
					intinput(frac1.fullpart, 1, 2);
				cls;
				writeprop3(vcshowtext, frac1, frac2, frac3, result);
			}

			//Ввод числителя первой дроби
			if (y == 3 && ch == CH_enter) {
				frac1.numerator = 0;
				cls;
				writeprop3(vcshowtext, frac1, frac2, frac3, result);
				if (vcshowtext)
					intinput(frac1.numerator, 25, 3);
				else
					intinput(frac1.numerator, 1, 3);
				cls;
				writeprop3(vcshowtext, frac1, frac2, frac3, result);
			}

			//Ввод знаменателя первой дроби
			if (y == 4 && ch == CH_enter) {
				frac1.denominator = 0;
				cls;
				writeprop3(vcshowtext, frac1, frac2, frac3, result);
				if (vcshowtext)
					intinput(frac1.denominator, 27, 4);
				else
					intinput(frac1.denominator, 1, 4);
				cls;
				writeprop3(vcshowtext, frac1, frac2, frac3, result);
			}




			//Ввод целой части второй дроби
			if (y == 5 && ch == CH_enter) {
				frac2.fullpart = 0;
				cls;
				writeprop3(vcshowtext, frac1, frac2, frac3, result);
				if (vcshowtext)
					intinput(frac2.fullpart, 27, 5);
				else
					intinput(frac2.fullpart, 1, 5);
				cls;
				writeprop3(vcshowtext, frac1, frac2, frac3, result);
			}

			//Ввод числителя второй дроби
			if (y == 6 && ch == CH_enter) {
				frac2.numerator = 0;
				cls;
				writeprop3(vcshowtext, frac1, frac2, frac3, result);
				if (vcshowtext)
					intinput(frac2.numerator, 25, 6);
				else
					intinput(frac2.numerator, 1, 6);
				cls;
				writeprop3(vcshowtext, frac1, frac2, frac3, result);
			}

			//Ввод знаменателя второй дроби
			if (y == 7 && ch == CH_enter) {
				frac2.denominator = 0;
				cls;
				writeprop3(vcshowtext, frac1, frac2, frac3, result);
				if (vcshowtext)
					intinput(frac2.denominator, 27, 7);
				else
					intinput(frac2.denominator, 1, 7);
				cls;
				writeprop3(vcshowtext, frac1, frac2, frac3, result);
			}






			//Ввод целой части третьей дроби
			if (y == 8 && ch == CH_enter) {
				frac3.fullpart = 0;
				cls;
				writeprop3(vcshowtext, frac1, frac2, frac3, result);
				if (vcshowtext)
					intinput(frac3.fullpart, 28, 8);
				else
					intinput(frac3.fullpart, 1, 8);
				cls;
				writeprop3(vcshowtext, frac1, frac2, frac3, result);
			}

			//Ввод числителя третьей дроби
			if (y == 9 && ch == CH_enter) {
				frac3.numerator = 0;
				cls;
				writeprop3(vcshowtext, frac1, frac2, frac3, result);
				if (vcshowtext)
					intinput(frac3.numerator, 26, 9);
				else
					intinput(frac3.numerator, 1, 9);
				cls;
				writeprop3(vcshowtext, frac1, frac2, frac3, result);
			}

			//Ввод знаменателя третьей дроби
			if (y == 10 && ch == CH_enter) {
				frac3.denominator = 0;
				cls;
				writeprop3(vcshowtext, frac1, frac2, frac3, result);
				if (vcshowtext)
					intinput(frac3.denominator, 28, 10);
				else
					intinput(frac3.denominator, 1, 10);
				cls;
				writeprop3(vcshowtext, frac1, frac2, frac3, result);
			}

			//Обработка
			if (y == 11 && ch == CH_enter) {
				result = prop3(frac1, frac2, frac3);
				cls;
				writeprop3(vcshowtext, frac1, frac2, frac3, result);
			}
			
			

			if (y == 15 && ch == CH_enter)
				runningprop3 = 0;
		}
	}
}

void writeftf(bool showtext, double numerator, double denominator, Fraction result) {
	cout << " Из дроби с плавающей запятой в обыкновенную" << endl << endl;

	if (showtext) cout << " Числитель:";
	cout << " " << numerator << endl;

	if (showtext) cout << " Знаменатель:";
	cout << " " << denominator << endl;

	cout << " Вычислить" << endl;
	
	if (showtext) cout << " Целая часть:";
	cout << " " << result.fullpart << endl;

	if (showtext) cout << " Числитель:";
	cout << " " << result.numerator << endl;

	if (showtext) cout << " Знаменатель:";
	cout << " " << result.denominator << endl;

	cout << " Выйти" << endl;
}

void vcftf() {
	Fraction result = NULL_FRACTION;
	double numerator = 0;
	double denominator = 0;

	if (profent){
		cls;
		bool reduce, itm;
		if (vcshowtext) cout << "Введите числитель: ";
		cin >> numerator;
		if (vcshowtext) cout << "Введите знаменатель: ";
		cin >> denominator;
		if (vcshowtext) cout << "Переводить в смешанную дробь если это возможно? (1 - Да, 0 - Нет): ";
		cin >> itm;
		if (vcshowtext) cout << "Сокращать дробь? (1 - Да, 0 - Нет): ";
		cin >> reduce;

		result = floatToFraction(numerator, denominator, itm, reduce);
		result.print();
		pause;
		cls;
	}
	else {
		cls;
		writeftf(vcshowtext, numerator, denominator, result);
		x = 0; y = 2;
		gotoxy(x, y);
		bool runningftf = 1;
		while (runningftf) {
			gotoxy(x, y);
			int ch = _getch();
			if (CH_sS)
				y++;
			if (CH_wW)
				y--;
			if (y <= 2)
				y = 2;
			if (y >= 8)
				y = 8;

			//Ввод числителя
			if (y == 2 && ch == CH_enter) {
				numerator = 0;
				cls;
				writeftf(vcshowtext, numerator, denominator, result);
				if (vcshowtext)
					doubleinput(numerator, 12, 2);
				else
					doubleinput(numerator, 1, 2);
				cls;
				writeftf(vcshowtext, numerator, denominator, result);
			}

			//Ввод знаменателя
			if (y == 3 && ch == CH_enter) {
				denominator = 0;
				cls;
				writeftf(vcshowtext, numerator, denominator, result);
				if (vcshowtext)
					doubleinput(denominator, 14, 3);
				else
					doubleinput(denominator, 1, 3);

				cls;
				writeftf(vcshowtext, numerator, denominator, result);
			}

			if (y == 4 && ch == CH_enter) {
				result = floatToFraction(numerator, denominator, true, true);
				cls;
				writeftf(vcshowtext, numerator, denominator, result);
			}



			if (y == 8 && ch == CH_enter)
				runningftf = 0;
		}
	}
}

void writetif(bool showtext, Fraction frac, Fraction result) {
	cout << " Из правильной дроби в неправильную" << endl << endl;

	if (showtext) cout << " Целая часть:";
	cout << " " << frac.fullpart << endl;

	if (showtext) cout << " Числитель:";
	cout << " " << frac.numerator << endl;

	if (showtext) cout << " Знаменатель:";
	cout << " " << frac.denominator << endl;

	cout << " Вычислить" << endl;

	if (showtext) cout << " Числитель:";
	cout << " " << result.numerator << endl;

	if (showtext) cout << " Знаменатель:";
	cout << " " << result.denominator << endl;

	cout << " Выйти" << endl;
}

void vctif() {
	Fraction frac = NULL_FRACTION, result = NULL_FRACTION;

	if (profent){
		cls;
		if (vcshowtext) cout << "Введите целую часть: ";
		cin >> frac.fullpart;
		if (frac.fullpart == 0)
			cout << "Смысл вам находить неправильную дробь, если у неё и так нету целой части?" << endl;
		else {
			if (vcshowtext) cout << "Введите числитель: ";
			cin >> frac.numerator;
			if (vcshowtext) cout << "Введите знаменатель: ";
			cin >> frac.denominator;
			frac.toImproperFraction();
			frac.print();
		}
		pause;
		cls;
	}
	else {
		cls;
		writetif(vcshowtext, frac, result);
		x = 0; y = 2;
		gotoxy(x, y);
		bool runningtif = 1;
		while (runningtif) {
			gotoxy(x, y);
			int ch = _getch();
			if (CH_sS)
				y++;
			if (CH_wW)
				y--;
			if (y <= 2)
				y = 2;
			if (y >= 8)
				y = 8;

			//Ввод целой части
			if (y == 2 && ch == CH_enter) {
				frac.fullpart = NULL;
				cls;
				writetif(vcshowtext, frac, result);
				if (vcshowtext)
					intinput(frac.fullpart, 14, 2);
				else
					intinput(frac.fullpart, 1, 2);
				cls;
				writetif(vcshowtext, frac, result);
			}

			//Ввод числителя
			if (y == 3 && ch == CH_enter) {
				frac.numerator = NULL;
				cls;
				writetif(vcshowtext, frac, result);
				if (vcshowtext)
					intinput(frac.numerator, 12, 3);
				else
					intinput(frac.numerator, 1, 3);
				cls;
				writetif(vcshowtext, frac, result);
			}

			//Ввод знаменателя
			if (y == 4 && ch == CH_enter) {
				frac.denominator = NULL;
				cls;
				writetif(vcshowtext, frac, result);
				if (vcshowtext)
					intinput(frac.denominator, 14, 4);
				else
					intinput(frac.denominator, 1, 4);
				cls;
				writetif(vcshowtext, frac, result);
			}

			if (y == 5 && ch == CH_enter) {
				result = frac;
				result.toImproperFraction();
				cls;
				writetif(vcshowtext, frac, result);
			}


			if (y == 8 && ch == CH_enter) {
				runningtif = false;
			}


		}
	}
}

void writeitm(bool showtext, Fraction frac, Fraction result) {
	cout << " Из неправильной дроби в обыкновенную" << endl << endl;

	if (showtext) cout << " Числитель:";
	cout << " " << frac.numerator << endl;
	
	if (showtext) cout << " Знаменатель:";
	cout << " " << frac.denominator << endl;

	cout << " Вычислить" << endl;

	if (showtext) cout << " Целая часть результата:";
	cout << " " << result.fullpart << endl;

	if (showtext) cout << " Числитель:";
	cout << " " << result.numerator << endl;

	if (showtext) cout << " Знаменатель:";
	cout << " " << result.denominator << endl;

	cout << " Выйти" << endl;
}

void vcitm() {
	Fraction frac = NULL_FRACTION;
	Fraction result = NULL_FRACTION;

	if (profent){
		cls;
		if (vcshowtext) cout << "Введите числитель: ";
		cin >> frac.numerator;
		if (vcshowtext) cout << "Введите знаменатель: ";
		cin >> frac.denominator;
		frac.toMixedFraction();
		frac.print();
		pause;
		cls;
	}
	else {
		cls;
		writeitm(vcshowtext, frac, result);
		x = 0; y = 2;
		gotoxy(x, y);
		bool runningitm = true;
		while (runningitm) {
			gotoxy(x, y);
			int ch = _getch();
			if (CH_sS)
				y++;
			if (CH_wW)
				y--;
			if (y <= 2)
				y = 2;
			if (y >= 8)
				y = 8;

			//Ввод числителя
			if (y == 2 && ch == CH_enter) {
				frac.fullpart = NULL;
				cls;
				writeitm(vcshowtext, frac, result);
				if (!vcshowtext)
					intinput(frac.numerator, 1, 2);
				else
					intinput(frac.numerator, 12, 2);
				cls;
				writeitm(vcshowtext, frac, result);
			}

			//Ввод знаменателя
			if (y == 3 && ch == CH_enter) {
				frac.fullpart = NULL;
				cls;
				writeitm(vcshowtext, frac, result);
				if (!vcshowtext)
					intinput(frac.denominator, 1, 3);
				else
					intinput(frac.denominator, 14, 3);
				cls;
				writeitm(vcshowtext, frac, result);
			}

			//Обработка
			if (y == 4 && ch == CH_enter) {
				result = frac;
				result.toMixedFraction();
				cls;
				writeitm(vcshowtext, frac, result);
			}

			//Выход
			if (y == 8 && ch == CH_enter) 
				runningitm = 0;
			
		}
	}
}

void writedtf(bool showtext, double decimal, Fraction result) {
	cout << " Из десятичной дроби в обыкновенную" << endl << endl;
	
	if (showtext) cout << " Десятичная дробь:";
	cout << " " << decimal << endl;

	cout << " Вычислить" << endl;
	
	if (showtext) cout << " Целая часть результата:";
	cout << " " << result.fullpart << endl;

	if (showtext) cout << " Числитель результата:";
	cout << " " << result.numerator << endl;

	if (showtext) cout << " Знаменатель результата:";
	cout << " " << result.denominator << endl;

	cout << " Выйти" << endl;
	//1
	//2
	//3
	//4
	//5
	//6
	//7
	//8
}

void vcdtf() {
	Fraction result = NULL_FRACTION;
	double decimal = 0;

	if (profent){
		cls;
		if (vcshowtext) cout << "Введите десятичную дробь: ";
		cin >> decimal;
		result = decimalToFraction(decimal);
		result.toMixedFraction();
		result.print();
		pause;
		cls;
	}
	else {
		cls;
		writedtf(vcshowtext, decimal, result);
		x = 0; y = 2;
		gotoxy(x, y);
		bool runningdtf = true;
		while (runningdtf) {
			gotoxy(x, y);
			int ch = _getch();
			if (CH_sS)
				y++;
			if (CH_wW)
				y--;
			if (y <= 2)
				y = 2;
			if (y >= 7)
				y = 7;

			//Ввод десятичной части
			if (y == 2 && ch == CH_enter) {
				decimal = NULL;
				cls;
				writedtf(vcshowtext, decimal, result);

				if (vcshowtext)
					doubleinput(decimal, 19, 2);
				else
					doubleinput(decimal, 1, 2);

				cls;
				writedtf(vcshowtext, decimal, result);
			}

			//Обработка
			if (y == 3 && ch == CH_enter) {
				result = decimalToFraction(decimal);
				result.toMixedFraction();
				cls;
				writedtf(vcshowtext, decimal, result);
			}

			//Выход
			if (y == 7 && ch == CH_enter) {
				runningdtf = false;
			}
		}
	}
}

void writetdap(bool showtext, Fraction frac, double decimal, double percent){
	cout << "   Превратить дробь в десятичное и проценты" << endl << endl;

	if (showtext) cout << " Целая часть:";
	cout << " " << frac.fullpart << endl;

	if (showtext) cout << " Числитель:";
	cout << " " << frac.numerator << endl;

	if (showtext) cout << " Знаменатель:";
	cout << " " << frac.denominator << endl;

	cout << " Вычислить" << endl;
	
	if (showtext) cout << " Десятичная:";
	cout << " " << decimal << endl;
	
	if (showtext) cout << " Проценты:";
	cout << " " << percent << "%" << endl;
	
	cout << " Выйти" << endl;
	//8

}

void vctdap(){
	Fraction frac = NULL_FRACTION;
	double decimal = 0;
	double percent = 0;

	if (profent){
		cls;
		if (vcshowtext) cout << "Введите целую часть: ";
		cin >> frac.fullpart;
		if (vcshowtext) cout << "Введите числитель: ";
		cin >> frac.numerator;
		if (vcshowtext) cout << "Введите знаменатель: ";
		cin >> frac.denominator;
		frac.toImproperFraction();
		double decimal = (double)frac.numerator / (double)frac.denominator;
		double percent = (double)frac.numerator / ((double)frac.denominator / 100);
		if (vcshowtext) cout << "Десятичная: ";
		cout << decimal << endl;
		if (vcshowtext) cout << "Процент: ";
		cout << percent << "%" << endl;
		pause;
		
	}
	else {
		cls;
		writetdap(vcshowtext, frac, decimal, percent);
		x = 0; y = 2;
		gotoxy(x, y);
		bool runningtdap = true;
		while (runningtdap) {
			gotoxy(x, y);
			int ch = _getch();
			if (CH_sS)
				y++;
			if (CH_wW)
				y--;
			if (y <= 2)
				y = 2;
			if (y >= 8)
				y = 8;

			//Ввод целой части
			if (y == 2 && ch == CH_enter) {
				frac.fullpart = NULL;
				cls;
				writetdap(vcshowtext, frac, decimal, percent);
				if (!vcshowtext)
					intinput(frac.fullpart, 1, 2);
				else
					intinput(frac.fullpart, 14, 2);
				cls;
				writetdap(vcshowtext, frac, decimal, percent);
			}

			//Ввод числителя
			if (y == 3 && ch == CH_enter) {
				frac.numerator = NULL;
				cls;
				writetdap(vcshowtext, frac, decimal, percent);
				if (!vcshowtext)
					intinput(frac.numerator, 1, 3);
				else
					intinput(frac.numerator, 12, 3);
				cls;
				writetdap(vcshowtext, frac, decimal, percent);
			}

			//Ввод знаменателя
			if (y == 4 && ch == CH_enter) {
				frac.denominator = NULL;
				cls;
				writetdap(vcshowtext, frac, decimal, percent);
				if (!vcshowtext)
					intinput(frac.denominator, 1, 4);
				else
					intinput(frac.denominator, 14, 4);
				cls;
				writetdap(vcshowtext, frac, decimal, percent);
			}

			//Обработка
			if (y == 5 && ch == CH_enter) {
				frac.toImproperFraction();
				decimal = (double)frac.numerator / (double)frac.denominator;
				percent = (double)frac.numerator / ((double)frac.denominator / 100);
				cls;
				writetdap(vcshowtext, frac, decimal, percent);
			}

			if (y == 8 && ch == CH_enter) {
				runningtdap = false;
			}
		}
	}
}

void writesqrt(bool showtext, double number, double result) {
	cout << " Найти квадратный корень" << endl << endl;

	if (showtext) cout << " Исходное число:";
	cout << " " << number << endl;

	cout << " Вычислить" << endl;

	if (showtext) cout << " Результат:";
	cout << " " << result << endl;

	cout << " Выйти" << endl;
}

void writecbrt(bool showtext, double number, double result) {
	cout << " Найти кубический корень" << endl << endl;

	if (showtext) cout << " Исходное число:";
	cout << " " << number << endl;

	cout << " Вычислить" << endl;

	if (showtext) cout << " Результат:";
	cout << " " << result << endl;

	cout << " Выйти" << endl;
}
//Найти кубический корень

void vccbrt() {
	
	double number = 0, result = 0;

	if (profent){
		cls;
		if (vcshowtext) cout << "Введите число: ";
		cin >> number;
		if (vcshowtext) cout << "Кубический корень числа: ";
		cout << cbrt(number);
		pause;
		cls;
	}
	else {
		cls;
		writecbrt(vcshowtext, number, result);
		x = 0; y = 2;
		gotoxy(x, y);
		bool runningsqrt = true;
		while (runningsqrt) {
			gotoxy(x, y);
			int ch = _getch();
			if (CH_sS)
				y++;
			if (CH_wW)
				y--;
			if (y <= 2)
				y = 2;
			if (y >= 5)
				y = 5;

			if (y == 2 && ch == CH_enter) {
				number = NULL;
				cls;
				writecbrt(vcshowtext, number, result);
				if (!vcshowtext)
					doubleinput(number, 1, 2);
				else
					doubleinput(number, 17, 2);
				cls;
				writecbrt(vcshowtext, number, result);
			}

			if (y == 3 && ch == CH_enter) {
				result = cbrt(number);
				cls;
				writecbrt(vcshowtext, number, result);
			}
			if (y == 5 && ch == CH_enter) {
				runningsqrt = false;
			}
		}
	}
}

//Найти квадратный корень

void vcsqrt() {
	double number = 0, result = 0;

	if (profent){
		cls;
		if (vcshowtext) cout << "Введите число: ";
		cin >> number;
		if (vcshowtext) cout << "Квадратный корень числа: ";
		cout << sqrt(number);
		pause; 
		cls;
	}
	else {
		cls;
		writesqrt(vcshowtext, number, result);
		x = 0; y = 2;
		gotoxy(x, y);
		bool runningsqrt = true;
		while (runningsqrt) {
			gotoxy(x, y);
			int ch = _getch();
			if (CH_sS)
				y++;
			if (CH_wW)
				y--;
			if (y <= 2)
				y = 2;
			if (y >= 5)
				y = 5;

			if (y == 2 && ch == CH_enter) {
				number = NULL;
				cls;
				writesqrt(vcshowtext, number, result);
				if (!vcshowtext)
					doubleinput(number, 1, 2);
				else
					doubleinput(number, 17, 2);
				cls;
				writesqrt(vcshowtext, number, result);
			}

			if (y == 3 && ch == CH_enter) {
				result = sqrt(number);
				cls;
				writesqrt(vcshowtext, number, result);
			}
			if (y == 5 && ch == CH_enter) {
				runningsqrt = false;
			}
		}
	}
	
}

//Найти корень
void writert(bool showtext, double number, double root, double result) {
	cout << "    Найти корень " << endl << endl;

	if (showtext) cout << " Исходное число:";
	cout << " " << number << endl;

	if (showtext) cout << " Корень:";
	cout << " " << root << endl;

	cout << " Вычислить" << endl;
	
	if (showtext) cout << " Результат:";
	cout << " " << result << endl;
	
	cout << " Выйти" << endl;
}
void vcrt() {
	double number = 0, root = 0, result = 0;
	if (profent){
		cls;

		if (vcshowtext) cout << "Введите число: ";
		cin >> number;
		if (vcshowtext) cout << "Введите корень: ";
		cin >> root;
		if (vcshowtext) cout << "Результат: ";
		cout << rt(number, root);
		pause;
		cls;

	}
	else {
		cls;
		writert(vcshowtext, number, root, result);
		x = 0; y = 2;
		gotoxy(x, y);
		bool runningrt = true;
		while (runningrt) {
			gotoxy(x, y);
			int ch = _getch();
			if (CH_sS)
				y++;
			if (CH_wW)
				y--;
			if (y <= 2)
				y = 2;
			if (y >= 6)
				y = 6;

			if (y == 2 && ch == CH_enter) {
				number = NULL;
				cls;
				writert(vcshowtext, number, root, result);
				if (!vcshowtext)
					doubleinput(number, 1, 2);
				else
					doubleinput(number, 17, 2);
				cls;
				writert(vcshowtext, number, root, result);
			}
			if (y == 3 && ch == CH_enter) {
				root = NULL;
				cls;
				writert(vcshowtext, number, root, result);
				if (!vcshowtext)
					doubleinput(root, 1, 3);
				else
					doubleinput(root, 9, 3);
				cls;
				writert(vcshowtext, number, root, result);
			}
			if (y == 4 && ch == CH_enter) {
				result = rt(number, root);
				cls;
				writert(vcshowtext, number, root, result);
			}


			if (y == 6 && ch == CH_enter) {
				runningrt = false;
			}
		}
	}
}

//Текст для калькулятора
void writecalc(bool showtext, double first, char operation, double second, double result) {
	cout << "   Калькулятор" << endl << endl;

	if (showtext) cout << " Первое число:";
	cout << " " << first << endl;
	if (showtext) cout << " Оператор: ";
	cout << " " << operation << endl;
	if (showtext) cout << " Второе число: ";
	cout << " " << second << endl;
	cout << " Вычислить" << endl;
	if (showtext) cout << " Результат: ";
	cout << " " << result << endl;
	cout << " Выйти" << endl;
}

//Текст для калькулятора процентов
void writecalcperc(bool showtext, double number, char operation, double percent, double result) {
	cout << " Калькултяор процентов" << endl << endl;
	if (showtext) cout << " Исходное число:";
	cout << " " << number << endl;
	
	if (showtext) cout << " Оператор:";
	cout << " " << operation << endl;
	
	if (showtext) cout << " Процент:";
	cout << " " << percent << endl;
	
	cout << " Вычислить" << endl;

	if (showtext) cout << " Результат:";
	cout << " " << result << endl;
	cout << " Выйти" << endl;

}

//Текст для калькулятора дробей
void writecalcfrac(bool showtext, Fraction first, char operation, Fraction second, Fraction result) {
	cout << "     Калькулятор дробей" << endl << endl;

	if (showtext) cout << " Целая часть первой дроби:";
	cout << " " << first.fullpart << endl;

	if (showtext) cout << " Числитель первой дроби:";
	cout << " " << first.numerator << endl;

	if (showtext) cout << " Знаменатель первой дроби:";
	cout << " " << first.denominator << endl;
	
	if (showtext) cout << " Оператор:";
	cout << " " << operation << endl;
	
	if (showtext) cout << " Целая часть второй дроби:";
	cout << " " << second.fullpart << endl;

	if (showtext) cout << " Числитель второй дроби:";
	cout << " " << second.numerator << endl;

	if (showtext) cout << " Знаменатель второй дроби:";
	cout << " " << second.denominator << endl;

	cout << " Вычислить" << endl;
	
	if (showtext) cout << " Целая часть результата:";
	cout << " " << result.fullpart << endl;

	if (showtext) cout << " Числитель результата:";
	cout << " " << result.numerator << endl;
	
	if (showtext) cout << " Знаменатель результата:";
	cout << " " << result.denominator << endl;
		 
	cout << " Выйти" << endl;
}

//Калькулятор дробей
void vccalcfrac() {
	bool itm = true;
	bool reduce = true;
	Fraction first, second, result;
	char operation = '+';
	cls;
	if (profent){
		if (vcshowtext) cout << "Введите целую часть первой дроби: ";
		cin >> first.fullpart;
		if (vcshowtext) cout << "Введите числитель первой дроби: ";
		cin >> first.numerator;
		if (vcshowtext) cout << "Введите знаменатель первой дроби: ";
		cin >> first.denominator;

		if (vcshowtext) cout << "Введите оператор (+, -, *, /): ";
		cin >> operation;

		if (vcshowtext) cout << "Введите целую часть второй дроби: ";
		cin >> second.fullpart;
		if (vcshowtext) cout << "Введите числитель второй дроби: ";
		cin >> second.numerator;
		if (vcshowtext) cout << "Введите знаменатель второй дроби: ";
		cin >> second.denominator;

		if (vcshowtext) cout << "Переводить в правильную дробь? 1 - Да, 0 - Нет: ";
		cin >> itm;
		if (vcshowtext) cout << "Сокращать результат? 1 - Да, 0 - Нет: ";
		cin >> reduce;

		if (operation == '+') {
			result = addFraction(first, second, itm, reduce);
			if (vcshowtext) cout << "Ответ: ";
			result.print();
		}
		else if (operation == '-') {
			result = subFraction(first, second, itm, reduce);
			if (vcshowtext) cout << "Ответ: ";
			result.print();
		}
		else if (operation == '*') {
			result = mulFraction(first, second, itm, reduce);
			if (vcshowtext) cout << "Ответ: ";
			result.print();
		}
		else if (operation == '/') {
			result = divFraction(first, second, itm, reduce);
			if (vcshowtext) cout << "Ответ: ";
			result.print();
		}
		pause;
		cls;
		
	}
	else {
		WCF;
		x = 0; y = 2;
		bool runningcalcfrac = true;
		while (runningcalcfrac) {
			gotoxy(x, y);
			int ch = _getch();
			if (CH_sS)
				y++;
			if (CH_wW)
				y--;
			if (y <= 2)
				y = 2;
			if (y >= 13)
				y = 13;

			//Ввод целой части первой дроби
			if (y == 2 && ch == CH_enter) {
				first.fullpart = NULL;
				cls;
				WCF;
				if (vcshowtext)
					intinput(first.fullpart, 27, y);
				else
					intinput(first.fullpart, 1, y);
				cls;
				WCF;
			}
			//Ввод числителя первой дроби
			if (y == 3 && ch == CH_enter) {
				first.numerator = NULL;
				cls;
				WCF;
				if (vcshowtext)
					intinput(first.numerator, 25, y);
				else
					intinput(first.numerator, 1, y);
				cls;
				WCF;
			}
			//Ввод знаменателя первой дроби
			if (y == 4 && ch == CH_enter) {
				first.denominator = NULL;
				cls;
				WCF;
				if (vcshowtext)
					intinput(first.denominator, 27, y);
				else
					intinput(first.denominator, 1, y);
				cls;
				WCF;
			}
			//Ввод оператора 
			if (y == 5 && ch == CH_enter) {
				operation = NULL;
				cls;
				WCF;
				if (vcshowtext)
					charinput(operation, 11, y);
				else
					charinput(operation, 1, y);
				cls;
				WCF;
			}


			//Ввод целой части второй дроби
			if (y == 6 && ch == CH_enter) {
				second.fullpart = NULL;
				cls;
				WCF;
				if (vcshowtext)
					intinput(second.fullpart, 27, y);
				else
					intinput(second.fullpart, 1, y);
				cls;
				WCF;
			}
			//Ввод числителя второй дроби
			if (y == 7 && ch == CH_enter) {
				second.numerator = NULL;
				cls;
				WCF;
				if (vcshowtext)
					intinput(second.numerator, 25, y);
				else
					intinput(second.numerator, 1, y);
				cls;
				WCF;
			}
			//Ввод знаменателя второй дроби
			if (y == 8 && ch == CH_enter) {
				second.denominator = NULL;
				cls;
				WCF;
				if (vcshowtext)
					intinput(second.denominator, 27, y);
				else
					intinput(second.denominator, 1, y);
				cls;
				WCF;
			}
			//Кнопка вычисления
			if (y == 9 && ch == CH_enter) {
				if (operation == '+') { result = addFraction(first, second, itm, reduce); cls; WCF; }
				else if (operation == '-') { result = subFraction(first, second, itm, reduce); cls; WCF; }
				else if (operation == '*') { result = mulFraction(first, second, itm, reduce); cls; WCF; }
				else if (operation == '/') { result = divFraction(first, second, itm, reduce); cls; WCF; }
			}
			if (y == 13 && ch == CH_enter) {
				runningcalcfrac = false;
			}
		}
	}
}

//Калькулятор процентов
void vccalcperc() {
	//Если что калькулятор процентов будет использовть тот же самый вывод, что и обычный калькулятор
	double first = 0, second = 0, result = 0;
	char operation = '+';
	cls;
	if (profent) {
		if (vcshowtext) cout << "Введите исходное число: ";
		cin >> first;
		if (vcshowtext) cout << "Введите действие (+, -, f, w, >, <, o): ";
		cin >> operation;
		if (vcshowtext) cout << "Введите процент: ";
		cin >> second;
		if (operation == '+') {
			if (vcshowtext) cout << "Ответ: ";
			cout << (first * (1 + second / 100)) << endl;
		}
		else if (operation == '-') {
			if (vcshowtext) cout << "Ответ: ";
			cout << (first * (1 - second / 100)) << endl;
		}
		else if (operation == 'f') {
			if (vcshowtext) cout << "Ответ: ";
			cout << (first * second / 100) << endl;
		}
		else if (operation == 'w') {
			if (vcshowtext) cout << "Ответ: ";
			cout << (first / second * 100) << endl;
		}
		else if (operation == '>') {
			if (vcshowtext) cout << "Ответ: ";
			cout << (first / second * 100 - 100) << endl;
		}
		else if (operation == '<') {
			if (vcshowtext) cout << "Ответ: ";
			cout << (100 - (first / second) * 100) << endl;
		}
		else if (operation == 'o') {
			if (vcshowtext) cout << "Ответ: ";
			cout << (first * 100 / second) << endl;
		}
		pause;
		cls;

	}
	else {
		writecalcperc(vcshowtext, first, operation, second, result);
		x = 0; y = 2;
		bool runningcalc = true;
		while (runningcalc) {
			gotoxy(x, y);
			int ch = _getch();
			if (CH_sS)
				y++;
			if (CH_wW)
				y--;
			if (y <= 2)
				y = 2;
			if (y >= 7)
				y = 7;

			//Ввод первого числа
			if (y == 2 && ch == CH_enter) {
				first = NULL;
				cls;
				writecalcperc(vcshowtext, first, operation, second, result);
				if (vcshowtext)
					doubleinput(first, 17, y);
				else
					doubleinput(first, 1, y);
				cls;
				writecalcperc(vcshowtext, first, operation, second, result);
			}
			//Ввод оператора
			else if (y == 3 && ch == CH_enter) {
				operation = NULL;
				cls;
				writecalcperc(vcshowtext, first, operation, second, result);
				if (vcshowtext)
					charinput(operation, 11, y);
				else
					charinput(operation, 1, y);
				cls;
				writecalcperc(vcshowtext, first, operation, second, result);
			}
			//Ввод второго числа
			else if (y == 4 && ch == CH_enter) {
				second = NULL;
				cls;
				writecalcperc(vcshowtext, first, operation, second, result);
				if (vcshowtext)
					doubleinput(second, 10, y);
				else
					doubleinput(second, 1, y);
				cls;
				writecalcperc(vcshowtext, first, operation, second, result);
			}

			//Вычисление
			else if (y == 5 && ch == CH_enter) {
				if (operation == '+') {
					result = (first * (1 + second / 100));
					cls;
					writecalcperc(vcshowtext, first, operation, second, result);
				}
				else if (operation == '-') {
					result = (first * (1 - second / 100));
					cls;
					writecalcperc(vcshowtext, first, operation, second, result);
				}
				else if (operation == 'f') {
					result = (first * second / 100);
					cls;
					writecalcperc(vcshowtext, first, operation, second, result);
				}
				else if (operation == 'w') {
					result = (first / second * 100);
					cls;
					writecalcperc(vcshowtext, first, operation, second, result);
				}
				else if (operation == '>') {
					result = (first / second * 100 - 100);
					cls;
					writecalcperc(vcshowtext, first, operation, second, result);
				}
				else if (operation == '<') {
					result = (100 - (first / second) * 100);
					cls;
					writecalcperc(vcshowtext, first, operation, second, result);
				}
				else if (operation == 'o') {
					result = (first * 100 / second);
					cls;
					writecalcperc(vcshowtext, first, operation, second, result);
				}

				else {
					gotoxy(0, 8);
					cout << "Вы ввели неправильный оператор!" << endl;
				}
			}


			else if (y == 7 && ch == 13) {
				cls;
				runningcalc = false;
				writefunctions();
			}
		}
	}
	
}

//Калькулятор
void vccalc() {
	double first = 0, second = 0, result = 0;
	char operation = '+';

	if (profent) {
		cls;
		if (vcshowtext)
			cout << "Введите первое число: ";
		cin >> first;
		if (vcshowtext)
			cout << "Введите действие (+, -, *, /, %, :, !, g, l): ";
		cin >> operation;
		if (vcshowtext)
			cout << "Введите второе число: ";
		cin >> second;
		if (operation == '+') {
			if (vcshowtext) cout << "Ответ: ";
			cout << first + second << endl;
		}
		else if (operation == '-') {
			if (vcshowtext) cout << "Ответ: ";
			cout << first - second << endl;
		}
		else if (operation == '*') {
			if (vcshowtext) cout << "Ответ: ";
			cout << first * second << endl;
		}
		else if (operation == '/' || operation == ':') {
			if (vcshowtext) cout << "Ответ: ";
			cout << first / second << endl;
		}
		else if (operation == '%') {
			if (vcshowtext) cout << "Ответ: ";
			cout << (int)first % (int)second << endl;
		}
		else if (operation == '^') {
			if (vcshowtext) cout << "Ответ: ";
			cout << pow(first, second) << endl;
		}
		else if (operation == '!') {
			if (vcshowtext) cout << "Ответ: ";
			cout << factorial(first + second) << endl;
		}
		else if (operation == 'g') {
			if (vcshowtext) cout << "Ответ: ";
			cout << gcd((int)first, (int)second) << endl;
		}
		else if (operation == 'l') {
			if (vcshowtext) cout << "Ответ: ";
			cout << lcm((int)first, (int)second) << endl;
		}
		pause;
		cls;
		writefunctions();
	}
	else {
		cls;
		writecalc(vcshowtext, first, operation, second, result);
		x = 0; y = 2;
		bool runningcalc = true;
		while (runningcalc) {
			gotoxy(x, y);
			int ch = _getch();
			if (CH_sS)
				y++;
			if (CH_wW)
				y--;
			if (y <= 2)
				y = 2;
			if (y >= 7)
				y = 7;

			//Ввод первого числа
			if (y == 2 && ch == CH_enter) {
				first = NULL;
				cls;
				writecalc(vcshowtext, first, operation, second, result);
				if (vcshowtext)
					doubleinput(first, 15, y);
				else
					doubleinput(first, 1, y);
				cls;
				writecalc(vcshowtext, first, operation, second, result);
			}
			//Ввод оператора
			else if (y == 3 && ch == CH_enter) {
				operation = NULL;
				cls;
				writecalc(vcshowtext, first, operation, second, result);
				if (vcshowtext)
					charinput(operation, 12, y);
				else
					charinput(operation, 1, y);
				cls;
				writecalc(vcshowtext, first, operation, second, result);
			}
			//Ввод второго числа
			else if (y == 4 && ch == CH_enter) {
				second = NULL;
				cls;
				writecalc(vcshowtext, first, operation, second, result);
				if (vcshowtext)
					doubleinput(second, 16, y);
				else
					doubleinput(second, 1, y);
				cls;
				writecalc(vcshowtext, first, operation, second, result);
			}

			//Вычисление
			else if (y == 5 && ch == CH_enter) {
				if (operation == '+') {
					result = first + second;
					cls;
					writecalc(vcshowtext, first, operation, second, result);
				}
				else if (operation == '-') {
					result = first - second;
					cls;
					writecalc(vcshowtext, first, operation, second, result);
				}
				else if (operation == '*') {
					result = first * second;
					cls;
					writecalc(vcshowtext, first, operation, second, result);
				}
				else if (operation == '/') {
					result = first / second;
					cls;
					writecalc(vcshowtext, first, operation, second, result);
				}
				else if (operation == '%') {
					result = (int)first % (int)second;
					cls;
					writecalc(vcshowtext, first, operation, second, result);
				}
				else if (operation == 'g') {
					result = gcd((int)first, (int)second);
					cls;
					writecalc(vcshowtext, first, operation, second, result);
				}
				else if (operation == 'l') {
					result = lcm((int)first, (int)second);
					cls;
					writecalc(vcshowtext, first, operation, second, result);
				}
				else if (operation == '!') {
					result = factorial(first + second);
					cls;
					writecalc(vcshowtext, first, operation, second, result);
				}
				else if (operation == '^') {
					result = pow(first, second);
					cls;
					writecalc(vcshowtext, first, operation, second, result);
				}

				else {
					gotoxy(0, 6);
					cout << "Вы ввели неправильный оператор!" << endl;
				}
			}


			else if (y == 7 && ch == 13) {
				runningcalc = false;
			}
		}
	}

}

//Все функции
void vcfunctions() {
	cls;
	writefunctions();
	x = 0; y = 0;
	gotoxy(x, y);
	bool runningfunctions = true;
	while (runningfunctions) {
		gotoxy(x, y);
		int ch = _getch();
		if (CH_sS)
			y++;
		if (CH_wW)
			y--;
		if (y <= 0)
			y = 0;
		if (y >= 19)
			y = 19;


		if (y == 0 && ch == CH_enter) {
			vccalc(); cls; writefunctions();
		}
		else if (y == 1 && ch == CH_enter) {
			vccalcperc(); cls; writefunctions();
		}
		else if (y == 2 && ch == CH_enter) {
			vccalcfrac(); cls; writefunctions();
		}
		else if (y == 3 && ch == CH_enter) {
			vcsqrt(); cls; writefunctions();
		}
		else if (y == 4 && ch == CH_enter) {
			vccbrt(); cls; writefunctions();
		}
		else if (y == 5 && ch == CH_enter) {
			vcrt(); cls; writefunctions();
		}
		else if (y == 6 && ch == CH_enter) {
			vctdap(); cls; writefunctions();
		}
		else if (y == 7 && ch == CH_enter) {
			vcdtf(); cls; writefunctions();
		}
		else if (y == 8 && ch == CH_enter) {
			vcitm(); cls; writefunctions();
		}
		else if (y == 9 && ch == CH_enter) {
			vctif(); cls; writefunctions();
		}
		else if (y == 10 && ch == CH_enter) {
			vcftf(); cls; writefunctions();
		}
		else if (y == 11 && ch == CH_enter) {
			vcprop3(); cls; writefunctions();
		}
		else if (y == 12 && ch == CH_enter) {
			vcfd(); cls; writefunctions();
		}
		else if (y == 13 && ch == CH_enter) {
			vcfp(); cls; writefunctions();
		}
		else if (y == 14 && ch == CH_enter) {
			vcmo(); cls; writefunctions();
		}
		else if (y == 15 && ch == CH_enter) {
			vcgcd(); cls; writefunctions();
		}
		else if (y == 16 && ch == CH_enter) {
			vclcm(); cls; writefunctions();
		}
		else if (y == 17 && ch == CH_enter) {
			vcian(); cls; writefunctions();
		}
		else if (y == 18 && ch == CH_enter) {
			vcsod(); cls; writefunctions();
		}
	

		else if (y == 19 && ch == CH_enter) 
			runningfunctions = false; cls; writefunctions();

		
	}
}

//Текст для настроек
void writesettings() {
	cout << " Показ текста: ";
	if (vcshowtext) cout << "Включено";
	else cout << "Выключено";
	cout << endl;


	cout << " Быстрый ввод: ";
	if (profent) cout << " Включено";
	else cout << " Выключено";
	cout << endl;

	cout << " Выйти" << endl;
}


void vcsettings() {
	cls;
	writesettings();
	x = 0; y = 0;
	gotoxy(x, y);
	bool runningsettings = true;
	while (runningsettings) {
		gotoxy(x, y);
		int ch = _getch();
		if (CH_sS)
			y++;
		if (CH_wW)
			y--;
		if (y <= 0)
			y = 0;
		if (y >= 2)
			y = 2;

		//Обработка включения/выключения показа текста
		if (y == 0 && CH_dD)
			vcshowtext = true; cls; writesettings();
		if (y == 0 && CH_aA)
			vcshowtext = false; cls; writesettings();

		
		if (y == 1 && CH_dD)
			profent = true; cls; writesettings();
		if (y == 1 && CH_aA)
			profent = false; cls; writesettings();


		if (y == 2 && ch == CH_enter)
			runningsettings = false;

	}
}

//Текст для выхода
void writeexit() {
	cout << " Выйти из программы" << endl;
	cout << " Отмена" << endl;
}

void vcexit() {
	cls;
	x = 0; y = 0;
	writeexit();
	gotoxy(x, y);
	bool runningexit = true;
	while (runningexit) {
		gotoxy(x, y);
		int ch = _getch();
		if (CH_sS)
			y++;
		if (CH_wW)
			y--;
		if (y <= 0)
			y = 0;
		if (y >= 1)
			y = 1;
		
		if (y == 0 && ch == CH_enter)
			exit(54);
		if (y == 1 && ch == CH_enter)
			runningexit = false;

	}
}

//Текст для вс режима
void writevcmode() {
	cout << " Помощь" << endl;
	cout << " Посмотреть все функции" << endl;
	cout << " Настройки программы" << endl;
	cout << " Выйти" << endl;
}

//Обработка логики вс режима
void vcmode() {
	cls;
	writevcmode();
	gotoxy(x, y);
	x = 0; y = 0;
	while (runningvcmode) {
		gotoxy(x, y);
		int ch = _getch();
		if (CH_sS)
			y++;
		if (CH_wW)
			y--;
		if (y <= 0)
			y = 0;
		if (y >= 3)
			y = 3;

		if (y == 3 && ch == CH_enter){
			vcexit(); vcmode();
		}

		else if (y == 2 && ch == CH_enter) {
			vcsettings(); vcmode();

		}
		else if (y == 1 && ch == CH_enter) {
			vcfunctions(); vcmode();
		}

		
	}
}
