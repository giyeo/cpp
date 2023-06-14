#include "Intern.hpp"

Intern::Intern() {};

Intern::~Intern() {};

Intern::Intern(Intern const &other){
    *this = other;
}

Intern &Intern::operator=(const Intern &other) {
	if (this == &other) {}
	return (*this);
}

AForm	*Intern::makePresidentialPardonForm( std::string target ) {
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeShrubberyCreationForm( std::string target ) {
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeRobotmyRequestForm( std::string target ) {
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makeForm( std::string name, std::string target ) {
	std::string types[3] = {"shrubbery creation",
		"robotomy request",
		"presidential pardon"};

	AForm    *(Intern::*forms[3])(std::string target) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotmyRequestForm,
		&Intern::makePresidentialPardonForm};

	for (size_t i = 0; i < 3; i++) {
		if (types[i] == name) {
			std::cout << "Intern creates " << types[i] << std::endl;
			return ((this->*forms[i])(target));
		}
	}
	std::cout << "This type of Form doesn't exists" << std::endl;
	return (NULL);
}