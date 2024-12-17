#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <Windows.h>
#include "header.h"
#include <SDL.h>
#include <SDL_ttf.h>
using namespace std;
bool showtext = false;

struct Button {
	SDL_Rect rect;
	SDL_Color color;

	void render(SDL_Renderer* renderer) {
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
		SDL_RenderFillRect(renderer, &rect);
	}

	bool isClicked(int x, int y) {
		return (x >= rect.x && x <= (rect.x + rect.w) && y >= rect.y && y <= (rect.y + rect.w));
	}

	void changeColor(int r, int g, int b) {
		color.r = r;
		color.g = g;
		color.b = b;
	}

	void moveTo(int x, int y) {
		rect.x = x;
		rect.y = y;
	}
};

struct Fonts {
	TTF_Font* arial_60 = TTF_OpenFont("arial.ttf", 60);
	TTF_Font* arial_50 = TTF_OpenFont("arial.ttf", 50);
	TTF_Font* arial_40 = TTF_OpenFont("arial.ttf", 40);
	TTF_Font* arial_30 = TTF_OpenFont("arial.ttf", 30);

	SDL_Color white = { 255,255,255,255 };
	SDL_Color black = { 0, 0, 0, 255 };
};

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
	cout << endl << endl;
	cout << "Другое: " << endl;
	cout << "Визуальный режим (бета) -> visual" << endl;
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
void tdap(bool showtext) {
	double first, second;
	if (showtext) cout << "Введите числитель: ";
	cin >> first;
	if (showtext) cout << "Введите знаменатель: ";
	cin >> second;

	if (showtext) {
		cout << "Десятичная: " << first / second << endl;
		cout << "Проценты: " << first / (second / 100) << endl;
	}
	else cout << first / second << endl << first / (second / 100) << endl;
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
	Fraction result;
	if (showtext) cout << "Введите десятичную дробь: ";
	cin >> decimal;
	result = decimalToFraction(decimal);
	cout << result.numerator << "/" << result.denominator << endl;
}

//Из неправильной дроби в правильную
void itm(bool showtext) {
	Fraction user, result;
	if (showtext) cout << "Введите числитель: ";
	cin >> user.numerator;
	if (showtext) cout << "Введите знаменатель: ";
	cin >> user.denominator;
	result = improperToMixed(user.numerator, user.denominator);
	cout << result.fullpart << " " << result.numerator << "/" << result.denominator << endl;
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
	if (action == '+'){
		c = addFraction(a, b, itm, reduce);
		if (showtext) cout << "Ответ: " << c.fullpart << " " << c.numerator << "/" << c.denominator << endl;
		else cout << c.fullpart << " " << c.numerator << "/" << c.denominator << endl;
	}
	else if (action == '-') {
		c = subFraction(a, b, itm, reduce);
		if (showtext) cout << "Ответ: " << c.fullpart << " " << c.numerator << "/" << c.denominator << endl;
		else cout << c.fullpart << " " << c.numerator << "/" << c.denominator << endl;
	}
	else if (action == '*'){
		c = mulFraction(a, b, itm, reduce);
		if (showtext) cout << "Ответ: " << c.fullpart << " " << c.numerator << "/" << c.denominator << endl;
		else cout << c.fullpart << " " << c.numerator << "/" << c.denominator << endl;
	}
	else if (action == '/') {
		c = divFraction(a, b, itm, reduce);
		if (showtext) cout << "Ответ: " << c.fullpart << " " << c.numerator << "/" << c.denominator << endl;
		else cout << c.fullpart << " " << c.numerator << "/" << c.denominator << endl;
	}
	else
		cout << "Неправильное действие, на будущее есть только +, -, *, /" << endl;
}

void github() {
	system("start https://github.com/rucomen5978/math");
}

void visual() {
	Fonts fonts;
	cout << "Создание шрифтов для текста" << endl;
	if (fonts.arial_60 == nullptr)cout << "Не удалось инициализировать шрифт arial.ttf, 60" << endl;
	else cout << "Инициализирован шрифт arial.ttf, 60" << endl;
	if (fonts.arial_50 == nullptr)cout << "Не удалось инициализировать шрифт arial.ttf, 50" << endl;
	else cout << "Инициализирован шрифт arial.ttf, 50" << endl;
	if (fonts.arial_40 == nullptr)cout << "Не удалось инициализировать шрифт arial.ttf, 40" << endl;
	else cout << "Инициализирован шрифт arial.ttf, 40" << endl;
	if (fonts.arial_30 == nullptr)cout << "Не удалось инициализировать шрифт arial.ttf, 30" << endl;
	else cout << "Инициализирован шрифт arial.ttf, 30" << endl;



	const int WINDOW_WIDTH = 1280;
	const int WINDOW_HEIGHT = 720;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	cout << "Создание окна и рендерера" << endl;
	window = SDL_CreateWindow("math", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr) cout << "Ошибка инициализации окна" << endl;
	else cout << "Инициализировано окно" << endl;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr) cout << "Ошибка инициализации рендерера" << endl;
	else cout << "Инициализирован рендерер" << endl;


	

	//Создание кнопки
	Button exit_button = { {WINDOW_WIDTH-320, WINDOW_HEIGHT-100, 300, 80},{255,255,255,255} };
	cout << "Создана кнопка выхода" << endl;

	//Создание текста для кнопки выхода
	SDL_Surface* exit_text_main_surface = TTF_RenderUTF8_Solid(fonts.arial_60, u8"Выйти", fonts.black);
	SDL_Texture* exit_text_main_texture = SDL_CreateTextureFromSurface(renderer, exit_text_main_surface);
	SDL_Rect exit_text_main_rect = {WINDOW_WIDTH-320, WINDOW_HEIGHT-100, exit_text_main_surface->w, exit_text_main_surface->h};
	if (exit_text_main_surface == nullptr) cout << "Не удалось сделать поверхность текста для кнопки выхода" << endl;
	else cout << "Создана поверхность текста для кнопки выхода" << endl;
	if (exit_text_main_texture == nullptr) cout << "Не удалось сделать текстуру текста для кнопки выхода" << endl;
	else cout << "Создана текстура текста для кнопки выхода" << endl;


	SDL_FreeSurface(exit_text_main_surface);

	bool running = true;
	SDL_Event event;
	int mouseX, mouseY;
	while (running) {
		SDL_GetMouseState(&mouseX, &mouseY);
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}

			if (exit_button.isClicked(mouseX, mouseY)) {
				exit_button.changeColor(200, 200, 200);
				if (event.type == SDL_MOUSEBUTTONDOWN) {
					running = false;
				}
			}

			if (!exit_button.isClicked(mouseX, mouseY)) {
				exit_button.changeColor(255, 255, 255);
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		exit_button.render(renderer);
		SDL_RenderCopy(renderer, exit_text_main_texture, nullptr, &exit_text_main_rect);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyTexture(exit_text_main_texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	TTF_Quit();
}

int initSDL() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		MessageBoxA(0, "Не удалось инициализировать SDL_EVERYTHING", "Ошибка", MB_ICONERROR);
		return 1;
	}
	else if (TTF_Init() < 0) {
		MessageBoxA(0, "Не удалось инициализировать SDL_TTF", "Ошибка", MB_ICONERROR);
		return 2;
	}

	return 0;
}

void loadSDL() {
	//Загрузка SDL
	int rois = initSDL();
	if (rois == 0){
		cout << "Успешно инициализирован SDL: " << rois << endl;
		visual();
	}
	else if (rois == 1)
		cout << "Не инициализирован SDL: " << rois << ", " << SDL_GetError() << endl;
	else if (rois == 2)
		cout << "Не инициализирован SDL_TTF: " << rois << "," << TTF_GetError << endl;
	else
		cout << "Неизвестный код результата инициализации" << endl;
}

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
	else if (action == "github")
		github();
	else if (action == "visual")
		loadSDL();

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

int main(int argc, char** argv) {
	SetConsoleOutputCP(1251);
	consolemenu();
	return 0;
}
