#include "BitcoinExchange.hpp"

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

//copy constructor
//operator equal

void BitcoinExchange::calculateBitcoinExchange(std::string date, std::string strValue) {
	float value = atof(strValue.c_str());
	// if(invalidDate(date) || invalidNumber(value))
	if(value < 0)
		std::cout << "Error: not a positive number." << std::endl;
	else if(value > 1000)
		std::cout << "Error: too large a number." << std::endl;
	else
		std::cout << date << "=> " << value << " = " << getValueByNearestDate(date) * value << std::endl;
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

bool invalidDate(intDate &date) {
	//allowed db.date after 2009-01-02
	if(date.year < 2009)
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

double BitcoinExchange::getValueByNearestDate(std::string date) {
	intDate dateInt;
	intDate dbDate;

	stringToIntDate(date, dateInt);
	if(invalidDate(dateInt))
		throw std::runtime_error("Date not allowed, valid date is after 2009-01-01");
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