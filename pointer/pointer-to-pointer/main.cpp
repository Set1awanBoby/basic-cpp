/*
pointer biasa -> variabel yang menyimpan alamat memori dari variabel lain
pointer pointer -> variabel yang menyimpan alamat memori dari pointer

int** pointer_ke_pointer;
variabel x, p -> x, pp -> p
x -> menyimpan nilai data -> 0x100
p -> menyimpan alamat memori dari x -> 0x200
pp -> menyimpan alamat memori dari p -> 0x300

1. alokasi memori dinamis
2. parameter fungsi
3. hirarki data
*/

#include <iostream>

void modifikasiNilai(int **pp)
{
    **pp = 50;
}

int main()
{
    int x = 40;
    int *p = &x;
    int **pp = &p;

    std::cout << "nilai x: " << x << std::endl;
    std::cout << "alamat memori x: " << &x << std::endl;
    std::cout << "nilai p(alamat memori &x): " << p << std::endl;
    std::cout << "nilai pp(alamat memori &p): " << pp << std::endl;
    std::cout << "nilai pp(alamat memori &pp): " << &pp << std::endl;
    std::cout << "nilai pp: " << **pp << std::endl;
    std::cout << "\n";

    std::cout << "nilai sebelum diubah: " << x << std::endl;
    modifikasiNilai(pp); // -> mengubah nilai x dari 40 menjadi 50
    std::cout << "nilai sesudah diubah dari double pointer: " << x << std::endl;
    std::cout << "\n";

    int baris = 3, kolom = 3;
    int **matrix = new int *[baris]; // -> alokasi memori dinamis untuk array 2 dimensi

    for (int i = 0; i < baris; i++)
    {
        matrix[i] = new int[baris]; // -> alokasi memori dinamis untuk array
    }

    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            matrix[i][j] = i * kolom + j; //-> isi array
        }
    }

    std::cout << "matrix: " << std::endl;
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            std::cout << "matrix[" << i << "][" << j << "]: " << matrix[i][j] << "  "; // -> menampilkan array
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < baris; i++)
    {
        delete[] matrix[i]; // -> menghapus array
    }

    delete[] matrix; // -> menghapus array

    return 0;
}