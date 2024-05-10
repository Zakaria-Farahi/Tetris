#include "../include/CircularLinkedList.h"
#include "../include/Node.h"
#include <iostream>

CircularLinkedList::~CircularLinkedList()
{
    while (Tail != nullptr && Tail->getNext() != Tail)
    {
        Node *temp = Tail->getNext();
        delete Tail;
        Tail = temp;
    }
    delete Tail;
}

// HEx color
//  Red : #FF0000; Blue : #0000FF; Green : #00FF00; Yellow : #FFFF00

// Insertion
void CircularLinkedList::insertAtEnd(char C, char F)
{
    Node *newNode = new Node(C, F);
    if (Tail == nullptr)
    {
        Tail = newNode;
        Tail->setNext(Tail);
        lstCoul[mapCoul[C]] = newNode;
        lstForm[mapForm[F]] = newNode;
        Tail->setNextSameColor(Tail);
        Tail->setPrevSameColor(newNode);
        Tail->setNextSameForm(Tail);
        Tail->setPrevSameForm(newNode);
        SizeCoul[mapCoul[C]]++;
        SizeForm[mapForm[F]]++;
    }
    else
    {
        newNode->setNext(Tail->getNext());
        Tail->setNext(newNode);
        Tail = newNode;
        if (lstCoul[mapCoul[C]] == nullptr)
        {
            lstCoul[mapCoul[C]] = Tail;
            Tail->setNextSameColor(Tail);
            Tail->setPrevSameColor(Tail);
        }
        else
        {
            Node *temp = lstCoul[mapCoul[C]];
            for (int i = 1; i < SizeCoul[mapCoul[C]]; i++)
                temp = temp->getNextSameColor();
            temp->setNextSameColor(Tail);
            Tail->setPrevSameColor(temp);
            Tail->setNextSameColor(lstCoul[mapCoul[C]]);
            lstCoul[mapCoul[C]]->setPrevSameColor(Tail);
            temp = nullptr;
        }
        SizeCoul[mapCoul[C]]++;

        if (lstForm[mapForm[F]] == nullptr)
        {
            lstForm[mapForm[F]] = newNode;
            Tail->setNextSameForm(Tail);
            Tail->setPrevSameForm(Tail);
        }
        else
        {
            Node *temp = lstForm[mapForm[F]];
            for (int i = 1; i < SizeForm[mapForm[F]]; i++)
                temp = temp->getNextSameForm();
            temp->setNextSameForm(Tail);
            Tail->setPrevSameForm(temp);
            Tail->setNextSameForm(lstForm[mapForm[F]]);
            lstForm[mapForm[F]]->setPrevSameForm(Tail);
            temp = nullptr;
        }
        SizeForm[mapForm[F]]++;
    }
    Size++;
    if (Size >= 3 && (SizeCoul[mapCoul[C]] >= 3 || SizeForm[mapForm[F]] >= 3))
    {
        // go to the last 3 element
        Node *temp = Tail;
        if ((temp->getPrevSameColor()->getNext() == temp && temp->getPrevSameColor()->getPrevSameColor()->getNext() == temp->getPrevSameColor()) || (temp->getPrevSameForm()->getNext() == temp && temp->getPrevSameForm()->getPrevSameForm()->getNext() == temp->getPrevSameForm()))
        {
            for (int i = 0; i < Size - 3; i++)
                temp = temp->getNext();
            Node *temp2 = temp->getNext();
            temp->setNext(Tail->getNext());
            Tail = temp;
            for (int j = 0; j < 3; j++) // 0 1 2
            {
                // Update SizeCoul and SizeForm based on the color and form of the node
                SizeCoul[mapCoul[temp2->getMyColor()]]--;
                SizeForm[mapForm[temp2->getMyForm()]]--;
                if (SizeCoul[mapCoul[temp2->getMyColor()]] == 0)
                {
                    lstCoul[mapCoul[temp2->getMyColor()]] = nullptr;
                }
                else
                {
                    temp2->getPrevSameColor()->setNextSameColor(temp2->getNextSameColor());
                    temp2->getNextSameColor()->setPrevSameColor(temp2->getPrevSameColor());
                    if (lstCoul[mapCoul[temp2->getMyColor()]] == temp2)
                        lstCoul[mapCoul[temp2->getMyColor()]] = temp2->getNextSameColor();
                }
                if (SizeForm[mapForm[temp2->getMyForm()]] == 0)
                {
                    lstForm[mapForm[temp2->getMyForm()]] = nullptr;
                }
                else
                {
                    temp2->getPrevSameForm()->setNextSameForm(temp2->getNextSameForm());
                    temp2->getNextSameForm()->setPrevSameForm(temp2->getPrevSameForm());
                    if (lstForm[mapForm[temp2->getMyForm()]] == temp2)
                        lstForm[mapForm[temp2->getMyForm()]] = temp2->getNextSameForm();
                }
                // Delete the current node and move to the next
                Node *nextNode = temp2->getNext();
                delete temp2;
                temp2 = nextNode;
            }
            temp = nullptr;
            temp2 = nullptr;
            Size -= 3;
            if (Size == 0)
            {
                Tail = nullptr;
            }
        }
    }
}

void CircularLinkedList::insertAtStart(char C, char F)
{
    Node *newNode = new Node(C, F);
    if (Tail == nullptr)
    {
        Tail = newNode;
        Tail->setNext(Tail);
        lstCoul[mapCoul[C]] = Tail;
        SizeCoul[mapCoul[C]]++;
        Tail->setNextSameColor(Tail);
        Tail->setPrevSameColor(Tail);
        Tail->setNextSameForm(Tail);
        Tail->setPrevSameForm(Tail);
        lstForm[mapForm[F]] = Tail;
        SizeForm[mapForm[F]]++;
    }
    else
    {
        newNode->setNext(Tail->getNext());
        Tail->setNext(newNode);
        if (lstCoul[mapCoul[C]] == nullptr)
        {
            lstCoul[mapCoul[C]] = newNode;
            newNode->setNextSameColor(newNode);
            newNode->setPrevSameColor(newNode);
        }
        else
        {
            Node *temp = lstCoul[mapCoul[C]];
            lstCoul[mapCoul[C]] = newNode;
            newNode->setNextSameColor(temp);
            newNode->setPrevSameColor(temp->getPrevSameColor());
            temp->getPrevSameColor()->setNextSameColor(newNode);
            temp->setPrevSameColor(newNode);
            temp = nullptr;
        }
        SizeCoul[mapCoul[C]]++;

        if (lstForm[mapForm[F]] == nullptr)
        {
            lstForm[mapForm[F]] = newNode;
            newNode->setNextSameForm(newNode);
            newNode->setPrevSameForm(newNode);
        }
        else
        {
            Node *temp = lstForm[mapForm[F]];
            lstForm[mapForm[F]] = newNode;
            newNode->setNextSameForm(temp);
            newNode->setPrevSameForm(temp->getPrevSameForm());
            temp->getPrevSameForm()->setNextSameForm(newNode);
            temp->setPrevSameForm(newNode);
            temp = nullptr;
        }
        SizeForm[mapForm[F]]++;
    }
    Size++;
    if (Size >= 3 && (SizeCoul[mapCoul[C]] >= 3 || SizeForm[mapForm[F]] >= 3))
    {
        // cout << "The Condition for form : " << (newNode->getNext() == newNode->getForm().getNext() || newNode->getNext()->getNext() == newNode->getForm().getNext()->getForm().getNext()) << endl;

        if ((newNode->getMyColor() == newNode->getNext()->getMyColor() && newNode->getMyColor() == newNode->getNext()->getNext()->getMyColor()) || (newNode->getMyForm() == newNode->getNext()->getMyForm() && newNode->getMyForm() == newNode->getNext()->getNext()->getMyForm()))
        {
            // Remove the First 3 Nodes // 0 1 2
            for (int i = 0; i < 3; i++)
            {
                if (Tail->getNext() == Tail)
                {
                    Tail = nullptr;
                    delete Tail;
                    Size = 0;
                    break;
                }
                Node *temp = Tail->getNext();
                Tail->setNext(temp->getNext());
                // Tail->getNext()->setPrevSameColor(lstCoul[mapCoul[Tail->getNext()->getMyColor()]]->getPrevSameColor());
                temp->getPrevSameColor()->setNextSameColor(temp->getNextSameColor());
                temp->getNextSameColor()->setPrevSameColor(temp->getPrevSameColor());
                // Tail->getNext()->setPrevSameForm(lstForm[mapForm[Tail->getNext()->getMyForm()]]->getPrevSameForm());
                temp->getPrevSameForm()->setNextSameForm(temp->getNextSameForm());
                temp->getNextSameForm()->setPrevSameForm(temp->getPrevSameForm());
                lstCoul[mapCoul[temp->getMyColor()]] = temp->getNextSameColor();
                SizeCoul[mapCoul[temp->getMyColor()]]--;
                lstForm[mapForm[temp->getMyForm()]] = temp->getNextSameForm();
                SizeForm[mapForm[temp->getMyForm()]]--;
                if (SizeCoul[mapCoul[temp->getMyColor()]] == 0)
                {
                    lstCoul[mapCoul[temp->getMyColor()]] = nullptr;
                }
                if (SizeForm[mapForm[temp->getMyForm()]] == 0)
                {
                    lstForm[mapForm[temp->getMyForm()]] = nullptr;
                }
                delete temp;
                Size--;
            }
        }
    }
}
// Display
void CircularLinkedList::display()
{
    if (Tail == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
    Node *temp = Tail->getNext();
    do
    {
        temp->Display();
        temp = temp->getNext();
    } while (temp != Tail->getNext());
}

int CircularLinkedList::getSize()
{
    return Size;
}

Node *CircularLinkedList::getTail()
{
    return Tail;
}

void CircularLinkedList::shift_form(char F)
{
    int size_of_form = SizeForm[mapForm[F]];
    if (size_of_form == 0)
        return;
    char temp_C = lstForm[mapForm[F]]->getMyColor();
    Node *temp = lstForm[mapForm[F]];
    for (int i = 1; i < size_of_form; i++)
    {
        temp->setMyColor(temp->getNextSameForm()->getMyColor());
        temp = temp->getNextSameForm();
    }
    temp->setMyColor(temp_C);
    Node *temp_Tail = Tail;
    Tail = nullptr;
    int temp_Size = Size;
    Size = 0;
    for (int i = 0; i < 4; ++i)
    {
        lstCoul[i] = nullptr;
        lstForm[i] = nullptr;
        SizeCoul[i] = 0;
        SizeForm[i] = 0;
    }
    Node *temp_to_start = temp_Tail->getNext();
    for (int i = 0; i < temp_Size; i++)
    {
        insertAtEnd(temp_to_start->getMyColor(), temp_to_start->getMyForm());
        Node *temp_to_delete = temp_to_start;
        temp_to_start = temp_to_start->getNext();
        delete temp_to_delete;
    }
};

void CircularLinkedList::shift_color(char C)
{
    int size_of_color = SizeCoul[mapCoul[C]];
    if (size_of_color == 0)
        return;
    char temp_F = lstCoul[mapCoul[C]]->getMyForm();
    Node *temp = lstCoul[mapCoul[C]];
    for (int i = 1; i < size_of_color; i++)
    {
        temp->setMyForm(temp->getNextSameColor()->getMyForm());
        temp = temp->getNextSameColor();
    }
    temp->setMyForm(temp_F);
    Node *temp_Tail = Tail;
    Tail = nullptr;
    int temp_Size = Size;
    Size = 0;
    for (int i = 0; i < 4; ++i)
    {
        lstCoul[i] = nullptr;
        lstForm[i] = nullptr;
        SizeCoul[i] = 0;
        SizeForm[i] = 0;
    }
    Node *temp_to_start = temp_Tail->getNext();
    for (int i = 0; i < temp_Size; i++)
    {
        insertAtEnd(temp_to_start->getMyColor(), temp_to_start->getMyForm());
        Node *temp_to_delete = temp_to_start;
        temp_to_start = temp_to_start->getNext();
        delete temp_to_delete;
    }
};