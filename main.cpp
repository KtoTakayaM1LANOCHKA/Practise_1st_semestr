#include <iostream>
#include <string>
using namespace std;


class Student{

    public:
        string name;
        int age,grade;

};



int add(){
    Student student1;
    cout<<"Введите ФИО:";
    string n;
    cin>>n;
    Student:student1;
    student1.name =n

}

int del(){

}

int upload_base_txt(){

}

int upload_base_bin(){

}

int show_table(){

}

int write_in_file(){

}

int re_information(){

}

int sort(){

}

int txt_to_bin(){

}

int choise(){
    int flag =1;
    while(flag!=0){
        cout <<"Выберите действие:"<<endl;
        cout <<"1. Добавить студента\n2.Удалить студента\n3.Загрузить базу данных(Текстовый файл)\n4.Загрузить базу данных(Бинарный файл)\n";
        cout<<"5.Вывести таблицу\n6.Записать данные в файл\n7.Редактирование информации\n8.Сортировка\n9.Перевод из текстого файла в бинарный\n0.Выход";

        int pick;
        cin>>pick;

        if (pick ==0){
            flag = 0;
         }else{
            switch (pick)
            {
            case 1:
                add();
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
                show_table();
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
                cout<<"Неправильный ввод!";
                break;
            }
         }
        }
        cout<<"До свидания!";
}





int main(){
    cout<<"Здравствуйте!\n";
    choise();
    return 0;
}