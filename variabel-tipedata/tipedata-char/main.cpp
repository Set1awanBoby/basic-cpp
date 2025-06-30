// char -> kode ASCII (American Standard Code for Information Interchange)
// ukuran data
// char -> 1 byte -> 8 bit
// rentang nilai char -128 sampai 127 -> 256 karakter
/*
fungsi:
1.) menyimpan karakter tunggal -> 'A', '*', '@'....
2.) dasar dari manipulasi string
3.) efesiensi memori
*/

#include <iostream>

int main()
{
    // int(nama_variabel) untuk melihat kode ASCII
    char huruf = 'a';  // 'a' -> 97
    char angka = '1';  // '1' -> 49
    char simbol = '@'; // '@' -> 64

    char nama[] = "boby"; // 'b' -> 98, 'o' -> 111, 'y' -> 121

    return 0;
}