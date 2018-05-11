/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, standard IO, and strings
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "game.h"
#include "SDL.h"


//Starts up SDL and creates window


//Loads media





int main( int argc, char* args[] )
{



	if( init() )
	{
    loadstart();
    menu();
    loadbackground();
	showimage();
	Sleep(500);
	khoitao();
	loadbackground();
	showimage();
    running();

	}
	else printf("erro");

	//Free resources and close SDL
	close();

	return 0;
}



