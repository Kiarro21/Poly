#include <stdlib.h>
#include <iostream>
#include <cmath>
#include "Header.h"

using namespace std;
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
    cout << l1 << " " << l2 << " " << l3 << endl;
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