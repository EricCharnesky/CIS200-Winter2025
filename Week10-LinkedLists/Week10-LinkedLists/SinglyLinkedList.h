#pragma once


#include <stdexcept>

using namespace std;

template<typename T>
class SinglyLinkedList {

private:


    template <typename T>
    class Node {
    public:
        T data;
        Node<T>* next;

        Node(T data, Node<T>* next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };


    Node<T>* first;
    int numberOfItems;

public:
    SinglyLinkedList() {
        first = nullptr;
        numberOfItems = 0;
    }

    // O(1) - average and worst case!
    void push(T data) {
        Node<T>* newNode = new Node<T>(data, first);
        first = newNode;
        numberOfItems++;
    }

    // O(1)
    T peek() {
        if (first == nullptr) {
            throw invalid_argument("empty");
        }
        return first->data;
    }

    // O(1)
    T pop() {
        if (first == nullptr) {
            throw invalid_argument("empty");
        }

        numberOfItems--;

        T data = first->data;

        auto old = first;

        first = first->next;

        delete old;

        return data;
    }

    // O(1)
    bool isEmpty() {
        return first == nullptr;
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
        Node<T> currentNode = first;

        while (currentIndex != index) {
            currentNode = currentNode->next;
            currentIndex++;
        }

        return currentNode->data;
    }

};

