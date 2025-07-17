#include "kotak.hpp"

Kotak::Kotak(double l, double t) : lebar(l), tinggi(t) {};

double Kotak::area() const
{
    return lebar * tinggi;
};

double Kotak::perimeter() const
{
    return 2 * (lebar + tinggi);
};

void Kotak::setLebar(double l)
{
    lebar = l;
};

void Kotak::setTinggi(double t)
{
    tinggi = t;
};

double Kotak::ambilLebar() const
{
    return lebar;
};

double Kotak::ambilTinggi() const
{
    return tinggi;
};