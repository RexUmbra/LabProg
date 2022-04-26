#include <iostream> //
#include <stdio.h>  //
#include <stdlib.h> // подключение библиотек 
#include <vector>   //
#include <string>   //
#include <fstream>
using namespace std;//подключение пространство имен std
struct st1 //структура данных для студентов
{
    string sName; //объявление переменной имя студента
    int n,nGr, physics, math, informatics; // объявление переменных номера студента, номер группы, баллы физики математики и информатики
    double srBall; //объявление перменной среднего балла
    st1() // конструктор стандартных значений структуры
    {
        n = 0;                                              //
        sName = "";                                         //  инициализация стандартных значений переменным
        nGr = 0, physics = 0, math= 0, informatics = 0;     //
        srBall = 0;                                         //
    }
    void srBall_() //метод структуры подсчета среднего балла студента
    {
        srBall = (physics + math + informatics) / 3.0; // подсчет среднего балла студента
    }
    void print() //метод структуры для вывода параметорав студента
    {
        cout <<"\nstudent number: "<< n << "\nsurname: " << sName << "\nN group: " << nGr << "\nphysics: " << physics << "\nmath: " << math << "\ninformatics: " << informatics
            << "\nGPA: " << srBall << '\n';
    }
};


void addZap(vector<st1*> &vec)  //добавление нового студента
{
    st1 *zap = new st1(); // выделение памяти для объекта класса
    cout << "\nwrite surname\n";
    cin >> zap->sName;
    cout << "N group\n";
    cin >> zap->nGr;
    cout << "write physics math informatics\n";
    cin >> zap->physics >> zap->math >> zap->informatics;
    zap->srBall_();
    zap->n = vec.size();
    vec.push_back(zap); // добавление новой переменной в конец вектора
    
}


void make() // функция для создания нового файла
{
    FILE* studFile;
    if (fopen_s(&studFile,"studF.txt", "w"))
    {
        cout << "ERROR";
    }
    cout << "new file has been created\n";
    
    fclose(studFile);
}


void self(vector<st1*> &vec) // функция для собственного задания (выведение студентов отличников с фамилией, которая начинается с определенной буквы)
{
    cout << "\nwrite first letter of surname ";
    char a;
    cin >> a;
    for (int i = 0; i < vec.size(); i++) // цикл для обхода вектора 
    {
        if (vec[i]->sName[0] == a && vec[i]->srBall >= 9) // если средний балл больше или равно 9 и фамилия начинается на определенную букву..
        {
            vec[i]->print(); //выводится информация про студента
        }
    }
}


void change(vector<st1*> &vec) // функция для изменения данных студента
{
    cout << "\nwrite nomber of student who need change ";
    int ans;
    cin >> ans;
    cout << "write surname\n";
    cin >> vec[ans]->sName;
    cout << "N group\n";
    cin >> vec[ans]->nGr;
    cout << "write physics math informatics\n";
    cin >> vec[ans]->physics >> vec[ans]->math >> vec[ans]->informatics;
    vec[ans]->srBall_();
    vec[ans]->n = ans;
}


void deleteStud(vector<st1*> &vec) //функция для удаления студента
{
    cout << "\nwrite nomber of student who need delete ";
    int ans;
    cin >> ans;
    vec.erase(vec.begin() + ans); // удаление 
    for (int i = 0; i < vec.size();i++)
    {
        vec[i]->n = i;
    }
}



void sortStudN(vector<st1*> &vec, int order) // прямой выбор
{
    int n;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        n = i;
        for (int j = i + 1; j < vec.size(); j++)
            if ((order && (vec[n]->n < vec[j]->n)) || (!order && (vec[j]->n < vec[n]->n))) n = j;

        //if(max !=i)
        swap(vec[n],vec[i]);
    }            
}
void sortSname(vector<st1*> &vec, int order) //сортировка пузырьком для фамилии
{
    for(int i = 0; i < vec.size()-1;i++)
        for (int j = 0; j < vec.size() - 1 - i; j++)
        {
            int n = 0;
            while (vec[j]->sName[n] == vec[j + 1]->sName[n]) n++; //нахождение позиции первой отличающайся буквы в фамилии
            if ((order && vec[j]->sName[n] < vec[j + 1]->sName[n]) || (!order && vec[j]->sName[n] > vec[j + 1]->sName[n])) swap(vec[j], vec[j + 1]);
        }
}
void sortGroupN(vector<st1*> &vec, int order) // QuickSort
{
    int i = 0, j = vec.size() - 1, x = vec[vec.size()/2]->nGr;

    while (i <= j) {
        while (vec[i]->nGr < x) i++;
        while (vec[j]->nGr > x) j--;
        if (i <= j) {
            swap(vec[i], vec[j]);
            i++; j--;
        }
    }

}
void sortPhys(vector<st1*> &vec, int order)//сортировка по физике
{
    for (int i = 0; i < vec.size() - 1; i++)
        for (int j = 0; j < vec.size() - 1 - i; j++)
            if ((order && vec[j]->physics < vec[j + 1]->physics) || (!order && vec[j]->physics > vec[j + 1]->physics)) swap(vec[j], vec[j + 1]);
}
void sortMath(vector<st1*> &vec, int order)//сортировка по математике
{
    for (int i = 0; i < vec.size() - 1; i++)
        for (int j = 0; j < vec.size() - 1 - i; j++)
            if ((order && vec[j]->math < vec[j + 1]->math) || (!order && vec[j]->math > vec[j + 1]->math)) swap(vec[j], vec[j + 1]);
}
void sortInfo(vector<st1*> &vec, int order)//сортировка по информатике
{
    for (int i = 0; i < vec.size() - 1; i++)
        for (int j = 0; j < vec.size() - 1 - i; j++)
            if ((order && vec[j]->informatics < vec[j + 1]->informatics) || (!order && vec[j]->informatics > vec[j + 1]->informatics)) swap(vec[j], vec[j + 1]);
}
void sortGPA(vector<st1*> &vec, int order) // сортировка по среднему баллу
{
    for (int i = 0; i < vec.size() - 1; i++)
        for (int j = 0; j < vec.size() - 1 - i; j++)
            if ((order && vec[j]->srBall < vec[j + 1]->srBall) || (!order && vec[j]->srBall > vec[j + 1]->srBall)) swap(vec[j], vec[j + 1]);
}
void sort(vector<st1*> &vec) // меню выбора сортировки
{
    int ans1, ans2;
    cout << "\nwrite 0 to student number sort\nwrite 1 to surname sort\nwrite 2 to group number sort\nwrite 3 to physics ball sort\nwrite 4 to math ball sort"
         << "\nwrite 5 to informatics ball sort\nwrite 6 to GPA sort\n";
    cin >> ans1;
    cout << "write 0 if u want sort of direct order or write 1 if u want sort of reverse order\n";
    cin >> ans2;
    if (ans1 == 0) sortStudN(vec, ans2);
    if (ans1 == 1) sortSname(vec, ans2);
    if (ans1 == 2) sortGroupN(vec, ans2);
    if (ans1 == 3) sortPhys(vec, ans2);
    if (ans1 == 4) sortMath(vec, ans2);
    if (ans1 == 5) sortInfo(vec, ans2);
    if (ans1 == 6) sortGPA(vec, ans2);
}

string decryption(string str) //функиця расшифрования
{
    string str2;
    for (int i = 0; str[i]; i++)
    {
        str2.push_back(str[i]);
        if ((str[i] == 'B' || str[i] == 'C' || str[i] == 'D' || str[i] == 'F' || str[i] == 'G' || str[i] == 'H' || str[i] == 'J' || str[i] == 'K' ||
            str[i] == 'L' || str[i] == 'M' || str[i] == 'N' || str[i] == 'P' || str[i] == 'Q' || str[i] == 'R' || str[i] == 'S' || str[i] == 'T' ||
            str[i] == 'V' || str[i] == 'W' || str[i] == 'X' || str[i] == 'Z') ||
            (str[i] == 'b' || str[i] == 'c' || str[i] == 'd' || str[i] == 'f' || str[i] == 'g' || str[i] == 'h' || str[i] == 'j' || str[i] == 'k' ||
                str[i] == 'l' || str[i] == 'm' || str[i] == 'n' || str[i] == 'p' || str[i] == 'q' || str[i] == 'r' || str[i] == 's' || str[i] == 't' ||
                str[i] == 'v' || str[i] == 'w' || str[i] == 'x' || str[i] == 'z'))
        {
            i++;
        }
    }
    return str2;
}
string encryption(string str) //функция шифрования
{
    string str2;
    for (int i = 0; str[i]; i++)
    {
        str2.push_back(str[i]);
        if ((str[i] == 'B' || str[i] == 'C' || str[i] == 'D' || str[i] == 'F' || str[i] == 'G' || str[i] == 'H' || str[i] == 'J' || str[i] == 'K' ||
             str[i] == 'L' || str[i] == 'M' || str[i] == 'N' || str[i] == 'P' || str[i] == 'Q' || str[i] == 'R' || str[i] == 'S' || str[i] == 'T' || 
             str[i] == 'V' || str[i] == 'W' || str[i] == 'X' || str[i] == 'Z') ||
            (str[i] == 'b' || str[i] == 'c' || str[i] == 'd' || str[i] == 'f' || str[i] == 'g' || str[i] == 'h' || str[i] == 'j' || str[i] == 'k' ||
             str[i] == 'l' || str[i] == 'm' || str[i] == 'n' || str[i] == 'p' || str[i] == 'q' || str[i] == 'r' || str[i] == 's' || str[i] == 't' ||
             str[i] == 'v' || str[i] == 'w' || str[i] == 'x' || str[i] == 'z'))
        {
            str2.push_back('a');
        }
    }
    return str2;
}
void encrypt() //меню для выбора шифровки/дешифровки
{
    ifstream fin("cr.txt");
    ofstream fout("ct.txt");
    string ans;
    string str = "";
    cout << "\nwrite 1 - wtite new string, 2 - print string, 3 - add string to file, 4 - get string from file, 5 - encryption, 6 - decryption\n";
    cin >> ans;
    if (ans == "1") cin >> str;
    else if (ans == "2") cout << str;
    else if (ans == "3")
    {
        fout << str;
    }
    else if (ans == "4")
    {
        fin >> str;
    }
    else if (ans == "5") str = encryption(str);
    else if (ans == "6") str = decryption(str);

}
void print(vector<st1*> &vec) // функция для вывода в консоль всего вектора 
{
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i]->print();
    }
    if (vec.size() == 0) cout << "student list is void";
}
void findStudGr(vector<st1*>& vec) //для двоичного поиска
{
    cout << "write number of group: ";
    char ans[10];
    cin >> ans;
    int a;
    a = atoi(ans);
    sortGroupN(vec,0);

    int i_key = 0, j = (vec.size()-1), m = vec.size()/2;
    while (i_key < j) {
        m = (i_key + j) / 2;
        if (vec[m]->nGr < a) i_key = m + 1;
        else j = m;
    }
    if (vec[i_key]->nGr != a) cout << "n grout not find"; // Элемент не найден
    else
    {
        print(vec);
        while (vec[i_key - 1]->nGr == a)
        {
            i_key--;
        }
        cout << i_key << '\n';
        while (i_key < vec.size() && vec[i_key]->nGr == a)
        {
            vec[i_key]->print();
            i_key++;
        }
    }
    sortStudN(vec,0);
}
void fUser(vector<st1*> &vec)//функция пользователя для выбора функций
{
    
    string ans;
    do
    {
    cout << "\nwrite 1 to create file(delete all information)\nwrite 2 to print student informtion\nwrite 3 to add student informtion\n"
         << "write 4 to look self work(print information about great student)\nwrite 5 to change students information\n"
         << "write 6 to delete student information\nwrite 7 to sort student\nwrite 8 to crypt\nwrite 9 to find to nGr(for bin. find)\nwrite 10 to close\n";
    
    cin >> ans;
    if (ans == "1") { make(); vec.erase(vec.begin(), vec.end()); }
    else if (ans == "2") print(vec);
    else if (ans == "3") addZap(vec);
    else if (ans == "4") self(vec);
    else if (ans == "5") change(vec);
    else if (ans == "6") deleteStud(vec);
    else if (ans == "7") sort(vec);
    else if (ans == "8") encrypt();
    else if (ans == "9") findStudGr(vec);
    else if(ans == "10")break;
    else cout << "incorrect answer\n";
    } while (1);
}

void start(vector<st1*>&vec) // функция начала работы программы, считывание из файла список, после предыдущей работы в программе
{
    FILE* studFile;
    if (fopen_s(&studFile, "studF.txt", "r") != NULL)
    {
        cout << "lol";
        make();
        fopen_s(&studFile, "studF.txt", "r");
    }
    
    while (!feof(studFile))
    {
        st1* kek = new st1();
        fread(kek, sizeof(st1), 1, studFile);
        
       fgetc(studFile);
        //kek->n = vec.size();
        if(kek->sName != "")
        vec.push_back(kek);
    }
    //print(vec);
    fclose(studFile);
}
void end(vector<st1*>& vec) //функуия конца программы, для вывода в файл итога работы 
{
    FILE* studFile;
    fopen_s(&studFile, "studF.txt", "w");
    st1* kek = new st1();
    for (int i = 0; i < vec.size(); i++)
    {
        kek = vec[i];
        fwrite(kek, sizeof(st1), 1, studFile);
        fputc('\n', studFile);
    }
    fclose(studFile);
    vec.erase(vec.begin(),vec.end());
    
}
int main()
{
    
    vector<st1*> vec;
    start(vec);
    fUser(vec);
    end(vec);
    
}
