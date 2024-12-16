#include "header.h"
#include <cmath>
#include <vector>
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
Fraction decimalToFraction(double decimal) {
	int sign = (decimal < 0) ? -1 : 1;
	decimal = fabs(decimal);
	int decimalPlaces = 0;
	while (fmod(decimal, 1) != 0) {
		decimal *= 10;
		decimalPlaces++;
	}
	int denominator = static_cast<int>(pow(10, decimalPlaces));
	int numerator = static_cast<int>(decimal * sign);
	int commonDivisor = gcd(abs(numerator), denominator);
	numerator /= commonDivisor;
	denominator /= commonDivisor;
	Fraction result;
	result.denominator = denominator;
	result.numerator = numerator;
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
	
	int cd = lcm(frac1.denominator, frac2.denominator);

	//нахождение множителя для числителя обоих дробей
	frac1.ntmb = cd / frac1.denominator;
	frac2.ntmb = cd / frac2.denominator;

	//умножение числителей, и изменение знаменателей дробей на общее
	frac1.numerator *= frac1.ntmb;
	frac1.denominator = cd;

	frac2.numerator *= frac2.ntmb;
	frac2.denominator = cd;

	//выполнение действия
	result.fullpart = frac1.fullpart + frac2.fullpart;
	result.numerator = frac1.numerator + frac2.numerator;
	result.denominator = cd;

	//выполнение дополнительных действий
	if (itm == true) {
		int lnv = 0;
		int counter = 0;

		// Преобразуем неправильную дробь в смешанную
		while (result.numerator >= result.denominator) {
			result.numerator -= result.denominator;
			counter++;
		}

		// Обновляем числитель и целую часть
		result.fullpart += counter;
		if (result.numerator < 0) {
			result.numerator += result.denominator; // Делаем числитель положительным
			result.fullpart--; // Уменьшаем целую часть, чтобы компенсировать
			
		}
	}
	else if (reduce == true) {
		int fracgcd = gcd(result.denominator, result.numerator);
		result.denominator = result.denominator / fracgcd;
		result.numerator = result.numerator / fracgcd;
	}
	return result;
}

//Отнять дробь
Fraction subFraction(Fraction frac1, Fraction frac2, bool itm, bool reduce) {
	Fraction result;

	int cd = lcm(frac1.denominator, frac2.denominator);

	//нахождение множителя для числителя обоих дробей
	frac1.ntmb = cd / frac1.denominator;
	frac2.ntmb = cd / frac2.denominator;

	//умножение числителей, и изменение знаменателей дробей на общее
	frac1.numerator *= frac1.ntmb;
	frac1.denominator = cd;

	frac2.numerator *= frac2.ntmb;
	frac2.denominator = cd;

	//выполнение действия
	result.fullpart = frac1.fullpart - frac2.fullpart;
	result.numerator = frac1.numerator - frac2.numerator;
	result.denominator = cd;

	//выполнение дополнительных действий
	if (itm == true) {
		int lnv = 0;
		int counter = 0;

		// Преобразуем неправильную дробь в смешанную
		while (result.numerator >= result.denominator) {
			result.numerator -= result.denominator;
			counter++;
		}

		// Обновляем числитель и целую часть
		result.fullpart += counter;
		if (result.numerator < 0) {
			result.numerator += result.denominator; // Делаем числитель положительным
			result.fullpart--; // Уменьшаем целую часть, чтобы компенсировать

		}
	}
	else if (reduce == true) {
		int fracgcd = gcd(result.denominator, result.numerator);
		result.denominator = result.denominator / fracgcd;
		result.numerator = result.numerator / fracgcd;
	}

	return result;
}

//Умножить дробь
Fraction mulFraction(Fraction frac1, Fraction frac2, bool itm, bool reduce) {
	Fraction result;

	//Перевод в неправильую дробь
	frac1.toImproperFraction();
	frac2.toImproperFraction();

	//Выполнение действия
	result.numerator = frac1.numerator * frac2.numerator;
	result.denominator = frac1.numerator * frac2.denominator;

	if (itm == true) {
		int lnv = 0;
		int counter = 0;

		// Преобразуем неправильную дробь в смешанную
		while (result.numerator >= result.denominator) {
			result.numerator -= result.denominator;
			counter++;
		}

		// Обновляем числитель и целую часть
		result.fullpart += counter;
		if (result.numerator < 0) {
			result.numerator += result.denominator; // Делаем числитель положительным
			result.fullpart--; // Уменьшаем целую часть, чтобы компенсировать

		}
	}
	else if (reduce == true) {
		int fracgcd = gcd(result.denominator, result.numerator);
		result.denominator = result.denominator / fracgcd;
		result.numerator = result.numerator / fracgcd;
	}

	return result;
}

//Разделить дробь
Fraction divFraction(Fraction frac1, Fraction frac2, bool itm, bool reduce) {
	Fraction result;

	//Перевод в неправильую дробь
	frac1.toImproperFraction();
	frac2.toImproperFraction();

	//Выполнение действия
	result.numerator = frac1.numerator * frac2.denominator;
	result.denominator = frac1.denominator * frac2.numerator;

	if (itm == true) {
		int lnv = 0;
		int counter = 0;

		// Преобразуем неправильную дробь в смешанную
		while (result.numerator >= result.denominator) {
			result.numerator -= result.denominator;
			counter++;
		}

		// Обновляем числитель и целую часть
		result.fullpart += counter;
		if (result.numerator < 0) {
			result.numerator += result.denominator; // Делаем числитель положительным
			result.fullpart--; // Уменьшаем целую часть, чтобы компенсировать

		}
	}
	else if (reduce == true) {
		int fracgcd = gcd(result.denominator, result.numerator);
		result.denominator = result.denominator / fracgcd;
		result.numerator = result.numerator / fracgcd;
	}

	return result;
}
