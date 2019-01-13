#include "../include/window.h"
#include <stdio.h>
#include "../include/CollisionDetector.h"
#include "../include/Physics.h"

Window::Window(const int width, const int height) : camera_(Camera(Vector3f(-0, 0, -3), Vector3f(0, 0, 0), 1.0f, 20.0f, 160.f)),player(Vector3f(0,0,1))
{
	this->SCREEN_WIDTH = width;
	this->SCREEN_HEIGHT = height;
	Init();

	Matrix3f square;
	square.AddVector(
		Vector3f(0, 0, 0),
		Vector3f(1, 0, 0),
		Vector3f(1, 1, 0),
		Vector3f(0, 1, 0));
	Matrix3f square2;
	square2.AddVector(
		Vector3f(1, 0, 0),
		Vector3f(1, 0, 1),
		Vector3f(1, 1, 1),
		Vector3f(1, 1, 0));
	Matrix3f square3;
	square3.AddVector(
		Vector3f(0, 0, 0),
		Vector3f(0, 0, 1),
		Vector3f(0, 1, 1),
		Vector3f(0, 1, 0));
	Matrix3f square4;
	square4.AddVector(
		Vector3f(0, 0, 0),
		Vector3f(1, 0, 0),
		Vector3f(1, 0, 1),
		Vector3f(0, 0, 1));
	Matrix3f square5;
	square5.AddVector(
		Vector3f(0, 1, 0),
		Vector3f(1, 1, 0),
		Vector3f(1, 1, 1),
		Vector3f(0, 1, 1));
	Matrix3f square6;
	square6.AddVector(
		Vector3f(0, 0, 1),
		Vector3f(1, 0, 1),
		Vector3f(1, 1, 1),
		Vector3f(0, 1, 1));

	std::vector<Matrix3f> matrices;
	matrices.push_back(square);
	matrices.push_back(square2);
	matrices.push_back(square3);
	matrices.push_back(square4);
	matrices.push_back(square5);
	matrices.push_back(square6);
	auto s = Shape(matrices, Vector3f(.5, .5, .5),Vector3f(0,0,1));
	s.translate(Vector3f (-.5, -.5, -.5));
	//s.rotate(Vector3f(45, 0, 0));
	//s.rotate(Vector3f(0, 45, 0));
	s.translate(Vector3f(0, 0, 2));
	s.translate(Vector3f(0,0,0));
	addToShapes(s);
	
	//Vector3f ves = Vector3f(1, 1, 1);
	//Vector3f veb = Vector3f(1, 1, 1);

	//Physics ss;
	//auto x = ss.calculateOutProduct(ves, veb);
}

Window::~Window()
{
}

void Window::Draw(Matrix matrix)
{
	//auto x = SCREEN_WIDTH / 2.f;
	//auto y = SCREEN_HEIGHT / 2.f;
	auto x = 1;
	auto y = 1;

	for (int r = 0; r < matrix.getColumns() - 1; r++) {
		if (matrix[r][3] > 0 && matrix[r+1][3] > 0) {
			//auto m1 = matrix[r];
			auto v1 = matrix[r];

			//auto m2 = matrix[r + 1];
			auto v2 = matrix[r + 1];

			v1[0] = matrix[r][0] / matrix[r][3];
			v1[1] = matrix[r][1] / matrix[r][3];

			v2[0] = matrix[r + 1][0] / matrix[r + 1][3];
			v2[1] = matrix[r + 1][1] / matrix[r + 1][3];
			DrawVector(v1, v2);
		}
	}
	const auto last = matrix.getColumns() - 1;
	if (matrix[last][3] > 0 && matrix[0][3] > 0) {
		auto v1 = matrix[0];
		auto v2 = matrix[last];

		v1[0] = matrix[0][0] / matrix[0][3];
		v1[1] = matrix[0][1] / matrix[0][3];

		v2[0] = matrix[last][0] / matrix[last][3];
		v2[1] = matrix[last][1] / matrix[last][3];
		DrawVector(v1, v2);
	}

}

void Window::Draw(const Shape& shape)
{
	auto matrices = shape.projections();
	for (auto it = matrices.begin(); it != matrices.end(); it++)
	{
		auto k1 = (*it).getTranslatable();
		//auto k2 = camera_.getTranformationMatrix();
		auto k2 = camera_.getTranslationMatrix();
		auto k3 = camera_.getPerspectiveMatrix();

		//auto k3 = Matrix4x4f::getIdentityMatrix() * k2;
		//auto k = camera_.getTranformationMatrix() * (*it).getTranslatable();
		//auto k = (*it).getMatrix().getTranslatable();
		//const auto ll = Vector3f(1, 1, 1);
		//shape.translate(ll.getVector());
		auto k4 = k2 * k1;
		auto k5 = k3 * k4;

		Draw(k3*k2*k1);
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
		vector.addNumber(0.0f, 1.0f, 0.0f);
		//shapes_[0]->rotateOrigin(Vector3f(0, 0, 1),Vector3f(1,0,0));
		//player.shape().rotate(vector);
		//player.shape().rotateOrigin(vector);
		//camera_.rotate(Vector3f(0, 1, 0));
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
				float accel = 0;
				auto move = Matrix3f::getIdentityMatrix();
				auto moveVector = Vector3f();
				auto rotateVector = Vector3f();
				switch (e.key.keysym.sym)
				{
				case SDLK_DOWN:
					//moveVector[1] -= .5;
					rotateVector[0] -= 5;
					break;
				case SDLK_UP:
					//moveVector[1] += .5;
					rotateVector[0] += 5;
					break;
				case SDLK_LEFT:
					//moveVector[0] -= .5;
					rotateVector[1] -= 5;
					break;
				case SDLK_RIGHT:
					//moveVector[0] += .5;
					rotateVector[1] += 5;
					break;
				case SDLK_w:
					//todo movevecto = heading * acceleration
					//move = 1;
					accel = 1;
					break;
				case SDLK_s:
					//todo movevecto = heading * acceleration
					accel = -1;
					break;
				}
				moveVector = move.getMatrix() * accel * player.shape().heading().getVector();
				camera_.move(moveVector);
				player.shape().translate(moveVector);
				player.rotate(rotateVector);
				camera_.rotate2(rotateVector);
				
				//shapes_[0]->rotateOrigin(Vector3f(0, -1, 0));
				
				//player.shape().rotateOrigin(Vector3f(0,90,0));
				
				//player.shape().translate(moveVector);
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

	//float scaleX = SCREEN_WIDTH / tempXsize;
	//float scaleY = SCREEN_HEIGHT / tempYsize;

	float scaleX = 1;
	float scaleY = 1;

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

	float scaleX = SCREEN_WIDTH / tempXsize;
	float scaleY = SCREEN_HEIGHT / tempYsize;

	//float scaleX = 1;
	//float scaleY = 1;

	auto centerX = SCREEN_WIDTH / 2;
	auto centerY = SCREEN_HEIGHT / 2;

	auto originX = origin[0] * scaleX + centerX;
	auto originY = origin[1] * -1 * scaleY + centerY;

	auto directionX = direction[0] * scaleX + centerX;
	auto directionY = direction[1] * -1 * scaleY + centerY;
	SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
	SDL_RenderDrawLine(gRenderer, originX, originY, directionX, directionY);
	//SDL_RenderDrawLine(gRenderer, origin[0], origin[1], direction[0], direction[1]);
}
