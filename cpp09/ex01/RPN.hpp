#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <algorithm>
#include <stack>

class RPN {
	public:
		RPN();
		RPN(const char *input);
		~RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
	private:
		void invalidInput(void);
		void invalidRPN(void);
		void calcRPN(void);
		std::stack<int> stack;
		std::string input;
};

#endif