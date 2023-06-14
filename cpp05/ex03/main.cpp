# include "Intern.hpp"

void    testMakeForm(Intern intern, std::string name, std::string target)
{
    AForm *form = intern.makeForm(name, target);

    if (form != NULL) {
        std::cout << "Name: " << form->getName() << std::endl;
        std::cout << "Grade To be Executed: " << form->getExecuteGradeRequired() << std::endl;
        std::cout << "Grade To be Signed: " << form->getSignGradeRequired() << std::endl;
        std::cout << std::endl;
    }
    delete form;
}

int main( void ) {
	Intern	intern;

    testMakeForm(intern, "robotomy request", "Mikasa");
    testMakeForm(intern, "shrubbery creation", "Mijardin");
    testMakeForm(intern, "presidential pardon", "Miwar");
    testMakeForm(intern, "space", "midOfTheUniverse");
	return (0);
}