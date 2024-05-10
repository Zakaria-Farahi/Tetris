#pragma once
#include "./shape.h"

class Node
{
    Node *Next;
    Node *NextSameColor;
    Node *PrevSameColor;
    Node *NextSameForm;
    Node *PrevSameForm;
    shape _shape;

public:
    Node(char C, char F) : Next(nullptr), _shape(C, F), NextSameColor(nullptr), PrevSameColor(nullptr), NextSameForm(nullptr), PrevSameForm(nullptr){};
    ~Node();
    void Display();
    char getMyColor();
    char getMyForm();
    void setMyColor(char C);
    void setMyForm(char F);
    // Node_Double<Node> getColor();
    // Node_Double<Node> getForm();
    //  Getters
    Node *getNext();
    // ## Color
    Node *getNextSameColor();
    Node *getPrevSameColor();
    // ## Form
    Node *getNextSameForm();
    Node *getPrevSameForm();
    // Setters
    void setNext(Node *next);
    // ## Color
    void setNextSameColor(Node *next);
    void setPrevSameColor(Node *prev);
    // ## Form
    void setNextSameForm(Node *next);
    void setPrevSameForm(Node *prev);
};