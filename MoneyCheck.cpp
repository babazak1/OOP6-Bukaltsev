#include <iostream>
#include "Moneydll.h"
#include "Windows.h"

using namespace std;
using namespace MoneyOperations;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    try {
        Money m1(150, 75);  
        Money m2(50, 30);   
        Money m3(200.45);   

        cout << "m1: " << m1.toString() << endl;
        cout << "m2: " << m2.toString() << endl;
        cout << "m3: " << m3.toString() << endl;

        cout << "\nАрифметичні операції:" << endl;
        cout << "m1 + m2 = " << (m1 + m2).toString() << endl;
        cout << "m1 - m2 = " << (m1 - m2).toString() << endl;
        cout << "m1 * 1.5 = " << (m1 * 1.5).toString() << endl;
        cout << "m1 / 2 = " << (m1 / 2).toString() << endl;
        cout << "m1 / m2 = " << (m1 / m2) << " (коефіцієнт)" << endl;

        cout << "\nПорівняння:" << endl;
        cout << "m1 == m2: " << (m1 == m2 ? "так" : "ні") << endl;
        cout << "m1 != m2: " << (m1 != m2 ? "так" : "ні") << endl;
        cout << "m1 > m2: " << (m1 > m2 ? "так" : "ні") << endl;
        cout << "m1 < m3: " << (m1 < m3 ? "так" : "ні") << endl;

    }
    catch (const exception& e) {
        cout << "Помилка: " << e.what() << endl;
    }

    return 0;
}
