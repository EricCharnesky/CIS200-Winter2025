
#include <iostream>
#include <vector>
#include <random>

using namespace std;

// O(n^2) always!
template <typename T>
void selectionSort(vector<T>& list) {
	for (int index = 0; index < list.size() - 1; index++) {
		int smallestIndex = index;
		for (int indexToCheck = index + 1; indexToCheck < list.size(); indexToCheck++) {
			if (list.at(indexToCheck) < list.at(smallestIndex)) {
				smallestIndex = indexToCheck;
			}
		}
		T temp = list.at(index);
		list.at(index) = list.at(smallestIndex);
		list.at(smallestIndex) = temp;
	}
}

// worst case O(n^2) - reverse sorted list
// average case O(n^2)
// best case O(n) - already sorted list
template <typename T>
void insertionSort(vector<T>& list) {
	for (int index = 1; index < list.size(); index++) {
		for (int indexToCheck = index; indexToCheck > 0; indexToCheck--) {
			if (list.at(indexToCheck) < list.at(indexToCheck - 1)) {
				T temp = list.at(indexToCheck);
				list.at(indexToCheck) = list.at(indexToCheck-1);
				list.at(indexToCheck-1) = temp;
			}
			else {
				break;
			}
		}

		
	}
}

int main()
{
	vector<int> numbers = { 7, 21, 3, 55, 32 };
	insertionSort(numbers);

	for (int number : numbers) {
		cout << number << endl;
	}

	vector<int> randomNumbers(100);

	for (int index = 0; index < 100; index++) {
		randomNumbers.at(index) = rand();
	}

	insertionSort(randomNumbers);

	for (int number : randomNumbers) {
		cout << number << endl;
	}

	
}
