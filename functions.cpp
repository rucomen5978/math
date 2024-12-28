//Файл который выдаёт результаты всех функций

#include "header.h"
#include <cmath>
#include <vector>
#include <string>
//Нахождение нода
int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

//Нахождение нока
int lcm(int a, int b) { return (a * b) / gcd(a, b); }

//Нахождение цетра
int center(int window, int object) { return (window / 2) - (object / 2); }

//Проверка на простое число
bool isPrime(int num) {
	if (num <= 1) {
		return false;
	}
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

//Нахождение делителей числа
std::vector<int> Divisors(int num) {
	std::vector<int> divisors;
	for (int i = 1; i <= num; i++) {
		if (num % i == 0) {
			divisors.push_back(i);
		}
	}
	return divisors;
}

//Из десятичной дроби в обыкновенную
Fraction decimalToFraction(double decimal, bool itm, bool reduce) {
	Fraction result;
	
	result.numerator = static_cast<int>(decimal * 10);
	result.denominator = 10;
	while (std::floor(result.numerator) != result.numerator) {
		result.numerator *= 10;
		result.denominator *= 10;
	}

	if (reduce) {
		int gcdval = gcd(result.denominator, result.numerator);
		result.numerator /= gcdval;
		result.denominator /= gcdval;
	}
	
	if (itm) {
		result.toMixedFraction();
	}

	return result;
}

//В смешанную дробь
Fraction improperToMixed(int numerator, int denominator) {
	Fraction result;
	result.numerator = numerator;
	result.denominator = denominator;
	result.toMixedFraction();
	return result;
}

Fraction toImporperFraction(Fraction frac1) {
	frac1.toImproperFraction();
	return frac1;
}

//Нахождение факториала
int factorial(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result = result * i;
	}
	return result;
}

//Добавить дробь
Fraction addFraction(Fraction frac1, Fraction frac2, bool itm, bool reduce) {
	Fraction result;

	// Преобразуем обе дроби в неправильные
	frac1.toImproperFraction();
	frac2.toImproperFraction();

	// Находим общий знаменатель
	int cd = lcm(frac1.denominator, frac2.denominator);

	// Находим множитель для числителя обоих дробей
	frac1.ntmb = cd / frac1.denominator;
	frac2.ntmb = cd / frac2.denominator;

	// Умножаем числители и изменяем знаменатели дробей на общий знаменатель
	frac1.numerator *= frac1.ntmb;
	frac2.numerator *= frac2.ntmb;

	// Складываем числители
	result.numerator = frac1.numerator + frac2.numerator;
	result.denominator = cd;

	// Выполнение дополнительных действий
	// Сокращение дроби, если требуется
	if (reduce) {
		int fracgcd = gcd(result.numerator, result.denominator);
		result.numerator /= fracgcd;
		result.denominator /= fracgcd;
	}

	// Преобразование в смешанную дробь, если требуется
	if (itm) {
		result.toMixedFraction();
	}

	return result;
}


Fraction subFraction(Fraction frac1, Fraction frac2, bool itm, bool reduce) {
	Fraction result;

	// Преобразуем обе дроби в неправильные
	frac1.toImproperFraction();
	frac2.toImproperFraction();

	// Находим общий знаменатель
	int cd = lcm(frac1.denominator, frac2.denominator);

	// Находим множитель для числителя обоих дробей
	frac1.ntmb = cd / frac1.denominator;
	frac2.ntmb = cd / frac2.denominator;

	// Умножаем числители и приводим знаменатели к общему знаменателю
	frac1.numerator *= frac1.ntmb;
	frac2.numerator *= frac2.ntmb;

	// Выполняем вычитание
	result.numerator = frac1.numerator - frac2.numerator;
	result.denominator = cd;

	// Выполняем дополнительные действия
	// Сокращение дроби, если требуется
	if (reduce) {
		int fracgcd = gcd(result.numerator, result.denominator);
		result.numerator /= fracgcd;
		result.denominator /= fracgcd;
	}

	// Преобразование в смешанную дробь, если требуется
	if (itm) {
		result.toMixedFraction();
	}

	return result;
}


Fraction mulFraction(Fraction frac1, Fraction frac2, bool itm, bool reduce) {
    Fraction result;

    // Перевод в неправильную дробь
    frac1.toImproperFraction();
    frac2.toImproperFraction();

    // Выполнение действия
    result.numerator = frac1.numerator * frac2.numerator;
    result.denominator = frac1.denominator * frac2.denominator; // Исправлено

    // Сначала выполняем сокращение, если нужно
    if (reduce) {
        int fracgcd = gcd(result.numerator, result.denominator);
        result.numerator /= fracgcd;
        result.denominator /= fracgcd;
    }

    // Преобразование в смешанную дробь, если требуется
    if (itm) {
        result.toMixedFraction();
    }

    return result;
}

//Разделить дробь
Fraction divFraction(Fraction frac1, Fraction frac2, bool itm, bool reduce) {
    Fraction result;

    // Переводим обе дроби в неправильные дроби
    frac1.toImproperFraction();
    frac2.toImproperFraction();

    // Выполнение действия деления
    result.numerator = frac1.numerator * frac2.denominator;
    result.denominator = frac1.denominator * frac2.numerator;

    // Сначала выполняем сокращение, если нужно
    if (reduce) {
        int fracgcd = gcd(result.numerator, result.denominator);
        result.numerator /= fracgcd;
        result.denominator /= fracgcd;
    }

    // Преобразование в смешанную дробь, если требуется
    if (itm) {
        int counter = 0;

        // Преобразуем неправильную дробь в смешанную
        while (result.numerator >= result.denominator) {
            result.numerator -= result.denominator;
            counter++;
        }

        // Обновляем числитель и целую часть
        result.fullpart = counter;
    }

    return result;
}

Fraction floatToFraction(double num1, double num2, bool itm, bool reduce) {
	// Преобразуем дроби в целые числа, умножив их на степень 10, чтобы избавиться от плавающей точки
	int scale = 1000000; // Степень 10 для преобразования до целых чисел (например, до 6 знаков после запятой)
	int numerator = static_cast<int>(num1 * scale);
	int denominator = static_cast<int>(num2 * scale);

	// Нахождение НОД для упрощения дроби
	int gcd_val = gcd(numerator, denominator);

	// Упрощение дроби
	if (reduce){
		numerator /= gcd_val;
		denominator /= gcd_val;
	}
	

	// Теперь можно преобразовать эту дробь в смешанную
	Fraction frac;
	frac.numerator = numerator;
	frac.denominator = denominator;

	// Преобразуем её в смешанную дробь
	if (itm) {
		frac.toMixedFraction();
	}
	return frac;
}

//Нахождение пропорции из трёх дробей
Fraction prop3(Fraction frac1, Fraction frac2, Fraction frac3){
	//ВАЖНО ПОНИМАТЬ ЧТО ПРОГРАММА РАБОТАЕТ ТАКИМ ОБРАЗОМ
	//   frac1      frac2
	//   ------	    -----
	//	 result	    frac3

	//Превращаем все дроби в неправильные
	frac1.toImproperFraction();
	frac2.toImproperFraction();
	frac3.toImproperFraction();

	//Умножаем первую дробь с третьей
	frac1.denominator *= frac3.denominator;
	frac1.numerator *= frac3.numerator;

	//Делим результат записанный в первую дробь на вторую дробь
	frac1 = divFraction(frac1, frac2, false, false);
	
	//Переводим в правильную дробь
	frac1.toMixedFraction();
	return frac1;
}

int sumOfDigits(double number) {
	std::string numberStr = std::to_string(number); // Преобразуем число в строку
	int sum = 0;

	for (char digit : numberStr) {
		if (isdigit(digit)) { // Проверяем, является ли символ цифрой
			sum += digit - '0'; // Преобразуем символ в цифру и добавляем к сумме
		}
	}

	// Суммируем цифры, пока не останется одна цифра
	while (sum >= 10) {
		int tempSum = 0;
		while (sum > 0) {
			tempSum += sum % 10; // Добавляем последнюю цифру к временной сумме
			sum /= 10; // Убираем последнюю цифру
		}
		sum = tempSum; // Обновляем сумму
	}
	return sum; // Возвращаем единственную цифру
}
