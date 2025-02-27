
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T, typename T2>
class Associations {
private:
    T key;
    T2 value;
public:
    Associations(T key, T2 value) {
        this->key = key;
        this->value = value;
    }

    T getKey() {
        return key;
    }

    T2 getValue() {
        return value;
    }
};


class SomeClass {
private:
    int number;

    // UMGPT 
   /* how can you cout << this class

        class SomeClass {
        private:
            int number;
    };*/



    friend ostream& operator<<(ostream& os, const SomeClass& obj) {
        os << "SomeClass(number: " << obj.number << ")";
        return os;
    }
public:
    SomeClass(int number = 0) {
        this->number = number;
    }

    bool operator>(const SomeClass& other) {
        return number > other.number;
    }
};

template<typename T>
void printThreeTimes(T value) {
    for (int number = 0; number < 3; number++) {
        cout << value << endl;
    }
    
}

template<typename T>
T largest(T first, T second, T third) {
    if (first > second && first > third ) {
        return first;
    }
    if (second > first && second > third) {
        return second;
    }
    return third;
}

int main()
{
    Associations<string, int> dictionary("C++", 23);
    cout << dictionary.getKey() << endl;
    cout << dictionary.getValue() << endl;

    vector<int> numbers;
    printThreeTimes(10);
    printThreeTimes("test");
    SomeClass someClass;
    SomeClass biggerClass(10);
    SomeClass smallerClass(-5);

    printThreeTimes(someClass);

    std::cout << "Hello World!\n";

    cout << largest(2, 5, 7) << endl;

    cout << largest(someClass, biggerClass, smallerClass) << endl;
}

