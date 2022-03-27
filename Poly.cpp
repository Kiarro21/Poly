#include <stdlib.h>
#include <iostream>
#include <cmath>
using namespace std;

struct Node                             //Структура, являющаяся звеном списка
{
    double x,y;                             //Значение x будет передаваться в список
    Node* Next, * Prev;                 //Указатели на адреса следующего и предыдущего элементов списка
};

class Poly                              //Создаем тип данных Список
{
    Node* Head, * Tail;                   //Указатели на адреса начала списка и его конца
    int count = 0;
public:
    Poly() :Head(NULL), Tail(NULL) {};    //Конструктор
    ~Poly();                              //Деструктора
    void ShowBegin();                     //Отображения списка вершин с начала
    void ShowEnd();                       //Отображения списка вершин с конца
    void PushBegin(double x, double y);         //Добавление элемента в начало
    void PushBack(double x, double y);          //Добавлении элемента в конец
    void DeleteBegin();                   //Удаление элемента с начала
    void DeleteEnd();                     //Удаление элемента с конца
    int GetNumber();                      //Получение количества вершин
    float GetLength();                    //Получение длины линии
    friend istream& operator>>(istream& in, Poly& p);
    friend ostream& operator<<(ostream& out, Poly& p);
    Poly operator=(Poly& p);
    friend bool operator==(Poly& p1, Poly& p2);
    friend bool operator!=(Poly& p1, Poly& p2);
    friend bool operator>(Poly& p1, Poly& p2);
    friend bool operator>=(Poly& p1, Poly& p2);
    friend bool operator<(Poly& p1, Poly& p2);
    friend bool operator<=(Poly& p1, Poly& p2);
};

Poly::~Poly()                           //Деструктор
{
    while (Head)                       //Пока по адресу на начало списка что-то есть
    {
        Tail = Head->Next;             //Резервная копия адреса следующего звена списка
        delete Head;                   //Очистка памяти от первого звена
        Head = Tail;                   //Смена адреса начала на адрес следующего элемента
    }
}

void Poly::PushBegin(double x, double y)
{
    Node* temp = new Node;               //Выделение памяти под новый элемент структуры
    temp->Next = NULL;                   //Указываем, что изначально по следующему адресу пусто
    temp->x = x;                         //Записываем значение x в структуру   
    temp->y = y;                         //Записываем значение y в структуру

    if (Head != NULL)                    //Если список не пуст
    {
        temp->Next = Head;               //Указываем адрес на предыдущий элемент в соотв. поле
        Head->Prev = temp;               //Указываем адрес следующего за хвостом элемента
        Head = temp;                     //Меняем адрес хвоста
        count += 1;
    }
    else                                 //Если список пустой
    {
        temp->Prev = NULL;               //Предыдущий элемент указывает в пустоту
        Head = Tail = temp;              //Голова=Хвост=тот элемент, что сейчас добавили
        count += 1;
    }
}
void Poly::PushBack(double x, double y)
{
    Node* temp = new Node;               //Выделение памяти под новый элемент структуры
    temp->Next = NULL;                   //Указываем, что изначально по следующему адресу пусто
    temp->x = x;                         //Записываем значение x в структуру   
    temp->y = y;                         //Записываем значение y в структуру

    if (Head != NULL)                    //Если список не пуст
    {
        temp->Prev = Tail;               //Указываем адрес на предыдущий элемент в соотв. поле
        Tail->Next = temp;               //Указываем адрес следующего за хвостом элемента
        Tail = temp;                     //Меняем адрес хвоста
        count += 1;
    }
    else //Если список пустой
    {
        temp->Prev = NULL;               //Предыдущий элемент указывает в пустоту
        Head = Tail = temp;              //Голова=Хвост=тот элемент, что сейчас добавили
        count += 1;
    }
}

void Poly::DeleteBegin()
{
    Node* temp = Head;
    Head = Head->Next;
    Head->Prev = NULL;
    delete temp;
    count -= 1;
}

void Poly::DeleteEnd()
{
    Node* temp = Tail;
    Tail = Tail->Prev;
    Tail->Next = NULL;
    delete temp;
    count -= 1;
}

int Poly::GetNumber()
{
    return count;
}

float Poly::GetLength()
{
    float Length = 0, line_length;
    int x_temp, y_temp;
    Node* temp = Head;
    while (temp->Next != NULL) {
        x_temp = Head->x;
        y_temp = Head->y;
        temp = Head->Next;
        line_length = sqrt(pow((temp->x - x_temp), 2) + pow((temp->y - y_temp), 2));
        Length += line_length;
        Head = Head->Next;
    }
    return Length;
}

Poly Poly::operator=(Poly& p)
{
    Node* temp = p.Head;
    while (temp != nullptr){
        PushBack(temp->x, temp->y);
        temp = temp->Next;
    }
    return *this;
}

void Poly::ShowBegin()
{
    //ВЫВОДИМ СПИСОК С НАЧАЛА
    Node* temp = Head;                       //Временно указываем на адрес первого элемента
    while (temp != NULL)              //Пока не встретим пустое значение
    {
        cout << '(' << temp->x << "," << temp->y << ')';      //Выводим каждое считанное значение на экран
        temp = temp->Next;             //Смена адреса на адрес следующего элемента
    }
    cout << "\n";
}

void Poly::ShowEnd()
{
    //ВЫВОДИМ СПИСОК С КОНЦА
    Node* temp = Tail;                   //Временный указатель на адрес последнего элемента

    while (temp != NULL)               //Пока не встретится пустое значение
    {
        cout << '(' << temp->x << "," << temp->y << ')';        //Выводить значение на экран
        temp = temp->Prev;             //Указываем, что нужен адрес предыдущего элемента
    }
    cout << "\n";
}

istream& operator>>(istream& in, Poly& p){
    int num;
    double x, y;
    cout << "Enter number of point you need ==> ";
    in >> num;
    while (num) {
        cout << "X ==> ";
        in >> x;
        cout << "Y ==> ";
        in >> y;
        cout << endl;
        p.PushBack(x,y);
        num--;
    }
    return in;
}

ostream& operator<<(ostream& out, Poly& p)
{
    Node* temp = p.Head;
    int i = 1;
    while (temp != nullptr) {
        out << "Point " << i << ": (" << temp->x << "," << temp->y << ");" << endl;
        i++;
        temp = temp->Next;
    }
    return out;
}

bool operator==(Poly& p1, Poly& p2)
{
    if (p1.GetLength() == p2.GetLength())
        return true;
    else
        return false;
}

bool operator!=(Poly& p1, Poly& p2)
{
    if (p1.GetLength() != p2.GetLength())
        return true;
    else
        return false;
}

bool operator>(Poly& p1, Poly& p2)
{
    if (p1.GetLength() > p2.GetLength())
        return true;
    else
        return false;
}

bool operator>=(Poly& p1, Poly& p2)
{
    if (p1.GetLength() >= p2.GetLength())
        return true;
    else
        return false;
}

bool operator<(Poly& p1, Poly& p2)
{
    if (p1.GetLength() < p2.GetLength())
        return true;
    else
        return false;
}

bool operator<=(Poly& p1, Poly& p2)
{
    if (p1.GetLength() <= p2.GetLength())
        return true;
    else
        return false;
}

int main()
{
    system("CLS");

    Poly p1,p2,p3;
    cin >> p1;
    cin >> p2;
    cin >> p3;
    double l1, l2, l3;
    l1 = p1.GetLength();
    l2 = p2.GetLength();
    l3 = p3.GetLength();
    if (l1 > l2 && l1 > l3)
        cout << p1;
    if (l2 > l3 && l2 > l1)
        cout << p2;
    if (l3 > l1 && l3 > l2)
        cout << p3;
    if (l1 == l2 && l2 == l3)
        cout << "Straight lines are equal!";
    return 0;
}
