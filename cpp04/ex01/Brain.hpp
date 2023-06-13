#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include <string>
#include <iostream>

class Brain {
    public:
        Brain();
        ~Brain();
        Brain(const Brain &other);
        Brain& operator=(const Brain &other);
		std::string ideas[100];
};

#endif