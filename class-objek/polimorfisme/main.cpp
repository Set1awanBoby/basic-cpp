/*
Kata polimorfisme berarti memiliki banyak bentuk.
Contoh nyata dari polimorfisme adalah seseorang yang pada saat yang
sama dapat memiliki karakteristik yang berbeda.
Seorang pria pada saat yang sama adalah seorang ayah, seorang suami,
dan seorang karyawan. Jadi, orang yang sama menunjukkan perilaku yang
berbeda dalam situasi yang berbeda. Ini disebut polimorfisme.

class Base {
    public:
        virtual void func() {
            ...
        }
    };

class Derived : public Base {
    public:
        void display() override {
            ...
        }
};
*/

#include <iostream>

class Shape
{
public:
    virtual void gambar()
    {
        std::cout << "gambar bentuk shape dasar" << std::endl;
    }
};

class Bulat : public Shape
{
public:
    void gambar() override
    {
        std::cout << "gambarkan lingkaran" << std::endl;
        std::cout << "o <- gambar bulat sudah dibuat " << std::endl;
    }
};

class Kotak : public Shape
{
public:
    void gambar() override
    {
        std::cout << "gambarkan kotak" << std::endl;
        std::cout << "[] <- gambar kotak sudah dibuat" << std::endl;
    }
};

class OperasiMatematika
{
public:
    int add(int a, int b)
    {
        return a + b;
    }
    double add(double a, double b)
    {
        return a + b;
    }
};

int main()
{
    Shape *shapePoint;
    Bulat bulat;
    shapePoint = &bulat;
    shapePoint->gambar();

    Kotak kotak;
    shapePoint = &kotak;
    shapePoint->gambar();
    std::cout << "\n";

    OperasiMatematika op_mtk;
    int a = 20, b = 30;
    double c = 3.14, d = 2.98;
    std::cout << "Penjumlahan dari bil bulat " << a << " dan " << b << std::endl;
    std::cout << op_mtk.add(a, b) << std::endl;
    std::cout << "Penjumlahan dari bil decimal " << c << " dan " << d << std::endl;
    std::cout << op_mtk.add(c, d) << std::endl;

    return 0;
}