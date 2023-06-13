#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <string>
#include <exception>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
    public:
        Bureaucrat();
        ~Bureaucrat();
		Bureaucrat(std::string name, int grade);

        Bureaucrat(const Bureaucrat &other);
        Bureaucrat& operator=(const Bureaucrat &other);

		void signForm( Form &toSignForm);
		void incrementGrade(int delta);
		void decrementGrade(int delta);
		int getGrade() const;
		std::string getName() const;
	private:
		const std::string name;
		int grade;

		struct GradeTooHighException : public std::exception {
				const char* what() const throw();
		};

		struct GradeTooLowException : public std::exception {
				const char* what() const throw();
		};
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& src );

#endif