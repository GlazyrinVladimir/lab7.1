#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

const float quadrant = 90.0;
const float second = 6.0;
const float half_second = 3.0;
const float third_quadrant = 30.0;
const float radius = 200.0;
int coord_x, coord_y;

struct init_shapes {
	RectangleShape arrowS;
	RectangleShape arrowM;
	RectangleShape arrowH;
	RectangleShape s_dot;
	RectangleShape h_dot;
	RectangleShape middle_dot;
};
init_shapes shape;