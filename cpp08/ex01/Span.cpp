#include "Span.hpp"

Span::Span() : size(0) {};

Span::Span(uint32_t size) : size(size) {};

Span::~Span() {};

Span::Span(const Span &other) {
    *this = other;
}

Span &Span::operator=(const Span &other) {
	if(this != &other) {
		this->size = other.size;
        this->values = other.values;
	}
	return *this;
}

void Span::addNumber(int number) {
    if(values.size() >= this->size)
        throw std::runtime_error("Can't add more numbers, max size reached!");
    values.push_back(number);
    std::sort(values.begin(), values.end());
}

int Span::shortestSpan() {
    if(values.size() <= 1)
        throw std::runtime_error("Can't get Span (need two or more values)!");
    int minSpan = INT_MAX;
    for(uint32_t i = 0; i + 1 < values.size(); i++) {
        int span = values[i + 1] - values[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() {
    if(values.size() <= 1)
        throw std::runtime_error("Can't get Span (need two or more values)!");
    std::vector<int>::iterator max = std::max_element(values.begin(), values.end());
    std::vector<int>::iterator min = std::min_element(values.begin(), values.end());
    return (*max - *min);
}

void Span::fillSpan() {
    for(size_t i = 0; values.size() < this->size; i++)
        values.push_back(i);
    std::sort(values.begin(), values.end());
}
