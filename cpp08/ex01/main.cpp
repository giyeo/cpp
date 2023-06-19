#include "Span.hpp"
#include <iostream>
int main() {
	//addNumber, longestSpan, shortestSpan Test
	{
		Span mySpan(3);
		mySpan.addNumber(1);	
		mySpan.addNumber(4);
		mySpan.addNumber(18);
		std::cout << "addNumber, longestSpan: " << mySpan.longestSpan() << "\n";
		std::cout << "addNumber, shortestSpan: " << mySpan.shortestSpan() << "\n";
	}
	//addNumber, longestSpan, shortestSpan Test
	{
		Span mySpan(10000);
		mySpan.fillSpan();
		std::cout << "fillSpan, longestSpan: " << mySpan.longestSpan() << "\n";
		std::cout << "fillSpan, shortestSpan: " << mySpan.shortestSpan() << "\n";
	}
	//addNumber and fillSpan
	{
		Span mySpan(10000);
		mySpan.addNumber(11000);
		mySpan.addNumber(20000);
		mySpan.fillSpan();
		std::cout << "addNumber and fillSpan, longestSpan: " << mySpan.longestSpan() << "\n";
		std::cout << "addNumber and fillSpan, shortestSpan: " << mySpan.shortestSpan() << "\n";
	}
	//addNumber more than max size Test
	{
		Span mySpan(3);
		try {
			mySpan.addNumber(1);	
			mySpan.addNumber(4);
			mySpan.addNumber(18);
			mySpan.addNumber(13);
		}
		catch(const std::exception& e)
		{
			std::cerr << "addNumber more than max size Test: " << e.what() << '\n';
		}
		
		std::cout << "addNumber more than max size, longestSpan: " << mySpan.longestSpan() << "\n";
		std::cout << "addNumber more than max size, shortestSpan: " << mySpan.shortestSpan() << "\n";
	}
	//Empty Span, addNumber Test
	{
		Span myEmptySpan;
		try{
			myEmptySpan.addNumber(1);
		}
		catch(const std::exception& e){
			std::cerr << "Empty Span, addNumber Test: " <<e.what() << '\n';
		}
	}
	//Empty Span, fillSpan test
	{
		//Only called when span size > 0;
		Span myEmptySpan;
		myEmptySpan.fillSpan();
	}
	//Empty Span, longestSpan Test
	{
		Span myEmptySpan;
		try{
			myEmptySpan.longestSpan();
		}
		catch(const std::exception& e){
			std::cerr << "Empty Span, longestSpan Test: " <<e.what() << '\n';
		}
	}
	//Empty Span, shortestSpan Test
	{
		Span myEmptySpan;
		try{
			myEmptySpan.shortestSpan();
		}
		catch(const std::exception& e){
			std::cerr << "Empty Span, shortestSpan Test: " <<e.what() << '\n';
		}
	}
	//Subject Test
	{
		std::cout << "Subject Test: Should out put 2 and 14 (subject test)\n";
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
}