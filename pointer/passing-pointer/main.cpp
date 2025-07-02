/*
Passing pointer ke fungsi berarti lokasi memori variabel diteruskan
ke parameter dalam fungsi, dan kemudian operasi dilakukan.
Definisi fungsi menerima alamat ini menggunakan pointer,
alamat disimpan menggunakan pointer.
*/

#include <iostream>

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swapPoint(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void updateNilaiArr(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        arr[i] += arrSize;
    }
}

void alokasiMemori(int **pointer, int ukuran)
{
    *pointer = new int[ukuran];

    for (int i = 0; i < ukuran; i++)
    {
        (*pointer)[i] = i + 1; // -> isi array
    }
}

void printNilai(const int *pointer)
{
    if (pointer == nullptr)
    {
        std::cout << "pointer tidak valid" << std::endl;
    }

    std::cout << "nilai: " << *pointer << std::endl;
}

int main()
{
    int a = 10, b = 20;

    std::cout << a << " " << b << std::endl; // -> 10 20
    swap(a, b);
    std::cout << a << " " << b << std::endl; // -> 10 20
    swapPoint(&a, &b);
    std::cout << a << " " << b << std::endl; // -> 20 10

    std::cout << "\n";

    int arr[] = {1, 2, 3, 4, 5};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    std::cout << "sebelum diubah: " << std::endl;
    for (int i = 0; i < arrSize; i++)
    {
        std::cout << "nilai index ke-[" << i << "] : " << arr[i] << std::endl;
    }

    std::cout << "\n";

    std::cout << "setelah diubah: " << std::endl;
    updateNilaiArr(arr, arrSize);
    for (int i = 0; i < arrSize; i++)
    {
        std::cout << "nilai index ke-[" << i << "] : " << arr[i] << std::endl;
    };

    std::cout << "\n";

    int *arr2 = nullptr;
    int ukuran = 5;
    alokasiMemori(&arr2, ukuran);
    std::cout << "array dinamis: " << std::endl;
    for (int i = 0; i < ukuran; i++)
    {
        std::cout << arr2[i] << " ";
    }

    std::cout << "\n";

    delete[] arr2;

    std::cout << "\n";

    int angka = 100;
    printNilai(&angka);

    return 0;
}