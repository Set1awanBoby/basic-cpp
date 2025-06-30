/*
if (kondisi) {
    ... <- ini adalah isi dari kode jika kondisi bernilai true
}

if statement
if (kondisi) {
    ... <- ini adalah isi dari kode jika kondisi bernilai true
} else {
    ... <- ini adalah isi dari kode jika kondisi bernilai false
}

if else if statement
if (kondisi1) {
    ... <- ini adalah isi dari kode jika kondisi1 bernilai true
} else if (kondisi2) {
    ... <- ini adalah isi dari kode jika kondisi2 bernilai true
} else {
    ... <- ini adalah isi dari kode jika kondisi1 dan kondisi2 bernilai false
}

*/

#include <iostream>

int main()
{
    int nilai;
    std::cout << "Masukkan nilai: ";
    std::cin >> nilai;
    if (nilai >= 85)
    {
        std::cout << "Nilai A" << std::endl;
    }
    else if (nilai >= 75)
    {
        std::cout << "Nilai B" << std::endl;
    }
    else if (nilai >= 65)
    {
        std::cout << "Nilai C" << std::endl;
    }
    else
    {
        std::cout << "Nilai D" << std::endl;
    }
    return 0;
}