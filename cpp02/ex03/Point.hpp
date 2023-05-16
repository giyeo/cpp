#ifndef __POINT_HPP__
#define __POINT_HPP__
#include <iostream>
#include <cmath>
#include "Fixed.hpp"
class Point
{
    public:
        Point(void);
        Point(
            const float x,
            const float y);
        ~Point(void);
        Point(const Point &other);
        Point& operator=(const Point &other);

        float getX(void);
        float getY(void); 
    private:
        const Fixed x;
        const Fixed y;
};

#endif