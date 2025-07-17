/*
Konflik nama dalam C++ terjadi ketika berbagai bagian program menggunakan
nama yang sama untuk variabel, fungsi, atau kelas,
yang menyebabkan kebingungan bagi kompilator.
Untuk menghindari hal ini, C++ memperkenalkan namespace.

Namespace adalah fitur yang menyediakan cara untuk mengelompokkan
pengidentifikasi terkait seperti variabel, fungsi,
dan kelas di bawah satu nama. Fitur ini menyediakan ruang di mana kita
dapat mendefinisikan atau mendeklarasikan pengidentifikasi,
misalnya variabel, metode, dan kelas.
Intinya, namespace mendefinisikan suatu cakupan.

*/

#include <iostream>
#include <string>

namespace OperasiMatematika
{
    int tambah(int a, int b)
    {
        return a + b;
    }

    int kurang(int a, int b)
    {
        return a - b;
    }
};

namespace OperasiString
{
    void print(const std::string &pesan)
    {
        std::cout << pesan << std::endl;
    }
};

namespace FullName
{
    void print(std::string nama_depan, std::string nama_belakang)
    {
        std::cout << "Hello " << nama_depan + " " + nama_belakang << std::endl;
    }
};

namespace Perusahaan
{
    namespace HumanResource
    {
        void infoKaryawan()
        {
            std::cout << "ini adalah info karyawan dari namespace HumanResource" << std::endl;
        }
    }

    namespace Programmer
    {
        void infoProject()
        {
            std::cout << "ini adalah info project dari namespace Programmer" << std::endl;
        }
    }
};

int main()
{
    int hasil = OperasiMatematika::tambah(10, 5);
    std::cout << hasil << std::endl;

    OperasiString::print("Hello World");

    namespace FN = FullName;
    FN::print("Boby", "Setiawan");

    Perusahaan::HumanResource::infoKaryawan();
    Perusahaan::Programmer::infoProject();

    return 0;
}