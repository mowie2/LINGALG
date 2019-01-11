#pragma once
#include <SDL.h>
#include "Vector.h"
#include "../include/Matrix.h"
#include "Shape.h"
#include "SpaceShip.h"
#include <memory>

class Window
{
public:
	Window(const int width, const int height);
	Window(const Window& other) = delete;
	Window& operator=(const Window& other) = delete;
	Window(Window&& other) = delete;
	Window& operator=(Window&& other) = delete;



	~Window();
	void Draw(Matrix matrix);
	void Draw(const Shape& shape);

	void addToShapes(const Shape& shape);
	void moveShapes(const Vector3f& moveVector);
	
	void render();
	
	void CloseWindow();
	bool Init();
	void DrawPoint(Vector point);
	void DrawVector(Vector start, Vector end);
	void DrawAxis();

private:
	//Screen dimension constants
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	std::vector<std::unique_ptr<Shape>> shapes_;
	
	//std::vector<Shape*> shapes_;

	SpaceShip player;

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

