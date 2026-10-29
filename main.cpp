#include <iostream>
#include <string>
#include <clocale>
#include <vector>
using namespace std;

class Student
{

public:
    string name;
    int age, birth;
    vector<int> grade;
    vector<string> discipline;
};

#include <iomanip>
#include <sstream>

// Печать ячейки с учётом русских букв UTF-8
void printCell(const string &text, int width)
{
    int length = 0;

    for (unsigned char c : text)
    {
        if ((c & 0xC0) != 0x80)
            length++;
    }

    cout << "| " << text;

    for (int i = length; i < width; i++)
        cout << " ";

    cout << " ";
}

void show_table(const vector<Student> &students)
{
    if (students.empty())
    {
        cout << "База студентов пуста!\n";
        return;
    }

    cout << "\nБАЗА ДАННЫХ СТУДЕНТОВ\n";

    // Заголовок таблицы
    printCell("N", 4);
    printCell("ФИО", 35);
    printCell("Год", 6);
    printCell("Курс", 6);
    printCell("Оценки", 16);
    printCell("Средний", 10);
    cout << "|\n";

    cout << string(96, '-') << "\n";

    for (int i = 0; i < students.size(); i++)
    {
        const Student &s = students[i];

        printCell(to_string(i + 1), 4);
        printCell(s.name, 35);
        printCell(to_string(s.birth), 6);
        printCell(to_string(s.course), 6);

        // Собираем оценки в одну строку
        string grades;
        double sum = 0;

        for (int j = 0; j < s.grade.size(); j++)
        {
            grades += to_string(s.grade[j]) + " ";
            sum += s.grade[j];
        }

        printCell(grades, 16);

        // Вычисляем средний балл
        double average = 0;

        if (!s.grade.empty())
            average = sum / s.grade.size();

        ostringstream result;
        result << fixed << setprecision(2) << average;

        printCell(result.str(), 10);
        cout << "|\n";
    }

    cout << string(96, '-') << "\n";
}

void add(vector<Student> &students)
{
    char choice = 'y';

    while (choice == 'y')
    {
        Student s;

        cout << "Введите ФИО студента: ";
        getline(cin >> ws, s.name);

        cout << "Введите год рождения: ";
        cin >> s.birth;

        cout << "Введите количество предметов: ";
        int count;
        cin >> count;

        // Ввод предметов
        for (int i = 0; i < count; i++)
        {
            string discipline;

            cout << "Введите предмет: ";
            getline(cin >> ws, discipline);

            s.discipline.push_back(discipline);
        }

        // Ввод оценок
        for (int j = 0; j < s.discipline.size(); j++)
        {
            int grade;

            cout << "Введите оценку по " << s.discipline[j] << ": ";

            cin >> grade;

            s.grade.push_back(grade);
        }

        // Добавляем готового студента
        students.push_back(s);

        cout << "Добавить ещё студента? (y/n): ";
        cin >> choice;
    }
}

int del()
{
    return 0;
}

int upload_base_txt()
{
    return 0;
}

int upload_base_bin()
{
    return 0;
}

int show_table(vector<Student> &students)
{
    for (int i = 0; i < students.size(); i++)
    {
        cout << "Имя\tГод рождения\tПредмет\tОценка" << endl;
        cout << students[i].name << "\t";
        cout << students[i].birth << "\t";
        for (int j = 0; j < students[i].discipline.size(); j++)
        {
            cout << students[i].discipline[j] << endl;
            cout << students[i].grade[j] << endl;
        }
        cout << "-------------" << endl;
    }
    return 0;
}

int write_in_file()
{
    return 0;
}

int re_information()
{
    return 0;
}

int sort()
{
    return 0;
}

int txt_to_bin()
{
    return 0;
}

int choise()
{
    int flag = 1;
    vector<Student> students;
    while (flag != 0)
    {
        cout << "Выберите действие:" << endl;
        cout << "1. Добавить студента\n2.Удалить студента\n3.Загрузить базу данных(Текстовый файл)\n4.Загрузить базу данных(Бинарный файл)\n";
        cout << "5.Вывести таблицу\n6.Записать данные в файл\n7.Редактирование информации\n8.Сортировка\n9.Перевод из текстого файла в бинарный\n0.Выход\n";

        int pick;
        cin >> pick;

        if (pick == 0)
        {
            flag = 0;
        }
        else
        {
            switch (pick)
            {
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

            default:
                cout << "Неправильный ввод!";
                break;
            }
        }
    }
    cout << "До свидания!";
    return 0;
}

int main()
{
    setlocale(LC_ALL, ".UTF8");
    cout << "Здравствуйте!\n";
    choise();
    return 0;
}