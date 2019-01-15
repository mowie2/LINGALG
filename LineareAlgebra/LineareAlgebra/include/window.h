#pragma once
#include <SDL.h>
#include "Vector.h"
#include "../include/Matrix.h"
#include "Shape.h"
#include "SpaceShip.h"
#include <memory>
#include "Camera.h"
#include <chrono>

class Window
{
public:
	Window(const int width, const int height);
	void generateLevel();
	Window(const Window& other) = delete;
	Window& operator=(const Window& other) = delete;
	Window(Window&& other) = delete;
	Window& operator=(Window&& other) = delete;

	void start();

	~Window();
	void Draw(Matrix matrix);
	void Draw(Shape& shape);

	void addToShapes(const Shape& shape);
	void addToShapes(std::unique_ptr<Shape> shape);
	void rotateShapes(const Vector3f& rotateVector);
	void moveShapes(const Vector3f& moveVector);

	void addToBullets(std::unique_ptr<Shape> shape);
	void moveMoveBullets(const Vector3f& moveVector);
	void rotateBullets(const Vector3f& rotateVector);

	void Update(float dt);
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
	std::vector<std::unique_ptr<Shape>> bullets_;

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

	std::chrono::time_point<std::chrono::system_clock> lastTime;
	std::chrono::time_point<std::chrono::system_clock> startTime;
	std::chrono::duration<long long, std::ratio<1, 1000000>> deltaTime;
	float dt;
	double sinValue = 0;

	Camera camera_;
};

