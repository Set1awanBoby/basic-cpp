/*
for(inisialisasi data; kondisi; increment/decrement) {
    ... <- statement kode yang akan diulang
            berdasarkan kondisi
}

1. inisialisasi data
2. periksa kondisi
    - jika kondisi bernilai true, maka statement kode akan diulang
    - jika kondisi bernilai false, maka statement kode tidak akan diulang
3. esekusi pembaruan dan ulangi langkah kedua

*/

#include <iostream>

int main()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (int i = 1; i <= 10; i++)
    {
        if (i % 2 == 0)
        {
            continue;
        }

        if (i == 7)
        {
            break;
        }
        std::cout << i << " ";
    }
    return 0;
}