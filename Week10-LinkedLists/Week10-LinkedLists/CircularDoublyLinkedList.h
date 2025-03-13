#pragma once

#include <stdexcept>

using namespace std;

template<typename T>
class CircularDoublyLinkedList {

private:


    template <typename T>
    class Node {
    public:
        T data;
        Node<T>* next;
        Node<T>* previous;

        Node(T data, Node<T>* next = nullptr, Node<T>* previous = nullptr) {
            this->data = data;
            this->next = next;
            this->previous = previous;
        }
    };


    Node<T>* dummy;

    int numberOfItems;

    void addBetween(T data, Node<T>* next, Node<T>* previous) {
        Node<T>* newNode = new Node<T>(data, next, previous);
        newNode->next->previous = newNode;
        newNode->previous->next = newNode;
        numberOfItems++;
    }

    void checkEmpty()
    {
        if (numberOfItems == 0) {
            throw invalid_argument("empty");
        }
    }

    T removeNode(Node<T>* node) {
        numberOfItems--;

        T data = node->data;

        node->previous->next = node->next;
        node->next->previous = node->previous;

        delete node;

        return data;
    }

public:
    CircularDoublyLinkedList() {
        dummy = new Node<T>(nullptr)
        numberOfItems = 0;
    }

    // O(1) - average and worst case!
    void addFront(T data) {
        addBetween(data, dummy->next, dummy);
    }

    void addLast(T data) {
        addBetween(data, dummy, dummy->previous);
    }

    // O(1)
    T front() {
        checkEmpty();
        return dummy->next->data;
    }

    // O(1)
    T back() {
        checkEmpty();
        return dummy->previous->data;
    }

    // O(1)
    T removeFront() {
        checkEmpty();

        return removeNode(dummy->next)
    }

    // O(1)
    T removeBack() {
        checkEmpty();

        return removeNode(dummy->previous)
    }

    // O(1)
    bool isEmpty() {
        return numberOfItems == 0;
    }

    int size() {
        return numberOfItems;
    }

    // O(n) average
    T get(int index) {
        if (index < 0 || index >= numberOfItems) {
            throw invalid_argument("invalid index");
        }

        int currentIndex = 0;
        Node<T> currentNode = dummy->next;

        while (currentIndex != index) {
            currentNode = currentNode->next;
            currentIndex++;
        }

        return currentNode->data;
    }

};

