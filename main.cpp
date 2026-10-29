
#include <iostream>
#include <string>
#include <clocale>
#include <vector>
#include <iomanip>
#include <sstream>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

// Класс студента
class Student
{
public:
    string name;
    int birth;
    int course;

    vector<int> grade;
    vector<string> discipline;
};

// Функция для красивого вывода ячейки
void printCell(const string &text, int width)
{
    int length = 0;

    // Учитываем русские символы UTF-8
    for (unsigned char c : text)
    {
        if ((c & 0xC0) != 0x80)
            length++;
    }

    cout << "| " << text;

    for (int i = length; i < width; i++)
    {
        cout << " ";
    }

    cout << " ";
}

// Вывод таблицы студентов
void show_table(const vector<Student> &students)
{
    if (students.empty())
    {
        cout << "База студентов пуста!\n";
        return;
    }

    cout << "\nБАЗА ДАННЫХ СТУДЕНТОВ\n";

    cout << string(96, '-') << endl;

    // Заголовки таблицы
    printCell("N", 4);
    printCell("ФИО", 35);
    printCell("Год", 6);
    printCell("Курс", 6);
    printCell("Оценки", 16);
    printCell("Средний", 10);

    cout << "|\n";

    cout << string(96, '-') << endl;

    // Перебираем студентов
    for (int i = 0; i < students.size(); i++)
    {
        const Student &s = students[i];

        printCell(to_string(i + 1), 4);
        printCell(s.name, 35);
        printCell(to_string(s.birth), 6);
        printCell(to_string(s.course), 6);

        // Собираем оценки
        string grades;
        double sum = 0;

        for (int j = 0; j < s.grade.size(); j++)
        {
            grades += to_string(s.grade[j]) + " ";
            sum += s.grade[j];
        }

        printCell(grades, 16);

        // Средний балл
        double average = 0;

        if (!s.grade.empty())
        {
            average = sum / s.grade.size();
        }

        ostringstream result;

        result << fixed
               << setprecision(2)
               << average;

        printCell(result.str(), 10);

        cout << "|\n";
    }

    cout << string(96, '-') << endl;
}

// Добавление студентов
void add(vector<Student> &students)
{
    char choice = 'y';

    while (choice == 'y' || choice == 'Y')
    {
        Student s;

        cout << "\nВведите ФИО студента: ";
        getline(cin >> ws, s.name);

        cout << "Введите год рождения: ";
        cin >> s.birth;

        cout << "Введите курс студента: ";
        cin >> s.course;

        // По варианту 25: четыре предмета
        const int count = 4;

        // Ввод предметов
        for (int i = 0; i < count; i++)
        {
            string discipline;

            cout << "Введите предмет "
                 << i + 1 << ": ";

            getline(cin >> ws, discipline);

            s.discipline.push_back(discipline);
        }

        // Ввод оценок
        for (int j = 0; j < s.discipline.size(); j++)
        {
            int grade;

            cout << "Введите оценку по "
                 << s.discipline[j] << ": ";

            cin >> grade;

            // Проверка оценки
            while (grade < 2 || grade > 5)
            {
                cout << "Оценка должна быть от 2 до 5: ";
                cin >> grade;
            }

            s.grade.push_back(grade);
        }

        // Добавляем студента в общую базу
        students.push_back(s);

        cout << "Студент успешно добавлен!\n";

        cout << "Добавить ещё студента? (y/n): ";
        cin >> choice;
    }
}

// Удаление студента (пока заглушка)
int del()
{
    return 0;
}

// Загрузка из текстового файла
int upload_base_txt()
{
    return 0;
}

// Загрузка из бинарного файла
int upload_base_bin()
{
    return 0;
}

// Вывод данных в файл
int write_in_file()
{
    return 0;
}

// Редактирование информации
int re_information()
{
    return 0;
}

// Сортировка
int sort()
{
    return 0;
}

// Перевод текстового файла в бинарный
int txt_to_bin()
{
    return 0;
}

// Запрос по варианту №25 (пока заглушка)
void variant25(const vector<Student> &students)
{
    cout << "Запрос по варианту 25 пока не реализован.\n";
}

// Главное меню
void choise()
{
    vector<Student> students;

    int flag = 1;

    while (flag != 0)
    {
        cout << "\n========== МЕНЮ ==========\n";

        cout << "1. Добавить студента\n"
             << "2. Удалить студента\n"
             << "3. Загрузить базу (текстовый файл)\n"
             << "4. Загрузить базу (бинарный файл)\n"
             << "5. Вывести таблицу\n"
             << "6. Записать данные в файл\n"
             << "7. Редактировать информацию\n"
             << "8. Сортировка\n"
             << "9. Перевод текстового файла в бинарный\n"
             << "10. Запрос по варианту 25\n"
             << "0. Выход\n";

        cout << "Выберите действие: ";

        int pick;
        cin >> pick;

        switch (pick)
        {
        case 0:
            flag = 0;
            break;

        case 1:
            add(students);
            break;

        case 2:
            del();
            break;

        case 3:
            upload_base_txt();
            break;

        case 4:
            upload_base_bin();
            break;

        case 5:
            show_table(students);
            break;

        case 6:
            write_in_file();
            break;

        case 7:
            re_information();
            break;

        case 8:
            sort();
            break;

        case 9:
            txt_to_bin();
            break;

        case 10:
            variant25(students);
            break;

        default:
            cout << "Неправильный ввод!\n";
            break;
        }
    }

    cout << "До свидания!\n";
}

int main()
{
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif

    setlocale(LC_ALL, ".UTF8");

    cout << "Здравствуйте!\n";

    choise();

    return 0;
}
