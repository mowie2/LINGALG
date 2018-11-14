#include "../include/window.h"
#include <stdio.h>

Window::Window()
{
	Init();
}

Window::~Window()
{
}

void Window::Draw()
{
	// Vectors
	Vector startPoint1 = Vector(0,0);
	Vector direction = Vector(9, 5);
	Vector startPoint2 = Vector(1, 0);


	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	//Get window surface
	screenSurface = SDL_GetWindowSurface(window);

	//Update the surface
	SDL_UpdateWindowSurface(window);

	//While application is running
			//While application is running
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 1, 1, 1, 255); // background color
		SDL_RenderClear(gRenderer);


		DrawPoint(startPoint1);
		DrawPoint(direction);
		DrawVector(startPoint1, direction);
		DrawVector(startPoint2, direction);
		DrawAxis();

		//Update screen
		SDL_RenderPresent(gRenderer);
	}
	//Wait two seconds
	//SDL_Delay(2000);

}
void Window::DrawAxis() {


	//Draw blue horizontal line
	SDL_SetRenderDrawColor(gRenderer, 0, 0, 255, 255);
	SDL_RenderDrawLine(gRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);
	//Draw vertical line of yellow dots
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0x00, 0xFF);
	SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT);
	//for (int i = 0; i < SCREEN_HEIGHT; i += 4)
	//{
	//	SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, i);
	//}
}

void Window::CloseWindow() {
	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();
}

bool Window::Init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
			}
		}
	}

	return success;
}

void Window::DrawPoint(Vector point)
{
	int scale = 100;
	auto centerX = SCREEN_WIDTH / 2;
	auto centerY = SCREEN_HEIGHT / 2;

	auto pointx = point.getXCor() * scale / 2;
	auto pointy = point.getYCor() * scale *-1 / 2;

	SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
	SDL_RenderDrawPoint(gRenderer, centerX + pointx, centerY + pointy);
}

void Window::DrawVector(Vector origin, Vector direction)
{
	int scale = 100;
	auto centerX = SCREEN_WIDTH / 2;
	auto centerY = SCREEN_HEIGHT / 2;

	auto originX = origin.getXCor() * scale / 2;
	auto OriginY = origin.getYCor() * scale *-1 / 2;

	auto directionX = direction.getXCor() * scale / 2;
	auto DirectionY = direction.getYCor() * scale *-1 / 2;

	
	auto deltaX = originX + directionX;
	auto deltaY = OriginY + DirectionY;

	SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
	SDL_RenderDrawLine(gRenderer, centerX + originX, centerY + OriginY, centerX + deltaX, centerY + deltaY);
}
