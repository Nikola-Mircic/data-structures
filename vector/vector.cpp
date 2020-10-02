#pragma once

#include <iostream>
#include <cstdlib>
#include <algorithm>

template <class TYPE>
class Vector {
private:
    int reserved_size;//Maximal number of elements in main_arr
    int curr_size;//Current number of elements in main_arr
    TYPE* main_arr;//Main array
    TYPE* temp_arr;//Array used for creating bigger array

    void double_arr() {
        temp_arr = new TYPE[2 * reserved_size];
        for (int i = 0; i < curr_size; ++i) {
            temp_arr[i] = main_arr[i];
        }
        delete main_arr;
        main_arr = temp_arr;
        temp_arr = NULL;
    }
public:
    //Creates empty vector for only 1 element
    Vector() {
        curr_size = 0;
        reserved_size = 1;
        main_arr = new TYPE[1];
        temp_arr = NULL;
    }

    //Creates empty vector for n elements
    Vector(const int n) {
        curr_size = 0;
        reserved_size = n;
        main_arr = new TYPE[n];
        temp_arr = NULL;
    };

    //Creates vector with elements of an array in range [arr_start, arr_end)
    Vector(const TYPE* arr_start, const TYPE* arr_end) {
        int n = arr_end - arr_start;

        curr_size = 0;
        reserved_size = n;

        main_arr = new TYPE[n];

        for (TYPE* i = (TYPE*)arr_start; i != (TYPE*)arr_end; ++i) {
            main_arr[curr_size++] = *i;
        }
    };

    //Creates vector with elements of the 'vec' vector
    Vector(const Vector<TYPE>& vec) {
        curr_size = vec.curr_size;
        reserved_size = vec.reserved_size;
        main_arr = new TYPE[reserved_size];

        for (int i = 0; i < curr_size; ++i)
            main_arr[i] = vec.main_arr[i];
    }

    //Add new elmenet 'element' to the vector
    void add_element(TYPE element) {
        if (curr_size == reserved_size)
            double_arr();
        main_arr[curr_size++] = element;
    }

    //Add all elemenets from range [arr_start, arr_end)
    void add_elements(TYPE* arr_start, TYPE* arr_end) {
        for (TYPE* i = arr_start; i != arr_end; ++i)
            add_element(*i);
    }

    //Returns value of element at index 'idx'
    TYPE at(int idx) {
        return main_arr[idx];
    }

    //Returns element at index 'idx';
    TYPE& get(int idx) {
        return main_arr[idx];
    }

    //Returns index of first element with value equals x
    int indexOf(TYPE x) {
        for (int i = 0; i < curr_size; ++i) {
            if (main_arr[i] == x)
                return i;
        }
        return -1;
    }

    //Returns pointer to the first element of vector
    TYPE* first() {
        return main_arr;
    }

    //Returns pointer to the last element of vector
    TYPE* last() {
        return main_arr + curr_size;
    }

    //Remove first element with value equals to x
    void rm_element(TYPE x) {
        int toMove = -1;
        for (int i = 0; i < curr_size; ++i) {
            if (main_arr[i] == x && toMove = -1) {
                toMove = i;
            }
            else {
                main_arr[toMove++] = main_arr[i];
            }
        }
        curr_size = toMove;
    }

    //Remove all elements with value equals to x
    void rm_elements(TYPE x) {
        int toMove = 0;
        for (int i = 0; i < curr_size; ++i) {
            if (main_arr[i] != x) {
                main_arr[toMove++] = main_arr[i];
            }
        }
        curr_size = toMove;
    }

    //Returns number of elements in array
    int getSize() {
        return curr_size;
    }

    //Print elements of arr;
    void print() {
        for (int i = 0; i < curr_size; ++i)
            std::cout << main_arr[i] << " ";
        std::cout << std::endl;
    }

    //Print elements using passed function
    template<class PRINT_TYPE> void custom_print(PRINT_TYPE func(TYPE x)) {
        for (int i = 0; i < curr_size; ++i)
            std::cout << func(main_arr[i]) << " ";
        std::cout << std::endl;
    };

    //Operators overloading:
    //Overloading "+" operator
    template <class T> Vector<T> operator + (Vector<T>& vector) {
        add_elements(vector.first(), vector.last());
        return *this;
    };

    //Overloading "+=" operator
    template <class T> Vector<T> operator += (Vector<T>& vector) {
        add_elements(vector.first(), vector.last());
        return *this;
    };
};