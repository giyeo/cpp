#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	AForm("PresidentialPardonForm", 25, 5), target("Someone") {};

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("PresidentialPardonForm", 25, 5), target(target) {};

PresidentialPardonForm::~PresidentialPardonForm() {};

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other):
	AForm("PresidentialPardonForm", 25, 5) {
	this->target = other.target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this == &other) {
		this->target = other.target;
	}
	return (*this);
}

const std::string PresidentialPardonForm::getTarget() const {
	return this->target;
}

void PresidentialPardonForm::execute(Bureaucrat &bureaucrat) const {
	if(!this->getIsSigned())
		throw PresidentialPardonForm::FormIsNotSigned();
	if (this->getExecuteGradeRequired() < bureaucrat.getGrade())
		throw PresidentialPardonForm::GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox\n";
}