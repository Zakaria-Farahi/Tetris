#include <iostream>
#include <map>
#include <cstdlib>
#include "./include/CircularLinkedList.h"
#include "./include/RenderWindow.h"
#include "./include/Entity.h"
using namespace std;

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

map<char, int> mapCoul = {{0, 'R'}, {1, 'B'}, {2, 'G'}, {3, 'Y'}};
map<char, int> mapForm = {{0, 'C'}, {1, 'S'}, {2, 'T'}, {3, 'D'}};
// map for ansi color
map<char, string> mapColorStart = {{'R', ANSI_COLOR_RED}, {'B', ANSI_COLOR_BLUE}, {'G', ANSI_COLOR_GREEN}, {'Y', ANSI_COLOR_YELLOW}};

char randomForm()
{
    return mapForm[rand() % 4];
}

char randomColor()
{
    return mapCoul[rand() % 4];
}

int main()
{
    // START SDL
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        cout << "SDL_Init has failed. Error: " << SDL_GetError() << endl;
        return 1; // Return an error code if SDL initialization fails
    }
    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        cout << "IMG_Init has failed. Error: " << SDL_GetError() << endl;
        SDL_Quit(); // Clean up SDL before exiting
        return 1;   // Return an error code if SDL image initialization fails
    }
    RenderWindow window("Avatar x Tetris", 1800, 800);               // Create SDL window
    SDL_Texture *background = window.loadTexture("./assets/BG.png"); // Load background texture
    bool isRunning = true;
    SDL_Event event;

    // END SDL
    srand(time(NULL));
    CircularLinkedList lst;
    window.clear();
    window.renderBG(background);
    window.display();
    do
    {
        cout << "The List : ";
        lst.display();
        cout << endl;
        cout << "Next Random Element : " << endl;
        char RndClr = randomColor();
        char RndForm = randomForm();
        cout << mapColorStart[RndClr] << RndForm << ANSI_COLOR_RESET << endl;
        window.DisplayTheNextElement(RndClr, RndForm);
        cout << "Q. Insert at the Start" << endl;
        cout << "D. Insert at the End" << endl;

    // Handle SDL events for keyboard input
    isJustMouse:

        SDL_WaitEvent(&event);

        if (event.type == SDL_QUIT)
        {
            isRunning = false;
        }
        else if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_q:
                lst.insertAtStart(RndClr, RndForm);
                break;
            case SDLK_d:
                lst.insertAtEnd(RndClr, RndForm);
                break;
            default:
                goto isJustMouse;
                break;
            }
        }
        else
        {
            goto isJustMouse;
        }
        window.clear();
        window.renderBG(background);
        window.display();
        window.displayLst(&lst);

        if (lst.getSize() > 18)
        {
            isRunning = false;
        }
    } while (isRunning);

    // Clean up resources
    window.cleanUp();
    SDL_Quit();
    return 0;
}