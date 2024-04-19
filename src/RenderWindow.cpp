#include "../include/RenderWindow.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>

RenderWindow::RenderWindow(const char *p_title, int p_w, int p_h)
    : window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, 0);
    if (window == NULL)
    {
        std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
    };
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED && SDL_RENDERER_PRESENTVSYNC);
}

SDL_Texture *RenderWindow::loadTexture(const char *p_filePath)
{
    SDL_Texture *texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);
    if (texture == NULL)
    {
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
    }
    return texture;
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::renderBG(SDL_Texture *p_texture)
{
    SDL_RenderCopy(renderer, p_texture, NULL, NULL);
}

void RenderWindow::render(Entity &p_entity)
{
    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;
    SDL_Rect dst;
    dst.x = p_entity.getX();
    dst.y = p_entity.getY();
    dst.w = p_entity.getCurrentFrame().w;
    dst.h = p_entity.getCurrentFrame().h;
    SDL_RenderCopy(renderer, p_entity.getText(), &src, &dst);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}

SDL_Texture *RenderWindow::loadTextureFromChar(char C, char F)
{
    std::string path = "./assets/element/";
    path += F;
    path += "-";
    path += C;
    path += ".png";
    return loadTexture(path.c_str());
}

void RenderWindow::displayLst(CircularLinkedList *lst)
{
    if (lst->getTail() != nullptr)
    {
        int posX = 0, posY = 600;
        Node *temp = lst->getTail()->getNext();
        // print address of temp
        cout << "Address of temp : " << temp << endl;
        do
        {
            SDL_Texture *Element = loadTextureFromChar(temp->getMyColor(), temp->getMyForm());
            Entity entity(posX, posY, Element);
            render(entity);
            posX += 100;
            SDL_RenderPresent(renderer);
            temp = temp->getNext();
            Element = nullptr;
        } while (temp != lst->getTail()->getNext());
    }
}

void RenderWindow::shiftTheList(CircularLinkedList *lst)
{
    if (lst->getTail() != nullptr)
    {
        int posX = 0, posY = 600;
        Node *temp = lst->getTail()->getNext();
        SDL_Texture *Element = loadTextureFromChar(temp->getMyColor(), temp->getMyForm());
        // it must be shifted 10 pixels to the right
        posX += 10;
    }
}

void RenderWindow::DisplayTheNextElement(char C, char F)
{
    SDL_Texture *Element = loadTextureFromChar(C, F);
    Entity entity(1500, 300, Element);
    render(entity);
    SDL_RenderPresent(renderer);
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}
