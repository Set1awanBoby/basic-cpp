/*
Pewarisan Bertingkat adalah jenis pewarisan dalam C++ di mana satu kelas
mewarisi kelas lain, yang pada gilirannya berasal dari kelas lain.
Pewarisan ini dikenal sebagai pewarisan bertingkat karena terdapat
lebih dari satu tingkat pewarisan.

class Base {
    ...
};

class Derived1 : public Base {
    ...
};

class Derived2 : public Derived1 {
    ...
};

*/

#include <iostream>
#include <string>

class MakhlukHidup
{
protected:
    std::string nama;

public:
    MakhlukHidup(std::string n) : nama(n) {}

    void bernapas()
    {
        std::cout << nama << " Bernapas." << std::endl;
    }
};

class Mamalia : public MakhlukHidup
{
public:
    Mamalia(std::string n) : MakhlukHidup(n) {}

    void caraBerkembangBiak()
    {
        std::cout << "Mamalia berkembang biak dengan cara melahirkan " << std::endl;
    }
};

class Paus : public Mamalia
{
public:
    Paus(std::string n) : Mamalia(n) {}

    void bersuara()
    {
        std::cout << nama << " Bersuara ngikngik " << std::endl;
    }
};

int main()
{
    Paus paus("Puff");
    paus.bernapas();
    paus.caraBerkembangBiak();
    paus.bersuara();

    return 0;
}