
#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main()
{
	Stack<int> stack;

	stack.push(10);
	stack.push(20);
	stack.push(30);

	while (!stack.isEmpty()) {
		cout << stack.pop() << endl;
	}

	LinkedQueue<int> queue;

	for (int number = 0; number < 10; number++) {
		queue.enqueue(number);
	}

	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;
	cout << queue.dequeue() << endl;

	for (int number = 10; number < 20; number++) {
		queue.enqueue(number);
	}

	while (!queue.isEmpty()) {
		cout << queue.dequeue() << endl;
	}
}
