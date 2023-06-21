#include "BitcoinExchange.hpp"

std::string trim(const std::string& str) {
    std::string::const_iterator start = str.begin();
    while (start != str.end() && std::isspace(*start)) {
        ++start;
    }
    std::string::const_iterator end = str.end();
    while (end != start && std::isspace(*(end - 1))) {
        --end;
    }
    return std::string(start, end);
}

bool isFloat(const std::string& str) {
    std::istringstream iss(str);
    float f;
    iss >> std::noskipws >> f;
    return iss.eof() && !iss.fail();
}

bool invalidDate(intDate &date) {
	//allowed db.date after 2009-01-02
	if(date.year < 2009 
	|| date.month > 12
	|| date.day > 31)
		return true;
	return false;
}

void stringToIntDate(std::string date, intDate &intDate) {
	intDate.year = atoi(date.substr(0,4).c_str());
	intDate.month = atoi(date.substr(5,2).c_str());
	intDate.day = atoi(date.substr(8,2).c_str());
}

bool isDateAfter(intDate dbDate, intDate date) {
	if((dbDate.year >= date.year)
	&& (dbDate.month >= date.month)
	&& (dbDate.day > date.day))
		return (1);
	return(0);
}

BitcoinExchange::BitcoinExchange() :
	isDatabaseLoaded(false),
	databasePath("data.csv"),
	inputFilePath("input.txt") {
		loadData();
	};

BitcoinExchange::BitcoinExchange(std::string inputFilePath) :
	isDatabaseLoaded(false),
	databasePath("data.csv"),
	inputFilePath(inputFilePath.c_str()) {
		loadData();
	};

BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if(this != &other) {}
	return *this;
}

void BitcoinExchange::loadData() {
	const char *pathToFile = databasePath;
	char delimiter = ',';
	if (isDatabaseLoaded) {
		pathToFile = inputFilePath;
		delimiter = '|';
	}
	std::ifstream file(pathToFile);
	if (file) {
		std::string line;
		std::getline(file, line);
		std::stringstream ss(line);
		std::string date, value;
		if (std::getline(ss, date, delimiter)
		 && std::getline(ss, value, delimiter)) {
			if ((trim(date).compare("date") == 1)
			&& ((trim(value).compare("exchange_rate") == 1)
			|| (trim(value).compare("value") == 1)))
				throw std::runtime_error("Error: invalid header.");
		}
		else
			std::cout << "Error: bad input => " << line << std::endl;
		while (std::getline(file, line)) {
			std::stringstream ss(line);
			std::string field1, field2;
			if (std::getline(ss, field1, delimiter)
			 && std::getline(ss, field2, delimiter)) {
				if(isDatabaseLoaded == false)
					database[field1] = field2;
				else
					calculateBitcoinExchange(field1, field2);
			}
			else
				std::cout << "Error: bad input => " << line << std::endl;
		}
		file.close();
	} else {
		std::cout << "Failed to open the file: " << pathToFile << std::endl;
	}
	if(isDatabaseLoaded == false) {
		isDatabaseLoaded = true;
		loadData();
	}
}

void BitcoinExchange::calculateBitcoinExchange(std::string date, std::string strValue) {
	float value = atof(strValue.c_str());
	intDate dateInt;
	stringToIntDate(date, dateInt);

	if(isFloat(trim(strValue)) == 0)
		std::cout << "Error: invalid number: " << strValue << "\n";
	if(invalidDate(dateInt))
		std::cout << "Error: date: " << date << " not allowed, must be after 2009-01-01 with YYYY-MM-DD format\n";
	std::map<std::string, std::string>::const_iterator iter;
	if(value < 0)
		std::cout << "Error: not a positive number." << std::endl;
	else if(value > 1000)
		std::cout << "Error: too large a number." << std::endl;
	else
		std::cout << date << "=> " << value << " = " << getValueByNearestDate(date) * value << std::endl;
}

double BitcoinExchange::getValueByNearestDate(std::string date) {
	intDate dateInt;
	intDate dbDate;

	stringToIntDate(date, dateInt);
	std::map<std::string, std::string>::const_iterator iter;

	double previousValue = 0.0;
	for (iter = this->database.begin(); iter != this->database.end(); ++iter) {
		const std::string& key = iter->first;
		double value = atof(iter->second.c_str());
		stringToIntDate(key, dbDate);
		if(date == key)
			return value;
		if(isDateAfter(dbDate, dateInt))
			return previousValue;
		previousValue = value;
	}
	return (previousValue);
}
