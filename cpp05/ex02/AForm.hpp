#ifndef AFORM_HPP
#define AFORM_HPP

# include <exception>
# include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm();
		virtual ~AForm();
		AForm(std::string name, int signGrade, int executeGrade);

		AForm(const AForm &other);
		AForm& operator=(const AForm &other);

		void beSigned(Bureaucrat &bureaucrat);

		const std::string getName() const;
		bool getIsSigned() const;
		int getSignGradeRequired() const;
		int getExecuteGradeRequired() const;

		virtual void execute(Bureaucrat &bureaucrat) const = 0;
	protected:
		struct GradeTooHighException : public std::exception {
				const char* what() const throw();
		};

		struct GradeTooLowException : public std::exception {
				const char* what() const throw();
		};

		struct FormIsNotSigned : public std::exception {
				const char* what() const throw();
		};
	private:
		const std::string name;
		bool isSigned;
		const int signGradeRequired;
		const int executeGradeRequired;
};

std::ostream& operator<<( std::ostream& os, const AForm& src );

#endif