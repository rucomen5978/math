#include <SDL.h>
#include <SDL_ttf.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <numeric>
#include <stdexcept>
#include <sstream>
using namespace std;

struct Fraction {
	int fullpart = 0;
	int numerator = 0;
	int denominator = 0;
	int ntmb = 0;
};
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
vector<int> findDivisors(int num) {
	vector<int> divisors;
	for (int i = 1; i <= num; i++) {
		if (num % i == 0) {
			divisors.push_back(i);
		}
	}
	return divisors;
}
void gotoxy(int x, int y) {
	COORD h;
	h.X = x;
	h.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), h);
}
int GetConsoleHeight() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
		return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	}
	else {
		return 0;
	}
}
int GetCursorX() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
		COORD cursorPosition = csbi.dwCursorPosition;
		return cursorPosition.X;
	}
	else {
		return 0;
	}
}
int GetCursorY() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
		COORD cursorPosition = csbi.dwCursorPosition;
		return cursorPosition.Y;
	}
	else {
		return 0;
	}
}
void clearBottom() {
	int x = GetCursorX();
	int y = GetCursorY();
	gotoxy(0, GetConsoleHeight());
	cout << "                                                        ";
	gotoxy(x, y);
}
void writeBottom(string text) {
	clearBottom();
	int x = GetCursorX();
	int y = GetCursorY();
	gotoxy(0, GetConsoleHeight());
	cout << text;
	gotoxy(x, y);
	if (GetCursorY() == GetConsoleHeight()) {
		gotoxy(GetCursorX(), 0);
		system("cls");
		
	}
}
int centerX(int objectW, int windowW) {
	return (windowW / 2) - (objectW / 2);
}
int centerY(int objectH, int windowH) {
	return (windowH / 2) - (objectH / 2);
}
int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}
string decimalToFraction(double decimal) {
	int sign = (decimal < 0) ? -1 : 1; // Хранит знак числа
	decimal = fabs(decimal); // Берём абсолютное значение

	// Считаем количество знаков после запятой
	int decimalPlaces = 0;
	while (fmod(decimal, 1) != 0) {
		decimal *= 10;
		decimalPlaces++;
	}

	// Знаменатель - это 10^количество знаков после запятой
	int denominator = static_cast<int>(pow(10, decimalPlaces));

	// Числитель - это значение десятичной дроби, умноженное на знаменатель
	int numerator = static_cast<int>(decimal * sign);

	// Упрощаем дробь
	int commonDivisor = gcd(abs(numerator), denominator);
	numerator /= commonDivisor;
	denominator /= commonDivisor;

	// Формируем строку для представления обыкновенной дроби
	return to_string(numerator) + "/" + to_string(denominator);
}
string improperToMixed(int numerator, int denominator) {
	// Проверяем, что знаменатель не равен нулю
	if (denominator == 0) {
		return "Ошибка: деление на ноль!";
	}

	// Находим целую часть
	int wholePart = numerator / denominator;

	// Находим новый числитель
	int newNumerator = abs(numerator % denominator); // Используем abs для положительного значени

	// Формируем строку результата
	if (newNumerator == 0) {
		return to_string(wholePart); // Если дробная часть равна 0
	}
	else {
		return std::to_string(wholePart) + " " + std::to_string(newNumerator) + "/" + std::to_string(denominator);
	}
}
void cls() {
	system("cls");
}
void pause() {
	system("pause>nul");
}
struct Button {
	SDL_Rect rect;
	SDL_Color color;
	
	void render(SDL_Renderer* renderer) {
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
		SDL_RenderFillRect(renderer, &rect);
	}

	bool isClicked(int x, int y) {
		return (x >= rect.x && x <= (rect.x + rect.w) && y >= rect.y && y <= (rect.y + rect.h));
	}

	void moveTo(int x, int y) {
		rect.x = x;
		rect.y = y;
	}
	
	void changeColor(int r, int g, int b) {
		color.r = r;
		color.g = g;
		color.b = b;
	}

	void sizeTo(int w, int h) {
		rect.w = w;
		rect.h = h;
	}
};
int LoadSDL() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		MessageBoxA(0, "Не удалось инициализировать SDL", "Ошибка", MB_ICONERROR);
		return 1;
	}
	else if (TTF_Init() < 0) {
		MessageBoxA(0, "Не удалось инициализировать SDL_TTF", "Ошибка", MB_ICONERROR);
		return 2;
	}
	return 0;
}

void help() {
	//cout << "Для консольного режима (для более опытных пользователей) -> console" << endl;
	cout << "Для визульного режима (для более новых пользователей) -> visual" << endl;
	cout << "Для помощи выбора режима окна -> help window flag" << endl;
	cout << "Для помощи выбора действий в калькуляторе процентов -> help calcperc" << endl;
	cout << "Для чистки всех сообщений -> clear" << endl;
	cout << "Для выхода из программы -> exit" << endl;
	cout << endl << endl;
	cout << "Режимы программы: " << endl;
	cout << "Калькулятор -> calc" << endl;
	cout << "Калькулятор процентов -> calcperc" << endl;
	cout << "Калькулятор дробей -> calcfrac" << endl;
	cout << "Найти наибольший общий делитель -> gcd" << endl;
	cout << "Найти наименьший общее кратное -> lcm" << endl;
	cout << "Найти квадратный корень -> sqrt" << endl;
	cout << "Найти факториал -> fact" << endl;
	cout << "Перевести десятичную дробь в обыкновенную -> dtf" << endl;
	cout << "Из неправильной дроби в правильную -> itm" << endl;
	cout << "Найти делители числа -> fd" << endl;
	cout << "Проверить на простое число -> fp" << endl;
	cout << "Ссылка на оригинальный репозиторий в github -> github" << endl;
}
void debugfrac(Fraction frac1, Fraction frac2, Fraction result) {
	cout << "frac1.fullpart:\t" << frac1.fullpart << endl;
	cout << "frac1.numerator:\t" << frac1.numerator << endl;
	cout << "frac1.denominator:\t" << frac1.denominator << endl;
	cout << "frac1.ntmb:\t\t" << frac1.ntmb << endl;
	cout << endl;
	cout << "frac2.fullpart:\t" << frac2.fullpart << endl;
	cout << "frac2.numerator:\t" << frac2.numerator << endl;
	cout << "frac2.denominator:\t" << frac2.denominator << endl;
	cout << "frac2.ntmb:\t\t" << frac2.ntmb << endl;
	cout << endl;
	cout << "result.fullpart:\t" << result.fullpart << endl;
	cout << "result.numerator:\t" << result.numerator << endl;
	cout << "result.denominator:\t" << result.denominator << endl;
	cout << "result.ntmb:\t\t" << result.ntmb << endl;
	cout << endl;
}
void findsqrt() {
	writeBottom("Режим: нахождение квадратного корня");

	double a;
	cin >> a;
	cout << sqrt(a) << endl;
}
void findgcd() {
	writeBottom("Режим: нахождение НОДа");

	int a, b;
	cin >> a >> b;

	if (gcd(a, b) == 1) {
		cout << "Взаимно простые числа" << endl;
	}
	else {
		cout << gcd(a, b) << endl;
		cout << a << "/" << gcd(a, b) << "=" << a / gcd(a, b) << endl;
		cout << b << "/" << gcd(a, b) << "=" << b / gcd(a, b) << endl;
	}
}
void findlcm() {
	writeBottom("Режим: нахождение НОКа");
	int a, b;
	cin >> a >> b;
	cout << lcm(a, b) << endl;
	cout << lcm(a, b) << "/" << a << "=" << lcm(a, b) / a<< endl;
	cout << lcm(a, b) << "/" << b << "=" << lcm(a, b) / b<< endl;
}
void calcSDL() {

}
void findPrime() {
	writeBottom("Режим: проверка на простое число");
	int num;
	cin >> num;
	if (isPrime(num)) {
		cout << "Число простое" << endl;
	}
	else if (!isPrime(num)) {
		cout << "Число не простое" << endl;
	}
}
void findDivisors() {
	writeBottom("Режим: нахождение делителей");
	int num;
	cin >> num;
	vector<int> divisors = findDivisors(num);
	cout << "Число делится на: ";
	for (int div : divisors) {
		cout << div << ", ";
	}
	cout << endl;
}
void startSDL() {
	writeBottom("Режим: создание визуального режима");

	int window_x, window_y, window_width, window_height, window_flag;
	Uint32 window_flags;
	cout << "Введите x позицию окна (для середины введите 0): ";
	cin >> window_x;
	cout << "Введите y позицию окна (для середины введите 0): ";
	cin >> window_y;
	cout << "Введите ширину окна (для 1280 введите 0): ";
	cin >> window_width;
	cout << "Введите высоту окна (для 720 введите 0): ";
	cin >> window_height;
	cout << "Введите флаг окна (стандартно 2): ";
	cin >> window_flag;

	if (window_x == 0) 
		window_x = SDL_WINDOWPOS_CENTERED;
	
	if (window_y == 0) 
		window_y = SDL_WINDOWPOS_CENTERED;
	
	if (window_width == 0)
		window_width = 1280;
	if (window_height == 0)
		window_height = 720;


	if (window_flag == 1) 
		window_flags = SDL_WINDOW_FULLSCREEN;
	
	else if (window_flag == 2) 
		window_flags = SDL_WINDOW_SHOWN;
	
	else if (window_flag == 3) 
		window_flags = SDL_WINDOW_HIDDEN;
	
	else if (window_flag == 4) 
		window_flags = SDL_WINDOW_BORDERLESS;
	
	
	else {
		cout << "Неправильная разметка флага окна, будет выбрано 2" << endl;
		window_flags = SDL_WINDOW_SHOWN;
	}

	SDL_Color white_color = { 255,255,255,255 };
	SDL_Color black_color = { 0,0,0,255 };
	TTF_Font* arial_50 = TTF_OpenFont("arial.ttf", 50);
	TTF_Font* arial_40 = TTF_OpenFont("arial.ttf", 40);

	
	SDL_Window* window = SDL_CreateWindow("math", window_x, window_y, window_width, window_height, window_flags);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr) {
		cout << "Не удалось инициализировать окно" << endl;
	}
	else if (renderer == nullptr) {
		cout << "Не удалось инициализировать рендерер" << endl;
	}
	Button button_calc = { {40, 70, 240, 50}, {255,255,255,255} };
	SDL_Surface* text_calc_surface = TTF_RenderUTF8_Solid(arial_40, u8"калькулятор", black_color);
	SDL_Texture* text_calc_texture = SDL_CreateTextureFromSurface(renderer, text_calc_surface);
	SDL_Rect text_calc_rect = { 40, 70, text_calc_surface->w, text_calc_surface->h };
	SDL_FreeSurface(text_calc_surface);

	Button button_leavefromvisualmode = { {window_width-580, window_height-80, 560, 60},{255,255,255,255} };
	SDL_Surface* text_leavefromvisualmode_surface = TTF_RenderUTF8_Solid(arial_40, u8"выйти из визуального режима", black_color);
	SDL_Texture* text_leavefromvisualmode_texture = SDL_CreateTextureFromSurface(renderer, text_leavefromvisualmode_surface);
	SDL_Rect text_leavefromvisualmode_rect = { window_width-580, window_height-80, text_leavefromvisualmode_surface->w, text_leavefromvisualmode_surface->h };
	SDL_FreeSurface(text_leavefromvisualmode_surface);


	SDL_Surface* text_main_surface = TTF_RenderUTF8_Solid(arial_50, u8"math главное визуальное меню", white_color);
	SDL_Texture* text_main_texture = SDL_CreateTextureFromSurface(renderer, text_main_surface);
	SDL_Rect text_main_rect = {centerX(text_main_surface->w, window_width), 10, text_main_surface->w, text_main_surface->h};
	SDL_FreeSurface(text_main_surface);

	bool running = true;
	SDL_Event event;
	int mouseX, mouseY;
	while (running) {
		SDL_GetMouseState(&mouseX, &mouseY);
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}

			if (button_leavefromvisualmode.isClicked(mouseX, mouseY)) {
				button_leavefromvisualmode.changeColor(200, 200, 200);
				if (event.type == SDL_MOUSEBUTTONDOWN) {
					running = false;
				}
			}
			if (!button_leavefromvisualmode.isClicked(mouseX, mouseY)) {
				button_leavefromvisualmode.changeColor(255, 255, 255);
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		button_calc.render(renderer);
		button_leavefromvisualmode.render(renderer);
		SDL_RenderCopy(renderer, text_calc_texture, nullptr, &text_calc_rect);
		SDL_RenderCopy(renderer, text_leavefromvisualmode_texture, nullptr, &text_leavefromvisualmode_rect);
		SDL_RenderCopy(renderer, text_main_texture, nullptr, &text_main_rect);
		SDL_RenderPresent(renderer);

	}
	SDL_DestroyTexture(text_leavefromvisualmode_texture);
	SDL_DestroyTexture(text_calc_texture);
	SDL_DestroyTexture(text_main_texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
int factorial(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result = result * i;
	}
	return result;
}
void findfromdecimaltofraction() {
	writeBottom("Режим: перевод десятичной дроби в обыкновенную");
	double n;
	cin >> n;
	cout << decimalToFraction(n) << endl;
}
void findfactorial() {
	writeBottom("Режим: нахождения факториала");
	int a;
	cin >> a;
	cout << factorial(a) << endl;
}
void visualmenu() {
	if (LoadSDL() == 0) {
		cout << "Успешно инициализирован SDL2: " << LoadSDL() << endl;
		startSDL();
	}
	else {
		cout << "Неуспешная инициализация SDL2: " << LoadSDL() << endl;
	}
	
}
void helpwindowflag() {
	cout << "1 - FULLSCREEN (на весь экран)" << endl;
	cout << "2 - SHOWN (оконный режим, при запуске видно)" << endl;
	cout << "3 - HIDDEN (оконный режим, при запуске не видно)" << endl;
	cout << "4 - BORDERLESS (оконный режим без верхней панели)" << endl;
	
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
void calcperc() {
	writeBottom("Режим: калькулятор процентов");
	double n, p;
	char c;
	cin >> n >> c >> p;
	if (c == '+')
		cout << (n * (1 + p / 100)) << endl;
	else if (c == '-')
		cout << (n * (1 - p / 100)) << endl;
	else if (c == 'f')
		cout << (n * p / 100);
	else if (c == 'w')
		cout << (n / p * 100) << endl;
	else if (c == '>')
		cout << (n / p * 100 - 100) << endl;
	else if (c == '<')
		cout << (100 - (n / p) * 100) << endl;
	else if (c == 'o')
		cout << (n * 100 / p) << endl;
}
void calc() {
	writeBottom("Режим: калькулятор");
	double a, b;
	char c;
	cin >> a >> c >> b;
	if (c == '+')
		cout << a + b << endl;
	else if (c == '-')
		cout << a - b << endl;
	else if (c == '*')
		cout << a * b << endl;
	else if (c == '/')
		cout << a / b << endl;
	else if (c == '^')
		cout << pow(a, b) << endl;
	else
		cout << "Ошибка: неправильный символ" << endl;
}
void itm() {
	writeBottom("Режим: из неправильной дроби в правильную");
	int num;
	int denom;
	cin >> num >> denom;
	cout << improperToMixed(num, denom) << endl;
}
void calcfraction2() {
	writeBottom("Режим: калькулятор дробей");
	Fraction frac1, frac2, result;
	
	int cd;
	char action;
	char reduce;
	char itm;
	char debug;

	cout << "frac1.fullpart: ";
	cin >> frac1.fullpart;
	cout << "frac1.numerator: ";
	cin >> frac1.numerator;
	cout << "frac1.denominator: ";
	cin >> frac1.denominator;
	cout << "action: ";
	cin >> action;
	cout << "frac2.fullpart: ";
	cin >> frac2.fullpart;
	cout << "frac2.numerator: ";
	cin >> frac2.numerator;
	cout << "frac2.denominator: ";
	cin >> frac2.denominator;
	cout << "делать из неправильной дроби в правильную? (y, n): ";
	cin >> itm;
	cout << "сокращать число? (y, n): ";
	cin >> reduce;
	cout << "включить режим отладки? (y, n): ";
	cin >> debug;


	//Действия для сложения 
	if (action == '+') {
		//cd - общий знаменатель
		cd = lcm(frac1.denominator, frac2.denominator);
		if (debug == 'y') {
			cout << "cd:\t" << cd << endl;
			debugfrac(frac1, frac2, result);
		}


		//ищем множитель для числителя дробей
		frac1.ntmb = cd / frac1.denominator;
		if (debug == 'y')
			debugfrac(frac1, frac2, result);
		frac2.ntmb = cd / frac2.denominator;
		if (debug == 'y')
			debugfrac(frac1, frac2, result);

		//переделываем дроби под общий знаменатель
		frac1.numerator = frac1.numerator * frac1.ntmb;
		if (debug == 'y')
			debugfrac(frac1, frac2, result);
		frac1.denominator = cd;
		if (debug == 'y')
			debugfrac(frac1, frac2, result);

		frac2.numerator = frac2.numerator * frac2.ntmb;
		if (debug == 'y')
			debugfrac(frac1, frac2, result);
		frac2.denominator = cd;
		if (debug == 'y')
			debugfrac(frac1, frac2, result);

		//делаем уже результат
		if (itm == 'n' && reduce == 'n') {
			result.fullpart = frac1.fullpart + frac2.fullpart;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			result.denominator = cd;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			result.numerator = frac1.numerator + frac2.numerator;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			else if (result.fullpart == 0) {
				cout << result.numerator << "/" << result.denominator << endl;
			}
			//выводим
			cout << result.fullpart << " " << result.numerator << "/" << result.denominator << endl;
		}
		else if (itm == 'n' && reduce == 'y') {
			int gcdfrac;
			result.fullpart = frac1.fullpart + frac2.fullpart;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			result.denominator = cd;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			result.numerator = frac1.numerator + frac2.numerator;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			gcdfrac = gcd(result.denominator, result.numerator);
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			result.denominator /= gcdfrac;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			result.numerator /= gcdfrac;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			else if (result.fullpart == 0) {
				cout << result.numerator << "/" << result.denominator << endl;
			}
			//выводим
			cout << result.fullpart << " " << result.numerator << "/" << result.denominator << endl;
		}

		else if (itm == 'y' && reduce == 'n') {
			int lnv = 0;
			int counter = 0;
			result.fullpart = frac1.fullpart + frac2.fullpart;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			result.denominator = cd;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			result.numerator = frac1.numerator + frac2.numerator;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);

			// Преобразуем неправильную дробь в смешанную
			while (result.numerator >= result.denominator) {
				result.numerator -= result.denominator;
				if (debug == 'y')
					debugfrac(frac1, frac2, result);
				counter++;
			}

			// Обновляем числитель и целую часть
			result.fullpart += counter;
			if (result.numerator < 0) {
				result.numerator += result.denominator; // Делаем числитель положительным
				if (debug == 'y')
					debugfrac(frac1, frac2, result);
				result.fullpart--; // Уменьшаем целую часть, чтобы компенсировать
				if (debug == 'y')
					debugfrac(frac1, frac2, result);
			}

			if (result.numerator == 0) {
				cout << result.fullpart << endl;
			}
			else if (result.fullpart == 0) {
				cout << result.numerator << "/" << result.denominator << endl;
			}
			else {
				cout << result.fullpart << " " << result.numerator << "/" << result.denominator << endl;
			}
		}

		else if (itm == 'y' && reduce == 'y') {
			int lnv = 0;
			int counter = 0;
			result.fullpart = frac1.fullpart + frac2.fullpart;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			result.denominator = cd;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			result.numerator = frac1.numerator + frac2.numerator;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);

			// Преобразуем неправильную дробь в смешанную
			while (result.numerator >= result.denominator) {
				result.numerator -= result.denominator;
				if (debug == 'y')
					debugfrac(frac1, frac2, result);
				counter++;
			}

			// Обновляем числитель и целую часть
			result.fullpart += counter;
			if (result.numerator < 0) {
				result.numerator += result.denominator; // Делаем числитель положительным
				if (debug == 'y')
					debugfrac(frac1, frac2, result);
				result.fullpart--; // Уменьшаем целую часть, чтобы компенсировать
			}

			if (result.numerator == 0) {
				cout << result.fullpart << endl;
			}
			else if (result.fullpart == 0) {
				cout << result.numerator << "/" << result.denominator << endl;
			}
			else {
				int gcdfrac = gcd(result.denominator, result.numerator);
				result.denominator /= gcdfrac;
				if (debug == 'y')
					debugfrac(frac1, frac2, result);
				result.numerator /= gcdfrac;
				if (debug == 'y')
					debugfrac(frac1, frac2, result);
				cout << result.fullpart << " " << result.numerator << "/" << result.denominator << endl;
			}
		}

		else if (itm == 'y' && reduce == 'n') {
			int lnv = 0;
			int counter = 0;
			result.fullpart = frac1.fullpart + frac2.fullpart;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			result.denominator = cd;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			result.numerator = frac1.numerator + frac2.numerator;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);

			// Преобразуем неправильную дробь в смешанную
			while (result.numerator >= result.denominator) {
				result.numerator -= result.denominator;
				if (debug == 'y')
					debugfrac(frac1, frac2, result);
				counter++;
			}

			// Обновляем числитель и целую часть
			result.fullpart += counter;
			if (result.numerator < 0) {
				result.numerator += result.denominator; // Делаем числитель положительным
				if (debug == 'y')
					debugfrac(frac1, frac2, result);
				result.fullpart--; // Уменьшаем целую часть, чтобы компенсировать
				if (debug == 'y')
					debugfrac(frac1, frac2, result);
			}

			if (result.numerator == 0) {
				cout << result.fullpart << endl;
			}
			else if (result.fullpart == 0) {
				cout << result.numerator << "/" << result.denominator << endl;
			}
			else {
				cout << result.fullpart << " " << result.numerator << "/" << result.denominator << endl;
			}
			}
	}


	//если действие минус
	else if (action == '-') {
		//находим общий знаменатель
		cd = lcm(frac1.denominator, frac2.denominator);
		if (debug == 'y')
			debugfrac(frac1, frac2, result);
		//находим множитель для числителей
		frac1.ntmb = cd / frac1.denominator;
		if (debug == 'y')
			debugfrac(frac1, frac2, result);
		frac2.ntmb = cd / frac2.denominator;
		if (debug == 'y')
			debugfrac(frac1, frac2, result);

		//изменение дробей под общий знаменатель
		//изменение знаменателей на общий
		frac1.denominator = cd;
		if (debug == 'y')
			debugfrac(frac1, frac2, result);
		frac2.denominator = cd;
		if (debug == 'y')
			debugfrac(frac1, frac2, result);
		//изменение числителей под новый знаменатель
		frac1.numerator *= frac1.ntmb;
		if (debug == 'y')
			debugfrac(frac1, frac2, result);
		frac2.numerator *= frac2.ntmb;
		if (debug == 'y')
			debugfrac(frac1, frac2, result);

		//результат без перевода в правильную дробь и без сокращения
		if (itm == 'n' && reduce == 'n') {
			//если нет целого числа
			//if (frac1.fullpart == 0 && frac2.fullpart == 0) {
				//в результате делаем общий знаменатель
				result.denominator = cd;
				if (debug == 'y')
					debugfrac(frac1, frac2, result);
				//делаем операцию с числителями
				result.numerator = frac1.numerator - frac2.numerator;
				if (debug == 'y')
					debugfrac(frac1, frac2, result);
				//делаем операцию с целыми числами
				result.fullpart = frac1.fullpart - frac2.fullpart;
				if (debug == 'y')
					debugfrac(frac1, frac2, result);
				//если нет целого числа то выводим без целого числа
				if (result.fullpart == 0) {
					cout << result.numerator << "/" << result.denominator << endl;
				}
				else if (result.numerator == 0) {
					cout << result.fullpart << endl;
				}
				else {
					cout << result.fullpart << " " << result.numerator << "/" << result.denominator << endl;
				}
				
			//}
		}
		//если включен перевод правильных дробей но выключено сокращение дробей
		else if (itm == 'y' && reduce == 'n') {
			
		}



}
}

void github() {
	system("")
}

void consolemenu() {
	writeBottom("Режим: главное меню");
	string input;
	//cout << ":";
	getline(cin, input);
	

	if (input == "help")
		help();
	else if (input == "help window flag")
		helpwindowflag();
	else if (input == "help calcperc")
		helpcalcperc();
	else if (input == "visual")
		visualmenu();
	else if (input == "clear")
		cls();
	else if (input == "exit")
		exit(0);

	else if (input == "calc")
		calc();
	else if (input == "calcperc")
		calcperc();
	else if (input == "calcfrac") {
		calcfraction2();
	}
	else if (input == "gcd")
		findgcd();
	else if (input == "lcm")
		findlcm();
	else if (input == "sqrt")
		findsqrt();
	else if (input == "fact")
		findfactorial();
	else if (input == "dtf")
		findfromdecimaltofraction();
	else if (input == "itm")
		itm();
	else if (input == "fp")
		findPrime();
	else if (input == "fd")
		findDivisors();
	

	consolemenu();
}
int main(int argc, char** argv) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	consolemenu();
	
	return 0;
}
