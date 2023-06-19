#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdint.h>
#include <list>

class Span {
	public:
		Span();
		Span(uint32_t size);
		~Span();
		Span(const Span &other);
		Span &operator=(const Span & other);

		void addNumber(int number);
		int shortestSpan();
		int longestSpan();

	private:
		std::list<int> *values;
};

#endif