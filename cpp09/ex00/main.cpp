#include "BitcoinExchange.hpp"

// bool invalidDate(intDate date) {

// }

// bool invalidNumber()

int main(int argc, char **argv) {
	if(argc != 2) {
		std::cerr << "The program expects only one argument\n";
		return (1);
	}

	try {
		BitcoinExchange btc(argv[1]);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	return (0);
}
