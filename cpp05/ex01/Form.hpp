#ifndef __FORM_HPP__
#define __FORM_HPP__

#include "Bureaucrat.hpp"

class	Bureaucrat;

class Form {
	public:
		Form();
        ~Form();
		Form(std::string name, int signGrade, int executeGrade);

        Form(const Form &other);
        Form& operator=(const Form &other);

		void beSigned(Bureaucrat &bureaucrat);

		const std::string getName() const;
		bool getIsSigned() const;
		int getSignGradeRequired() const;
		int getExecuteGradeRequired() const;
	private:
		const std::string name;
		bool isSigned;
		const int signGradeRequired;
		const int executeGradeRequired;

		struct GradeTooHighException : public std::exception {
				const char* what() const throw();
		};

		struct GradeTooLowException : public std::exception {
				const char* what() const throw();
		};
};

std::ostream& operator<<( std::ostream& os, const Form& src );

#endif