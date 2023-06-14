NAME := bureaucrats
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address -Wfatal-errors

SRCS := ./main.cpp ./Bureaucrat.cpp ./AForm.cpp ./PresidentialPardonForm.cpp ./RobotomyRequestForm.cpp ./ShrubberyCreationForm.cpp ./Intern.cpp
OBJDIR := ./objs/
OBJS := $(addprefix $(OBJDIR), $(notdir $(SRCS:.cpp=.o)))

$(OBJDIR)%.o: ./%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) -r $(NAME)

re: fclean all

.PHONY: all clean fclean re