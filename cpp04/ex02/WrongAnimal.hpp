#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__

#include <string>
#include <iostream>

class WrongAnimal {
    public:
        WrongAnimal();
		WrongAnimal(std::string type);
        ~WrongAnimal();
        WrongAnimal(const WrongAnimal &other);
        WrongAnimal& operator=(const WrongAnimal &other);

        void makeSound() const;
		std::string getType() const;
	protected:
        std::string type;
};

#endif