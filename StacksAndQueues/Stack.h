#pragma once

#include <vector>

using namespace std;
template <typename T>
class Stack {

private:
	vector<T> items;

public:
	Stack() {
		items = vector<T>();
	}

	// Average O(1)
	// worst O(n) occasionally you have to double your storage
	void push(T item) {
		items.push_back(item);
	}

	// Average O(1)
	T pop() {
		T item = items.at(items.size() - 1);
		items.pop_back();
		return item;
	}

	// always O(1)
	T peek() {
		return items.at(items.size() - 1);
	}

	bool isEmpty() {
		return items.size() == 0;
	}
};