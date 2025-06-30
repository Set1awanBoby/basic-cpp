/*
switch (ekspresi) {
    case 1: <- ekspresi sama dengan 1
        ... <- ini adalah isi dari kode jika ekspresi bernilai 1
        break; <- digunakan untuk menghentikan eksekusi switch
    case 2:
        ...
        break;
    default:
        ...
        break;
}

*/

#include <iostream>

int main()
{
    char Operasi;
    double a, b, hasil;

    std::cout << "Masukan Operasi (+, -, *, /): ";
    std::cin >> Operasi;
    std::cout << "Masukan angka pertama: ";
    std::cin >> a;
    std::cout << "Masukan angka kedua: ";
    std::cin >> b;

    switch (Operasi)
    {
    case '+':
        hasil = a + b;
        std::cout << a << " + " << b << " = " << hasil << std::endl;
        break;
    case '-':
        hasil = a - b;
        std::cout << a << " - " << b << " = " << hasil << std::endl;
        break;
    case '*':
        hasil = a * b;
        std::cout << a << " * " << b << " = " << hasil << std::endl;
        break;
    case '/':
        if (b == 0)
        {
            std::cout << "Pembagian dengan nol tidak dapat dilakukan" << std::endl;
        }
        else
        {
            hasil = a / b;
            std::cout << a << " / " << b << " = " << hasil << std::endl;
        }
        break;
    default:
        std::cout << "Operasi tidak valid" << std::endl;
        break;
    }

    return 0;
}