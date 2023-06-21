#include <vector>
#include <iostream>
#include <deque>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <algorithm>

typedef unsigned int uint;
typedef std::vector<uint> uint_vector;
typedef std::vector<uint_vector> uint_vector_vector;
typedef std::list<uint> uint_list;
typedef std::list<uint_list> uint_list_list;

template<typename Iterator>
void printContainer(Iterator begin, Iterator end) {
    for (Iterator it = begin; it != end; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}
template<typename Container>
void print(Container &container) {
	printContainer(container.begin(), container.end());
}
template<typename Containers>
void printAll(Containers &containers) {
	std::cout << "__PAIRS__" << "\n";
	for(uint i = 0; i < containers.size(); i++) {
		print(containers[i]);
	}
	std::cout << "_________" << "\n";
}

int	jacobsthalNumber(int n) {
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	return jacobsthalNumber(n - 1) + 2 * jacobsthalNumber(n - 2);
}

uint_vector buildJacobInsertionSequence(uint len) {
	uint_vector endSequence;
	uint jacobIndex = 2;

	while (static_cast<uint>(jacobsthalNumber(jacobIndex)) < len - 1) {
		endSequence.push_back(jacobsthalNumber(jacobIndex));
		jacobIndex++;
	}
	return endSequence;
}

void binarySearchInsert(uint_vector& S, uint n) {
    int left = 0;
    int right = S.size() - 1;
	
    while (left <= right) {
        uint mid = (left + right) / 2;

		// std::cout << "RUN:" << counter << " > "
		// << mid << " :" << left << " , "<< right
		// << "{}" << S[mid] << " " << n <<"\n";
		
		if(mid == 0)
		
        if (S[mid] == n) {
            // If the number already exists in the list, insert it at the rightmost position
            S.insert(S.begin() + mid + 1, n);
			return ;
        }

        if (n < S[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    S.insert(S.begin() + left, n);
    return ;
}
int main() {
	uint arr_values[] = {37, 2, 12, 44, 34, 45, 7, 27, 31, 50, 21, 5, 23, 41, 43, 18, 32, 46, 8, 48, 40, 4, 35, 6, 28, 42, 29, 25, 26, 38, 19, 10, 17, 11, 39, 16, 36, 15, 14, 49, 20, 1, 30, 22, 33, 24, 9, 3, 13, 47};
    std::deque<uint> arr(arr_values, arr_values + sizeof(arr_values) / sizeof(uint));
	
	std::vector<uint> vec;
	vec.reserve(arr.size());
	std::copy(arr.begin(), arr.end(), std::back_inserter(vec));

	std::list<uint> llist;
	std::copy(arr.begin(), arr.end(), std::back_inserter(llist));

	// print(arr);
	// print(vec);
	// print(llist);
	

	//---------------- start algo

	//#1
	uint n = vec.size();

	uint_vector_vector L;
	uint_vector temp;
	int straggler = -1;
	if( n % 2 == 1 ) {
		straggler = vec.back();
		vec.pop_back();
	}

	for(uint i = 0; i < vec.size(); i++) {
		temp.push_back(vec[i]);
		if(i % 2 == 1) {
			L.push_back(temp);
			temp.clear();
		}
	}

	// printAll(L);
	//std::cout << straggler << "\n";
	//#2
	//#3
	//#4
	uint_vector S;
	for(uint i = 0; i < L.size(); i++) {
		uint &a = L[i][0];
		uint &b = L[i][1];
		if(a > b) {
			uint temp = b;
			b = a;
			a = temp;
		}
		S.push_back(L[i][1]);
	}
	std::sort(S.begin(), S.end());

	{
		// uint_vector seq = buildJacobInsertionSequence(L.size());
		// uint_vector indexSeq;

		// int wasJacob = 0;
		// uint item = 0;
		// print(seq);
		for(uint i = 0; i < L.size(); i++) {
			
			// // std::cout << i << "\n";
			// // print(indexSeq);
			// if(seq.size() != 0 and wasJacob == 0) {
			// 	indexSeq.push_back(seq[0]);
			// 	item = L[seq[0] - 1][0];
			// 	seq.erase(seq.begin());
			// 	wasJacob = 1;
			// }

			// else {
			// 	if(std::find(indexSeq.begin(), indexSeq.end(), i ) != indexSeq.end()) {
			// 		i++;
			// 	}
			// 	item = L[i - 1][0];
			// 	indexSeq.push_back(i);
			// 	wasJacob = 0;
			// }
			binarySearchInsert(S,L[i][0]);
		}
		
		if(straggler != -1)
			binarySearchInsert(S,straggler);
	}

	print(S);
}