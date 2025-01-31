#pragma once
#include <vector>
#include <string>
#include <iostream>
int center(int window, int object);
bool isPrime(int num);

#define CH_s 115
#define CH_S 83
#define CH_sS ch==115||ch==83

#define CH_a 97
#define CH_A 65
#define CH_aA ch==97||ch == 65

#define CH_d 100
#define CH_D 68
#define CH_dD ch==100||ch==68

#define CH_w 119
#define CH_W 87
#define CH_wW ch==119||ch==87

#define CH_enter 13
#define cls system("cls")

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
        numerator = fullpart * denominator + numerator;
        fullpart = 0;
    }

    void toMixedFraction() {
        fullpart = numerator / denominator;
        numerator %= denominator;
    }

    void reduce() {
        numerator /= gcd(numerator, denominator);
        denominator /= gcd(numerator, denominator);
    }

    void print() const {
        if (fullpart != 0) {
            std::cout << fullpart << " ";
        }
        if (numerator != 0) {
            std::cout << numerator << "/" << denominator;
        }
        if (fullpart == 0 && numerator == 0) {
            std::cout << 0;
        }
        std::cout << std::endl;
    }

};

struct doubleFraction {
    double fullpart = 0;
    double numerator = 0;
    double denominator = 0;
    double ntmb = 0;
    void toImproperFraction() {
        numerator = fullpart * denominator + numerator;
        fullpart = 0;
    }
    void print() {
        if (fullpart != 0)
            std::cout << fullpart << " ";
        if (numerator != 0)
            std::cout << numerator << "/" << denominator;
        if (fullpart == 0 && numerator == 0)
            std::cout << 0;
        std::cout << std::endl;
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

Fraction toImporperFraction(Fraction frac1);

Fraction prop3(Fraction frac1, Fraction frac2, Fraction frac3);

Fraction floatToFraction(double num1, double num2, bool itm, bool reduce);

int sumOfDigits(double number);

double rt(double number, double root);

//Консольный режим
void consolemenu();

void vcmode();
