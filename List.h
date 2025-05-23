#pragma once
#ifndef LIST_H
#define LIST_H


using namespace std;

template <typename genaric_data_type>
class List {
private:
    genaric_data_type* items;
    int capacity;
    int count;

public:
    List(int initialCapacity = 10) : capacity(initialCapacity), count(0) {
        items = new genaric_data_type[capacity];
    }

    ~List() {
        delete[] items;
    }

    void add(const genaric_data_type& item) {
        if (count >= capacity) {
            capacity *= 2;
            genaric_data_type* newItems = new genaric_data_type[capacity];
            for (int i = 0; i < count; i++) {
                newItems[i] = items[i];
            }
            delete[] items;
            items = newItems;
        }
        items[count++] = item;
    }

    genaric_data_type& get(int index) {
        if (index < 0 || index >= count) {
            throw out_of_range("Index out of bounds");
        }
        return items[index];
    }

    const genaric_data_type& get(int ref_index) const {
        if (ref_index < 0 || ref_index >= count) {
            throw out_of_range("Index out of bounds");
        }
        return items[ref_index];
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

    genaric_data_type& operator[](int index) {
        return get(index);
    }

    const genaric_data_type& operator[](int index) const {
        return get(index);
    }
};

#endif 