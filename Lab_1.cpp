#include <iostream>
#include <clocale>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;
#define e 2.71828182845904523536
#define E 0.001

void task_1();
void task_2();
void task_3_1();
void task_3_2();
void task_3_3();
void task_3_4();
void task_3_5();
void task_3_6();
void task_3_7();
void task_4();
double f(double a, double b);

int main() {
    setlocale(LC_ALL, "RUS");
    int choice1, choice2;

    do {
        cout << "\n=== ГЛАВНОЕ МЕНЮ ===\n";
        cout << "1 - Задание 1\n";
        cout << "2 - Задание 2\n";
        cout << "3 - Задание 3 (с подзаданиями)\n";
        cout << "4 - Задание 4\n";
        cout << "0 - Выход\n";
        cout << "Выберите задание: ";
        cin >> choice1;

        switch (choice1) {
        case 1:
            task_1();
            break;
        case 2:
            task_2();
            break;
        case 3:
            cout << "\n--- Задание 3 ---\n";
            cout << "1 - Подзадание 3.1\n";
            cout << "2 - Подзадание 3.2\n";
            cout << "3 - Подзадание 3.3\n";
            cout << "4 - Подзадание 3.4\n";
            cout << "5 - Подзадание 3.5\n";
            cout << "6 - Подзадание 3.6\n";
            cout << "7 - Подзадание 3.7\n";
            cout << "0 - Назад в главное меню\n";
            cout << "Выберите подзадание: ";
            cin >> choice2;

            switch (choice2) {
            case 1: task_3_1(); break;
            case 2: task_3_2(); break;
            case 3: task_3_3(); break;
            case 4: task_3_4(); break;
            case 5: task_3_5(); break;
            case 6: task_3_6(); break;
            case 7: task_3_7(); break;
            case 0: cout << "Возврат в главное меню...\n"; break;
            default: cout << "Неверный выбор подзадания!\n"; break;
            }
            break; 
        case 4:
            task_4();
            break;
        case 0:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный выбор задания! Попробуйте ещё раз.\n";
            break;
        }
    } while (choice1 != 0);
    return 0;
}

void task_1() {
 
    double a, b;
    std::cout << "Введите a и b:";
    std::cin >> a >> b;
    std::cout << "Результат функции:" << f(a, b);
}

double f(double a, double b)
{
    double numerator = sin(a * a) + cos(b);
    double denominator = sqrt(1.0 + exp(1.0) / (a * a * a + 3.4 * b));
    return log(numerator / denominator);
}

void task_2() {
    const double EPS = 0.001;

    double x;

    cout << "Расчёт функции F(x) = 1 - 2x + 3x^2 - 4x^3 + ..." << endl;
    cout << "Точность: " << EPS << endl;

    cout << "\nВведите x: ";
    cin >> x;

    double sum = 0;
    double current_term;
    double previous_term = 0;
    double diff;
    int n = 1;

    do {
        // Вычисляем x^(n-1) умножением
        double power = 1;
        for (int i = 1; i <= n - 1; i++) {
            power = power * x;
        }

        // Определяем знак
        double sign;
        if (n % 2 == 1) {
            sign = 1;  // нечётный номер -> плюс
        }
        else {
            sign = -1; // чётный номер -> минус
        }

        // Текущий член
        current_term = sign * n * power;

        // Добавляем к сумме
        sum = sum + current_term;

        // Вычисляем разность
        if (n == 1) {
            diff = fabs(current_term);
        }
        else {
            diff = fabs(current_term - previous_term);
        }

        previous_term = current_term;
        n++;

    } while (diff > EPS);

    cout << "\nРезультат:" << endl;
    cout << "F(" << x << ") = " << sum << endl;
    cout << "Количество членов: " << n - 1 << endl;
}

void task_3_1()
{
    int n, i;          // объявили переменные

    cout << "Enter n: ";
    cin >> n;          // ввели n

    cout << "Divisors: ";

    for (i = 1; i <= n / 2; i++) {  // исправили for
        if (n % i == 0) {            // исправили = на ==
            cout << i << " ";        // исправили coun на cout
        }
    }

    cout << n << endl;  // добавили вывод самого числа
}

void task_3_2()
{
    int i, fn, n, y;          // объявили переменные (I -> i)

    cout << "Enter n: ";       // добавили ввод n
    cin >> n;                  // ввели n

    fn = 1;                    // начальное значение

    if (n % 2 == 0) {          // четное
        for (i = 2; i <= n; i += 2) {  // исправили: четные числа
            fn = fn * i;
        }
    }
    else {                    // нечетное
        for (i = 1; i <= n; i += 2) {  // исправили: нечетные числа
            fn = fn * i;
        }
    }

    y = fn;                     // присвоили результат
    cout << n << "!! = " << y << endl;  // вывели результат
}

void task_3_3()
{
    int n0, i;
    double p = 1.0;  // произведение, начинаем с 1

    cout << "Enter n: ";
    cin >> n0;

    // Первый способ: четные i (2,4,6...)
    // for (i = 2; i <= n; i += 2) {
    //     p = p * (1.0 / (i + 1));
    // }

    // Второй способ: нечетные i (1,3,5...)
    for (i = 1; i <= n0; i += 2) {
        p = p * ((i + 1.0) / i);
    }

    cout << "Product = " << p << endl;

    int n, k, m;        // объявили переменные
    double x, s, r, res; // вещественные переменные

    cout << "Enter n: ";
    cin >> n;
    cout << "Enter x: ";
    cin >> x;

    res = 0;  // итоговая сумма

    for (k = 1; k <= n; k++) {      // внешний цикл
        r = 0;  // сумма для текущего k
        for (m = k; m <= n; m++) {  // внутренний цикл
            s = (x + k) / m;        // считаем слагаемое
            r = r + s;              // добавляем к r
        }
        res = res + r;  // добавляем r к итогу
    }

    cout << "Result = " << res << endl;

}

void task_3_4() 
{
    int n, k, m;        // объявили переменные
    double x, s, r, res; // вещественные переменные

    cout << "Enter n: ";
    cin >> n;
    cout << "Enter x: ";
    cin >> x;

    res = 0;  // итоговая сумма

    for (k = 1; k <= n; k++) {      // внешний цикл
        r = 0;  // сумма для текущего k
        for (m = k; m <= n; m++) {  // внутренний цикл
            s = (x + k) / m;        // считаем слагаемое
            r = r + s;              // добавляем к r
        }
        res = res + r;  // добавляем r к итогу
    }

    cout << "Result = " << res << endl;

}

void task_3_5()
{
    int i, j, n;
    float sum = 0;  // общая сумма

    cout << "n: ";
    cin >> n;

    for (i = 1; i <= n; i++) {          // внешний цикл
        for (j = 1; j <= i; j++) {      // внутренний цикл
            sum = sum + 1.0 / (i + 2 * j);  // 1.0 для вещественного деления
        }
    }

    cout << fixed << setprecision(3);   // формат: 3 знака после запятой
    cout << "Result = " << sum << endl;

}

void task_3_6()
{
    int n = 0;  // счетчик
    float a, b, c;
    int i;

    cout << "a1 = ";
    cin >> b;
    cout << "a2 = ";
    cin >> c;

    for (i = 3; i <= 200; i++) {  // начинаем с 3-го элемента
        cout << "a" << i << " = ";
        cin >> a;

        // проверяем, больше ли c своих соседей b и a
        if (c > b && c > a) {
            n = n + 1;
        }

        // сдвигаем окно: b <- c, c <- a
        b = c;
        c = a;
    }

    cout << "Result = " << n << endl;

}

void task_3_7()
{
    int i, j;
    float p = 1.0;  // произведение начинается с 1

    for (i = 1; i <= 20; i++) {        // внешний цикл
        for (j = 1; j <= 20; j++) {    // внутренний цикл
            p = p * (1.0 / (i * i + j * j));  // умножаем, а не складываем
        }
    }

    cout << "Product = " << p << endl;
}

void task_4() 
{
    double x;

    cout << "Введите число: ";
    cin >> x;

    if (x >= -2 && x <= 2) {
        cout << "Число " << x << " попадает в диапазон [-2, 2]" << endl;
    }
    else {
        cout << "Число " << x << " НЕ попадает в диапазон [-2, 2]" << endl;
    }

}