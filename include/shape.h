#pragma once

class shape
{
    char color;
    char form;

public:
    shape(char C, char F);
    char getMyColor();
    char getMyForm();
    void setMyColor(char C);
    void setMyForm(char F);
};
