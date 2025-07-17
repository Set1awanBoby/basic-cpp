/*
Multiple Inheritance merupakan fitur C++ di mana sebuah kelas dapat
mewarisi lebih dari satu kelas. Konstruktor kelas yang diwarisi dipanggil
dalam urutan yang sama dengan saat diwarisi. Misalnya, dalam program berikut,
konstruktor B dipanggil sebelum konstruktor A.

class Base_A {
    ...
};

class Base_B {
    ...
};

class Derived : public Base_A, public Base_B {
    ...
};

*/

#include <iostream>
#include <string>

class SoftwareDev
{
protected:
    std::string programLang;

public:
    SoftwareDev(std::string lang) : programLang(lang) {}

    void ngoding()
    {
        std::cout << "Ngoding di bahasa: " << programLang << std::endl;
    }
};

class ProjectManager
{
protected:
    int jumlahProject;

public:
    ProjectManager(int j) : jumlahProject(j) {}

    void manageProject()
    {
        std::cout << "manage project: " << jumlahProject << " project" << std::endl;
    }
};

class Karyawan : public SoftwareDev, public ProjectManager
{
private:
    std::string nama;

public:
    Karyawan(std::string n, std::string lang, int j) : SoftwareDev(lang), ProjectManager(j), nama(n) {}

    void infoKaryawan()
    {
        std::cout << "Nama: " << nama << std::endl;
        ngoding();
        manageProject();
    }
};

int main()
{
    Karyawan karyawan("Boby", "C++", 8);
    karyawan.infoKaryawan();
    return 0;
}