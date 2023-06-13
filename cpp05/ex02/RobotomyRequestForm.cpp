#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm():
	AForm("RobotomyRequestForm", 72, 45), target("Someone") {};

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("RobotomyRequestForm", 72, 45), target(target) {};

RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other):
	AForm("RobotomyRequestForm", 72, 45) {
	this->target = other.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this == &other) {
		this->target = other.target;
	}
	return (*this);
}

const std::string RobotomyRequestForm::getTarget() const {
	return this->target;
}

void RobotomyRequestForm::execute(Bureaucrat &bureaucrat) const {
	if(!this->getIsSigned())
		throw RobotomyRequestForm::FormIsNotSigned();
	if (this->getExecuteGradeRequired() < bureaucrat.getGrade())
		throw RobotomyRequestForm::GradeTooLowException();
	std::cout << "some drilling noises Whirrrr Buzzzz Rat-a-tat-tat" << std::endl;
	srand(time(0));
	if(rand() % 2 == 0)
		std::cout << this->target << " has been robotomized\n";
	else
		std::cout << this->target << " robotomy failed\n";
}