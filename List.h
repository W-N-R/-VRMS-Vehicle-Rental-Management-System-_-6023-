#pragma once
#ifndef LIST_H
#define LIST_H


using namespace std;

template <typename T>
class List {
private:
    T* items;
    int capacity;
    int count;

public:
    List(int initialCapacity = 10) : capacity(initialCapacity), count(0) {
        items = new T[capacity];
    }

    ~List() {
        delete[] items;
    }

    void add(const T& item) {
        if (count >= capacity) {
            // Resize the array
            capacity *= 2;
            T* newItems = new T[capacity];
            for (int i = 0; i < count; i++) {
                newItems[i] = items[i];
            }
            delete[] items;
            items = newItems;
        }
        items[count++] = item;
    }

    T& get(int index) {
        if (index < 0 || index >= count) {
            throw out_of_range("Index out of bounds");
        }
        return items[index];
    }

    const T& get(int index) const {
        if (index < 0 || index >= count) {
            throw out_of_range("Index out of bounds");
        }
        return items[index];
    }

    int size() const {
        return count;
    }

    void remove(int index) {
        if (index < 0 || index >= count) {
            throw out_of_range("Index out of bounds");
        }
        for (int i = index; i < count - 1; i++) {
            items[i] = items[i + 1];
        }
        count--;
    }

    // Operator overloading for array-like access
    T& operator[](int index) {
        return get(index);
    }

    const T& operator[](int index) const {
        return get(index);
    }
};

#endif // LIST_H