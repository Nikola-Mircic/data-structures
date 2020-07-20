#include <iostream>
#include <cstdlib>
#include <algorithm>

template <class TYPE> class myVector{
private:
    int reserved_size;//Maximal number of elements in main_arr
    int curr_size;//Current number of elements in main_arr
    TYPE * main_arr;//Main array
    TYPE * temp_arr;//Array used for creating bigger array

    void double_arr(){
        temp_arr = new TYPE[2*reserved_size];
        for(int i=0;i<curr_size;++i){
            temp_arr[i] = main_arr[i];
        }
        delete main_arr;
        main_arr = temp_arr;
        temp_arr = NULL;
    }
public:
    //Creates empty vector for n elements
    myVector(const int n){
        curr_size = 0;
        reserved_size = n;
        main_arr = new TYPE[n];
    };
    //Creates vector with elements of an array in range [arr_start,arr_end)
    myVector(const TYPE * arr_start,const TYPE * arr_end){
        int n = arr_end-arr_start;

        curr_size = 0;
        reserved_size = n;

        main_arr = new TYPE[n];

        for(TYPE* i = (TYPE*)arr_start; i!=(TYPE*)arr_end; ++i){
            main_arr[curr_size++] = *i;
        }
    };

    myVector(const myVector<TYPE>& vec){
        curr_size = vec.curr_size;
        reserved_size = vec.reserved_size;
        main_arr = new TYPE[reserved_size];

        for(int i=0;i<curr_size;++i)
            main_arr[i] = vec.main_arr[i];
    }

    void add_element(TYPE element){
        if(curr_size == reserved_size)
            double_arr();
        main_arr[curr_size++] = element;
    }

    void add_elements(TYPE * arr_start,TYPE * arr_end){
        for(TYPE * i = arr_start;i!=arr_end;++i)
            add_element(*i);
    }

    //Returns element at index 'idx';
    TYPE& get(int idx){
        return main_arr[idx];
    }

    //Returns index of first element with value equals x
    int indexOf(TYPE x){
        for(int i=0;i<curr_size;++i){
            if(main_arr[i]==x)
                return i;
        }
        return -1;
    }

    //remove first element with value equals to x
    void rm_element(TYPE x){
        int toMove = -1;
        for(int i=0;i<curr_size;++i){
            if(main_arr[i]==x && toMove = -1){
                toMove = i;
            }else{
                main_arr[toMove++] = main_arr[i];
            }
        }
        curr_size = toMove;
    }

    //remove all elements with value equals to x
    void rm_elements(TYPE x){
        int toMove = 0;
        for(int i=0;i<curr_size;++i){
            if(main_arr[i]!=x){
                main_arr[toMove++] = main_arr[i];
            }
        }
        curr_size = toMove;
    }

    //returns number of elements in array
    int getSize(){
        return curr_size;
    }

    //print elements of arr;
    void print(){
        for(int i=0;i<curr_size;++i)
            std::cout << main_arr[i] << " ";
        std::cout << std::endl;
    }

    //print elements using passed function
    template<typename PRINT_TYPE> void custom_print(PRINT_TYPE func(TYPE x)){
        for(int i=0;i<curr_size;++i)
            std::cout << func(main_arr[i]) << " ";
        std::cout << std::endl;
    }
};
