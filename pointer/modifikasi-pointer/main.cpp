/*
1. mengubah alamat yang disimpan oleh si pointer
2. mengubah data di alamat yang ditunjuk oleh si pointer
- mengubah nilai anggota tertentu dalam union
- menunjukkan pointer ke bagian lain dari union atau data lain
*/

#include <iostream>

union Data
{
    int angka_integer;
    float angka_desimal;
    char *char_pointer;
};

union Data2
{
    int arrayBulat[5];
    float nilai_desimal;
};

int main()
{
    int angka1 = 10, angka2 = 20;
    int *pointer_angka1 = &angka1;

    std::cout << "sebelum data diubah: " << *pointer_angka1 << std::endl; // 10

    *pointer_angka1 = 50;
    std::cout << "sesudah data diubah: " << angka1 << std::endl; // 50

    pointer_angka1 = &angka2;
    std::cout << "sesudah pointer diubah: " << *pointer_angka1 << std::endl; // 20

    std::cout << "\n";

    Data data;

    data.angka_integer = 22;
    std::cout << "nilai integer sekarang: " << data.angka_integer << std::endl; // 22

    float *pointer_desimal = reinterpret_cast<float *>(&data);
    *pointer_desimal = 3.14f;
    std::cout << "nilai desimal sekarang: " << data.angka_desimal << std::endl; // 3.14

    char kata[] = "goby ganteng bgt";
    data.char_pointer = kata;
    std::cout << "kata sekarang: " << data.char_pointer << std::endl; // goby ganteng bgt

    *data.char_pointer = 'B';
    std::cout << "kata sekarang: " << data.char_pointer << std::endl; // Boby ganteng bgt

    std::cout << "\n";

    Data2 data2;

    data2.arrayBulat[0] = 10;
    data2.arrayBulat[1] = 20;
    data2.arrayBulat[2] = 30;
    data2.arrayBulat[3] = 40;
    data2.arrayBulat[4] = 50;

    int *pointer_arrayBulat = data2.arrayBulat;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "sebelum data diubah element array ke-[" << i << "]: " << std::endl;
        std::cout << "nilai: " << *(pointer_arrayBulat + i) << ", alamat: " << (pointer_arrayBulat + i) << std::endl;
    }

    std::cout << "\n";

    *(pointer_arrayBulat + 2) = 100;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "sesudah data diubah element array ke-[" << i << "]: " << std::endl;
        std::cout << "nilai: " << *(pointer_arrayBulat + i) << ", alamat: " << (pointer_arrayBulat + i) << std::endl;
    }

    return 0;
}