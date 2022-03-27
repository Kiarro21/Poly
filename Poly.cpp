#include <stdlib.h>
#include <iostream>
#include <cmath>
using namespace std;

struct Node                             //���������, ���������� ������ ������
{
    double x,y;                             //�������� x ����� ������������ � ������
    Node* Next, * Prev;                 //��������� �� ������ ���������� � ����������� ��������� ������
};

class Poly                              //������� ��� ������ ������
{
    Node* Head, * Tail;                   //��������� �� ������ ������ ������ � ��� �����
    int count = 0;
public:
    Poly() :Head(NULL), Tail(NULL) {};    //�����������
    ~Poly();                              //�����������
    void ShowBegin();                     //����������� ������ ������ � ������
    void ShowEnd();                       //����������� ������ ������ � �����
    void PushBegin(double x, double y);         //���������� �������� � ������
    void PushBack(double x, double y);          //���������� �������� � �����
    void DeleteBegin();                   //�������� �������� � ������
    void DeleteEnd();                     //�������� �������� � �����
    int GetNumber();                      //��������� ���������� ������
    float GetLength();                    //��������� ����� �����
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

Poly::~Poly()                           //����������
{
    while (Head)                       //���� �� ������ �� ������ ������ ���-�� ����
    {
        Tail = Head->Next;             //��������� ����� ������ ���������� ����� ������
        delete Head;                   //������� ������ �� ������� �����
        Head = Tail;                   //����� ������ ������ �� ����� ���������� ��������
    }
}

void Poly::PushBegin(double x, double y)
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
void Poly::PushBack(double x, double y)
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
    //������� ������ � ������
    Node* temp = Head;                       //�������� ��������� �� ����� ������� ��������
    while (temp != NULL)              //���� �� �������� ������ ��������
    {
        cout << '(' << temp->x << "," << temp->y << ')';      //������� ������ ��������� �������� �� �����
        temp = temp->Next;             //����� ������ �� ����� ���������� ��������
    }
    cout << "\n";
}

void Poly::ShowEnd()
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
