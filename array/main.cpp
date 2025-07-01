/*
1. index teurut -> 0
2. tipe data sama
3. ukuran data sama

int a[5] = {1,2,3,4,5};
           [0 1 2 3 4]
*/

#include <iostream>

int main()
{
    int prima[6] = {2, 3, 5, 7, 11};
    std::cout << "nilai bilangan prima ke-1: " << prima[0] << std::endl;
    std::cout << "nilai bilangan prima ke-5: " << prima[4] << std::endl;

    prima[5] = 13;
    std::cout << "nilai bilangan prima ke-6: " << prima[5] << std::endl;

    std::cout << "\n\n";
    // for loop array
    for (int i = 0; i < 6; i++)
    {
        std::cout << "nilai bilangan prima ke-" << i + 1 << ": " << prima[i] << std::endl;
    }
    std::cout << "\n\n";
    // array 2 dimensi
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << "matrix[" << i << "][" << j << "]: " << matrix[i][j] << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << "\n\n";
    // array dinamis
    int ukuran;
    std::cout << "Masukkan ukuran array: ";
    std::cin >> ukuran;

    int *arr = new int[ukuran]; // -> membuat array dengan dinamis

    for (int i = 0; i < ukuran; i++) // -> mengisi array
    {
        arr[i] = (i + 1) * 10;
    }

    std::cout << "Array: ";
    for (int i = 0; i < ukuran; i++) // -> menampilkan array
    {
        std::cout << arr[i] << " ";
    }

    delete[] arr; // -> menghapus array dari memori

    return 0;
}