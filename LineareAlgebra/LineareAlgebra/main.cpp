//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "include/window.h"

#ifdef main
#undef main
#endif /* main */

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	Window window = Window();
	window.Draw();
	
	
	return 0;
}