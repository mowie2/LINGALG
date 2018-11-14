#pragma once
#include <SDL.h>
#include "Vector.h"

class Window
{
public:
	Window();
	~Window();
	void Draw();
	void CloseWindow();
	bool Init();
	void DrawPoint(Vector point);
	void DrawVector(Vector start, Vector end);
	void DrawAxis();

private:
	//Screen dimension constants
	const int SCREEN_WIDTH = 1000;
	const int SCREEN_HEIGHT = 1000;

	//The window we'll be rendering to
	SDL_Window* window;

	SDL_Renderer* gRenderer;

	//The surface contained by the window
	SDL_Surface* screenSurface;

	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;

	//The surface contained by the window
	SDL_Surface* gScreenSurface = NULL;

	//The image we will load and show on the screen
	SDL_Surface* gHelloWorld = NULL;
};

