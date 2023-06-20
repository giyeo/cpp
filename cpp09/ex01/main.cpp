#include "RPN.hpp"


// void stringToIntDate(std::string date, intDate &intDate) {
// 	intDate.year = atoi(date.substr(0,4).c_str());
// 	intDate.month = atoi(date.substr(5,2).c_str());
// 	intDate.day = atoi(date.substr(8,2).c_str());
// }

int main(int argc, char **argv) {
	if(argc != 2) {
		std::cerr << "The program expects only one argument" << std::endl;
		return (1);
	}
	try {
		RPN rpn(argv[1]);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}