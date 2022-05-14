#pragma once
#include <stdlib.h>
#include <iostream>
#include <cmath>
using namespace std;

struct Node
{
    double x, y;
    Node* Next, * Prev;
};

class Poly
{
public:
    Node* Head, * Tail;
    int count = 0;
    Poly() :Head(NULL), Tail(NULL) {};
    ~Poly();
    void ShowBegin();
    void ShowEnd();
    void PushBegin(double x, double y);
    void PushBack(double x, double y);
    void DeleteBegin();
    void DeleteEnd();
    int GetNumber();
    float GetLength();
    friend istream& operator>>(istream& in, Poly& p);
    friend ostream& operator<<(ostream& out, Poly& p);
    Poly operator=(Poly& p);
    Poly operator+(Poly& p);
};