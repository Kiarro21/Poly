#include <iostream>
#include "Header.h"
using namespace std;

class Polygon : public Poly {

public:
	float GetLength();
	float GetSquare();
    friend bool operator==(Polygon& p1, Polygon& p2);
    friend bool operator!=(Polygon& p1, Polygon& p2);
    friend bool operator>(Polygon& p1, Polygon& p2);
    friend bool operator>=(Polygon& p1, Polygon& p2);
    friend bool operator<(Polygon& p1, Polygon& p2);
    friend bool operator<=(Polygon& p1, Polygon& p2);
};

float Polygon::GetLength(){
	return (Poly::GetLength() + 
		sqrt(pow((Head->x - Tail->x), 2) + pow((Head->y - Tail->y), 2)));
}

float Polygon::GetSquare()
{

    float Length = 0, l1 = 0, l2 = 0;
    int x_temp, y_temp;
    Node* temp = Head;
    while (temp->Next != nullptr) {
        x_temp = temp->x;
        temp = temp->Next;
        y_temp = temp->y;
        l1 += x_temp * y_temp;
    }
    l1 += Head->y * Tail->x;
    temp = Head;
    while (temp->Next != nullptr) {
        y_temp = temp->y;
        temp = temp->Next;
        x_temp = temp->x;
        l2 += x_temp * y_temp;
    }
    l2 += Head->x * Tail->y;
    return ((l1 - l2) / 2);
}

bool operator==(Polygon& p1, Polygon& p2)
{
    return (p1.GetSquare() == p2.GetSquare());
}

bool operator!=(Polygon& p1, Polygon& p2)
{
    return (p1.GetSquare() != p2.GetSquare());
}

bool operator==(Polygon& p1, Poly& p2)
{
    return false;
}

bool operator!=(Polygon& p1, Poly& p2)
{
    return false;
}

bool operator>(Polygon& p1, Polygon& p2)
{
    return (p1.GetSquare() > p2.GetSquare());
}

bool operator>=(Polygon& p1, Polygon& p2)
{
    return (p1.GetSquare() >= p2.GetSquare());
}

bool operator<(Polygon& p1, Polygon& p2)
{
    return (p1.GetSquare() < p2.GetSquare());
}

bool operator<=(Polygon& p1, Polygon& p2)
{
    return (p1.GetSquare() <= p2.GetSquare());
}

int main() {
    Polygon p1, p2, p3;
    cin >> p1;
    cin >> p2;
    cin >> p3;
    double l1, l2, l3;
    l1 = p1.GetSquare();
    l2 = p2.GetSquare();
    l3 = p3.GetSquare();
    cout << l1 << " " << l2 << " " << l3 << endl;
    if (l1 < l2 && l1 < l3)
        cout << p1;
    if (l2 < l3 && l2 < l1)
        cout << p2;
    if (l3 < l1 && l3 < l2)
        cout << p3;
    if (l1 == l2 && l2 == l3)
        cout << "Straight lines are equal!";
    return 0;

}
