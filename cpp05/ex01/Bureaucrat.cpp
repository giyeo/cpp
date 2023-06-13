#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(100) {};

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
	(grade <= 150)
		? ( (grade < 1) 
			? throw GradeTooHighException() : 0)
		: throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other): grade(other.getGrade()) {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->grade = other.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {};

void Bureaucrat::incrementGrade(int delta) {
	(this->grade - delta < 1)
		? throw GradeTooHighException()
		: this->grade -= delta;
}

void Bureaucrat::decrementGrade(int delta) {
	(this->grade + delta > 150)
		? throw GradeTooLowException()
		: this->grade += delta;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

std::string Bureaucrat::getName() const {
	return this->name;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat& src ) {
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return (os);
}

void Bureaucrat::signForm( Form &toSignForm) {
	try {
		toSignForm.beSigned(*this);
		std::cout << this->getName()
		<< " signed " << toSignForm.getName()
		<< std::endl;
	} catch(const std::exception& e) {
		std::cout << this->getName()
		<< " couldn't sign " << toSignForm.getName()
		<< " because " << e.what()
		<< std::endl;
	}
	
};