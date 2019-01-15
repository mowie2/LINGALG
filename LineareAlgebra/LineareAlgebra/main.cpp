//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "include/window.h"
#include "../LineareAlgebra/include/Matrix.h"
#include <vector>
#include "../../SDL2/include/SDL_stdinc.h"

#ifdef main
#undef main
#endif /* main */

//Screen dimension constants
const int SCREEN_WIDTH = 1;
const int SCREEN_HEIGHT = 1;

int main(int argc, char* args[])
{
	Window window = Window(1000,500);
	window.render();
	return 0;
}