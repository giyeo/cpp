#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdint.h>
#include <list>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <deque>

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
		void fillSpan();
	private:
        uint32_t size;
		std::vector<int> values;
};

#endif