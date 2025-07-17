/*
Template C++ adalah alat canggih yang memungkinkan Anda menulis kode generik
yang dapat bekerja dengan semua tipe data. Idenya adalah dengan meneruskan
tipe data tersebut sebagai parameter sehingga kita tidak perlu menulis kode
yang sama untuk tipe data yang berbeda.

Misalnya, algoritma pengurutan yang sama dapat bekerja untuk tipe data
yang berbeda, jadi daripada menulis dan mengelola beberapa kode,
kita dapat menulis satu sort() dan meneruskan tipe data tersebut sebagai parameter.

- function template -> Dalam C++, template memungkinkan kita menulis kode generik
        untuk fungsi yang dapat digunakan dengan berbagai tipe data,
        dan ini dapat dicapai melalui templat fungsi.
        Misalnya, kita dapat menulis fungsi yang memberikan maksimal dua angka,
        tetapi fungsi tersebut dapat menerima angka apa pun,
        baik itu int, float, maupun double.

- class template -> Template kelas, seperti template fungsi, berguna ketika
        suatu kelas mendefinisikan sesuatu yang independen dari tipe datanya.
        Templat ini berguna untuk kelas-kelas seperti Linked List, Binary tree,
        Stack, Queue, Array, dll.
*/

#include <iostream>
#include <string>

template <typename T>
T tambah(T a, T b)
{
    return a + b;
};

template <typename T>
class Kotak
{
private:
    T value;

public:
    Kotak(T nilai) : value(nilai) {}
    void setNilai(T nilai)
    {
        value = nilai;
    }

    T ambilValue() const
    {
        return value;
    }
};

template <typename T1, typename T2>
class Pair
{
private:
    T1 pertama;
    T2 kedua;

public:
    Pair(T1 p, T2 k) : pertama(p), kedua(k) {}

    void show() const
    {
        std::cout << "nilai pertama " << pertama << std::endl;
        std::cout << "nilai kedua " << kedua << std::endl;
    }
};

template <typename T>
class Printer
{
public:
    void print(T pesan)
    {
        std::cout << "generik: " << pesan << std::endl;
    }
};

template <>
class Printer<char>
{
public:
    void print(char pesan)
    {
        std::cout << "Char: " << pesan << "(ASCII: " << int(pesan) << ")" << std::endl;
    }
};

int main()
{
    std::cout << "tambah int: " << tambah(10, 20) << std::endl;
    std::cout << "tambah double: " << tambah(10.5, 20.5) << std::endl;
    std::cout << "menggabungkan string: " << tambah(std::string("Boby "), std::string("Setiawan")) << std::endl;
    std::cout << "\n";

    Kotak<int> kotakInt(32);
    std::cout << "Int kotak: " << kotakInt.ambilValue() << std::endl;

    Kotak<double> kotakDouble(33.14);
    std::cout << "Double kotak: " << kotakDouble.ambilValue() << std::endl;
    std::cout << "\n";

    Pair<int, double> pair1(10, 30.4);
    pair1.show();
    Pair<std::string, int> pair2("Boby", 19);
    pair2.show();
    std::cout << "\n";

    Printer<int> intPrinter;
    intPrinter.print(123);

    Printer<char> charPrinter;
    charPrinter.print('A');

    return 0;
}