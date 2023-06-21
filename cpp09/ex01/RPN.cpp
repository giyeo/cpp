#include "RPN.hpp"

bool isOperator(char c) {
	if (c == '+' or c == '-' or c == '/' or c== '*')
		return 1;
	return 0;
}

void RPN::invalidInput() {
	std::string valid = "+-/*0123456789";
	bool wasSpace = true;
	for (unsigned int i = 0; i < input.length(); ++i) {
		char c = input[i];
		if(c != ' ') {
			if(wasSpace == false)
				throw std::runtime_error("Error: Invalid Character input");
			wasSpace = false;
			if(std::find(valid.begin(), valid.end(), c) == valid.end())
				throw std::runtime_error("Error: Invalid Character input");
		}
		else
			wasSpace = true;
	}
	std::string result = input;
    result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());
    input = result;
}

void RPN::invalidRPN() {

}

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN &RPN::operator=(const RPN &other) {
	if(this != &other) {}
	return *this;
}

int	doOperation(char c, int a, int b) {
	if(c == '+')
		return (a + b);
	if(c == '/') {
		if(b == 0)
			throw std::runtime_error("Error: Division by Zero");
		return (a / b);
	}
	if(c == '-')
		return (a - b);
	return (a * b);
}

void RPN::calcRPN(void) {
	for(unsigned int i = 0; i < input.length(); i++) {
		char c = input[i];
		if(isOperator(c) == false)
			stack.push(c - '0');
		else {
			if(stack.size() < 2)
				throw std::runtime_error("Error: Invalid Syntax");
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			stack.push(doOperation(c, a, b));
		}
	}
	if(stack.size() != 1)
		throw std::runtime_error("Error: Invalid Syntax");
	std::cout << stack.top() << std::endl;
}

RPN::RPN(const char *input) : input(input) {
	invalidInput();
	invalidRPN();
	calcRPN();
}
