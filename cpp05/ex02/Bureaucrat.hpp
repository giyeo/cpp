#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
    public:
        Bureaucrat();
        ~Bureaucrat();
		Bureaucrat(std::string name, int grade);

        Bureaucrat(const Bureaucrat &other);
        Bureaucrat& operator=(const Bureaucrat &other);

		void signForm( AForm &toSignForm);
		void incrementGrade(int delta);
		void decrementGrade(int delta);
		int getGrade() const;
		std::string getName() const;

		void executeForm( AForm const & form);
	protected:
		class GradeTooHighException : public std::exception {
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
				const char* what() const throw();
		};
	private:
		const std::string name;
		int grade;
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& src );

#endif