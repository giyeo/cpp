#include "Form.hpp"

Form::Form():
	name("default"),
	isSigned(false),
	signGradeRequired(150),
	executeGradeRequired(150) {};

Form::~Form() {};

Form::Form(std::string name, int signGrade, int executeGrade):
	name(name),
	isSigned(false),
	signGradeRequired(signGrade),
	executeGradeRequired(executeGrade) {
	(signGradeRequired <= 150 || executeGradeRequired <= 150) 
		? ( (signGradeRequired < 1 || executeGradeRequired < 1)
			? throw GradeTooHighException() : 0 )
		: throw GradeTooLowException();
	};

Form::Form(const Form &other):
	name(other.getName()),
	isSigned(other.getIsSigned()),
	signGradeRequired(other.getSignGradeRequired()),
	executeGradeRequired(other.getExecuteGradeRequired()) {};


Form &Form::operator=(const Form& other)
{
	if (this != &other) {
		this->isSigned = other.getIsSigned();
		const_cast<int &>(this->signGradeRequired) = other.getSignGradeRequired();
		const_cast<int &>(this->executeGradeRequired) = other.getExecuteGradeRequired();
	}
	return (*this);
}

void	Form::beSigned( Bureaucrat &bureaucrat) {
	if (this->signGradeRequired < bureaucrat.getGrade()) {
		this->isSigned = false;
		throw Form::GradeTooLowException();
	} else {
		this->isSigned = true;
	}
}

const std::string Form::getName() const {
	return(this->name);
};

bool Form::getIsSigned() const{
	return(this->isSigned);
};

int Form::getSignGradeRequired() const{
	return(this->signGradeRequired);
};

int Form::getExecuteGradeRequired() const{
	return(this->executeGradeRequired);
};

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is Too High";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is Too Low";
}

std::ostream& operator<<( std::ostream& os, const Form& src ) {
	os << src.getName() << ", Form grade" << src.getSignGradeRequired() << std::endl;
	return (os);
}