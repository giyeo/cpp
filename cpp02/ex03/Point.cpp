#include "Point.hpp"

Point::Point(void) : x(0), y(0) {};

Point::Point(const float x, const float y) : x(x), y(y) {};

Point::~Point(void) {};

Point::Point(const Point &other) : x(other.x), y(other.y) {};

Point& Point::operator=(const Point &other)
{
    if(this != &other) {}
    return *this;
}

float Point::getX(void)
{
    return this->x.toFloat();
}

float Point::getY(void)
{
    return this->y.toFloat();
}