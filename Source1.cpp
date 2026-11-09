#include <iostream>
#include <stdexcept>
#include <windows.h>

class smart_array {

private:

    int* data_;
    unsigned int capacity_;
    unsigned int size_;

public:

    smart_array(unsigned int capacity)
        : data_(new int[capacity]), capacity_(capacity), size_(0) {
    }


    smart_array(const smart_array& other)
        : data_(new int[other.capacity_]),
        capacity_(other.capacity_),
        size_(other.size_) {
        for (unsigned int i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }


    smart_array& operator=(const smart_array& other) {
        if (this != &other) {
            int* new_data = new int[other.capacity_];
            for (unsigned int i = 0; i < other.size_; ++i) {
                new_data[i] = other.data_[i];
            }
            delete[] data_;
            data_ = new_data;
            capacity_ = other.capacity_;
            size_ = other.size_;
        }
        return *this;
    }

    ~smart_array() {
        delete[] data_;
    }

    void add_element(int value) {
        if (size_ >= capacity_) {
            throw std::out_of_range("Массив переполнен");
        }
        data_[size_++] = value;
    }

    int get_element(unsigned int index) const {
        if (index >= size_) {
            throw std::out_of_range("Некорректный индекс");
        }
        return data_[index];
    }

    unsigned int size() const {
        return size_;
    }
};

int main() {

    SetConsoleOutputCP(65001);

    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);

        smart_array new_array(2);
        new_array.add_element(44);
        new_array.add_element(34);

        arr = new_array;

        std::cout << arr.get_element(0) << std::endl;
        std::cout << arr.get_element(1) << std::endl;

        new_array.add_element(7);
        std::cout << arr.size() << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    };

    return 0;
};
