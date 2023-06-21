#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <list>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <stdlib.h>

typedef struct v_intDate{
	int year;
	int month;
	int day;
}		intDate;

class BitcoinExchange {
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(std::string inputFilePath);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		void	loadData();
		double	getValueByNearestDate(std::string date);
		void	calculateBitcoinExchange(std::string date, std::string strValue);
	private:
		std::map<std::string, std::string> database;
		bool		isDatabaseLoaded;
		const char	*databasePath;
		const char	*inputFilePath;
};

#endif