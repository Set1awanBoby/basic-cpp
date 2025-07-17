#ifndef KOTAK_HPP_
#define KOTAK_HPP_

class Kotak
{
private:
    double lebar;
    double tinggi;

public:
    Kotak(double lebar, double tinggi);

    double area() const;
    double perimeter() const;

    void setLebar(double lebar);
    void setTinggi(double tinggi);

    double ambilLebar() const;
    double ambilTinggi() const;
};

#endif