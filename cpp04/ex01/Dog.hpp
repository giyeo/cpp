#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    public:
        Dog();
        ~Dog();
        Dog(const Dog &other);
        Dog& operator=(const Dog &other);
        
        void makeSound() const;
		std::string getIdea(int index) const;
		void setIdea(std::string idea, int index);
	private:
		Brain *brain;
};

#endif