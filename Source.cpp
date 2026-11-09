#include <iostream>
#include <Windows.h>
#include <exception>


class smart_array {
private:
    int* data_;
    unsigned int capacity_;
    unsigned int size_;

public:

    smart_array(unsigned int capacity)
        : data_(new int[capacity]), capacity_(capacity), size_(0) {
    };


    smart_array(const smart_array&) = delete;
    smart_array& operator=(const smart_array&) = delete;


    ~smart_array() {
        delete[] data_;
    };


    void add_element(int value) {
        if (size_ >= capacity_) {
            throw std::out_of_range("Массив переполнен");
        };
        data_[size_++] = value;
    };
   

    int get_element(unsigned int index) const {
        if (index >= size_) {
            throw std::out_of_range("Некорректный индекс");
        };
        return data_[index];
    };

    unsigned int size() const {
        return size_;
    };
};


int main() {
    SetConsoleOutputCP(65001);

	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	};

    return 0;
};