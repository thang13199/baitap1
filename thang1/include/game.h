#ifndef GAME_H
#define GAME_H
#include <stdio.h>
#include <string>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <SDL2/SDL.h>
#include "SDL.h"
extern int mang[];
extern int x,y; // tọa độ ô trống
extern int xx,yy; // xác định tọa độ cần in ảnh
void khoitao();
void hoanvi();
void phai();
void trai();
void len();
void xuong();
int chisootrong();
bool ktketthuc();
void running();



#endif // GAME_H
