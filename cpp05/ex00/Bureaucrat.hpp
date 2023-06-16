#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <exception>
#include <iostream>

class Bureaucrat {
    public:
        Bureaucrat();
        ~Bureaucrat();
		Bureaucrat(std::string name, int grade);

        Bureaucrat(const Bureaucrat &other);
        Bureaucrat& operator=(const Bureaucrat &other);

		void incrementGrade(int delta);
		void decrementGrade(int delta);

		int getGrade() const;
		std::string getName() const;
	private:
		const std::string name;
		int grade;

		class GradeTooHighException : public std::exception {
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
				const char* what() const throw();
		};
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& src );

#endif