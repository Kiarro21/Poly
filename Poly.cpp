#include <stdlib.h>
#include <iostream>
#include <cmath>
using namespace std;

struct Node                             //Структура, являющаяся звеном списка
{
    int x,y;                             //Значение x будет передаваться в список
    Node* Next, * Prev;                 //Указатели на адреса следующего и предыдущего элементов списка
};

class List                              //Создаем тип данных Список
{
    Node* Head, * Tail;                   //Указатели на адреса начала списка и его конца
    int count = 0;
public:
    List() :Head(NULL), Tail(NULL) {};    //Конструктор
    ~List();                              //Деструктора
    void ShowBegin();                     //Отображения списка вершин с начала
    void ShowEnd();                       //Отображения списка вершин с конца
    void PushBegin(int x, int y);         //Добавление элемента в начало
    void PushBack(int x, int y);          //Добавлении элемента в конец
    void DeleteBegin();                   //Удаление элемента с начала
    void DeleteEnd();                     //Удаление элемента с конца
    int GetNumber();                      //Получение количества вершин
    float GetLength();                    //Получение длины линии
};

List::~List()                           //Деструктор
{
    while (Head)                       //Пока по адресу на начало списка что-то есть
    {
        Tail = Head->Next;             //Резервная копия адреса следующего звена списка
        delete Head;                   //Очистка памяти от первого звена
        Head = Tail;                   //Смена адреса начала на адрес следующего элемента
    }
}

void List::PushBegin(int x, int y)
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
void List::PushBack(int x, int y)
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

void List::DeleteBegin()
{
    Node* temp = Head;
    Head = Head->Next;
    Head->Prev = NULL;
    delete temp;
    count -= 1;
}

void List::DeleteEnd()
{
    Node* temp = Tail;
    Tail = Tail->Prev;
    Tail->Next = NULL;
    delete temp;
    count -= 1;
}

int List::GetNumber()
{
    return count;
}

float List::GetLength()
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

void List::ShowBegin()
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

void List::ShowEnd()
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

int main()
{
    system("CLS");
    List lst; //Объявляем переменную, тип которой есть список

    lst.PushBegin(1,1);
    lst.PushBack(2,2);
    lst.PushBack(2,3);
    lst.PushBack(5,2);

    lst.ShowBegin(); //Отображаем список на экране
    cout << lst.GetNumber() << endl;

    cout << lst.GetLength() << endl;
    return 0;
}
