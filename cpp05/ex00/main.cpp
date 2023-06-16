#include "Bureaucrat.hpp"

void	putBreaksLines(int n) {
	for (int i = 0; i < n; i++)
		std::cout << "\n";
}

void	printBureaucrat(Bureaucrat &b) {
		std::cout
			<< "Name: " << b.getName() << "\n"
			<< "Grade: " << b.getGrade() << "\n";
		putBreaksLines(2);
}

int main(void) {
	Bureaucrat  Marik("Marik", 45);

	printBureaucrat(Marik);

	try {
		std::cout << "Try down grade by 130: " << Marik.getGrade() + 130 << "\n";
		Marik.decrementGrade(130);
	}
	catch (const std::exception & e) {
		std::cout << "Can't change your grade: " << e.what() << "\n";
	}

	printBureaucrat(Marik);

	try {
		std::cout << "Try down grade by 105: " << Marik.getGrade() + 105 << "\n";
		Marik.decrementGrade(105);
	}
	catch (const std::exception & e) {
		std::cout << "Can't change your grade: " << e.what() << "\n";
	}
	
	printBureaucrat(Marik);

	try {
		std::cout << "Try descrease grade by 25:" << "\n";
		Marik.incrementGrade(25);
	}
	catch (const std::exception & e) {
		std::cout << "Can't change your grade: " << e.what() << "\n";
	}
	
	printBureaucrat(Marik);

	try {
		std::cout << "Try descrease grade by 125:" << "\n";
		Marik.incrementGrade(125);
	}
	catch (const std::exception & e) {
		std::cout << "Can't change your grade: " << e.what() << "\n";
	}

	printBureaucrat(Marik);

	return (0);
}