#include "game.h"


int mang[9]={1,2,3,4,5,6,7,8,0};
int x=2,y=2;
int xx=0,yy=0;


int chisootrong(){ //tìm ô trống.
return (x*3+y);
}

bool ktketthuc(){ // kiểm tra đã hết game
    for(int i=0;i<8;i++)
        if(mang[i]!=i+1)
            return false;
         return true;
}
void hoanvi(int i){ //đổi giá trị của 2 ô trong mảng
    int o=chisootrong();
    int temp=mang[o];
    mang[o]=mang[o+i];
    mang[o+i]=temp;
}
void len(){
if (x>0){  //kiểm tra xem còn có thể di chuyển ô trống không
    hoanvi(-3); //truyền vào hàm hoanvi để lấy dc giá trị ô bên trên
    x--;     // thay đổi tọa độ ô trống ( ô trống di chuyển lên)
}
}
void xuong(){
if (x<2){
    hoanvi(3);
    x++;
}
}
 void trai(){
if (y>0){
    hoanvi(-1);
    y--;
}
}
void phai(){
if (y<2){
    hoanvi(1);
    y++;
}
}

void khoitao(){                // Tráo đổi các ô ảnh ( các giá trị trong mảng
srand((unsigned int)time(0));
for (int i=0;i<=50;i++){
    int r=rand()%4;
    if (r==0) len();
    if (r==1) xuong();
    if (r==2) trai();
    if (r==3) phai();

}
}

void running(){ // vòng lặp game

bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while(1)
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					//User presses a key
					else if( e.type == SDL_KEYDOWN )
					{
						//Select surfaces based on key press
						switch( e.key.keysym.sym ) // kiểm tra nút bấm
						{
							case SDLK_UP:
							xuong();
							break;

							case SDLK_DOWN:
							len();
							break;

							case SDLK_LEFT:
							phai();

							break;
                            case SDLK_RIGHT:
                            trai();
							default:
                            break;
						}
						showimage();
                        if (ktketthuc())
                        {
                            loadEnd();
                            Sleep(3000);
                            close();
                        }
					}
				}
				}
}

