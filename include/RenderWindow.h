#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "CircularLinkedList.h"
#include "Entity.h"
class RenderWindow
{
public:
    RenderWindow(const char *p_title, int p_w, int p_h);
    SDL_Texture *loadTexture(const char *p_filePath);
    void cleanUp();
    void clear();
    void renderBG(SDL_Texture *p_texture);
    SDL_Texture *loadTextureFromChar(char C, char F);
    void render(Entity &p_entity);
    void display();
    void displayLst(CircularLinkedList *lst);
    void insertedAtTheStart(char C, char F);
    void shiftTheList(CircularLinkedList *lst);
    void insertedAtTheEnd(char C, char F);
    void DisplayTheNextElement(char C, char F);

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};