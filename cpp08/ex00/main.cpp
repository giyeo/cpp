#include "easyfind.hpp"

int main() {
    // Test with std::list
    std::list<int> myList;
    std::vector<int> myVector;
    std::deque<int> myDeque;

	//position will be = value - 1, starts with 1 so... 49 numbers.
	for(int i = 1; i < 50; i++) {
		myList.push_back(i);
		myVector.push_back(i);
		myDeque.push_back(i);
	}

	//Elements exists

	try {
		{//test list
			std::list<int>::iterator it = easyFind(myList, 30);
			std::cout << "Element found in std::list at position: " << std::distance(myList.begin(), it) << std::endl;
		}
		{//test vector
			std::vector<int>::iterator it = easyFind(myVector, 41);
			std::cout << "Element found in std::vector at position: " << std::distance(myVector.begin(), it) << std::endl;
		}
		{//test deque
			std::deque<int>::iterator it = easyFind(myDeque, 1);
			std::cout << "Element found in std::deque at position: " << std::distance(myDeque.begin(), it) << std::endl;
		}
	} catch (const std::runtime_error& error) {
		std::cout << "Element not found in std::list: " << error.what() << std::endl;
	}

	//Elements does not exists
	try {
		std::list<int>::iterator it = easyFind(myList, 303);
		std::cout << "Element found in std::list at position: " << std::distance(myList.begin(), it) << std::endl;
    } catch (const std::runtime_error& error) {
        std::cout << "Element not found in std::list: " << error.what() << std::endl;
    }

	try {
		std::vector<int>::iterator it = easyFind(myVector, 411);
		std::cout << "Element found in std::vector at position: " << std::distance(myVector.begin(), it) << std::endl;
    } catch (const std::runtime_error& error) {
		std::cout << "Element not found in std::vector: " << error.what() << std::endl;
    }

	try {
		std::deque<int>::iterator it = easyFind(myDeque, -3);
		std::cout << "Element found in std::deque at position: " << std::distance(myDeque.begin(), it) << std::endl;
    } catch (const std::runtime_error& error) {
		std::cout << "Element not found in std::deque: " << error.what() << std::endl;
    }
	
    return 0;
};