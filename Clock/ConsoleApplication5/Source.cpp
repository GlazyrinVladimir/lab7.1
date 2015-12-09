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
	arrow.setPosition(RADIUS, RADIUS);
	arrow.setOrigin(0, float(depth / 2));
}

void shapes_position(init_shapes &shape) 
{
	arrow_pos(shape.hourArrow, 100, 6);
	shape.hourArrow.setFillColor(sf::Color::White);

	arrow_pos(shape.minuteArrow, 140, 4);
	shape.minuteArrow.setFillColor(sf::Color::White);

	arrow_pos(shape.secondArrow, 180, 2);
	shape.secondArrow.setFillColor(sf::Color::White);

	shape.dot.setSize(sf::Vector2f(2, 2));
	shape.dot.setFillColor(sf::Color::White);

	shape.middle_dot.setSize(sf::Vector2f(10, 10));
	shape.middle_dot.setFillColor(sf::Color::White);
	shape.middle_dot.setPosition(RADIUS-5, RADIUS-5);

	shape.dot.setSize(sf::Vector2f(6, 6));
	shape.dot.setFillColor(sf::Color::White);
	
}

void draw_dots(RenderWindow &window, init_shapes &shape)
{
	for (int i = 0; i < AMOUNT_OF_DOTS; i++) 
	{
		if (i % 5 == 0)
		{
			shape.dot.setSize(Vector2f(6, 6));
			shape.dot.setOrigin(4 / 2, 4 / 2);
			shape.dot.setPosition(coordinateDots[i].x, coordinateDots[i].y);
			window.draw(shape.dot);
		}
		else
		{
			shape.dot.setSize(Vector2f(2, 2));
			shape.dot.setOrigin(2 / 2, 2 / 2);
			shape.dot.setPosition(coordinateDots[i].x, coordinateDots[i].y);
			window.draw(shape.dot);
		}
	}
}

void coord_dots() {
	Vector2f coordinateDot;
	for (int i = 0; i < AMOUNT_OF_DOTS; i++) 
	{
		coordinateDot.x = RADIUS + 180 * cos(i * SECOND * float(M_PI) / 180);
		coordinateDot.y = RADIUS + 180 * sin(i * SECOND * float(M_PI) / 180);
		coordinateDots[i] = { coordinateDot.x, coordinateDot.y };
	}
}

void start_program(RenderWindow &window, init_shapes &shape)
{
	SYSTEMTIME time;
	coord_dots();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		GetSystemTime(&time);

		shape.secondArrow.setRotation(float(time.wSecond * 6 - 90));
		shape.minuteArrow.setRotation(float(time.wMinute * 6 - 90));
		shape.hourArrow.setRotation(float((time.wHour + 3) * 30 - 90));
		
		window.clear();
		
		draw_dots(window, shape);

		window.draw(shape.secondArrow);
		window.draw(shape.minuteArrow);
		window.draw(shape.hourArrow);
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