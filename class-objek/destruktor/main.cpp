/*
1. nama desctructor sama dengan nama kelas
2. tidak memiliki parameter atau return type
3. dipanggil secara otomatis saat object itu dihancurkan

*/

#include <iostream>
#include <string>

class Orang
{
public:
    std::string nama;

    Orang(std::string n)
    {
        nama = n;
        std::cout << "constructor dipanggil" << std::endl;
    }

    ~Orang()
    {
        std::cout << "desctructor dipanggil" << std::endl;
    }

    void greeting()
    {
        std::cout << "Wello" << nama << std::endl;
    }
};

class ArrDinamis
{
private:
    int *arr;
    int arrSize;

public:
    ArrDinamis(int u)
    {
        arrSize = u;
        arr = new int[arrSize];
        std::cout << "array dengan ukuran " << arrSize << " dialokasikan" << std::endl;
    }

    ~ArrDinamis()
    {
        delete[] arr;
        std::cout << "memori dari array sudah dibebaskan" << std::endl;
    }
};

int main()
{
    Orang orang1("Jane");
    Orang orang2("Boby");
    std::cout << "\n";

    ArrDinamis arr1(5);

    return 0;
}