#include "../include/window.h"
#include <stdio.h>
#include "../include/Objects.h"

Window::Window(const int width, const int height)
{
	this->SCREEN_WIDTH = width;
	this->SCREEN_HEIGHT = height;
	Init();

	shapes_.push_back(std::make_unique<Shape>(Objects::cube(Vector3f{ 3,3,3 }), Vector3f{ 3,3,3 }));
	shapes_.at(0)->rotate(Vector3f{ 0,0,45 });

	shapes_.push_back(std::make_unique<Shape>(Objects::cube(Vector3f{ -2,-2,-2 }), Vector3f{ -2,-2,-2 }));
	shapes_.at(1)->rotate(Vector3f{ 0,35,0 });
}

Window::~Window()
{
}

void Window::Draw(Matrix matrix)
{
	for (int r = 0; r < matrix.getColumns() - 1; r++) {
		DrawVector(matrix[r], matrix[r + 1]);
	}
	DrawVector(matrix[0], matrix[matrix.getColumns() - 1]);
}

void Window::Draw(const Shape& shape)
{
	auto matrices = shape.projections();
	for (auto it = matrices.begin(); it != matrices.end(); it++)
	{
		Draw((*it).getMatrix());
	}
}

void Window::addToShapes(const Shape& shape)
{
	shapes_.push_back(std::make_unique<Shape>(shape));
}

void Window::moveShapes(const Vector3f & moveVector)
{
	auto& shapes = shapes_;
	for (auto it = shapes_.begin(); it != shapes_.end(); it++)
	{
		(*it)->translate(moveVector);
	}
}

void Window::rotateShapes(const Vector3f & rotateVector)
{
	auto& shapes = shapes_;
	for (auto it = shapes_.begin(); it != shapes_.end(); it++)
	{
		(*it)->rotateAround(player.shape(), rotateVector);
	}
}

void Window::render()
{//Main loop flag
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
		Vector vector;
		vector.addNumber(0.1f, 0.2f, 0.2f);
		//player.shape().rotate(vector);
		//player.shape().rotateOrigin(vector);

		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//catch input

			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				auto moveVector = Vector3f();
				switch (e.key.keysym.sym)
				{
				case SDLK_s:
					rotateShapes(Vector3f(0.f, 0.f, 0.5f));
					//player.shape().rotateOrigin(Vector3f(0.f, 0.f, 0.5f));
					break;
				case SDLK_w:
					rotateShapes(Vector3f(0.f, 0.f, -0.5f));
					break;
				case SDLK_a:
					rotateShapes(Vector3f(0.5f, 0.f, 0.f));
					break;
				case SDLK_d:
					rotateShapes(Vector3f(-0.5f, 0.f, 0.f));
					break;
				case SDLK_q:
					rotateShapes(Vector3f(0.f, -0.5f, 0.f));
					break;
				case SDLK_e:
					rotateShapes(Vector3f(0.f, 0.5f, 0.f));
					break;
					break;
				}
				moveShapes(moveVector);
			}
		}

		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 1, 1, 1, 255); // background color
		SDL_RenderClear(gRenderer);
		DrawAxis();

		Draw(player.shape());

		auto& shapes = shapes_;
		for (auto it = shapes.begin(); it != shapes.end(); it++)
		{
			Draw(*(*it));
		}


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
	int tempXsize = 20;
	int tempYsize = 10;

	float scaleX = SCREEN_WIDTH / tempXsize;
	float scaleY = SCREEN_HEIGHT / tempYsize;

	auto centerX = SCREEN_WIDTH / 2;
	auto centerY = SCREEN_HEIGHT / 2;

	auto pointx = point[0] * scaleX + centerX;
	auto pointy = point[1] * -1 * scaleY + centerY;

	SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
	SDL_RenderDrawPoint(gRenderer, pointx, pointy);
}

void Window::DrawVector(Vector origin, Vector direction)
{
	int tempXsize = 20;
	int tempYsize = 10;
	
	float scaleX = SCREEN_WIDTH/tempXsize;
	float scaleY = SCREEN_HEIGHT/tempYsize;
	
	auto centerX = SCREEN_WIDTH / 2;
	auto centerY = SCREEN_HEIGHT / 2;

	auto originX = origin[0] * scaleX + centerX;
	auto originY = origin[1] * -1 * scaleY + centerY;

	auto directionX = direction[0] * scaleX + centerX;
	auto directionY = direction[1] * -1 * scaleY + centerY;
	SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
	SDL_RenderDrawLine(gRenderer, originX, originY, directionX, directionY);
}
