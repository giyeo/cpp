#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    public:
        Cat();
        ~Cat();
        Cat(const Cat &other);
        Cat& operator=(const Cat &other);

        void makeSound() const;
		std::string getIdea(int index) const;
		void setIdea(std::string idea, int index);
	private:
		Brain *brain;
};

#endif