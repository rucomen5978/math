#pragma once
#include <vector>

int center(int window, int object);
bool isPrime(int num);

// Объявление функции для нахождения НОД
int gcd(int a, int b);

// Объявление функции для нахождения НОК
int lcm(int a, int b);

std::vector<int> Divisors(int num);

int factorial(int n);

// Объявление структуры Fraction
struct Fraction {
    //Целая часть
    int fullpart = 0;
    //Числитель
    int numerator = 0;
    //Знаменатель 
    int denominator = 0;
    //Множитель для числителя
    int ntmb = 0;

    // В неправильную дробь
    void toImproperFraction() {
        if (fullpart != 0) {
            numerator = fullpart * denominator + numerator;
            fullpart = 0;
        }
    }

    void toMixedFraction() {
        fullpart = numerator / denominator;
        numerator %= denominator;
    }

};

Fraction decimalToFraction(double decimal);

Fraction improperToMixed(int numerator, int denominator);

// Объявление функции для сложения дробей
Fraction addFraction(Fraction frac1, Fraction frac2, bool itm, bool reduce);

// Объявление функции для вычитания дробей
Fraction subFraction(Fraction frac1, Fraction frac2, bool itm, bool reduce);

// Объявление функции для умножения дробей
Fraction mulFraction(Fraction frac1, Fraction frac2, bool itm, bool reduce);

// Объявление функции для деления дробей
Fraction divFraction(Fraction frac1, Fraction frac2, bool itm, bool reduce);