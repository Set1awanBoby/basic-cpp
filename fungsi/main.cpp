/*
fungsi
1. mengurangi duplikasi kode
2. mempermudah penulisan kode
3. membuat kode lebih bersih atau terorganisir

tipe_return nama_fungsi(argument) {
    ... <- statement kode
    return value;
}
*/

#include <iostream>
#include <string>

// overloading function
// -> function dengan nama yang sama namun dengan parameter yang berbeda
int tambah(int a, int b) { return a + b; }
double tambah(double a, double b) { return a + b; }

// rekursif function
// -> function yang memanggil dirinya sendiri
int faktorial(int angka)
{
    if (angka <= 1)
    {
        return 1;
    }
    return angka * faktorial(angka - 1);
}

// function dengan parameter tanpa nilai kembali/return
void nama(std::string name = "tidak ada nama")
{
    std::cout << name << std::endl;
}

int main()
{
    std::cout << "integer: " << tambah(10, 20) << std::endl;
    std::cout << "decimal: " << tambah(10.5, 20.5) << std::endl;
    std::cout << "\n";

    std::cout << "faktorial: " << faktorial(5) << std::endl;
    std::cout << "\n";

    nama();
    nama("boby");
    return 0;
}