// Interface cronstrution for the IA GRAPHICS
// Of Tiago for the World

#include <windows.h>
#include <iostream>
#include "SDL.h"
#include <SDL2\SDL_image.h>
#include <SDL2\SDL_ttf.h>
#undef main

// Graphics
#define square_space_x 40
#define square_space_y 20

#ifndef INTERFACE_H
#define INTERFACE_H

typedef struct {
  int x;
  int y;
} pos;

class interface_ {
 public:
void init_(int LEN_x___, int LEN_y___);
void ___print(std::string str);
void ___print_square(pos pos_, std::string str);
void ___print__floor(int i, pos pos_);
void close___();
void wait_and_continue();
void __image(int p_, pos pos_, int number);
void clean___();
void clean_m();  
private:
SDL_Surface *screen;
SDL_Window *window;
SDL_Window *m_window;
SDL_Surface *image;
SDL_Renderer *renderer;
SDL_Renderer *m_renderer;
SDL_Texture *texture = NULL;
SDL_Surface *surfaceMessage;
SDL_Texture *Message;
SDL_Surface *surfaceMessage_;
SDL_Texture *Message_;
SDL_Event evt;
SDL_Rect SrcR;
SDL_Rect DestR;
int __i;
bool x__;
int LEN_x;
int LEN_y;
};

#endif
