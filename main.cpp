#include <SDL.h> //Для визуального режима
#include <SDL_ttf.h> //Для текста в визуальном режиме
#include <Windows.h> //Для MessageBox в случае ошибок в визуальном режиме
#include <iostream> //Для ввода вывода в консольном режиме
#include <string> //Тип текста
#include <cmath> //Библиотека для возведения в степень и других полезных функций
#include <vector> //Для нахождения делителей числа
#include <fstream> //Для создание настроек программы и их чтение
using namespace std;

//Структура дроби
struct Fraction {
	//Целая часть дроби
	int fullpart = 0;
	//Числитель дроби
	int numerator = 0;
	//Знаменатель дроби
	int denominator = 0;
	//Множитель для числителя
	int ntmb = 0;

	void toImproperFraction() {
		numerator = fullpart * denominator + numerator;
		fullpart = 0;
	}

	void toMixedFraction() {
		fullpart = numerator / denominator;
		numerator %= denominator;
	}
};
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
vector<int> findDivisors(int num) {
	vector<int> divisors;
	for (int i = 1; i <= num; i++) {
		if (num % i == 0) {
			divisors.push_back(i);
		}
	}
	return divisors;
}
//Переместится в консоли
void gotoxy(int x, int y) {
	COORD h;
	h.X = x;
	h.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), h);
}
//Получить высоту консоли
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
//Получить координаты курсора по X
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
//Получить координаты курсора по Y
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
//Очистить нижную часть консоли
void clearBottom() {
	int x = GetCursorX();
	int y = GetCursorY();
	gotoxy(0, GetConsoleHeight());
	cout << "                                                        ";
	gotoxy(x, y);
}
//Написать что то в нижую часть консоли
void writeBottom(string text) {
	//clearBottom();
	//int x = GetCursorX();
	//int y = GetCursorY();
	//gotoxy(0, GetConsoleHeight());
	//cout << text;
	//gotoxy(x, y);
}
//Получить центр координат
int center(int objectWoH, int windowWoH) {
	return (windowWoH / 2) - (objectWoH / 2);
}
//Нахождение НОДа (Для программы)
int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
//Нахождение НОКа (Для программы)
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}
//Из десятичной дроби в обыкновенную (Для программы)
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
//Из неправильной дроби в правильную (Для программы)
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
//Очистить консоль
void cls() {
	system("cls");
}
//Ждать ввод пользователя в консоли
void pause() {
	system("pause>nul");
}
//Структура кнопки в визуальном режиме

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

//Инициализация визуального режима
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

//Режим помощи
void help() {
	//cout << "Для консольного режима (для более опытных пользователей) -> console" << endl;
	cout << "Настройки программы -> options" << endl;
	cout << "Для визульного режима (для более новых пользователей) -> visual" << endl;
	cout << "Для помощи выбора режима окна -> help window flag" << endl;
	cout << "Для помощи выбора действий в калькуляторе процентов -> help calcperc" << endl;
	cout << "Для помощи в калькуляторе дробей -> help calcfrac" << endl;
	cout << "Для чистки всех сообщений -> clear" << endl;
	cout << "Для выхода из программы -> exit" << endl;
	cout << "Формулы -> formuls" << endl;
	cout << "Ссылка на оригинальный репозиторий в github -> github" << endl;
	cout << endl << endl;
	cout << "Режимы программы: " << endl;
	cout << "Калькулятор -> calc" << endl; //Calculator
	cout << "Калькулятор процентов -> calcperc" << endl; //Calculator percent
	cout << "Калькулятор дробей без подсказок -> calfracwt" << endl; //Calculator fraction without text
	cout << "Калькулятор дробей -> calcfrac" << endl; //Calculator fraction
	cout << "Найти наибольший общий делитель -> gcd" << endl; //greatest common divisor
	cout << "Найти наименьший общее кратное -> lcm" << endl; //least common multiple
	cout << "Найти квадратный корень -> в калькуляторе возвести ваше число в степень 0.5" << endl;
	cout << "Найти кубический корень -> в калькуляторе возвести ваше число в степень 0.3333333 (чем больше троек тем точнее)" << endl;
	cout << "Найти факториал -> fact" << endl; //Factorial
	cout << "Перевести десятичную дробь в обыкновенную -> dtf" << endl; //Decimal to fraction
	cout << "Из неправильной дроби в правильную -> itm" << endl; //Improper to mixed
	cout << "Найти делители числа -> fd" << endl; //Find divisors
	cout << "Проверить на простое число -> fp" << endl; //Find prime
	cout << "Превратить дробь в десятичную дробь и проценты -> tdap" << endl; //To decimal and percent
}
//Отладка обычной дроби
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
//Отладка обычной дроби и не правильной дроби
void debugmulfrac(Fraction frac1, Fraction frac2, Fraction wfrac1, Fraction wfrac2, Fraction result) {
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
	cout << "wfrac1.fullpart:\t" << wfrac1.fullpart << endl;
	cout << "wfrac1.numerator:\t" << wfrac1.numerator << endl;
	cout << "wfrac1.denominator:\t" << wfrac1.denominator << endl;
	cout << "wfrac1.ntmb:\t\t" << wfrac1.ntmb << endl;
	cout << endl;
	cout << "wfrac2.fullpart:\t" << wfrac2.fullpart << endl;
	cout << "wfrac2.numerator:\t" << wfrac2.numerator << endl;
	cout << "wfrac2.denominator:\t" << wfrac2.denominator << endl;
	cout << "wfrac2.ntmb:\t\t" << wfrac2.ntmb << endl;
	cout << endl;
	cout << "result.fullpart:\t" << result.fullpart << endl;
	cout << "result.numerator:\t" << result.numerator << endl;
	cout << "result.denominator:\t" << result.denominator << endl;
	cout << "result.ntmb:\t\t" << result.ntmb << endl;
	cout << endl;
}
//Нахождение квадратного корня (Нету в помощи)
void findsqrt() {
	writeBottom("Режим: нахождение квадратного корня");

	double a;
	cin >> a;
	cout << sqrt(a) << endl;
}
//Найти НОД (Для пользователя)
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
//Найти НОК (Для пользователя)
void findlcm() {
	writeBottom("Режим: нахождение НОКа");
	int a, b;
	cin >> a >> b;
	cout << lcm(a, b) << endl;
	cout << lcm(a, b) << "/" << a << "=" << lcm(a, b) / a<< endl;
	cout << lcm(a, b) << "/" << b << "=" << lcm(a, b) / b<< endl;
}
//Режим калькулятора в визуальном режиме
void calcSDL() {

}
//Проверка на простое число (Для пользователя)
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
//Нахождение делителей числа (Для пользователя)
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

//Создание визуального режима
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
	SDL_Rect text_main_rect = {center(text_main_surface->w, window_width), 10, text_main_surface->w, text_main_surface->h};
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
//Нахождение факториала
int factorial(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result = result * i;
	}
	return result;
}
//Перевод десятичной дроби в обыкновенную (Для пользователя)
void findfromdecimaltofraction() {
	writeBottom("Режим: перевод десятичной дроби в обыкновенную");
	double n;
	cin >> n;
	cout << decimalToFraction(n) << endl;
}
//Найти факториал (Для пользователя)
void findfactorial() {
	writeBottom("Режим: нахождения факториала");
	int a;
	cin >> a;
	cout << factorial(a) << endl;
}
//Инициализация SDL
void visualmenu() {
	if (LoadSDL() == 0) {
		cout << "Успешно инициализирован SDL2: " << LoadSDL() << endl;
		startSDL();
	}
	else {
		cout << "Неуспешная инициализация SDL2: " << LoadSDL() << endl;
	}
}
//Помощь выбора флага для визуального режима
void helpwindowflag() {
	cout << "1 - FULLSCREEN (на весь экран)" << endl;
	cout << "2 - SHOWN (оконный режим, при запуске видно)" << endl;
	cout << "3 - HIDDEN (оконный режим, при запуске не видно)" << endl;
	cout << "4 - BORDERLESS (оконный режим без верхней панели)" << endl;
}
//Помощь калькулятора процентов
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
//Калькулятор процентов 
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

void tdap() {
	double first;
	double second;
	double tohex;
	double inpercentage;
	cin >> first >> second;
	tohex = first / second;
	inpercentage = first / (second / 100);
	cout << "Десятичная: " << tohex << endl;
	cout << "Процент: " << inpercentage << "%" << endl;
}

//Калькулятор
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
	else if (c == '%')
		cout << (int)a % (int)b << endl;
	else
		cout << "Ошибка: неправильный символ" << endl;
}
//Перевести из неправильной дроби в правильную (Для пользователя)
void itm() {
	writeBottom("Режим: из неправильной дроби в правильную");
	int num;
	int denom;
	cin >> num >> denom;
	cout << improperToMixed(num, denom) << endl;
}

//Калькулятор дробей для двух чисел
void calcfraction2(bool writetext) {
	writeBottom("Режим: калькулятор дробей");
	Fraction frac1, frac2, result;
	
	int cd;
	char action;
	char reduce;
	char itm;
	char debug;

	if (writetext) {
		cout << "frac1.fullpart: ";
	}
	cin >> frac1.fullpart;
	if (writetext) {
		cout << "frac1.numerator: ";
	}
	cin >> frac1.numerator;
	if (writetext) {
		cout << "frac1.denominator: ";
	}
	cin >> frac1.denominator;
	if (writetext) {
		cout << "action: ";
	}
	cin >> action;
	if (writetext) {
		cout << "frac2.fullpart: ";
	}
	cin >> frac2.fullpart;
	if (writetext) {
		cout << "frac2.numerator: ";
	}
	cin >> frac2.numerator;
	if (writetext) {
		cout << "frac2.denominator: ";
	}
	cin >> frac2.denominator;
	if (writetext) {
		cout << "делать из неправильной дроби в правильную? (y, n): ";
	}
	cin >> itm;
	if (writetext) {
		cout << "сокращать число? (y, n): ";
	}
	cin >> reduce;
	if (writetext) {
		cout << "включить режим отладки? (y, n): ";
	}
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
			//делаем общий знаменатель
			result.denominator = cd;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);

			//проверка если числитель первой дроби меньше чем второй
			if (frac1.numerator < frac2.numerator) {
				//мы проверяем есть ли у нас целое число
				if (frac1.fullpart >= 1) {
					//если есть то занимаем у него единицу
					frac1.fullpart--;
					if (debug == 'y')
						debugfrac(frac1, frac2, result);
					//эту занятую единицу представляем в виде числителя
					frac1.numerator += frac1.denominator;
					if (debug == 'y')
						debugfrac(frac1, frac2, result);

					//а потом уже отнимаем
					result.numerator = frac1.numerator - frac2.numerator;
					if (debug == 'y')
						debugfrac(frac1, frac2, result);
					//отнимаем целые числа
					result.fullpart = frac1.fullpart - frac2.fullpart;
					if (debug == 'y')
						debugfrac(frac1, frac2, result);

					//int a = 41;
					//int b = 35;
					//int fakecounter = 0;
					//int lnv = 0;
					//while (a > 0) {
					//	a -= b;
					//	fakecounter++;
					//}
					//if (a + b > 0) {
					//	lnv = (a + b);
					//}
					//int realcounter = fakecounter - 1;
	
					//cout << realcounter << " " << lnv;
	
					int fakecounter = 0;
					int lnv = 0;
					while (frac1.numerator > 0) {
						frac1.numerator -= frac2.numerator;
						fakecounter++;
						if (debug == 'y')
							debugfrac(frac1, frac2, result);
					}
					if (frac1.numerator + frac2.numerator > 0) {
						lnv = (frac1.numerator + frac2.numerator);
						if (debug == 'y')
							debugfrac(frac1, frac2, result);
					}
					int realcounter = fakecounter - 1;
					if (debug == 'y')
						debugfrac(frac1, frac2, result);
					result.fullpart += realcounter;
					if (debug == 'y')
						debugfrac(frac1, frac2, result);


					//и тут уже выводим
					if (result.fullpart == 0) {
						cout << result.numerator << "/" << result.denominator << endl;
					}
					else if (result.numerator == 0) {
						cout << result.fullpart << endl;
					}
					else {
						cout << result.fullpart << " " << result.numerator << "/" << result.denominator << endl;
					}

				}
			}
			//если у нас первый числитель больше второго то
			else {
				result.numerator = frac1.numerator - frac2.numerator;
				if (debug == 'y')
					debugfrac(frac1, frac2, result);
				result.fullpart = frac1.fullpart - frac2.fullpart;
				if (debug == 'y')
					debugfrac(frac1, frac2, result);
				int fakecounter = 0;
				int lnv = 0;
				while (frac1.numerator > 0) {
					frac1.numerator -= frac2.numerator;
					fakecounter++;
					if (debug == 'y')
						debugfrac(frac1, frac2, result);
				}
				if (frac1.numerator + frac2.numerator > 0) {
					lnv = (frac1.numerator + frac2.numerator);
					if (debug == 'y')
						debugfrac(frac1, frac2, result);
				}
				int realcounter = fakecounter - 1;
				if (debug == 'y')
					debugfrac(frac1, frac2, result);
				result.fullpart += realcounter;
				if (debug == 'y')
					debugfrac(frac1, frac2, result);


				//и тут уже выводим
				if (result.fullpart == 0) {
					cout << result.numerator << "/" << result.denominator << endl;
				}
				else if (result.numerator == 0) {
					cout << result.fullpart << endl;
				}
				else {
					cout << result.fullpart << " " << result.numerator << "/" << result.denominator << endl;
				}
			}
		}
		if (itm == 'n' && reduce == 'y') {
			result.denominator = cd;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			result.numerator = frac1.numerator - frac2.numerator;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			result.fullpart = frac1.fullpart - frac2.fullpart;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			int gcdfrac = gcd(result.denominator, result.numerator);
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			result.denominator /= gcdfrac;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			result.numerator /= gcdfrac;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			if (result.fullpart == 0) {
				cout << result.numerator << "/" << result.denominator << endl;
			}
			else if (result.numerator == 0) {
				cout << result.fullpart << endl;
			}
			else {
				cout << result.fullpart << " " << result.numerator << "/" << result.denominator << endl;
			}
		}
		if (itm == 'y' && reduce == 'y') {
			//делаем общий знаменатель
			result.denominator = cd;

			//проверка если числитель первой дроби меньше чем второй
			if (frac1.numerator < frac2.numerator) {
				//мы проверяем есть ли у нас целое число
				if (frac1.fullpart >= 1) {
					//если есть то занимаем у него единицу
					frac1.fullpart--;
					if (debug == 'y')
						debugfrac(frac1, frac2, result);
					//эту занятую единицу представляем в виде числителя
					frac1.numerator += frac1.denominator;
					if (debug == 'y')
						debugfrac(frac1, frac2, result);

					//а потом уже отнимаем
					result.numerator = frac1.numerator - frac2.numerator;
					if (debug == 'y')
						debugfrac(frac1, frac2, result);
					//отнимаем целые числа
					result.fullpart = frac1.fullpart - frac2.fullpart;
					if (debug == 'y')
						debugfrac(frac1, frac2, result);

					//int a = 41;
					//int b = 35;
					//int fakecounter = 0;
					//int lnv = 0;
					//while (a > 0) {
					//	a -= b;
					//	fakecounter++;
					//}
					//if (a + b > 0) {
					//	lnv = (a + b);
					//}
					//int realcounter = fakecounter - 1;

					//cout << realcounter << " " << lnv;

					// Преобразование в правильную дробь после вычитания
					if (result.numerator < 0) {
						// Если числитель отрицательный, занимаем из целой части
						result.fullpart -= 1; // Уменьшаем целую часть
						if (debug == 'y')
							debugfrac(frac1, frac2, result);
						result.numerator += result.denominator; // Добавляем знаменатель к числителю
						if (debug == 'y')
							debugfrac(frac1, frac2, result);
					}

					// Приведение дроби к правильной форме
					if (result.numerator >= result.denominator) {
						result.fullpart += result.numerator / result.denominator;
						if (debug == 'y')
							debugfrac(frac1, frac2, result);
						result.numerator %= result.denominator;
						if (debug == 'y')
							debugfrac(frac1, frac2, result);
					}


					int gcdfrac = gcd(result.denominator, result.numerator);
					if (debug == 'y')
						debugfrac(frac1, frac2, result);
					result.denominator /= gcdfrac;
					if (debug == 'y')
						debugfrac(frac1, frac2, result);
					result.numerator /= gcdfrac;
					if (debug == 'y')
						debugfrac(frac1, frac2, result);

					//и тут уже выводим
					if (result.fullpart == 0) {
						cout << result.numerator << "/" << result.denominator << endl;
					}
					else if (result.numerator == 0) {
						cout << result.fullpart << endl;
					}
					else {
						cout << result.fullpart << " " << result.numerator << "/" << result.denominator << endl;
					}

				}
			}
			//если у нас первый числитель больше второго то
			else {
				result.numerator = frac1.numerator - frac2.numerator;
				if (debug == 'y')
					debugfrac(frac1, frac2, result);
				result.fullpart = frac1.fullpart - frac2.fullpart;
				if (debug == 'y')
					debugfrac(frac1, frac2, result);
				// Преобразование в правильную дробь после вычитания
				if (result.numerator < 0) {
					// Если числитель отрицательный, занимаем из целой части
					result.fullpart -= 1; // Уменьшаем целую часть
					if (debug == 'y')
						debugfrac(frac1, frac2, result);
					result.numerator += result.denominator; // Добавляем знаменатель к числителю
					if (debug == 'y')
						debugfrac(frac1, frac2, result);
				}

				// Приведение дроби к правильной форме
				if (result.numerator >= result.denominator) {
					result.fullpart += result.numerator / result.denominator;
					if (debug == 'y')
						debugfrac(frac1, frac2, result);
					result.numerator %= result.denominator;
					if (debug == 'y')
						debugfrac(frac1, frac2, result);
				}


				int gcdfrac = gcd(result.denominator, result.numerator);
				result.denominator /= gcdfrac;
				if (debug == 'y')
					debugfrac(frac1, frac2, result);
				result.numerator /= gcdfrac;
				if (debug == 'y')
					debugfrac(frac1, frac2, result);

				//и тут уже выводим
				if (result.fullpart == 0) {
					cout << result.numerator << "/" << result.denominator << endl;
				}
				else if (result.numerator == 0) {
				cout << result.fullpart << endl;
				}
				else {
					cout << result.fullpart << " " << result.numerator << "/" << result.denominator << endl;
				}		
			}
		}
	}
	//если мы умножаем дробь
	else if (action == '*') {
		//делаем дробь неправильной
		Fraction wfrac1, wfrac2;
		//проверяем есть ли у нас смешанная дробь
		if (frac1.fullpart >= 1) {
			wfrac1.numerator = frac1.denominator * frac1.fullpart + frac1.numerator;
			if (debug == 'y')
				debugmulfrac(frac1, frac2, wfrac1, wfrac2, result);
			wfrac1.denominator = frac1.denominator;
			if (debug == 'y')
				debugmulfrac(frac1, frac2, wfrac1, wfrac2, result);
		}
		else {
			wfrac1 = frac1; // Если это не смешанная дробь
			if (debug == 'y')
				debugmulfrac(frac1, frac2, wfrac1, wfrac2, result);
		}

		if (frac2.fullpart >= 1) {
			wfrac2.numerator = frac2.denominator * frac2.fullpart + frac2.numerator;
			if (debug == 'y')
				debugmulfrac(frac1, frac2, wfrac1, wfrac2, result);
			wfrac2.denominator = frac2.denominator;
			if (debug == 'y')
				debugmulfrac(frac1, frac2, wfrac1, wfrac2, result);
		}
		else {
			wfrac2 = frac2; // Если это не смешанная дробь
			if (debug == 'y')
				debugmulfrac(frac1, frac2, wfrac1, wfrac2, result);
		}


		//вторая неправильная дробь готова

		//умножаем дроби друг на друга
		//если нам не надо переводить обратно в правильную дробь и не надо сокращать
		if (itm == 'n' && reduce == 'n') {
			result.denominator = wfrac1.denominator * wfrac2.denominator;
			if (debug == 'y')
				debugmulfrac(frac1, frac2, wfrac1, wfrac2, result);
			result.numerator = wfrac1.numerator * wfrac2.numerator;
			if (debug == 'y')
				debugmulfrac(frac1, frac2, wfrac1, wfrac2, result);
			if (result.fullpart == 0) {
				cout << result.numerator << "/" << result.denominator << endl;
			}
			else if (result.numerator == 0) {
				cout << result.fullpart << endl;
			}
			else {
				cout << result.fullpart << " " << result.numerator << "/" << result.denominator << endl;
			}
		}
		//если нам надо переводить в правильную дробь и не надо сокращать
		else if (itm == 'y' && reduce == 'n') {
			result.denominator = wfrac1.denominator * wfrac2.denominator;
			if (debug == 'y')
				debugmulfrac(frac1, frac2, wfrac1, wfrac2, result);
			result.numerator = wfrac1.numerator * wfrac2.numerator;
			if (debug == 'y')
				debugmulfrac(frac1, frac2, wfrac1, wfrac2, result);

			//// Преобразование в правильную дробь после вычитания
			//if (result.numerator < 0) {
			//	// Если числитель отрицательный, занимаем из целой части
			//	result.fullpart -= 1; // Уменьшаем целую часть
			//	result.numerator += result.denominator; // Добавляем знаменатель к числителю
			//}

			// Приведение дроби к правильной форме
			if (result.numerator >= result.denominator) {
				result.fullpart += result.numerator / result.denominator;
				if (debug == 'y')
					debugmulfrac(frac1, frac2, wfrac1, wfrac2, result);
				result.numerator %= result.denominator;
				if (debug == 'y')
					debugmulfrac(frac1, frac2, wfrac1, wfrac2, result);
			}

			if (result.fullpart == 0) {
				cout << result.numerator << "/" << result.denominator << endl;
			}
			else if (result.numerator == 0) {
				cout << result.fullpart << endl;
			}
			else {
				cout << result.fullpart << " " << result.numerator << "/" << result.denominator << endl;
			}
		}
		//если нам надо только сократить
		else if (itm == 'n' && reduce == 'y') {
			result.denominator = wfrac1.denominator * wfrac2.denominator;
			if (debug == 'y')
				debugmulfrac(frac1, frac2, wfrac1, wfrac2, result);
			result.numerator = wfrac1.numerator * wfrac2.numerator;
			if (debug == 'y')
				debugmulfrac(frac1, frac2, wfrac1, wfrac2, result);
			int gcdfrac = gcd(result.denominator, result.numerator);
			result.denominator /= gcdfrac;
			if (debug == 'y')
				debugmulfrac(frac1, frac2, wfrac1, wfrac2, result);
			result.numerator /= gcdfrac;
			if (debug == 'y')
				debugmulfrac(frac1, frac2, wfrac1, wfrac2, result);
			if (result.fullpart == 0) {
				cout << result.numerator << "/" << result.denominator << endl;
			}
			else if (result.numerator == 0) {
				cout << result.fullpart << endl;
			}
			else {
				cout << result.fullpart << " " << result.numerator << "/" << result.denominator << endl;
			}
		}
		//если нам надо и сократить и перевести в правильную дробь
		else if (itm == 'y' && reduce == 'y') {
			result.denominator = wfrac1.denominator * wfrac2.denominator;
			if (debug == 'y')
				debugmulfrac(frac1, frac2, wfrac1, wfrac2, result);
			result.numerator = wfrac1.numerator * wfrac2.numerator;
			if (debug == 'y')
				debugmulfrac(frac1, frac2, wfrac1, wfrac2, result);

			// Преобразование в правильную дробь
			if (result.numerator >= result.denominator) {
				result.fullpart += result.numerator / result.denominator;
				if (debug == 'y')
					debugmulfrac(frac1, frac2, wfrac1, wfrac2, result);
				result.numerator %= result.denominator;
				if (debug == 'y')
					debugmulfrac(frac1, frac2, wfrac1, wfrac2, result);
			}

			// Сокращение дроби
			int gcdfrac = gcd(result.denominator, result.numerator);
			result.denominator /= gcdfrac;
			if (debug == 'y')
				debugmulfrac(frac1, frac2, wfrac1, wfrac2, result);
			result.numerator /= gcdfrac;
			if (debug == 'y')
				debugmulfrac(frac1, frac2, wfrac1, wfrac2, result);

			// Вывод
			if (result.fullpart == 0) {
				cout << result.numerator << "/" << result.denominator << endl;
			}
			else if (result.numerator == 0) {
				cout << result.fullpart << endl;
			}
			else {
				cout << result.fullpart << " " << result.numerator << "/" << result.denominator << endl;
			}
		}
	}
	//если действие деление
	else if (action == '/') {
		//создаём не правильные дроби

		//проверяем на наличие целой части
		if (frac1.fullpart >= 1) {
			frac1.toImproperFraction();
		}
		//делаем тоже самое со второй дробью
		if (frac2.fullpart >= 1) {
			frac2.toImproperFraction();
		}

		if (itm == 'n' && reduce == 'n') {
			result.numerator = frac1.numerator * frac2.denominator;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			result.denominator = frac1.denominator * frac2.numerator;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			if (result.fullpart == 0) {
				cout << result.numerator << "/" << result.denominator << endl;
			}
			else if (result.numerator == 0) {
				cout << result.fullpart << endl;
			}
			else {
				cout << result.fullpart << " " << result.numerator << "/" << result.denominator << endl;
			}
		}
		if (itm == 'y' && reduce == 'n') {
			result.numerator = frac1.numerator * frac2.denominator;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			result.denominator = frac1.denominator * frac2.numerator;

			if (debug == 'y')
				debugfrac(frac1, frac2, result);

			if (result.numerator >= result.denominator) {
				result.fullpart += result.numerator / result.denominator;
				if (debug == 'y')
					debugfrac(frac1, frac2, result);
				result.numerator %= result.denominator;
				if (debug == 'y')
					debugfrac(frac1, frac2, result);
			}


			if (result.fullpart == 0) {
				cout << result.numerator << "/" << result.denominator << endl;
			}
			else if (result.numerator == 0) {
				cout << result.fullpart << endl;
			}
			else {
				cout << result.fullpart << " " << result.numerator << "/" << result.denominator << endl;
			}
		}
		if (itm == 'n' && reduce == 'y') {
			result.numerator = frac1.numerator * frac2.denominator;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			result.denominator = frac1.denominator * frac2.numerator;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);

			int gcdfrac = gcd(result.denominator, result.numerator);
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			result.denominator /= gcdfrac;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			result.numerator /= gcdfrac;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);

			if (result.fullpart == 0) {
				cout << result.numerator << "/" << result.denominator << endl;
			}
			else if (result.numerator == 0) {
				cout << result.fullpart << endl;
			}
			else {
				cout << result.fullpart << " " << result.numerator << "/" << result.denominator << endl;
			}
		}
		if (itm == 'y' && reduce == 'y') {
			result.numerator = frac1.numerator * frac2.denominator;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			result.denominator = frac1.denominator * frac2.numerator;

			if (debug == 'y')
				debugfrac(frac1, frac2, result);

			if (result.numerator >= result.denominator) {
				result.fullpart += result.numerator / result.denominator;
				if (debug == 'y')
					debugfrac(frac1, frac2, result);
				result.numerator %= result.denominator;
				if (debug == 'y')
					debugfrac(frac1, frac2, result);
			}
			int gcdfrac = gcd(result.denominator, result.numerator);
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			result.denominator /= gcdfrac;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);
			result.numerator /= gcdfrac;
			if (debug == 'y')
				debugfrac(frac1, frac2, result);

			if (result.fullpart == 0) {
				cout << result.numerator << "/" << result.denominator << endl;
			}
			else if (result.numerator == 0) {
				cout << result.fullpart << endl;
			}
			else {
				cout << result.fullpart << " " << result.numerator << "/" << result.denominator << endl;
			}
		}
	}
}
int f()
{
	while (5 == 4)
	{

	}
}

//Формулы
void formuls() {
	cout << "S - Площадь, P - Периметр, Pi - Число Пи, R - Радиус, C - Длина окружности, a b c - Переменные, они могут быть разные в зависимости от вашей задачи" << endl;
	cout << "N - Исходное число, Pr - Процент" << endl;
	cout << "% - Действие которое означает остаток от деления целого числа" << endl;
	cout << "Формула нахождения НОДа по алгоритму Евклида на C-Подобных языках: " << endl;
	cout << "\tint НОД(int a, int b)" << endl;
	cout << "\t{" << endl;
	cout << "\twhile (b != 0)" << endl;
	cout << "\t	{" << endl;
	cout << "\t		int temp = b;" << endl;
	cout << "\t		b = a % b;" << endl;
	cout << "\t		a = temp;" << endl;
	cout << "\t	}" << endl;
	cout << "\t	return a;" << endl;
	cout << "\t}" << endl;
	cout << endl;
	
	cout << "Формула нахождения НОКа:" << endl;
	cout << "\t(a * b) / НОД(a, b)" << endl;
	cout << endl;


	cout << "Калькулятор процентов: " << endl;
	cout << "\tДобавить процент к числу: (N * (1 + Pr / 100))" << endl;
	cout << "\tОтнять процент от числа: (N * (1 - Pr / 100))" << endl;
	cout << "\tНайти процент от числа: (N * Pr / 100)" << endl;
	cout << "\tНайти сколько процентов составляет число от числа: (N / Pr * 100)" << endl;
	cout << "\tНайти сколько процентов одно число больше другого: (N / Pr * 100 - 100)" << endl;
	cout << "\tНайти сколько процентов одно число меньше другого: (100 - (N / Pr) * 100)" << endl;
	cout << "\tНайти 100 процентов: (N * 100 / Pr)" << endl << endl; 

	cout << "Геометрия: " << endl;
	cout << "\tНайти площадь фигуры: умножить длины всех сторон" << endl;
	cout << "\t\tПример нахождения площади квадрата: S = a * a = a^2" << endl;
	cout << "\t\tПример нахождения площади прямоугольника: S = a * b" << endl;
	cout << "\t\tПример нахождения площади куба: S = a * a * a = a^3" << endl;
	cout << "\t\tПример нахождения площади параллелепипеда: S = a * b * c" << endl;
	cout << "\tНайти периметр фигуры: сложить сумму длин всех сторон" << endl;
	cout << "\t\tПример нахождения периметра квадрата: P = 4 * a" << endl;
	cout << "\t\tПример нахождения периметра прямоугольника: P = 2 * (a + b)" << endl;
	cout << "\tНайти площадь круга: S = Pi * R^2" << endl;
	cout << "\tНайти длину окружности: C = 2 * Pi * R" << endl;
	cout << "\tПлощадь треугольника: S = 1/2 * a * h" << endl;


}

//Открывание оригинального репозитория в браузере
void github() {
	system("start https://github.com/rucomen5978/math");
}
//Помощь калькулятора дробей
void helpcalcfrac() {
	cout << "Для правильной работы с дробями надо ввести 10 параметров" << endl;
	cout << "Сначало вводим целую часть первой дроби, если её нет пишем 0" << endl;
	cout << "Вводим числитель первой дроби" << endl;
	cout << "Вводим знаментаель первой дроби" << endl;
	cout << "Вводим знак действия (+, -, *, /)" << endl;
	cout << "Вводим всё тоже самое для второй дроби только без знака действия" << endl;
	cout << "Дальше у нас есть три параметра на выбор" << endl;
	cout << "ОЧЕНЬ ВАЖНО ПОМНИТЬ что через каждый параметр нужно ставить пробел, в примере показано правильно как" << endl;
	cout << "Важно помнить что все дополнительные параметры включаются на 'y', и выключатся на 'n'" << endl;
	cout << "itm или же перевод в правильную дробь (рекомендуется включить)" << endl;
	cout << "\tДопустим у нас дробь 7/3, и что бы такого результата в итоге не было включаем данный параметр символом y" << endl;
	cout << "\tИ в итоге у нас получится из 7/3 в 2 1/3, что даёт нам правильный итоговый ответ" << endl;
	cout << "reduce или же сокращение дроби (рекомендуется включить)" << endl;
	cout << "\tДопустим у нас дробь 5/10, и для итогового ответа нам надо сократить дробь" << endl;
	cout << "\tC включенным данным параметр у нас из 5/10 сокращается в 1/2" << endl;
	cout << "debug или же режим отладки (рекомендуется отключить)" << endl;
	cout << "\tОтладка для обычных пользователей не особо нужна, но нужна для разработчика например меня" << endl;
	cout << "\tС её помощью можно находить баги в программе или же полное представление что делает программа для вычисления дроби" << endl;
	cout << endl;
	cout << "Пример записи для пользователя: " << endl;
	cout << "calcfracwt" << endl;
	cout << "5 1 4 / 0 4 5 y y n" << endl;
	cout << "6 9/16" << endl;
	cout << endl;
}
//Консольное меню
void consolemenu() {
	writeBottom("Режим: главное меню");
	string input;
	cout << ":";
	getline(cin, input);
	

	if (input == "help")
		help();
	else if (input == "help window flag")
		helpwindowflag();
	else if (input == "help calcperc")
		helpcalcperc();
	else if (input == "help calcfrac")
		helpcalcfrac();
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
	else if (input == "calcfracwt") {
		calcfraction2(false);
	}
	else if (input == "calcfrac") {
		calcfraction2(true);
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
	else if (input == "github")
		github();
	else if (input == "formuls")
		formuls();
	else if (input == "tdap")
		tdap();
	

	consolemenu();
}
int main(int argc, char** argv) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	consolemenu();
	return 0;
}
