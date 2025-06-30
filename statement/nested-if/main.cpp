/*
if (kondisi 1) {
    if (kondisi 2) { <- ini adalah statement jika kondisi 1 bernilai true
        ... <- ini adalah isi dari kode jika kondisi 2 bernilai true
    } else {
        ... <- ini adalah isi dari kode jika kondisi 2 bernilai false
    }
} else {
    ... <- ini adalah isi dari kode jika kondisi 1 bernilai false
}

*/

#include <iostream>
#include <string>

int main()
{
    std::string username, password;
    std::cout << "Masukkan username: ";
    std::getline(std::cin, username);

    if (username == "admin")
    {
        std::cout << "Masukkan password: ";
        std::getline(std::cin, password);
        if (password == "admin123")
        {
            std::cout << "Selamat datang admin" << std::endl;
        }
        else
        {
            std::cout << "Password salah" << std::endl;
        }
    }
    else
    {
        std::cout << "Username salah" << std::endl;
    }
    return 0;
}