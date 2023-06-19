#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <deque>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyFind(T &container, int toFind) {
	typename T::iterator position = std::find(container.begin(), container.end(), toFind);
	if(position == container.end())
		throw std::runtime_error("Not found");
	return (position);
};

#endif
