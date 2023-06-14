#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern {
	public:
		Intern();
		~Intern();
		Intern(const Intern &other);
		Intern& operator=(const Intern &other);

        AForm *makeForm(std::string name, std::string target);
    private:
		AForm	*makeShrubberyCreationForm(std::string target);
		AForm	*makeRobotmyRequestForm(std::string target);
		AForm	*makePresidentialPardonForm(std::string target);
};

#endif