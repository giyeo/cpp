#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <algorithm>
#include <stdexcept>
#include <stdint.h>

template <typename T>
class Array {
    public:
        Array() : content(new T[0]), length(0) {};
        ~Array() { delete[] content; };
        Array(uint32_t n) : content(new T[n]), length(n) {
            std::fill_n(content, n, 0);
        };
        Array(const Array &other) {
            *this = other;
        }
        Array& operator=(const Array &other) {
            if (this != &other) {
                this->length = other.length;
                this->content = new T[length];
                std::copy(other.content, other.content + length, this->content);
            }
            return (*this);
        }
        uint32_t size(void) const{
            return this->length;
        }
        T& operator[](uint32_t index) {
            if (index >= length)
                throw std::out_of_range("Index out of range");
            return this->content[index];
        };
    private:
        T *content;
        uint32_t length;

};

#endif