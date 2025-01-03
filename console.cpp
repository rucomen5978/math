//Файл для взаимодействия с программой

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <Windows.h>
#include "header.h"

#define inst <<"Инструкция по использованию"<<

//Один миллилитр
#define onemillilitertocbsm 1
#define onemillilitertolitr 0.001

bool pukikaki = true;


using namespace std;
bool showtext = false;
bool whilefunc = false;

//ЧАСТЬ ПРОГРАММЫ С РУКОВОДСТВАМИ

//helpcalc
// аббр. help calculator
void helpcalc() { 
	cout << "Ну тут наверное ничего интересного не будет, разве что про операторы буду тут рассказывать." << endl;
	cout << "Начну скорее всего то что сейчас данная версия калькулятора поддерживает только одно действие, и о типах действии сейчас расскажу." << endl;
	cout << "+ <- Сложение чисел, ну тут наверное и так всё ясно, вводим в программу например 5+5 и в ответ получаем 10." << endl;
	cout << "- <- Вычитание чисел, тут всё тоже ясно, вводим в программу например 3-1 и в ответ получаем 2." << endl;
	cout << "* <- Умножение чисел, это тоже самое сложение только выполненное несколько раз. Например вводим 8*2 и в ответ получаем 16, потому что 8 мы складываем два раза тоесть 8 + 8 = 16." << endl;
	cout << "/ <- Деление чисел, тут тоже все ясно, вводим в калькулятор 10 / 2. В ответ получаем 5." << endl;
	cout << "% <- Остаток от деления." << endl;
	cout << ": <- Тоже самое что и деление." << endl;
	cout << "^ <- Введение в степень, тоже самое что и умножение, только вот в умножении мы складываем число, а тут умножаем." << endl;
	cout << "! <- Факториал, тут в моей программе оба числа складываются и выдаёт факториал. Факториал это если что Число * Число-1 * Число-2, и так до одного." << endl;
	cout << "g <- Наибольший общий делитель, как создатель программы заявляю что те кто используют в калькуляторе НОД какие то мазохисты, потому что есть более удобная функция gcd." << endl;
	cout << "l <- Наименьшее общее кратное, тоже самое что и с НОДом только функция lcm." << endl;
	cout << "Калькулятор если что ожидает от вас 3 параметра, это число, оператор, второе число." << endl;
	cout << "Числа могут быть хоть и десятичными, и обыкновенными, но операторы могут быть только которые я представил выше." << endl;
	cout << "Ну и вот пример как использовать эту функцию: " << endl;
	cout << "первое_число оператор второе_число" << endl << "ответ" << endl;
	cout << "4g18" << endl;
	cout << "2" << endl;
	cout << "Вы кстати можете писать между числом и оператором неограниченное количество пробелов, или вообще их не ставить, на ответ это никак не повляет." << endl;
}

//helpcalcperc
// аббр. help calculator percent
void helpcalcperc() {
	cout << "Тут по синтаксису очень всё схоже с обычным калькултяром, и я тут тоже буду рассказывать про операторы." << endl;
	cout << "Тут важно помнить то что первое введённое число — исходное число." << endl;
	cout << "А второе введённое число после оператора — это процент, исключение операторы f, w, <, >." << endl;
	cout << "+ <- Прибавить процент к исходному числу." << endl;
	cout << "- <- Отнять процент к исходному числу." << endl;
	cout << "f <- Нахождение процента от числа." << endl;
	cout << "w <- Нахождение процентов составляет от первого числа." << endl;
	cout << "> <- Нахождение процентов одно число больше другого." << endl;
	cout << "< <- Нахождение процентов одно число меньше другого." << endl;
	cout << "o <- Нахождение 100 процентов." << endl;
	cout << "Пример: " << endl;
	cout << "50+50" << endl << "75" << endl;
	cout << "Тут если что всё также можно ставить неограниченное количество пробелов между числом и оператором." << endl;
	cout << "Формулы всех операторов содержатся в функции -> formuls." << endl;
}

//helptdap
// аббр. help to decimal and percent
void helptdap() {
	cout << "Мы вводим два числа, а именно числитель и знаменатель. Можно так и через пробел, а можно нажимать Enter и отступать каждую строчку." << endl;
	cout << "В ответ мы получаем нашу дробь в виде десятичной и процентах." << endl;
	cout << "Десятичную дробь можно узнать по простой формуле: числитель/знаменатель." << endl;
	cout << "А в виде процентов можно узнать тоже по простой формуле: числитель/(знаменатель/100)." << endl;
	cout << "Кратко говоря все ответы вы можете узнать через простой калькулятор." << endl;
}

//helpfd
// аббр. help find divisors
void helpfd() {
	cout << "Мы вводим одно число, и нам выдается все делители числа." << endl;
	cout << "Вот пример: " << endl;
	cout << "120" << endl << "1 2 3 4 5 6 8 10 12 15 20 24 30 40 60 120" << endl;
	cout << "Важно помнить если в списке делителей будет только: 1 и само число, то это называется простым числом." << endl;
	cout << "Проверить на простое число можно функцией fp." << endl;
}

//helpfp
// аббр. help find prime
void helpfp() {
	cout << "Мы вводим одно число, и нам может выдать только 2 результата, это просто число, или же не простое." << endl;
	cout << "Простое число -> число которое делится только на себя и 1." << endl;
	cout << "Не простое число -> число которое на что-то делится помимо 1 и себя" << endl;
	cout << "Вот пример:" << endl << "13" << endl << "Число простое" << endl;
	cout << "Или же вот ещё пример: " << endl << "14" << endl << "Число не простое" << endl;
}

//helpdtf
// аббр. help decimal to fraction
void helpdtf() {
	cout << "Мы вводим десятичную дробь и получаем эту же дробь только в виде обыкновенной." << endl;
	cout << "Вот пример: " << endl << "1.12" << "28/25" << endl;
}

//helpitm
// аббр. help improper to mixed
void helpitm() {
	cout << "Программа ожидает от нас ввода числителя(который больше знаменателя) а потом знаменателя." << endl;
	cout << "В итоге мы получаем правильную, несокращённую дробь." << endl;
	cout << "Пример: " << endl;
	cout << "15 10" << endl << "1 5/10" << endl;
}

//helpcalcfrac
// аббр. help calculator fraction
void helpcalcfrac() {
	cout << "Тут будет рассказываться - что программа будет от вас ожидать." << endl;
	cout << "В начале вас программа будет просить целую часть первой дроби, если её нету введите 0." << endl;
	cout << "Второй ввод от вас программа будет просить ввести числитель первой дроби." << endl;
	cout << "Третий ввод от вас программа будет просить ввести знаменатель первой дроби. Если даже у вас целое число - введите 1." << endl;
	cout << "Четвертый ввод от вас программа будет просить ввести оператор, это +, -, *, /." << endl;
	cout << "Пятый ввод от вас программа будет просить ввести целую часть второй дроби, если её нету введите 0." << endl;
	cout << "Шестой ввод от вас программа будет просить ввести числитель второй дроби." << endl;
	cout << "Седьмой ввод от вас программа будет просить ввести знаменатель второй дроби. Если даже у вас целое число - введите 1." << endl;
	cout << "Восьмой ввод от вас программа спрашивает, надо ли дробь переводить в правильную. Если не надо - вводим 0, Если надо - вводим 1." << endl;
	cout << "Девятый ввод от вас программа спрашивает, надо ли сокращать дробь, тут ввод такой же как и с прошлым." << endl;
	cout << "int - Целое число, char - один символ, bool - 1 или 2." << endl;
	cout << "Вот сокращенный вариант ввода: " << endl;
	cout << "int, int, int, char, int, int, int, bool, bool" << endl;
	cout << "Вот пример правильной записи: " << endl;
	cout << "1 5 9 + 3 7 8 1 1" << endl << "5 31/72" << endl;
}

//helpgcd
// аббр. help greatest common divisor
void helpgcd() {
	cout << "Мы вводим два числа, в итоге получаем общий делитель для обоих чисел, и число делённое на итог." << endl;
	cout << "Интересный факт: если у нас включены подсказки и НОД = 1, то выдастся интересное сообщение которое не будет с выключенными подсказками." << endl;
	cout << "Вот пример: " << endl;
	cout << "4 8" << endl << "4" << endl << "4/4=1" << endl << "8/4=2" << endl;
}

//helplcm
// аббр. help least common multiple
void helplcm() {
	cout << "Мы вводим два числа, в итоге получаем число которое будет делиться на оба введённых числа." << endl;
	cout << "После итога мы получаем две строчки: НОК/первое_число и НОК/второе_число." << endl;
	cout << "Также как интересный факт, НОК можно получить просто умножением двух чисел, но может быть результат будет очень большим." << endl;
	cout << "Вот пример: " << endl;
	cout << "11 13" << endl << "143" << endl << "143/11=13" << endl << "143/13=11" << endl;
}

//helptif
// аббр. help to imporper fraction
void helptif() {
	cout << "Мы вводим три значения для итога, а именно:" << endl;
	cout << "Целое число дроби, числитель дроби, знаменатель дроби." << endl;
	cout << "В итоге мы получаем результат по этой формуле: (знаменатель_дроби*целая_часть_дроби+числитель_дроби)/знаменатель_дроби" << endl;
	cout << "Вот пример: " << endl;
	cout << "1 13 395" << endl << "408/395" << endl;
}

//helpprop3
// аббр. proportion 3
void helpprop3() {
	cout << "Мы вводим ТРИ дроби и получаем четвёртую." << endl;
	cout << "Я считаю легче всего объяснить как работает эта функция можно объяснив про структуру дроби и в каком порядке мы её используем." << endl;
	cout << "Структура дроби состоит из 4 переменных и 3 функций." << endl;
	cout << "Первая переменная это целая часть, её мы вводим первой" << endl;
	cout << "Вторая переменная это числитель, её мы вводим вторым" << endl;
	cout << "Третья переменная это знаменатель, её мы вводим третьим" << endl;
	cout << "Четвертая переменная это множитель для числителя, её мы нигде не вводим, она нужна только для удобства" << endl;
	cout << "Первая функция, это перевод в неправильную дробь" << endl;
	cout << "Вторая функция, это перевод в правильную дробь" << endl;
	cout << "Третья функция, это вывод дроби" << endl;
	cout << "Как работает функция по нахождению пропорции: " << endl;
	cout << "первая_дробь	вторая_дробь" << endl;
	cout << "------------   ------------" << endl;
	cout << "результат      третья_дробь" << endl;
	cout << "Ну и как наверно вы поняли мы вводим наши дроби по порядку." << endl;
	cout << "В ответе мы получаем дробь. При делении первой дроби с результатом, мы получим тот же самый ответ что и с делением второй дроби с третьей." << endl;
	cout << "Найти ответ можно по вот такой формуле: первая_дробь*третья_дробь/вторая_дробь." << endl;
}

//helpftf
// аббр. help float to fraction
void helpftf() {
	cout << "Цель функции - превратить из дроби с десятичным числителем и знаменателем в адекватную дробь с понятными числителями и знаменателями." << endl;
	cout << "Что ожидает от нас программа? - Десятичного числителя, десятичного знаменателя, сокращать дробь или нет, переводить в смешанную дробь или нет.";
	cout << "Если мы попытаемся разделить дробь с десятичным числителем и знаменателем, и сверем это число с (результатный_числитель/результатный_знаменатель) то ответ будет одинаковый." << endl;
	cout << "Функция работает по такому образу: умножаем числитель и знаменатель в 1000000, и потом сокращаем их." << endl;
	cout << "Вот пример: " << endl;
	cout << "1.152 5.68 1 1" << endl << "72/355" << endl;
}

//helpian
// аббр. info about number
void helpian(){
	cout << "Эта функция позволяет выводить некоторые данные о числе. От нас требуется лишь ввести одно число." << endl;
	cout << "Тут легче всего наверное вам будет включить подсказки, потому что вам будет тяжело понимать что и где" << endl;
	cout << "Первый параметр это квадрат числа, ну тут ясно, число умноженное на себя два раза." << endl;
	cout << "Второй параметр это куб числа, тут тоже ясно, число умноженное на себя три раза." << endl;
	cout << "Третий параметр это квадратный корень числа, это число^0.5" << endl;
	cout << "Четвёртый параметр это кубический корень числа, это число^0.333333" << endl;
	cout << "Пятый параметр это число^число, чаще всего оно будет показываться inf, потому что c++ не умеет выводить такие большие числа." << endl;
	cout << "Шестой параметр это сложение чисел, если вам правда это интересно введите команду helpsod" << endl;
	cout << "Седьмой параметр это делители числа, тут наверное и так всё ясно." << endl;
	cout << "Восьмой параметр это корень самого себя. Если квадратный корень это число^(1/2), а кубический корень это число^(1/3), то у нас тут число^(1/число)" << endl;
	cout << "Девятый параметр это 1 / число. Кстати мы это же число вводим в степень что бы получить восьмой параметр." << endl;
	cout << "Девятый параметр это 1 / (число / 100)." << endl;
}

//helpian2
// аббр. info about number 2
void helpian2() {
	cout << "Эта функция позволяет выводить некоторые данные о двух числа. От нас требуется ввести два числа." << endl;
	cout << "Первый параметр это сложение чисел" << endl;
	cout << "Второй параметр это вычитание чисел" << endl;
	cout << "Третий параметр это умножение чисел" << endl;
	cout << "Четвёртый параметр это деление чисел" << endl;
	cout << "Пятый параметр это остаток от деления чисел" << endl;
	cout << "Шестой параметр это НОД чисел. (Если он равен 1 то 8 и 9 параметров не будет)" << endl;
	cout << "Седьмой параметр это НОК чисел." << endl;
	cout << "Восьмой параметр чисел это первое_число/нод" << endl;
	cout << "Девятый параметр чисел это второе_число/нод" << endl;
	cout << "Десятый параметр чисел это нок/первое_число" << endl;
	cout << "Одиннадцатый параметр чисел это нок/второе_число" << endl;
	cout << "Двенадцатый параметр чисел это первое_число^(1/второе_число)" << endl;
	cout << "Тренадцатый параметр чисел это умноженное сложение чисел. Подробнее в helpsod" << endl;
}

//helpsod
// аббр. help sum of digits
void helpsod() {
	cout << "Такие функции я отношу к категории простых, более подробно можно посмотреть по функции gv." << endl;
	cout << "Эта функция позволяет складывать все числа, например возьмем число 36" << endl;
	cout << "Возьмем все цифры в нем и сложим, 3 + 6 = 9, в ответ функции мы получим значит 9" << endl;
	cout << "Вот ещё один пример: 53145 = 5 + 3 + 1 + 4 + 5 = 18 = 1 + 8 = 9, в ответ мы тоже получим 9" << endl;
}

//helprt
// аббр. help root
void helprt() {
	cout << "Мы вводим число и корень, и в ответ получаем квадратный, кубический корень числа и корень который вы ввели." << endl;
	cout << "Если что вы можете эти действия сделать в обычном калькуляторе" << endl;
	cout << "Если вы хотите получить квадратный корень в калькуляторе, то взведите ваше число в степень (1/2)" << endl;
	cout << "Если вы хотите получить кубический корень в калькуляторе, то взведите ваше число в степень (1/3)" << endl;
	cout << "Если вы хотите получить заданный вами корень в калькуляторе, то взведите ваше число в степень (1/n). n - это ваше число если что." << endl;
}

//mo
// аббр. multiples of
void helpmo() {
	cout << "Вы вводите число, и количество результатов которые будут делиться на первое число." << endl;
	cout << "Вот пример: " << endl;
	cout << "5 10" << endl;
	cout << "5 10 15 20 25 30 35 40 45 50" << endl;
}

//helpshowtext
void helpshowtext() {
	cout << "Что бы включить показ подсказок в функциях введите комманду showtext" << endl;
	cout << "Что бы отключить показ подсказок в функциях введите комманду disabletext" << endl;
	cout << "Что бы проверить статус показ подсказок в функциях введите комманду checktext" << endl;
	cout << "Если checktext выдаёт 0, это означает то что показ подсказок в функциях выключен" << endl;
	cout << "Если checktext выдаёт 1, это означает то что показ подсказок в функциях включено" << endl;
}

//helpwhilefunc
void helpwhilefunc() {
	cout << "Если вы хотите использовать функцию несколько раз, при этом не вводя одну и ту же комманду вызова функции кучу раз, то эта комманда для вас." << endl;
	cout << "Что бы включить эту функцию надо ввести комманду enablewhilefunc" << endl;
	cout << "Что бы выключить эту функцию надо ввести комманду disablewhilefunc" << endl;
	cout << "Если вы зайдёте в какую либо функцию с этим включенным режимом, то выйти можно введя нули куда только можно кроме действий." << endl;
	cout << "Вот допустим мы зашли в калькулятор с включенным whilefunc. Мы сделали все свои дела, а что бы выйти мы пишем например 0+0, 0/0, 0*0, 0-0. В любом из этих действий калькулятор выйдет из постоянного цикла." << endl;
	cout << "Что бы проверить включен ли этот режим, введите комманду checkwhilefunc" << endl;
}

//help
void help() {
	cout << "Руководство использования программы: " << endl;
	
	cout << "helpcalc <- " inst " калькулятора" << endl;
	cout << "helpcalcperc <- " inst " калькулятора процентов" << endl;
	cout << "helptdap <-" inst " превращения дроби в десятичную и проценты" << endl;
	cout << "helpfd <- " inst " функции нахождения делителей числа" << endl;
	cout << "helpfp <- " inst " функции проверки на простое число" << endl;
	cout << "helpdtf <- " inst " перевода десятичной дроби в обыкновенную" << endl;
	cout << "helpitm <- " inst " перевода из неправильной дроби в обыкновенную" << endl;
	cout << "helpcalcfrac <- " inst " калькулятора дробей" << endl;
	cout << "helpgcd <- " inst " нахождения НОДа" << endl;
	cout << "helplcm <- " inst " нахождения НОКа" << endl;
	cout << "helptif <- " inst " превращения из правильной дроби в неправильную" << endl;
	cout << "helpprop3 <- " inst " нахождения пропорции зная три дроби" << endl;
	cout << "helpftf <- " inst " превращения в обычную дробь из десятичных числителей и знаменателей" << endl;
	cout << "helpian <- " inst " нахождения информации о числе" << endl;
	cout << "helpian2 <- " inst " нахождения информации о двух числах" << endl;
	cout << "helpsod <- " inst " нахождении сложении всех цифр в числе" << endl;
	cout << "helprt <- " inst " нахождения корней числа" << endl;
	cout << "helpmo <- " inst " нахождению всех чисел кратные заданному" << endl;
	cout << "helpshowtext <- " inst " настройке показа подсказок" << endl;
	cout << "helpwhilefunc <- " inst " настройке повтору функции" << endl;


	cout << "Очистить всю консоль -> clear" << endl;
	cout << "Выйти из программы -> exit" << endl;
	cout << "Переход на репозиторий github -> github" << endl;
	cout << endl << endl;

	cout << "calc <- Калькулятор" << endl;
	cout << "sqrt <- Найти квадратный корень" << endl;
	cout << "cbrt <- Найти кубический корень" << endl;

	cout << "calcperc <- Калькулятор процентов" << endl;
	cout << "tdap <- В десятичную дробь и проценты" << endl;
	cout << "fd <- Вывести делители числа" << endl;
	cout << "fp <- Проверить на простое число" << endl;
	cout << "dtf <- Из десятичной дроби в обыкновенную" << endl;
	cout << "itm <- Из неправильной дроби в обыкновенную" << endl;
	cout << "calcfrac <- Калькулятор дробей" << endl;
	cout << "gcd <- Найти НОД" << endl;
	cout << "lcm <- Найти НОК" << endl;
	cout << "tif <- Из правильной дроби в неправильную" << endl;
	cout << "prop3 <- Найти пропорцию зная 3 дроби" << endl;
	cout << "ftf <- Из дроби с плавающей запятой в обыкновенную" << endl;
	cout << "ian <- Информация о числе" << endl;
	cout << "ian2 <- Информация о двух числах" << endl;
	cout << "sod <- Сложить все цифры" << endl;
	cout << "rt <- Найти корни числа" << endl;
	cout << "mo <- Найти числа кратные заданному" << endl;
	cout << endl << endl;
	cout << "Другое: " << endl;
	cout << "Включить подсказки в функциях -> showtext" << endl;
	cout << "Выключить подсказки в функциях -> disabletext" << endl;
	cout << "Посмотреть статус показа текста -> checktext" << endl;
	cout << endl;
	cout << "Включить повтор функций -> enablewhilefunc" << endl;
	cout << "Выключить повтор функций -> disablewhilefunc" << endl;
	cout << "Посомтреть статус повтора функций -> checkwhilefunc" << endl;
}

//ЧАСТЬ ПРОГРАММЫ С ВВОДОМ ЧЕГО ЛИБО

//Калькулятор, calculator
void calc(bool showtext, bool whilefunc) {
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
	if (c == '+') {
		if (showtext) cout << "Ответ: ";
		cout << a + b << endl;
	}
	else if (c == '-') {
		if (showtext) cout << "Ответ: ";
		cout << a - b << endl;
	}
	else if (c == '*') {
		if (showtext) cout << "Ответ: ";
		cout << a * b << endl;
	}
	else if (c == '/' || c == ':') {
		if (showtext) cout << "Ответ: ";
		cout << a / b << endl;
	}
	else if (c == '%') {
		if (showtext) cout << "Ответ: ";
		cout << (int)a % (int)b << endl;
	}
	else if (c == '^') {
		if (showtext) cout << "Ответ: ";
		cout << pow(a, b) << endl;
	}
	else if (c == '!') {
		if (showtext) cout << "Ответ: ";
		cout << factorial(a + b) << endl;
	}
	else if (c == 'g') {
		if (showtext) cout << "Ответ: ";
		cout << gcd((int)a, (int)b) << endl;
	}
	else if (c == 'l') {
		if (showtext) cout << "Ответ: ";
		cout << lcm((int)a, (int)b) << endl;
	}
	if (a == 0 && b == 0 && whilefunc) { whilefunc = false; }
	if (whilefunc) { calc(showtext, whilefunc); }
}

//Калькулятор процентов, calculator percent
void calcperc(bool showtext, bool whilefunc) {
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

	if (n == 0 && p == 0 && whilefunc) { whilefunc = false; }
	if (whilefunc) { calcperc(showtext, whilefunc); }
}

//Нахождение корня, find root
void findrt(bool showtext, bool whilefunc) {
	double number;
	double root;
	if (showtext) cout << "Введите число: ";
	cin >> number;
	if (showtext) cout << "Введите корень: ";
	cin >> root;
	if (showtext) cout << "Квадратный корень: ";
	cout << sqrt(number) << endl;
	if (showtext) cout << "Кубический корень: ";
	cout << rt(number, 3) << endl;
	if (showtext) cout << "Заданный вами корень: ";
	cout << rt(number, root) << endl;

	if (number == 0 && root == 0 && whilefunc) { whilefunc = false; }
	if (whilefunc) { findrt(showtext, whilefunc); }
}

//Превратить число в десятичное и проценты, to decimal and percent
void tdap(bool showtext, bool whilefunc) {
	double fullpart, numerator, denominator;
	if (showtext) cout << "Введите целую часть: ";
	cin >> fullpart;
	if (showtext) cout << "Введите числитель: ";
	cin >> numerator;
	if (showtext) cout << "Введите знаменатель: ";
	cin >> denominator;
	if (fullpart != 0) {
		numerator = fullpart * denominator + numerator;
		fullpart = 0;
	}
	double decimal = numerator / denominator;
	double percent = numerator / (denominator / 100);
	if (showtext) cout << "Десятичная: ";
	cout << decimal << endl;
	if (showtext) cout << "Процент: ";
	cout << percent << "%" << endl;

	if (fullpart == 0 && numerator == 0 && denominator && whilefunc) { whilefunc = false; }
	if (whilefunc) { tdap(showtext, whilefunc); }
}

//Проверить на простое число, find prime
void findPrime(bool showtext, bool whilefunc) {
	int num;
	if (showtext) cout << "Введите число: " << endl;
	cin >> num;
	if (isPrime(num))
		cout << "Число простое" << endl;
	else
		cout << "Число не простое" << endl;

	if (num == 0 && whilefunc) { whilefunc = false; }
	if (whilefunc) { findPrime(showtext, whilefunc); }
}

//Посмотреть делители числа, find divisors
void findDivisors(bool showtext, bool whilefunc) {
	int num;
	if (showtext) cout << "Введите число: " << endl;
	cin >> num;
	vector<int> divisors = Divisors(num);
	for (int div : divisors) {
		cout << div << ", ";
	}
	cout << endl;

	if (num == 0 && whilefunc) { whilefunc = false; }
	if (whilefunc) { findDivisors(showtext, whilefunc); }
}

//Из десятичной дроби в обыкновенную, decimal to fraction
void dtf(bool showtext, bool whilefunc) {
	double decimal;
	Fraction result;
	if (showtext) cout << "Введите десятичную дробь: ";
	cin >> decimal;
	result = decimalToFraction(decimal);
	result.print();

	if (decimal == 0 && whilefunc) { whilefunc = false; }
	if (whilefunc) { dtf(showtext, whilefunc); }
}

//Из неправильной дроби в правильную, improper to mixed
void itm(bool showtext, bool whilefunc) {
	Fraction user, result;
	if (showtext) cout << "Введите числитель: ";
	cin >> user.numerator;
	if (showtext) cout << "Введите знаменатель: ";
	cin >> user.denominator;
	result = improperToMixed(user.numerator, user.denominator);
	result.print();

	if (user.numerator == 0 && user.denominator == 0 && whilefunc) { whilefunc = false; }
	if (whilefunc) { itm(showtext, whilefunc); }
}

//Калькулятор дробей, calculator fraction
void calcfrac(bool showtext, bool whilefunc) {
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
		if (showtext) cout << "Ответ: ";
		c.print();
	}
	else if (action == '-') {
		c = subFraction(a, b, itm, reduce);
		if (showtext) cout << "Ответ: ";
		c.print();
	}
	else if (action == '*') {
		c = mulFraction(a, b, itm, reduce);
		if (showtext) cout << "Ответ: ";
		c.print();
	}
	else if (action == '/') {
		c = divFraction(a, b, itm, reduce);
		if (showtext) cout << "Ответ: ";
		c.print();
	}
	else
		cout << "Неправильное действие, на будущее есть только +, -, *, /" << endl;

	if (a.fullpart == 0 && a.numerator == 0 && a.denominator == 0 && b.fullpart == 0 && b.numerator == 0 && b.denominator == 0 && whilefunc) { whilefunc = false; }
	if (whilefunc) { calcfrac(showtext, whilefunc); }
}

void github() { system("start https://github.com/rucomen5978/math"); }

//В неправильную дробь, to imporper fraction
void tif(bool showtext, bool whilefunc) { //И
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

	if (frac1.fullpart == 0 && frac1.numerator == 0 && frac1.denominator && whilefunc || frac1.fullpart == 0 && whilefunc) { whilefunc = false; }
	if (whilefunc) { tif(showtext, whilefunc); }
}

//Найти НОД, find greatest common divisor
void findgcd(bool showtext, bool whilefunc) {
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

	if (a == 0 && b == 0 && whilefunc) { whilefunc = false; }
	if (whilefunc) { findgcd(showtext, whilefunc); }
}

//Найти НОК, find least common multiple
void findlcm(bool showtext, bool whilefunc) {
	int a, b;
	if (showtext) cout << "Введите первое число: ";
	cin >> a;
	if (showtext) cout << "Введите второе число: ";
	cin >> b;

	if (showtext) cout << "Ответ: " << lcm(a, b) << endl;
	else cout << lcm(a, b) << endl;
	cout << lcm(a, b) << "/" << a << "=" << lcm(a, b) / a << endl;
	cout << lcm(a, b) << "/" << b << "=" << lcm(a, b) / b << endl;

	if (a == 0 && b == 0 && whilefunc) { whilefunc = false; }
	if (whilefunc) { findlcm(showtext, whilefunc); }
}

//Найти пропорцию 3, find proportion 3
void findprop3(bool showtext, bool whilefunc) {
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

	if (frac1.fullpart == 0 && frac1.numerator == 0 && frac1.denominator == 0 && frac2.fullpart == 0 && frac2.numerator == 0 && frac2.denominator == 0 && frac3.fullpart == 0 && frac3.numerator == 0 && frac3.denominator == 0 && whilefunc) { whilefunc = false; }
	if (whilefunc) { findprop3(showtext, whilefunc); }
}

//Информация о числе, info about number
void ian(bool showtext, bool whilefunc) {
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

	if (number == 0 && whilefunc) { whilefunc = false; }
	if (whilefunc) { ian(showtext, whilefunc); }
}

//Информация о двух числах, info about number 2
void ian2(bool showtext, bool whilefunc) {
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

	if (number1 == 0 && number2 == 0 && whilefunc) { whilefunc = false; }
	if (whilefunc) { ian2(showtext, whilefunc); }
}

//Из дроби с плаващей запятой в обыкновенную, float to fraction
void ftf(bool showtext, bool whilefunc) {
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

	if (a == 0 && b == 0 && whilefunc) { whilefunc = false; }
	if (whilefunc) { ftf(showtext, whilefunc); }
}

//Сумма цифр, sum of digits
void sod(bool showtext, bool whilefunc) {
	double number;
	if (showtext) cout << "Введите число: ";
	cin >> number;
	cout << sumOfDigits(number) << endl;

	if (number == 0 && whilefunc) { whilefunc = false; }
	if (whilefunc) { sod(showtext, whilefunc); }
}

//Числа кратные заданному, multiples of
void mo(bool showtext, bool whilefunc) {
	int number, count;
	if (showtext) cout << "Введите число: ";
	cin >> number;
	if (showtext) cout << "Количество чисел: ";
	cin >> count;
	int i = 1;
	while (i != count+1) {
		cout << number * i << " ";
		i++;
	}
	cout << endl;

	if (number == 0 && whilefunc) { whilefunc = false; }
	if (whilefunc) { mo(showtext, whilefunc); }
}

void consolemenu() {
	string action;
	cout << ":";
	cin >> action;
	if (action == "helpcalc")
		helpcalc();
	else if (action == "helpcalcperc")
		helpcalcperc();
	else if (action == "helptdap")
		helptdap();
	else if (action == "helpfd")
		helpfd();
	else if (action == "helpfp")
		helpfp();
	else if (action == "helpdtf")
		helpdtf();
	else if (action == "helpitm")
		helpitm();
	else if (action == "helpcalcfrac")
		helpcalcfrac();
	else if (action == "helpgcd")
		helpgcd();
	else if (action == "helplcm")
		helplcm();
	else if (action == "helptif")
		helptif();
	else if (action == "helpprop3")
		helpprop3();
	else if (action == "helpftf")
		helpftf();
	else if (action == "helpian")
		helpian();
	else if (action == "helpian2")
		helpian2();
	else if (action == "helpsod")
		helpsod();
	else if (action == "helprt")
		helprt();
	else if (action == "helpmo")
		helpmo();
	else if (action == "helpwhilefunc")
		helpwhilefunc();
	else if (action == "helpshowtext")
		helpshowtext();


	else if (action == "github")
		github();

	else if (action == "help")
		help();
	else if (action == "calc")
		calc(showtext, whilefunc);
	else if (action == "calcperc")
		calcperc(showtext, whilefunc);
	else if (action == "tdap")
		tdap(showtext, whilefunc);
	else if (action == "fd")
		findDivisors(showtext, whilefunc);
	else if (action == "fp")
		findPrime(showtext, whilefunc);
	else if (action == "dtf")
		dtf(showtext, whilefunc);
	else if (action == "itm")
		itm(showtext, whilefunc);
	else if (action == "calcfrac")
		calcfrac(showtext, whilefunc);
	else if (action == "clear")
		system("cls");
	else if (action == "tif")
		tif(showtext, whilefunc);
	else if (action == "gcd")
		findgcd(showtext, whilefunc);
	else if (action == "lcm")
		findlcm(showtext, whilefunc);
	else if (action == "prop3")
		findprop3(showtext, whilefunc);
	else if (action == "ftf")
		ftf(showtext, whilefunc);
	else if (action == "ian")
		ian(showtext, whilefunc);
	else if (action == "ian2")
		ian2(showtext, whilefunc);
	else if (action == "sod")
		sod(showtext, whilefunc);
	else if (action == "rt")
		findrt(showtext, whilefunc);
	else if (action == "mo")
		mo(showtext, whilefunc);
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
	else if (action == "enablewhilefunc") {
		cout << "Повторение функций включено" << endl;
		whilefunc = true;
	}
	else if (action == "disablewhilefunc") {
		cout << "Повторение функций отключено" << endl;
		whilefunc = false;
	}
	else if (action == "checkwhilefunc")
		cout << whilefunc << endl;

	consolemenu();
}
