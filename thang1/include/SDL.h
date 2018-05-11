#ifndef SDL_H
#define SDL_H
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "game.h"

extern int SCREEN_WIDTH; // kích cỡ của sổ sdl
extern int SCREEN_HEIGHT;
extern SDL_Window* gWindow;//The window we'll be rendering to
extern SDL_Surface *loadSurface( std::string path );//load đường dẫn ảnh
extern SDL_Window* gWindow ;
extern SDL_Surface* gScreenSurface ;
extern SDL_Surface* gCurrentSurface ;
extern SDL_Surface* gStretchedSurface ;
bool init(); // tạo của sổ
void close();//đóng của sổ sdl
bool loadMedia(int i);
void loadbackground();
void loadEnd();
void loadhuongdan();
void menu();
void loadstart();
void load_xy(int i);
void showimage() ;

//void showimage();
#endif // SDL_H
