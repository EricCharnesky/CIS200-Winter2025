#pragma once

#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class SlowQueue {

private:
	vector<T> items;

public:
	SlowQueue() {
		items = vector<T>();
	}

	// average O(1)
	void enqueue(T item) {
		items.push_back(item);
	}

	// O(n)
	T dequeue() {
		T item = items.at(0);
		
		auto front = items.begin();

		items.erase(front);

		return item;
	}

	T front() {
		return items.at(0);
	}

	bool isEmpty() {
		return items.size() == 0;
	}
};


template <typename T>
class FasterQueue {

private:
	vector<T> items;
	int frontIndex;

public:
	FasterQueue() {
		items = vector<T>();
		frontIndex = 0;
	}

	// average O(1)
	void enqueue(T item) {
		items.push_back(item);
	}

	// O(1)
	T dequeue() {
		if (isEmpty()) {
			throw new invalid_argument("empty");
		}
		T item = items.at(frontIndex);
		frontIndex++;

		return item;
	}

	T front() {
		return items.at(frontIndex);
	}

	bool isEmpty() {
		return frontIndex >= items.size();
	}
};



template <typename T>
class CircularQueue {

private:
	vector<T> items;
	int frontIndex;
	int backIndex;
	int numberOfItems;

	void resize() {
		vector<T> newItems = vector<T>();
		newItems.resize(items.size() * 2);
		int newItemIndex = 0;
		for (int index = frontIndex; index < items.size(); index++) {
			newItems.at(newItemIndex) = items.at(index);
			newItemIndex++;
		}
		if (backIndex <= frontIndex) {
			for (int index = 0; index < backIndex; index++) {
				newItems.at(newItemIndex) = items.at(index);
				newItemIndex++;
			}
		}
		items = newItems;
		frontIndex = 0;
		backIndex = numberOfItems;
	}

public:
	CircularQueue() {
		items = vector<T>();
		items.resize(10);

		frontIndex = 0;
		backIndex = 0;
		numberOfItems = 0;
	}

	// average O(1)
	void enqueue(T item) {
		if (numberOfItems == items.size()) {
			resize();
		}
		items.at(backIndex) = item;
		backIndex = (backIndex + 1) % items.size();
		numberOfItems++;
	}

	// O(1)
	T dequeue() {
		if (isEmpty()) {
			throw new invalid_argument("empty");
		}
		T item = items.at(frontIndex);
		frontIndex = (frontIndex + 1) % items.size();

		numberOfItems--;

		return item;
	}

	T front() {
		return items.at(frontIndex);
	}

	bool isEmpty() {
		return numberOfItems == 0;
	}
};


template <typename T>
class LinkedQueue {

	template <typename T>
	class Node {
	public:
		Node<T>* next;
		Node<T>* previous;
		T data;

		Node(T data, Node<T>* next = nullptr, Node<T>* previous = nullptr) {
			this->next = next;
			this->previous = previous;
			this->data = data;
		}
	};

private:
	
	Node<T>* frontNode;
	Node<T>* backNode;
	int numberOfItems;

public:
	LinkedQueue() {
		frontNode = nullptr;
		backNode = nullptr;
		numberOfItems = 0;
	}

	// always O(1)
	void enqueue(T item) {
		if (backNode == nullptr) {
			backNode = new Node<T>(item);
			frontNode = backNode;
		}
		Node<T>* newBack = new Node<T>(data, nullptr, backNode);
		backNode = newBack;

		numberOfItems++;
	}

	// always O(1)
	T dequeue() {
		T item = frontNode->data;

		frontNode = frontNode->next;

		numberOfItems--;

		return item;
	}

	T front() {
		return frontNode.data;
	}

	bool isEmpty() {
		return numberOfItems == 0;
	}
};