//Файл для взаимодействия с программой

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <Windows.h>
#include "header.h"
using namespace std;
bool showtext = false;

//Инструкции по использованию чего то
void helpcalc() {
	cout << "В калькуляторе нет ничего прям удивительного но всё таки есть что рассказать." << endl;
	cout << "Можно начать с ввида записи чего то в калькулятор." << endl;
	cout << "Ну тут довольно всё просто, вводите первое число, действие, второе число. Потом вам выдается ответ." << endl;
	cout << "Есть всего 9 операторов действий." << endl;
	cout << "Первый это сложение, он выглядит вот так +. Он складывает к первому числу второе" << endl;
	cout << "Второй это вычитание, он выглядит вот так -. Он отнимает с первого числа второе" << endl;
	cout << "Третее это умножение, он выглядит вот так *. Он складывает первое число второе_число количество раз" << endl;
	cout << "Четвертое это деление, он выглядит вот так /. Он делит первое число на второе_число части" << endl;
	cout << "Пятое это это остаток от деления, он выглядит вот так %. Оно выдаёт остаток целой части от деления двух чисел" << endl;
	cout << "Шестое это :, делает тоже самое что и деление" << endl;
	cout << "Седьмое это факториал, он выглядит вот так !. Оно выводит факториал первое_число+второе_число" << endl;
	cout << "Восьмое это НОД, он выглядит вот так g." << endl;
	cout << "Девятое это НОК, он выглядит вот так l." << endl;
	cout << endl << endl;
	cout << "Вот пример записи:";
	cout << "3!2" << endl << "120" << endl;
	cout << "5!0" << endl << "120" << endl;
	cout << "59%3" << endl << "2" << endl;
}

void helpcalcfrac() {
	cout << "Для правильной работы с дробями надо ввести 9 параметров" << endl;
	cout << "Сначало вводим целую часть первой дроби, если её нет пишем 0" << endl;
	cout << "Вводим числитель первой дроби" << endl;
	cout << "Вводим знаментаель первой дроби" << endl;
	cout << "Вводим знак действия (+, -, *, /)" << endl;
	cout << "Вводим всё тоже самое для второй дроби только без знака действия" << endl;
	cout << "Дальше у нас есть три параметра на выбор" << endl;
	cout << "ОЧЕНЬ ВАЖНО ПОМНИТЬ что через каждый параметр нужно ставить пробел, в примере показано правильно как" << endl;
	cout << "Важно помнить что все дополнительные параметры включаются на 1, и выключатся на 0" << endl;
	cout << "itm или же перевод в правильную дробь (рекомендуется включить)" << endl;
	cout << "\tДопустим у нас дробь 7/3, и что бы такого результата в итоге не было включаем данный параметр символом 1" << endl;
	cout << "\tИ в итоге у нас получится из 7/3 в 2 1/3, что даёт нам правильный итоговый ответ" << endl;
	cout << "reduce или же сокращение дроби (рекомендуется включить)" << endl;
	cout << "\tДопустим у нас дробь 5/10, и для итогового ответа нам надо сократить дробь" << endl;
	cout << "\tC включенным данным параметр у нас из 5/10 сокращается в 1/2" << endl;
	cout << endl;
	cout << "Пример записи для пользователя: " << endl;
	cout << "calcfrac" << endl;
	cout << "5 1 4 / 0 4 5 1 1" << endl;
	cout << "6 9/16" << endl;
	cout << endl;
}

void helpcalcperc() {
	cout << "Первое число это исходное число или первое" << endl;
	cout << "Второе число это процент или второе число" << endl;
	cout << "Для прибавления процента к числу -> +" << endl;
	cout << "Для отнятия процента от числа -> -" << endl;
	cout << "Для нахождения процента от числа -> f" << endl;
	cout << "Для нахождения сколько процентов составляет число от числа -> w" << endl;
	cout << "Для нахождения сколько процентов одно число больше другого -> >" << endl;
	cout << "Для нахождения сколько процентов одно число меньше другого -> <" << endl;
	cout << "Для нахождения 100 процентов -> o" << endl;
	cout << endl << endl;
	cout << "Пример записи: " << endl;
	cout << "50+50" << endl << "75" << endl;
}

void help() {
	cout << "Инструкции использования программы: " << endl;
	cout << "Как использовать нахождение пропорции 3 дробей -> helpprop3" << endl;
	cout << "Как использовать калькулятор -> helpcalc" << endl;
	cout << "Как использовать калькулятор дробей -> helpcalcfrac" << endl;
	cout << "Как использовать калькулятор процентов -> helpcalcperc" << endl;


	cout << "Очистить всю консоль -> clear" << endl;
	cout << "Выйти из программы -> exit" << endl;
	cout << "Переход на репозиторий github -> github" << endl;
	cout << endl << endl;

	cout << "Калькулятор -> calc" << endl;
	cout << "Найти квадратный корень -> в калькуляторе возвести ваше число в степень 0.5" << endl;
	cout << "Найти кубический корень -> в калькуляторе возвсети ваше число в степень 0.333333333" << endl;
	cout << "Калькулятор процентов -> calcperc" << endl;
	cout << "В десятичную дробь и проценты -> tdap" << endl;
	cout << "Найти делители числа -> fd" << endl;
	cout << "Проверить на простое число -> fp" << endl;
	cout << "Перевести десятичную дробь в обыкновенную -> dtf" << endl;
	cout << "Из неправильно дроби в правильную -> itm" << endl;
	cout << "Калькулятор дробей -> calcfrac" << endl;
	cout << "Найти НОД -> gcd" << endl;
	cout << "Найти НОК -> lcm" << endl;
	cout << "В неправильную дробь -> tif" << endl;
	cout << "Найти пропорцию зная три дроби -> prop3" << endl;
	cout << "Из дроби с плавающей запятой в обыкновенную дробь -> ftf" << endl;
	cout << endl << endl;
	cout << "Другое: " << endl;
	cout << "Включить подсказки в функциях -> showtext" << endl;
	cout << "Выключить подсказки в функциях -> disabletext" << endl;
	cout << "Посмотреть статус показа текста -> checktext" << endl;
}


//Калькулятор
void calc(bool showtext) {
	double a, b;
	char c;
	if (showtext)
		cout << "Введите первое число: ";
	cin >> a;
	if (showtext)
		cout << "Введите действие (+, -, *, /, %, :, !, g, l): ";
	cin >> c;
	if (showtext)
		cout << "Введите второе число: ";
	cin >> b;
	if (c == '+')
		if (showtext) cout << "Ответ: " << a + b << endl;
		else cout << a + b << endl;
	else if (c == '-')
		if (showtext) cout << "Ответ: " << a - b << endl;
		else cout << a - b << endl;
	else if (c == '*')
		if (showtext) cout << "Ответ: " << a * b << endl;
		else cout << a * b << endl;
	else if (c == '/')
		if (showtext) cout << "Ответ: " << a / b << endl;
		else cout << a / b << endl;
	else if (c == '%')
		if (showtext) cout << "Ответ: " << (int)a % (int)b << endl;
		else cout << (int)a % (int)b << endl;
	else if (c == ':')
		if (showtext) cout << "Ответ: " << a / b << endl;
		else cout << a / b << endl;
	else if (c == '^')
		if (showtext) cout << "Ответ: " << pow(a, b) << endl;
		else cout << pow(a, b) << endl;
	else if (c == '!')
		if (showtext) cout << "Ответ: " << factorial(a + b) << endl;
		else cout << factorial(a + b) << endl;
	else if (c == 'g')
		if (showtext) cout << "Ответ: " << gcd((int)a, (int)b) << endl;
		else cout << gcd((int)a, (int)b) << endl;
	else if (c == 'l')
		if (showtext) cout << "Ответ: " << lcm(a, b) << endl;
		else cout << lcm((int)a, (int)b) << endl;
}

//Калькулятор процентов
void calcperc(bool showtext) {
	double n, p;
	char c;
	if (showtext) cout << "Введите исходное число: ";
	cin >> n;
	if (showtext) cout << "Введите действие (+, -, f, w, >, <, o): ";
	cin >> c;
	if (showtext) cout << "Введите процент: ";
	cin >> p;
	if (c == '+')
		if (showtext) cout << "Ответ: " << (n * (1 + p / 100)) << endl;
		else cout << (n * (1 + p / 100)) << endl;
	else if (c == '-')
		if (showtext) cout << "Ответ: " << (n * (1 + p / 100)) << endl;
		else cout << (n * (1 - p / 100)) << endl;
	else if (c == 'f')
		if (showtext) cout << "Ответ: " << (n * (1 + p / 100)) << endl;
		else cout << (n * p / 100) << endl;
	else if (c == 'w')
		if (showtext) cout << "Ответ: " << (n * (1 + p / 100)) << endl;
		else cout << (n / p * 100) << endl;
	else if (c == '>')
		if (showtext) cout << "Ответ: " << (n * (1 + p / 100)) << endl;
		else cout << (n / p * 100 - 100) << endl;
	else if (c == '<')
		if (showtext) cout << "Ответ: " << (n * (1 + p / 100)) << endl;
		else cout << (100 - (n / p) * 100) << endl;
	else if (c == 'o')
		if (showtext) cout << "Ответ: " << (n * (1 + p / 100)) << endl;
		else cout << (n * 100 / p) << endl;
}

//Превратить число в десятичное и проценты
void tdap(bool showtext) { //to decimal and procent
	Fraction result;

	if (showtext) cout << "Введите целую часть: ";
	cin >> result.fullpart;
	if (showtext) cout << "Введите числитель: ";
	cin >> result.numerator;
	if (showtext) cout << "Введите знаменатель: ";
	cin >> result.denominator;

	if (result.fullpart != 0)
		result.toImproperFraction();

	double decimal = (double)result.numerator / (double)result.denominator;
	double percent = (double)result.numerator / ((double)result.denominator / 100);
	if (showtext) cout << "Десятичная: " << decimal << endl << "Процент: " << percent << "%" << endl;
	else cout << decimal << endl << percent << "%" << endl;
}

//Проверить на простое число
void findPrime(bool showtext) {
	int num;
	if (showtext) cout << "Введите число: " << endl;
	cin >> num;
	if (isPrime(num))
		cout << "Число простое" << endl;
	else
		cout << "Число не простое" << endl;
}

//Посмотреть делители числа
void findDivisors(bool showtext) {
	int num;
	if (showtext) cout << "Введите число: " << endl;
	cin >> num;
	vector<int> divisors = Divisors(num);
	for (int div : divisors) {
		cout << div << ", ";
	}
	cout << endl;
}

//Из десятичной дроби в обыкновенную
void dtf(bool showtext) {
	double decimal;
	bool itm, reduce;
	Fraction result;
	if (showtext) cout << "Введите десятичную дробь: ";
	cin >> decimal;
	if (showtext) cout << "Сокращать число (1 - Да, 0 - Нет): ";
	cin >> reduce;
	if (showtext) cout << "Переводить в смешанную дробь (1 - Да, 0 - Нет): ";
	cin >> itm;
	result = decimalToFraction(decimal, itm, reduce);
	result.print();
}

//Из неправильной дроби в правильную
void itm(bool showtext) {
	Fraction user, result;
	if (showtext) cout << "Введите числитель: ";
	cin >> user.numerator;
	if (showtext) cout << "Введите знаменатель: ";
	cin >> user.denominator;
	result = improperToMixed(user.numerator, user.denominator);
	result.print();
}

//Калькулятор дробей
void calcfrac(bool showtext) {
	Fraction a, b, c;
	char action;
	bool itm, reduce;

	if (showtext) cout << "Введите целую часть первой дроби: ";
	cin >> a.fullpart;
	if (showtext) cout << "Введите числитель первой дроби: ";
	cin >> a.numerator;
	if (showtext) cout << "Введите знаменатель первой дроби: ";
	cin >> a.denominator;
	if (showtext) cout << "Введите действие (+, -, *, /): ";
	cin >> action;
	if (showtext) cout << "Введите целую часть второй дроби: ";
	cin >> b.fullpart;
	if (showtext) cout << "Введите числитель второй дроби: ";
	cin >> b.numerator;
	if (showtext) cout << "Ввеидте знаменатель второй дроби: ";
	cin >> b.denominator;
	if (showtext) cout << "Переводить в правильную дробь? 1 - Да, 0 - Нет: ";
	cin >> itm;
	if (showtext) cout << "Сокращать результат? 1 - Да, 0 - Нет: ";
	cin >> reduce;
	if (action == '+') {
		c = addFraction(a, b, itm, reduce);
		if (showtext) { cout << "Ответ: "; c.print(); }
		else c.print();
	}
	else if (action == '-') {
		c = subFraction(a, b, itm, reduce);
		if (showtext) { cout << "Ответ: "; c.print(); }
		else c.print();
	}
	else if (action == '*') {
		c = mulFraction(a, b, itm, reduce);
		if (showtext) { cout << "Ответ: "; c.print(); }
		else c.print();
	}
	else if (action == '/') {
		c = divFraction(a, b, itm, reduce);
		if (showtext) { cout << "Ответ: "; c.print(); }
		else c.print();
	}
	else
		cout << "Неправильное действие, на будущее есть только +, -, *, /" << endl;
}

void github() { system("start https://github.com/rucomen5978/math"); }


void tif(bool showtext) {
	Fraction frac1;
	if (showtext) cout << "Введите целую часть: ";
	cin >> frac1.fullpart;
	if (frac1.fullpart == 0) cout << "Если целая часть равна нулю, то зачем вам превращать в неправильную дробь?" << endl;
	else {

		if (showtext) cout << "Введите числитель: ";
		cin >> frac1.numerator;
		if (showtext) cout << "Введите знаменатель: ";
		cin >> frac1.denominator;

		frac1.toImproperFraction();
		if (showtext) cout << "Ответ: " << frac1.numerator << "/" << frac1.denominator << endl;
		else cout << frac1.numerator << "/" << frac1.denominator << endl;
	}
}

void findgcd(bool showtext) {
	int a, b;
	if (showtext) cout << "Введите первое число: ";
	cin >> a;
	if (showtext) cout << "Введите второе число: ";
	cin >> b;
	if (gcd(a, b) == 1 && showtext) cout << "Взаимно простые числа, либо же НОД = 1" << endl;
	else {
		if (showtext) cout << "Ответ: " << gcd(a, b) << endl;
		else cout << gcd(a, b) << endl;
		cout << a << "/" << gcd(a, b) << "=" << a / gcd(a, b) << endl;
		cout << b << "/" << gcd(a, b) << "=" << b / gcd(a, b) << endl;
	}
}

void findlcm(bool showtext) {
	int a, b;
	if (showtext) cout << "Введите первое число: ";
	cin >> a;
	if (showtext) cout << "Введите второе число: ";
	cin >> b;

	if (showtext) cout << "Ответ: " << lcm(a, b) << endl;
	else cout << lcm(a, b) << endl;
	cout << lcm(a, b) << "/" << a << "=" << lcm(a, b) / a << endl;
	cout << lcm(a, b) << "/" << b << "=" << lcm(a, b) / b << endl;
}

void findprop3(bool showtext) {
	Fraction frac1, frac2, frac3, result;

	if (showtext) cout << "Введите целую часть первой дроби: ";
	cin >> frac1.fullpart;
	if (showtext) cout << "Введите числитель первой дроби: ";
	cin >> frac1.numerator;
	if (showtext) cout << "Введите знаменатель первой дроби: ";
	cin >> frac1.denominator;
	if (showtext) cout << "Введите целую часть второй дроби: ";
	cin >> frac2.fullpart;
	if (showtext) cout << "Введите числитель второй дроби: ";
	cin >> frac2.numerator;
	if (showtext) cout << "Введите знаменатель второй дроби: ";
	cin >> frac2.denominator;
	if (showtext) cout << "Введите целую часть третьей дроби: ";
	cin >> frac3.fullpart;
	if (showtext) cout << "Введите числитель третьей дроби: ";
	cin >> frac3.numerator;
	if (showtext) cout << "Введите знаменатель третьей дроби: ";
	cin >> frac3.denominator;

	result = prop3(frac1, frac2, frac3);
	if (showtext) cout << "Целая часть: " << result.fullpart << " " << endl;
	else cout << result.fullpart << " ";
	if (showtext) cout << "Числитель: " << result.numerator << "/" << endl;
	else cout << result.numerator << " ";
	if (showtext) cout << "Знаменатель: " << result.denominator << endl;
	else cout << result.denominator << endl;
}

void helpprop3() {
	cout << "первая дробь    вторая дробь" << endl;
	cout << "------------    ------------" << endl;
	cout << " результат      третья дробь" << endl;
	cout << endl << "Результат находится с помощью умножения первой и третьей дроби и делением на вторую дробь." << endl;
}

void ian(bool showtext) { //info about number
	double number;
	if (showtext) cout << "Введите число: ";
	cin >> number;

	if (showtext) cout << "Квадрат числа: \t\t\t";
	cout << number * number << endl;

	if (showtext) cout << "Куб числа: \t\t\t";
	cout << number * number * number << endl;

	if (showtext) cout << "Квадратный корень числа: \t";
	cout << pow(number, 0.5) << endl;

	if (showtext) cout << "Кубический корень числа: \t";
	cout << pow(number, 0.33333333333333333333333333) << endl;

	if (showtext) cout << "Степень на себя: \t\t";
	cout << pow(number, number) << endl;

	if (showtext) cout << "Сложение чисел: \t\t";
	cout << sumOfDigits(number) << endl;

	if (showtext) cout << "Делители числа: \t\t";
	vector<int> divisors = Divisors(number);
	for (int div : divisors) {
		cout << div << " ";
	}
	cout << endl;

	if (showtext) cout << "Корень самого себя: \t\t";
	cout << pow(number, 1.0 / number) << endl;
	
	if (showtext) cout << "1 Делённый на число: \t\t";
	cout << 1 / number << endl;

	if (showtext) cout << "1 / (a / 100): \t\t\t";
	cout << 1 / (number / 100) << endl;
}

void ian2(bool showtext) {
	double number1, number2;
	if (showtext) cout << "Введите первое число: ";
	cin >> number1;
	if (showtext) cout << "Введите второе число: ";
	cin >> number2;

	if (showtext) cout << "Сложение чисел: ";
	cout << number1 + number2 << endl;
	if (showtext) cout << "Вычитание чисел: ";
	cout << number1 - number2 << endl;
	if (showtext) cout << "Умножение чисел: ";
	cout << number1 * number2 << endl;
	if (showtext) cout << "Деление чисел: ";
	cout << number1 / number2 << endl;
	if (showtext) cout << "Остаток от деления: ";
	cout << (int)number1 % (int)number2 << endl;

	if (showtext) cout << "НОД: ";
	cout << gcd(number1, number2) << endl;
	
	if (showtext) cout << "НОК: ";
	cout << lcm(number1, number2) << endl;

	if (gcd(number1, number2) != 1) {
		if (showtext) cout << number1 << " / " << gcd(number1, number2) << ": ";
		cout << number1 / gcd(number1, number2) << endl;
		if (showtext) cout << number2 << " / " << gcd(number1, number2) << ": ";
		cout << number2 / gcd(number1, number2) << endl;
	}
	
	if (showtext) cout << lcm(number1, number2) << " / " << number1 << ": ";
	cout << lcm(number1, number2) / number1 << endl;
	if (showtext) cout << lcm(number1, number2) << " / " << number2 << ": ";
	cout << lcm(number1, number2) / number2 << endl;
	
	if (showtext) cout << number2 << " Корень " << number1 << ": ";
	cout << pow(number1, 1.0 / number2) << endl;

	if (showtext) cout << number1 << "^" << number2 << ": ";
	cout << pow(number1, number2) << endl;

	if (showtext) cout << "Умноженное сложение чисел: ";
	cout << sumOfDigits(number1 * number2) << endl;

}

void ftf(bool showtext) {
	double a, b;
	bool itm, reduce;

	if (showtext) cout << "Введите числитель: ";
	cin >> a;
	if (showtext) cout << "Введите знаменатель: ";
	cin >> b;
	if (showtext) cout << "Превращать в смешанную дробь? (1 - Да, 0 - Нет): ";
	cin >> itm;
	if (showtext) cout << "Сокращать дробь? (1 - Да, 0 - Нет): ";
	cin >> reduce;
	Fraction result;
	result = floatToFraction(a, b, itm, reduce);
	result.print();
}

void consolemenu() {
	string action;
	cout << ":";
	cin >> action;

	if (action == "helpcalc")
		helpcalc();
	else if (action == "helpcalcfrac")
		helpcalcfrac();
	else if (action == "helpcalcperc")
		helpcalcperc();
	else if (action == "helpprop3")
		helpprop3();

	else if (action == "github")
		github();

	else if (action == "help")
		help();
	else if (action == "calc")
		calc(showtext);
	else if (action == "calcperc")
		calcperc(showtext);
	else if (action == "tdap")
		tdap(showtext);
	else if (action == "fd")
		findDivisors(showtext);
	else if (action == "fp")
		findPrime(showtext);
	else if (action == "dtf")
		dtf(showtext);
	else if (action == "itm")
		itm(showtext);
	else if (action == "calcfrac")
		calcfrac(showtext);
	else if (action == "clear")
		system("cls");
	else if (action == "tif")
		tif(showtext);
	else if (action == "gcd")
		findgcd(showtext);
	else if (action == "lcm")
		findlcm(showtext);
	else if (action == "prop3")
		findprop3(showtext);
	else if (action == "ftf")
		ftf(showtext);
	else if (action == "ian")
		ian(showtext);
	else if (action == "ian2")
		ian2(showtext);
	else if (action == "exit")
		exit(0);

	else if (action == "showtext") {
		cout << "Подсказки в функциях были включены" << endl;
		showtext = true;
	}
	else if (action == "disabletext") {
		cout << "Подсказки в функциях были отключены" << endl;
		showtext = false;
	}
	else if (action == "checktext")
		cout << showtext << endl;

	consolemenu();
}
