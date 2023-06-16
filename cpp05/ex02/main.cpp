#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

template <typename T>
void	testForms( T& form) {
	std::cout << "Creating a " << form.getName() << "\n";
	std::cout << "Target: " << form.getTarget() << "\n";
	std::cout << "Grade to be Signed: " << form.getSignGradeRequired() << "\n";
	std::cout << "Grade to be Executed: " << form.getExecuteGradeRequired() << "\n";
	std::cout << "\n";
}

template <typename T>
void	trySigned(T& form, Bureaucrat& bure) {

	std::cout << "Name: " << bure.getName() << "\n";
	std::cout << "Grade: " << bure.getGrade() << "\n";
	std::cout << "\n";
	std::cout << "Signing " << bure.getName() << " to " << form.getName() << "\n";
	try {
		form.beSigned(bure);
		std::cout << "Signed successfully" << "\n";
	} catch(std::exception &e) {
		std::cout << "Signed Unsuccessfully" << "\n";
	}
	std::cout << "\n";
	std::cout << "Executing " << bure.getName() << " to " << form.getName() << "\n";
	try {
		form.execute(bure);
		std::cout << "Execute successfully" << "\n";
	} catch(std::exception &e) {
		std::cout << "Execute Unsuccessfully" << "\n";
	}
	std::cout << "\n";
}

int main( void ) {

	//AForm form = new AForm();
	PresidentialPardonForm pardon("world peace");
	RobotomyRequestForm robot("Future");
	ShrubberyCreationForm shruberry("Nothing");
	
	testForms(pardon);
	testForms(robot);
	testForms(shruberry);

	Bureaucrat  mark("mark", 50);
	Bureaucrat  flavio("flavio", 10);
	Bureaucrat  zoro("zoro", 136);

	trySigned(pardon, mark);
	trySigned(robot, flavio);
	trySigned(shruberry, zoro);

	Bureaucrat hendrick("hendrick", 60);

	std::cout << "Name: " << hendrick.getName() << "\n";
	std::cout << "Grade: " << hendrick.getGrade() << "\n";
	std::cout << "\n";

	hendrick.executeForm(shruberry);
	hendrick.executeForm(robot);
	hendrick.executeForm(pardon);
	return (0);
}