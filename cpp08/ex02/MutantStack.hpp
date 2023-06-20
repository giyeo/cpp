#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack<T>() {};
		~MutantStack() {};
		MutantStack<T>(const MutantStack<T> &other) {
			*this = other;
		};
		MutantStack<T> &operator=(const MutantStack<T> &other) {
			*this = other;
			return *this;
		}
		iterator begin() {
			return this->c.begin();
		}
		iterator end() {
			return this->c.end();
		};
};

#endif
