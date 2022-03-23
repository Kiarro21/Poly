#include <stdlib.h>
#include <iostream>
#include <cmath>
using namespace std;

struct Node                             //���������, ���������� ������ ������
{
    int x,y;                             //�������� x ����� ������������ � ������
    Node* Next, * Prev;                 //��������� �� ������ ���������� � ����������� ��������� ������
};

class List                              //������� ��� ������ ������
{
    Node* Head, * Tail;                   //��������� �� ������ ������ ������ � ��� �����
    int count = 0;
public:
    List() :Head(NULL), Tail(NULL) {};    //�����������
    ~List();                              //�����������
    void ShowBegin();                     //����������� ������ ������ � ������
    void ShowEnd();                       //����������� ������ ������ � �����
    void PushBegin(int x, int y);         //���������� �������� � ������
    void PushBack(int x, int y);          //���������� �������� � �����
    void DeleteBegin();                   //�������� �������� � ������
    void DeleteEnd();                     //�������� �������� � �����
    int GetNumber();                      //��������� ���������� ������
    float GetLength();                    //��������� ����� �����
};

List::~List()                           //����������
{
    while (Head)                       //���� �� ������ �� ������ ������ ���-�� ����
    {
        Tail = Head->Next;             //��������� ����� ������ ���������� ����� ������
        delete Head;                   //������� ������ �� ������� �����
        Head = Tail;                   //����� ������ ������ �� ����� ���������� ��������
    }
}

void List::PushBegin(int x, int y)
{
    Node* temp = new Node;               //��������� ������ ��� ����� ������� ���������
    temp->Next = NULL;                   //���������, ��� ���������� �� ���������� ������ �����
    temp->x = x;                         //���������� �������� x � ���������   
    temp->y = y;                         //���������� �������� y � ���������

    if (Head != NULL)                    //���� ������ �� ����
    {
        temp->Next = Head;               //��������� ����� �� ���������� ������� � �����. ����
        Head->Prev = temp;               //��������� ����� ���������� �� ������� ��������
        Head = temp;                     //������ ����� ������
        count += 1;
    }
    else                                 //���� ������ ������
    {
        temp->Prev = NULL;               //���������� ������� ��������� � �������
        Head = Tail = temp;              //������=�����=��� �������, ��� ������ ��������
        count += 1;
    }
}
void List::PushBack(int x, int y)
{
    Node* temp = new Node;               //��������� ������ ��� ����� ������� ���������
    temp->Next = NULL;                   //���������, ��� ���������� �� ���������� ������ �����
    temp->x = x;                         //���������� �������� x � ���������   
    temp->y = y;                         //���������� �������� y � ���������

    if (Head != NULL)                    //���� ������ �� ����
    {
        temp->Prev = Tail;               //��������� ����� �� ���������� ������� � �����. ����
        Tail->Next = temp;               //��������� ����� ���������� �� ������� ��������
        Tail = temp;                     //������ ����� ������
        count += 1;
    }
    else //���� ������ ������
    {
        temp->Prev = NULL;               //���������� ������� ��������� � �������
        Head = Tail = temp;              //������=�����=��� �������, ��� ������ ��������
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
    //������� ������ � ������
    Node* temp = Head;                       //�������� ��������� �� ����� ������� ��������
    while (temp != NULL)              //���� �� �������� ������ ��������
    {
        cout << '(' << temp->x << "," << temp->y << ')';      //������� ������ ��������� �������� �� �����
        temp = temp->Next;             //����� ������ �� ����� ���������� ��������
    }
    cout << "\n";
}

void List::ShowEnd()
{
    //������� ������ � �����
    Node* temp = Tail;                   //��������� ��������� �� ����� ���������� ��������

    while (temp != NULL)               //���� �� ���������� ������ ��������
    {
        cout << '(' << temp->x << "," << temp->y << ')';        //�������� �������� �� �����
        temp = temp->Prev;             //���������, ��� ����� ����� ����������� ��������
    }
    cout << "\n";
}

int main()
{
    system("CLS");
    List lst; //��������� ����������, ��� ������� ���� ������

    lst.PushBegin(1,1);
    lst.PushBack(2,2);
    lst.PushBack(2,3);
    lst.PushBack(5,2);

    lst.ShowBegin(); //���������� ������ �� ������
    cout << lst.GetNumber() << endl;

    cout << lst.GetLength() << endl;
    return 0;
}
