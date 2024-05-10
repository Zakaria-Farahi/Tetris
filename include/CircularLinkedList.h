#pragma once
#include <map>
#include "Node.h"
using namespace std;

class CircularLinkedList
{
    Node *Tail;
    int Size;
    // 0 : Red, 1 : Blue, 2 : Green, 3 : Yellow
    // R to Ascii = 82, B = 66, G = 71, Y = 89
    map<char, int> mapCoul = {{'R', 0}, {'B', 1}, {'G', 2}, {'Y', 3}};
    Node *lstCoul[4];
    int SizeCoul[4];
    // 0 : Circle, 1 : Square, 2 : Triangle, 3 : Diamond
    // C to Ascii = 67, S = 83, T = 84, D = 68
    map<char, int> mapForm = {{'C', 0}, {'S', 1}, {'T', 2}, {'D', 3}};
    Node *lstForm[4];
    int SizeForm[4];

public:
    CircularLinkedList() : Tail(nullptr), Size(0)
    {
        for (int i = 0; i < 4; ++i)
        {
            lstCoul[i] = nullptr;
            lstForm[i] = nullptr;
            SizeCoul[i] = 0;
            SizeForm[i] = 0;
        }
    }
    ~CircularLinkedList();
    int getSize();
    Node *getTail();
    void insertAtEnd(char C, char F);
    void insertAtStart(char C, char F);
    void display();
    void shift_color(char C);
    void shift_form(char F);
};