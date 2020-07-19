#include <cstdio>
#include "vector/vector.cpp"

struct man{
    std::string name;
    int age;
};

int printFunc1(man x){
    return x.age;
}

std::string printFunc2(man x){
    return x.name;
}

void printTextOnStart(){
    printf(" DATA STRUCUTRES EXAMPLES\n");
    printf("==============================================\n");
    printf(" For more informations please read \"README.md\"\n");
    printf("\n");
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    myVector<int> test(arr,arr+5);
    test.add_elements(arr+3,arr+5);
    test.print();
    return 0;
}
