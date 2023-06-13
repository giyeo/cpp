#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <string>
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
		size_t getGrade() const;
		std::string getName() const;
	private:
		const std::string name;
		size_t grade;

		struct GradeTooHighException : public std::exception {
				const char* what() const throw();
		};

		struct GradeTooLowException : public std::exception {
				const char* what() const throw();
		};
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& src );

#endif