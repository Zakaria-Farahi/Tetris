#include "../include/Node.h"
#include <iostream>
#include <map>
using namespace std;

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

Node ::~Node()
{
    Next = nullptr;
    NextSameColor = nullptr;
    PrevSameColor = nullptr;
    NextSameForm = nullptr;
    PrevSameForm = nullptr;
}

// Getters
Node *Node::getNext()
{
    return Next;
}
// ## Color
Node *Node::getNextSameColor()
{
    return NextSameColor;
}
Node *Node::getPrevSameColor()
{
    return PrevSameColor;
}
// ## Form
Node *Node::getNextSameForm()
{
    return NextSameForm;
}
Node *Node::getPrevSameForm()
{
    return PrevSameForm;
}

// Setter

void Node::setNext(Node *next)
{
    Next = next;
}
// ## Color
void Node::setNextSameColor(Node *next)
{
    NextSameColor = next;
}
void Node::setPrevSameColor(Node *prev)
{
    PrevSameColor = prev;
}
// ## Form
void Node::setNextSameForm(Node *next)
{
    NextSameForm = next;
}
void Node::setPrevSameForm(Node *prev)
{
    PrevSameForm = prev;
}

// Display
void Node::Display()
{
    map<char, int> mapCoul = {{0, 'R'}, {1, 'B'}, {2, 'G'}, {3, 'Y'}};
    map<char, int> mapForm = {{0, 'C'}, {1, 'S'}, {2, 'T'}, {3, 'D'}};
    // map for ansi color
    map<char, string> mapColorStart = {{'R', ANSI_COLOR_RED}, {'B', ANSI_COLOR_BLUE}, {'G', ANSI_COLOR_GREEN}, {'Y', ANSI_COLOR_YELLOW}};
    char colored = _shape.getMyColor();
    char formed = _shape.getMyForm();

    cout << mapColorStart[colored] << formed << ANSI_COLOR_RESET;
}

char Node::getMyColor()
{
    return _shape.getMyColor();
}

char Node::getMyForm()
{
    return _shape.getMyForm();
}

void Node::setMyColor(char C){
    _shape.setMyColor(C);
}
void Node::setMyForm(char F){
    _shape.setMyForm(F);
}