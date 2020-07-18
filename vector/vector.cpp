#include <iostream>
#include <cstdlib>

template <class TYPE> class myVector{
private:
    int reserved_size;//Maximal number of elements in main_arr
    int curr_size;//Current number of elements in main_arr
    TYPE * main_arr;//Main array
    TYPE * temp_arr;//Array used for creating bigger array

    void double_arr(){
        temp_arr = (TYPE*) malloc(2*reserved_size*sizeof(TYPE));
        for(int i=0;i<curr_size;++i){
            temp_arr[i] = main_arr[i];
        }
        delete main_arr;
        main_arr = temp_arr;
        temp_arr = NULL;
    }
public:
    //Creates empty vector for n elements
    myVector(int n){
        curr_size = 0;
        reserved_size = n;
        main_arr = (TYPE*) malloc(n*sizeof(TYPE));
    };
    //Creates vector with elements of an array in range [arr_start,arr_end)
    myVector(TYPE * arr_start,TYPE * arr_end){
        if(main_arr != NULL)
            delete main_arr;

        int n = arr_end-arr_start;

        curr_size = n;
        reserved_size = n;

        main_arr = (TYPE*) malloc(n*sizeof(TYPE));

        for(int i=0;i<n;++i)
            main_arr[i] = arr_start[i];
    };

    void add_element(TYPE element){
        if(curr_size == reserved_size)
            double_arr();
        main_arr[curr_size++] = element;
    }

    TYPE get(int idx){
        return main_arr[idx];
    }

    //remove first element with value equals to x
    void rm_element(TYPE x){
        int toMove = 0;
        for(int i=0;i<curr_size;++i){
            if(main_arr[i]!=x){
                main_arr[toMove++] = main_arr[i];
            }
        }
        --curr_size;
    }

    int getSize(){
        return curr_size;
    }

    void print(){
        for(int i=0;i<curr_size;++i)
            std::cout << main_arr[i] << " ";
        std::cout << std::endl;
    }
};
