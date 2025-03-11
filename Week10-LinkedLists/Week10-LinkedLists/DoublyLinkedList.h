#pragma once

#include <stdexcept>

using namespace std;

template<typename T>
class DoublyLinkedList {

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


    Node<T>* first;
    Node<T>* last;
    int numberOfItems;

public:
    DoublyLinkedList() {
        first = nullptr;
        last = nullptr;
        numberOfItems = 0;
    }

    // O(1) - average and worst case!
    void addFront(T data) {
        Node<T>* newNode = new Node<T>(data, first);

        if (first != nullptr) {
            first->previous = newNode;
        }
        else {
            last = newNode;
        }
        
        first = newNode;
        numberOfItems++;
    }

    void addLast(T data) {
        Node<T>* newNode = new Node<T>(data, nullptr, last);

        if (last != nullptr) {
            last->next = newNode;
        }
        else {
            first = newNode;
        }
        
        last = newNode;
        numberOfItems++;
    }

    // O(1)
    T front() {
        if (first == nullptr) {
            throw invalid_argument("empty");
        }
        return first->data;
    }

    // O(1)
    T back() {
        if (last == nullptr) {
            throw invalid_argument("empty");
        }
        return last->data;
    }

    // O(1)
    T removeFront() {
        if (first == nullptr) {
            throw invalid_argument("empty");
        }

        numberOfItems--;

        T data = first->data;

        auto old = first;

        first = first->next;

        if (first != nullptr) {
            first->previous = nullptr;
        }
        else {
            last = nullptr;
        }

        delete old;

        return data;
    }

    // O(1)
    T removeBack() {
        if (last == nullptr) {
            throw invalid_argument("empty");
        }

        numberOfItems--;

        T data = last->data;

        auto old = last;

        last = last->previous;

        if (last != nullptr) {
            last->next = nullptr;
        }
        else {
            first = nullptr;
        }

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

