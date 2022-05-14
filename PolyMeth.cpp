#include "Header.h"

Poly::~Poly()
{
    while (Head)
    {
        Tail = Head->Next;
        delete Head;
        Head = Tail;
    }
}

void Poly::PushBegin(double x, double y)
{
    Node* temp = new Node;
    temp->Next = NULL;
    temp->x = x;
    temp->y = y;

    if (Head != NULL)
    {
        temp->Next = Head;
        Head->Prev = temp;
        Head = temp;
        count += 1;
    }
    else
    {
        temp->Prev = NULL;
        Head = Tail = temp;
        count += 1;
    }
}
void Poly::PushBack(double x, double y)
{
    Node* temp = new Node;
    temp->Next = NULL;
    temp->x = x;
    temp->y = y;

    if (Head != NULL)
    {
        temp->Prev = Tail;
        Tail->Next = temp;
        Tail = temp;
        count += 1;
    }
    else
    {
        temp->Prev = NULL;
        Head = Tail = temp;
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
    while (temp->Next != nullptr) {
        x_temp = temp->x;
        y_temp = temp->y;
        temp = temp->Next;
        line_length = sqrt(pow((temp->x - x_temp), 2) + pow((temp->y - y_temp), 2));
        Length += line_length;
    }
    //Length += sqrt(pow((Head->x - Tail->x), 2) + pow((Head->y - Tail->y), 2));
    return Length;
}


Poly Poly::operator=(Poly& p)
{
    Node* temp = Head;
    while (Head != nullptr) {
        temp = Head->Next;
        delete Head;
        if (temp != nullptr)
            temp->Prev = nullptr;
        Head = temp;
    }
    Tail = nullptr;
    temp = p.Head;
    while (temp != nullptr) {
        PushBack(temp->x, temp->y);
        temp = temp->Next;
    }
    return *this;
}

Poly Poly::operator+(Poly& p)
{
    Node* temp = p.Head;
    while (temp != nullptr) {
        PushBack(temp->x, temp->y);
        temp = temp->Next;
    }
    return *this;
}

void Poly::ShowBegin()
{
    Node* temp = Head;
    while (temp != NULL)
    {
        cout << '(' << temp->x << "," << temp->y << ')';
        temp = temp->Next;
    }
    cout << "\n";
}

void Poly::ShowEnd()
{
    Node* temp = Tail;

    while (temp != NULL)
    {
        cout << '(' << temp->x << "," << temp->y << ')';
        temp = temp->Prev;
    }
    cout << "\n";
}

istream& operator>>(istream& in, Poly& p) {
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
        p.PushBack(x, y);
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
