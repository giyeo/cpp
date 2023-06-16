#include "AForm.hpp"

AForm::AForm():
	name("default"),
	isSigned(false),
	signGradeRequired(150),
	executeGradeRequired(150) {};

AForm::~AForm() {};

AForm::AForm(std::string name, int signGrade, int executeGrade):
	name(name),
	isSigned(false),
	signGradeRequired(signGrade),
	executeGradeRequired(executeGrade) {
	(signGradeRequired > 150 || executeGradeRequired > 150)
		? throw GradeTooLowException() : 0;
	(signGradeRequired < 1 || executeGradeRequired < 1)
		? throw GradeTooHighException() : 0;
	};

AForm::AForm(const AForm &other):
	name(other.getName()),
	isSigned(other.getIsSigned()),
	signGradeRequired(other.getSignGradeRequired()),
	executeGradeRequired(other.getExecuteGradeRequired()) {};


AForm &AForm::operator=(const AForm& other)
{
	if (this != &other) {
		this->isSigned = other.getIsSigned();
		const_cast<int &>(this->signGradeRequired) = other.getSignGradeRequired();
		const_cast<int &>(this->executeGradeRequired) = other.getExecuteGradeRequired();
	}
	return (*this);
}

void	AForm::beSigned( Bureaucrat &bureaucrat) {
	if (this->signGradeRequired < bureaucrat.getGrade()) {
		this->isSigned = false;
		throw AForm::GradeTooLowException();
	} else {
		this->isSigned = true;
	}
}

const std::string AForm::getName() const {
	return(this->name);
};

bool AForm::getIsSigned() const{
	return(this->isSigned);
};

int AForm::getSignGradeRequired() const{
	return(this->signGradeRequired);
};

int AForm::getExecuteGradeRequired() const{
	return(this->executeGradeRequired);
};

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade is Too High";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade is Too Low";
}

const char *AForm::FormIsNotSigned::what() const throw() {
	return "Form is not signed, cannot be executed";
}

std::ostream& operator<<( std::ostream& os, const AForm& src ) {
	os << src.getName() << ", AForm grade" << src.getSignGradeRequired() << std::endl;
	return (os);
}