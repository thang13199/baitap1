#include "SDL.h"
const int KTanh=130,le=30; // kich thuoc anh. kick thuoc le
int SCREEN_WIDTH = 803; //kick thuoc cửa sổ sdl
int SCREEN_HEIGHT = 450;
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;//The surface contained by the window
SDL_Surface* gCurrentSurface = NULL;//Current displayed image
SDL_Surface* gStretchedSurface ;
SDL_Surface *loadSurface( std::string path )
{
	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() ); // load ảnh BMP
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
	}

	return loadedSurface;
}
void close()//đóng cửa sổ sdl
{
	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}


bool init() // tạo của sổ sdl
{
	//Initialization flag
	bool success = true;
		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
	return success;
}
void loadbackground() // load ảnh nền
{
           gCurrentSurface = loadSurface("nen.bmp");				//load ảnh
            SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, NULL );				//Update the surface
            SDL_UpdateWindowSurface( gWindow );


}
void loadEnd() // load ảnh kết thúc
{
            gCurrentSurface = loadSurface("end.bmp");				//load ảnh
            SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, NULL );				//Update the surface
            SDL_UpdateWindowSurface( gWindow );



}
void loadhuongdan() // load ảnh hướng dẫn
{
            gCurrentSurface = loadSurface("huongdan.bmp");
            SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, NULL );				//Update the surface
            SDL_UpdateWindowSurface( gWindow );



}
void loadstart() // load ảnh bắt đầu
{
            gCurrentSurface = loadSurface("batdau.bmp");
            SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, NULL );				//Update the surface
            SDL_UpdateWindowSurface( gWindow );



}

void menu(){ // vòng lặp bắt đầu

bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while(!quit)
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit

					 if( e.type == SDL_KEYDOWN )
					{
						//Select surfaces based on key press
						switch( e.key.keysym.sym ) // kiểm tra nút bấm
						{
							case SDLK_s:
							quit=true;
							break;

                            case SDLK_h:
                            loadhuongdan();
                            break;
							default:
                            break;
						}

					}
				}
				}
}





bool loadMedia(int i)    /* load đường dẫn ảnh: với từng giá trị của mang[i]*/
{
	//Loading success flag
	bool success = true;

	//Load stretching surface
	switch(i)//i là giá trị hiện tại của mang[i];
						{
							case 1:
							gStretchedSurface = loadSurface( "1.bmp" );
							break;
							case 2:
							gStretchedSurface = loadSurface( "2.bmp" );
							break;
							case 3:
							gStretchedSurface = loadSurface( "3.bmp" );
							break;
							case 4:
							gStretchedSurface = loadSurface( "4.bmp" );
							break;
							case 5:
							gStretchedSurface = loadSurface( "5.bmp" );
							break;
							case 6:
							gStretchedSurface = loadSurface( "6.bmp" );
							break;
							case 7:
							gStretchedSurface = loadSurface( "7.bmp" );
							break;
							case 8:
							gStretchedSurface = loadSurface( "8.bmp" );
							break;
							default:
							gStretchedSurface = loadSurface( "0.bmp" );
							break;

						}



	return success;
}
void load_xy(int i)  /* Xác định tọa độ in ảnh, lần lượt là 0 2 3
                                                            4 5 6
                                                            7 8 default
                                                            */
{switch(i)
						{
							case 0:
							xx=le;yy=le;
							break;
							case 1:
							xx=le+KTanh;yy=le;
							break;
							case 2:
							xx=le+KTanh*2;yy=le;
							break;
							case 3:
							xx=le;yy=le+KTanh;
							break;
							case 4:
							xx=le+KTanh;yy=le+KTanh;
							break;
							case 5:
							xx=le+KTanh*2;yy=le+KTanh;
							break;
							case 6:
							xx=le;yy=le+KTanh*2;
							break;
							case 7:
							xx=le+KTanh;yy=le+KTanh*2;
							break;
                            default:
							xx=le+KTanh*2;yy=le+KTanh*2;
							break;

}
}
void showimage()  /* in ảnh(ảnh nhỏ) ra màn hình game*/
{
    int i;
    for (i=0;i<9;i++)
    {
     load_xy(i);
    if( !loadMedia(mang[i]) )
		{
			printf( "Failed to load media!\n" );
		}
		else{
                SDL_Rect stretchRect;
				stretchRect.x = xx;
				stretchRect.y = yy;
				stretchRect.w = 130;
				stretchRect.h = 130;
				SDL_BlitScaled( gStretchedSurface, NULL, gScreenSurface, &stretchRect );

				//Update the surface
				SDL_UpdateWindowSurface( gWindow );
            }
    }
}
