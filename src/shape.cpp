#include <iostream>
#include "../include/shape.h"
using namespace std;

shape::shape(char C, char F)
{
    color = C;
    form = F;
}

char shape::getMyColor()
{
    return color;
}

char shape::getMyForm()
{
    return form;
}

void shape::setMyColor(char C)
{
    color = C;
}
void shape::setMyForm(char F)
{
    form = F;
}