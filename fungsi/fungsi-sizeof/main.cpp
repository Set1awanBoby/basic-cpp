#include <iostream>

struct Data
{
    char c;
    int i;
    double d;
};

void ukuran(int arr[])
{
    std::cout << "ukuran arr didalam fungsi: " << sizeof(arr) << " bytes" << std::endl;
}

int main()
{
    std::cout << "ukuran dari char: " << sizeof(char) << " byte" << std::endl;
    std::cout << "ukuran dari int: " << sizeof(int) << " byte" << std::endl;
    std::cout << "ukuran dari float: " << sizeof(float) << " byte" << std::endl;
    std::cout << "ukuran dari double: " << sizeof(double) << " byte" << std::endl;

    std::cout << "\n";

    int arr[10];
    std::cout << "ukuran arr: " << sizeof(arr) << " byte" << std::endl;    // -> 40(4 * 10)
    std::cout << "ukuran arr: " << sizeof(arr[0]) << " byte" << std::endl; // -> 4
    std::cout << sizeof(arr) / sizeof(arr[0]) << std::endl;                // -> 10

    std::cout << "\n";

    std::cout << "ukuran dari struct Data: " << sizeof(Data) << " bytes" << std::endl; // -> 16

    std::cout << "ukuran arr didalam entrypoint: " << sizeof(arr) << " bytes" << std::endl; // -> 40
    ukuran(arr);                                                                            // -> 8

    return 0;
}