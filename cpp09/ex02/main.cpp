#include "PmergeMe.hpp"

bool isInteger(const std::string& str) {
    std::istringstream iss(str);
    int num;
    return (iss >> num) && iss.eof();
}

int main(int argc, char **argv) {
    if(argc < 2) {
		std::cerr << "This program expects positive integers as arguments" << std::endl;
		return (1);
	}
    std::deque<unsigned int> input;
    for(int i = 1; i < argc; i++) {
        int num = 0;
        if(isInteger(argv[i])) {
            num = std::atoi(argv[i]);
            if(num < 0)
                throw std::runtime_error("Negative Number was found");
            if(std::find(input.begin(), input.end(), num) != input.end())
                throw std::runtime_error("Duplicates not allowed");
            input.push_back(static_cast<unsigned int>(num));
        }
        else
            throw std::runtime_error("Non-numeric value was found.");
    }

    //pmergeme(input).sort(input);

    
    std::deque<unsigned int>::const_iterator iter;
    for(int i = 0; i < argc - 1; i++)
        std::cout << input[i] << " ";
    std::cout  << "\n";

    return(0);
}