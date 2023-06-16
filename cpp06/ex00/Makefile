NAME := convert
CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address -Wfatal-errors

SRCS := ./main.cpp ./ScalarConverter.cpp

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

# New target to compile "test"
TEST_SRCS := ./test.cpp ./ScalarConverter.cpp
TEST_OBJDIR := ./test_objs/
TEST_OBJS := $(addprefix $(TEST_OBJDIR), $(notdir $(TEST_SRCS:.cpp=.o)))

test: $(TEST_OBJS)
	$(CC) $(CFLAGS) $(TEST_OBJS) -o test

$(TEST_OBJDIR)%.o: ./%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_OBJS): | $(TEST_OBJDIR)

$(TEST_OBJDIR):
	mkdir $(TEST_OBJDIR)

test_clean:
	$(RM) -r $(TEST_OBJDIR)

test_fclean: test_clean
	$(RM) -r test

test_re: test_fclean test

.PHONY: test test_clean test_fclean test_re