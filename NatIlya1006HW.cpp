//Задание.
//Создайте шаблонный класс матрица. Необходимо реализовать динамическое выделение памяти, очистку памяти,
//заполнение матрицы с клавиатуры, заполнение случайными значениями, отображение матрицы, арифметические
//операции с помощью перегруженных операторов(+, –,
//    *, / ), поиск максимального и минимального элемента.



#include <iostream>
#include <ctime>
#include "Windows.h"
using namespace std;

//Шаблонный класс "Матрица".
template <class T>
class Matrix
{
private:
    int amountOfElements; // Количетство элементов в строке.
    int amountOfLines; // Количество строк.
    int maxElement; // Максимальный элемент.
    int minElement; // Миниамльный элемент.
    T* line = new <T>; // Динамический массив строк.
    T* elementsOfLine = new <T>; // Динамический массив элементов строки.
public:
    Matrix(int settingAmountOfElements, int settingAmountOfLines, bool isRand) : amountOfElements{ settingAmountOfElements }, amountOfLines{ settingAmountOfLines } // Конструктор класса.
    {
        // Если значение переменной "isRand" типа bool является true, то матрица заполняется случайными числами. Иначе, пользователь самостоятельно заполняет матрицу.
        if (isRand)
        {
            srand(time(0));
            for (int i = 0; i < amountOfLines; i++)
            {
                for (int j = 0; j < amountOfElements; j++)
                {
                    elementsOfLine[j] = rand() % 100;
                    setMaxMin(i, j);
                }
                line[i] = elementsOfLine;
            }
        }
        else
        {
            for (int i = 0; i < amountOfLines; i++)
            {
                for (int j = 0; j < amountOfElements; j++)
                {
                    cout << "Введите " << j + 1 << "-й элемент строки " << i + 1 << ":";
                    cin << *elementsOfLine[j];
                    setMaxMin(i, j);
                }
                line[i] = elementsOfLine;
            }
        }
    };

    // Печать матрицы.
    void print()
    {
        for (int i = 0; i < amountOfLines; i++)
        {   
            T* lineElements = new <T>;
            lineElements = *line[i];
            for (int j = 0; j < amountOfElements; j++)
            {
                cout << lineElements[j] << ' ';
            }
            cout << '\n';
        }
    }

    // Установка минимального и максимальных элементов. Изначально самый первый элемент матрицы задаётся как максимальный и минимальный элемент, 
    // если дальше будут найдены большие или меньшие значения, то они будут записаны в соответствующие переменные.
    void setMaxMin(int XIndex, int YIndex)
    {
        if (XIndex = 0 && YIndex = 0)
        {
            maxElement = elementsOfLine[YIndex];
            minElement = elementsOfLine[YIndex];
        }
        else if (maxElement < elementsOfLine[YIndex])
        {
            maxElement = elementsOfLine[YIndex]
        }
        else if (minElement > elementsOfLine[YIndex])
        {
            minElement = elementsOfLine[YIndex];
        }
    }

    // Возвращение максимального элемента матрицы.
    int returnMaxElement() { return maxElement; }

    // Возвращение минимального элемента матрицы.
    int returnMinElement() { return minElement; }

    // Возвращение элемента по его индексам.
    int returnElement(int XIndex, int YIndex)
    {
        T* lineElements = new <T>;
        lineElements = *line[XIndex];
        return *lineElements[YIndex];
    }


    // Деструктор класса.
    ~Matrix()
    {
        if (line != nullptr)
            delete[] line;
        if (elementsOfLine != nullptr)
            delete[] elementsOfLine;

        cout << "(Отработал деструктор.)";
    };

};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Hello World!\n";
    bool isRand;
    do {
        cout << "Заполнить матрицу вручную?\n 1 - да, 0 - нет.";
        cin >> isRand;
        if (isRand != 1 || isRand != 0)
            cout << "Повторите ввод.\n"; 
    } while (isRand != 1 || isRand != 0);

    cout << "Введите количество элементов в строке: ";
    int settingAmountOfElements;
    cin >> settingAmountOfElements;

    cout << "Введите количество строк: ";
    int settingAmountOfLines;
    cin >> settingAmountOfLines;

    Matrix<int> matrix1(settingAmountOfElements, settingAmountOfLines, isRand);

    int choice;
    do {
        cout << "Введите команду: \n(1 - напечатать матрицу; 2 - вывести минимальный элемент матрицы; 3 - вывести максимальный элемент матрицы; 4 - выполнить арифметические операции с элементами матрицыю; 5 - выйти из программы)\n";
        switch (choice)
        {

        case 1: 
        {
            cout << "Печать матрицы.\n"; 
            matrix1.print();
            break;
        }

        case 2: 
        {
            cout << "Минимальный элемент матрицы равен: " << matrix1.returnMinElement() << ".\n";
            break;
        }

        case 3: 
        {
            cout << "Максимальный элемент матрицы равен: " << matrix1.returnMaxElement() << ".\n";
            break;
        }

        case 4: 
        {
            cout << "Выполнение арифметических операций над элементами матрицы.\n";

            cout << "Введите индексы(по 'x' и по 'y') первого элемента: ";
            int firstElementXIndex, firstElementYIndex;
            cin >> firstElementXIndex >> firstElementYIndex;

            cout << "Введите индексы(по 'x' и по 'y') второго элемента: ";
            int secondElementXIndex, secondElementYIndex;
            cin >> secondElementXIndex >> secondElementYIndex;

            int operation;
            do {
                cout << "Выполнить: 1 - сложение; 2 - вычитание; 3 - умножение; 4 - деление;";
                cin >> operation;

                switch (operation) 
                {
                case 1: 
                {
                    cout << "Результат сложения равен: " << matrix1.returnElement(firstElementXIndex, firstElementYIndex) + matrix1.returnElement(secondElementXIndex, secondElementYIndex);
                    break;
                }

                case 2: 
                {
                    cout << "Результат вычитания равен: " << matrix1.returnElement(firstElementXIndex, firstElementYIndex) - matrix1.returnElement(secondElementXIndex, secondElementYIndex);
                    break;
                }

                case 3: 
                {
                    cout << "Результат умножения равен: " << matrix1.returnElement(firstElementXIndex, firstElementYIndex) * matrix1.returnElement(secondElementXIndex, secondElementYIndex);
                    break;
                }

                case 4: 
                {
                    cout << "Результат деления равен: " << matrix1.returnElement(firstElementXIndex, firstElementYIndex) / matrix1.returnElement(secondElementXIndex, secondElementYIndex);
                    break;
                }

                default:
                {
                    cout << "Такой операции нет. Повторите ввод.\n";
                    break;
                }
                }
            } while (operation != 1 || operation != 2 || operation != 3 || operation != 4);

        }

        case 5: 
        {
            cout << "Выход из программы.\n";
            matrix1.~Matrix();
            break;
        }

        default:
            cout << "Такой команды нет. Повторите ввод.\n";
            break;
        }

    } while (choice != 5);
    // Оно не работает.
}

