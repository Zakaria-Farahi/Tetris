#pragma once

template <class T>
class Node_Double
{
    T *Next;
    T *Prev;

public:
    Node_Double() : Next(nullptr), Prev(nullptr) {}
    T *getNext()
    {
        return Next;
    }
    void setNext(T *next)
    {
        Next = next;
    }
    T *getPrev()
    {
        return Prev;
    }
    void setPrev(T *prev)
    {
        Prev = prev;
    }
};
