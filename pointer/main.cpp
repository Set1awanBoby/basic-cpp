/*
pointer adalah variabel yang menyimpan alamat memori dari variabel lain
pointer ini tidak menyimpan nilai data secara langsung,
melainkan akan menyimpan alamat memori dimana data tersebut disimpan

tipe_data *variabel_pointer;

1. dereferencing pointer (*) -> mengambil nilai dari alamat memori

*/

#include <iostream>

struct Orang
{
    std::string nama;
    int umur;
};

int main()
{
    int nilai = 10;
    int *pointer_nilai = &nilai;              // -> pointer_nilai menyimpan alamat memori dari nilai
    std::cout << *pointer_nilai << std::endl; // -> mengambil nilai dari alamat memori pointer_nilai yaitu 10
    std::cout << pointer_nilai << std::endl;  // -> mengambil alamat memori pointer_nilai yaitu 0x7ffebf5f4e30
    std::cout << nilai << std::endl;          // -> sama dengan *pointer_nilai
    std::cout << &nilai << std::endl;         // -> sama dengan pointer_nilai

    // mengganti nilai dari pointer
    *pointer_nilai = 20;
    std::cout << *pointer_nilai << std::endl; // -> 20
    std::cout << "\n";

    // menggunakan pointer untuk membuat array
    // array sendiri merupakan sebuah pointer
    int array[5] = {1, 2, 3, 4, 5};
    int *pointer_array = array;                     // -> pointer_array menyimpan alamat memori dari array
    std::cout << *pointer_array << std::endl;       // -> 1
    std::cout << *(pointer_array + 1) << std::endl; // -> 2

    for (int i = 0; i < 5; i++)
    {
        std::cout << "element arr ke-[" << i << "]: " << *(pointer_array + i) << "" << std::endl;
    }
    std::cout << "\n";

    // menggunakan pointer untuk membuat struct
    Orang orang = {"boby", 20};                    // -> membuat objek orang
    Orang *pointer_orang = &orang;                 // -> pointer_orang menyimpan alamat memori dari orang
    std::cout << pointer_orang->nama << std::endl; // -> mengambil nilai dari alamat memori pointer_orang yaitu "boby"
    std::cout << pointer_orang->umur << std::endl; // -> mengambil nilai dari alamat memori pointer_orang yaitu 20

    pointer_orang->umur = 21;
    std::cout << pointer_orang->umur << std::endl; // mengubah umur orang

    return 0;
}