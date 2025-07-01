/*
+ dan - -> menggeser alamat memori
int (4 byte) -> + 1 -> akan menggeser sebanyak 4 byte
char (1 byte) -> + 1 -> akan menggeser sebanyak 1 byte
*/

#include <iostream>

int main()
{

    int array[] = {10, 20, 30, 40, 50};
    int *pointer_array = array;

    std::cout << "pointer pertama adalah: " << *pointer_array << std::endl;

    pointer_array++;
    // pointer akan menggeser sebanyak 4 byte
    // [0] = 10 -> [1] = 20
    std::cout << "ketika sudah digeser: " << *pointer_array << std::endl; // 20

    pointer_array += 2;
    // pointer akan menggeser sebanyak 8 byte
    //[1] = 20 -> [3] = 40
    std::cout << "ketika sudah digeser: " << *pointer_array << std::endl; // 40

    pointer_array--;
    // pointer akan menggeser sebanyak 4 byte
    // [3] = 40 -> [2] = 30
    std::cout << "ketika sudah digeser: " << *pointer_array << std::endl; // 30

    int array2[] = {2, 3, 5, 7, 11};
    int *pointer_array2_elemen2 = &array2[1];
    int *pointer_array2_elemen5 = &array2[4];

    int jarak = pointer_array2_elemen2 - pointer_array2_elemen5; // -3
    std::cout << "jarak antara elemen ke-2 dan elemen ke-5: " << jarak << std::endl;

    char blok_memori[] = {'A', 'B', 'C', 'D', 'E'};
    char *pointer_blok_memori = blok_memori;

    for (int i = 0; i < 5; i++)
    {
        std::cout << *(pointer_blok_memori + i) << " ";
    }

    *(pointer_blok_memori + 1) = 'X';

    std::cout << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << *(pointer_blok_memori + i) << " ";
    }

    return 0;
}