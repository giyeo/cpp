#include "Form.hpp"
#include "Bureaucrat.hpp"

void    printForm(Form &form) {
	std::cout << "Name: " << form.getName() << "\n";
	std::cout << "Grade: to be signed " << form.getSignGradeRequired() << "\n";
	std::cout << "Grade: to be executed " << form.getExecuteGradeRequired() << "\n";
	std::cout << "Is signed: " << ((form.getIsSigned())? "true":"false") << "\n";
	std::cout << "\n";
}

void    printBureaucrat(Bureaucrat &bure) {
	std::cout << "Name: " << bure.getName() << "\n";
	std::cout << "Grade: " << bure.getGrade() << "\n";
	std::cout << "\n";
}

void	testSignedForm(Form &form, Bureaucrat &bure) {
	try {
		form.beSigned(bure);
		std::cout << "Form " << form.getName() << " signed by " << bure.getName() << "\n";
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
}

int main( void ) {
	Form form;

	printForm(form);
	Form coolform("coolform", 10, 10);

	printForm(coolform);

	Bureaucrat defaultGuy;
	Bureaucrat jimmy("jimmy", 4);

	printBureaucrat(defaultGuy);
	printBureaucrat(jimmy);

	std::cout << "Sign defaultGuy to " << coolform.getName() << "\n";
	testSignedForm(coolform, defaultGuy);
	defaultGuy.signForm(coolform);
	std::cout << "\n";

	std::cout << "Sign jimmy to " << coolform.getName() << "\n";
	testSignedForm(coolform, jimmy);
	jimmy.signForm(coolform);
	std::cout << "\n";

	return (0);
}