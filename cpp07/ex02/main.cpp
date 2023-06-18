#include <iostream>
#include "Array.hpp"
#include <iostream>

#define MAX_VAL 750
int main(int, char**)
{
	{
		const Array<int> ints(3);
		Array<char> chars(20);
		Array<float> floats(18);
		Array<double> doubles(3);
		Array<int> empty;

		std::cout << "size should be 3: " << ints.size() << std::endl;
		std::cout << "size should be 20: "<< chars.size() << std::endl;
		std::cout << "size should be 18: "<< floats.size() << std::endl;
		std::cout << "size should be 3: "<< doubles.size() << std::endl;
		std::cout << "size should be 0: "<< empty.size() << std::endl;

		for (uint32_t i = 0; i < ints.size(); i++) {
			setRandNumberFloat(ints[i]);
			printIt(ints[i]);
		}

		for (uint32_t i = 0; i < doubles.size(); i++) {
			setRandNumberFloat(doubles[i]);
			printIt(doubles[i]);
		}

	}
	//Main.cpp of the subject
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
	}
    return 0;
}