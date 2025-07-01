/*
1.

*/

#include <iostream>

union Data
{
    int angka_integer;
    float angka_desimal;
    char *char_pointer;
};

int main()
{
    Data data;

    data.angka_integer = 10;
    std::cout << "nilai integer: " << data.angka_integer << std::endl; // 10

    data.angka_desimal = 3.14;
    std::cout << "nilai desimal: " << data.angka_desimal << std::endl;          // 3.14
    std::cout << "nilai integer sekarang: " << data.angka_integer << std::endl; // 1078523331

    char text[] = "boby";
    data.char_pointer = text;
    std::cout << data.char_pointer << std::endl; // boby

    *data.char_pointer = 'A';
    std::cout << data.char_pointer << std::endl; // Aoby

    return 0;
}