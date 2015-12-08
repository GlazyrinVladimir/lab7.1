#include <windows.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES
#include <math.h>
#include "var.h"

using namespace sf;

void arrow_pos(RectangleShape &arrow, float height, float depth) 
{
	arrow.setSize(sf::Vector2f(float(height), float(depth)));
	arrow.setPosition(radius, radius);
	arrow.setOrigin(0, float(depth / 2));
}

void shapes_position(init_shapes &shape) 
{
	arrow_pos(shape.arrowH, 100, 6);
	shape.arrowH.setFillColor(sf::Color::White);

	arrow_pos(shape.arrowM, 140, 4);
	shape.arrowM.setFillColor(sf::Color::White);

	arrow_pos(shape.arrowS, 180, 2);
	shape.arrowS.setFillColor(sf::Color::White);

	shape.s_dot.setSize(sf::Vector2f(2, 2));
	shape.s_dot.setFillColor(sf::Color::White);

	shape.middle_dot.setSize(sf::Vector2f(10, 10));
	shape.middle_dot.setFillColor(sf::Color::White);
	shape.middle_dot.setPosition(radius-5, radius-5);

	shape.h_dot.setSize(sf::Vector2f(6, 6));
	shape.h_dot.setFillColor(sf::Color::White);
	
}

void draw_dots(RenderWindow &window, init_shapes &shape, float(&arrayX)[60], float(&arrayY)[60])
{
	for (int i = 0; i < 60; i++) 
	{
		if (i % 5 == 0)
		{
			shape.h_dot.setOrigin(4 / 2, 4 / 2);
			shape.h_dot.setPosition(arrayX[i], arrayY[i]);
			window.draw(shape.h_dot);
		}
		else
		{
			shape.s_dot.setOrigin(2 / 2, 2 / 2);
			shape.s_dot.setPosition(arrayX[i], arrayY[i]);
			window.draw(shape.s_dot);
		}
	}
}

void coord_dots(float(&arrayX)[60], float(&arrayY)[60]) {
	for (int i = 0; i < 60; i++) 
	{
		arrayX[i] = radius + 180 * cos(i * 6 * float(M_PI) / 180);
		arrayY[i] = radius + 180 * sin(i * 6 * float(M_PI) / 180);
	}
}

void start_program(RenderWindow &window, init_shapes &shape)
{
	float arrayX[60], arrayY[60];
	SYSTEMTIME time;
	coord_dots(arrayX, arrayY);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		GetSystemTime(&time);

		shape.arrowS.setRotation(float(time.wSecond * 6 - 90));
		shape.arrowM.setRotation(float(time.wMinute * 6 - 90));
		shape.arrowH.setRotation(float((time.wHour + 3) * 30 - 90));
		
		window.clear();
		
		draw_dots(window, shape, arrayX, arrayY);

		window.draw(shape.arrowS);
		window.draw(shape.arrowM);
		window.draw(shape.arrowH);
		window.draw(shape.middle_dot);
		window.display();
	}
}

int main()
{
	shapes_position(shape);

	sf::RenderWindow window(sf::VideoMode(400, 400), "Clock");

	start_program(window, shape);
}