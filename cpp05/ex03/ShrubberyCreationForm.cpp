#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("ShrubberyCreationForm", 145, 137), target("Someone") {};

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("ShrubberyCreationForm", 145, 137), target(target) {};

ShrubberyCreationForm::~ShrubberyCreationForm() {};

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other):
	AForm("ShrubberyCreationForm", 145, 137) {
	this->target = other.target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this == &other) {
		this->target = other.target;
	}
	return (*this);
}

const std::string ShrubberyCreationForm::getTarget() const {
	return this->target;
}

void ShrubberyCreationForm::execute(Bureaucrat &bureaucrat) const {
	if(!this->getIsSigned())
		throw ShrubberyCreationForm::FormIsNotSigned();
	if (this->getExecuteGradeRequired() < bureaucrat.getGrade())
		throw ShrubberyCreationForm::GradeTooLowException();

	std::string name = this->target + "_shrubbery";
	std::ofstream outputFile(name.c_str());

    if (outputFile.is_open()) {
        outputFile << "               ,@@@@@@@,\n";
        outputFile << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
        outputFile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
        outputFile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
        outputFile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
        outputFile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
        outputFile << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
        outputFile << "       |o|        | |         | |\n";
        outputFile << "       |.|        | |         | |\n";
        outputFile << "jgs \\\\/ ._/\\/_/__/  ,\\_//__\\\\/.  \\_//__/_\n";
        outputFile.close();
        std::cout << "File created and input added successfully.\n";
    } else {
        std::cout << "Failed to create/open the file.\n";
    }
}