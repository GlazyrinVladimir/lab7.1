#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

static const float QUADRANT = 90.0;
static const float SECOND = 6.0;
static const float RADIUS = 200.0;
static const int AMOUNT_OF_DOTS = 60;
//int coord_x, coord_y;
//const Vector2f COORDINATES = { COORD_X, COORD_Y };
Vector2f coordinateDots[AMOUNT_OF_DOTS];

struct init_shapes {
	RectangleShape secondArrow;
	RectangleShape minuteArrow;
	RectangleShape hourArrow;
	RectangleShape dot;

	RectangleShape middle_dot;
};
init_shapes shape;