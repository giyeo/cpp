#include <iostream>
#include "Point.hpp"
bool bsp( const Point a, const Point b, const Point c, const Point point);

int main( void ) {
	Point a(4,0);
	Point b(0,0);
	Point c(2,3);

	//Inside
	Point* point = new Point(2, 1);
	std::cout << ((bsp(a,b,c,*point)) ? "True" : "False") << "\n";
	delete point;

	point = new Point(1.1, 1.3);
	std::cout << ((bsp(a,b,c,*point)) ? "True" : "False") << "\n";
	delete point;

	//Edge
	point = new Point(0, 0);
	std::cout << ((bsp(a,b,c,*point)) ? "True" : "False") << "\n";
	delete point;

	//Outside
	point = new Point(3, 2);
	std::cout << ((bsp(a,b,c,*point)) ? "True" : "False") << "\n";
	delete point;

	point = new Point(5.4, 2.3);
	std::cout << ((bsp(a,b,c,*point)) ? "True" : "False") << "\n";
	delete point;
	
	point = new Point(2, 4);
	std::cout << ((bsp(a,b,c,*point)) ? "True" : "False") << "\n";
	delete point;


	return 0;
}