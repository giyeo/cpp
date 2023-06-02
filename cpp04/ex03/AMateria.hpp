#ifndef __AMATERIA_HPP__
#define __AMATERIA_HPP__

#include <string>
#include "ICharacter.hpp"

class AMateria
{
	public:
		AMateria(std::string const & type);
		//[...]
		std::string const &getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
	protected:
		std::string type;
		//[...]
};

#endif