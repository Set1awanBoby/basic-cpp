/*
aritmatika:
    + -> penjumlahan
    - -> pengurangan
    * -> perkalian
    / -> pembagian
    % -> modulus

relasional:
    == -> sama dengan
    != -> tidak sama dengan
    > -> lebih besar
    < -> lebih kecil
    >= -> lebih besar atau sama dengan
    <= -> lebih kecil atau sama dengan

operator logika
    && -> and
    || -> or
    ! -> not

operator bitwise
    & -> and bitwise
    | -> or bitwise
    ^ -> xor bitwise
    ~ -> not bitwise
    << -> shift left
    >> -> shift right

operator assign
    = -> assignment
    += -> assignment penjumlahan
    -= -> assignment pengurangan
    *= -> assignment perkalian
    /= -> assignment pembagian
    %= -> assignment modulus
*/

#include <iostream>

int main()
{
    int a = 10, b = 20;

    // aritmatika
    std::cout << "aritmatika operator" << std::endl;
    std::cout << "a = 10, b = 20" << std::endl;
    std::cout << "a + b: " << (a + b) << std::endl;
    std::cout << "a - b: " << (a - b) << std::endl;
    std::cout << "a * b: " << (a * b) << std::endl;
    std::cout << "a / b: " << (a / b) << std::endl;
    std::cout << "a % b: " << (a % b) << std::endl;

    // relasional
    std::cout << "\nrelasional operator" << std::endl;
    std::cout << "a = 10, b = 20" << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;

    // logika
    std::cout << "\nlogika operator" << std::endl;
    std::cout << "a = 10, b = 20" << std::endl;
    std::cout << "a && b: " << (a && b) << std::endl;
    std::cout << "a || b: " << (a || b) << std::endl;
    std::cout << "!a: " << (!a) << std::endl;

    // bitwise
    std::cout << "\nbitwise operator" << std::endl;
    std::cout << "a = 10, b = 20" << std::endl;
    std::cout << "a & b: " << (a & b) << std::endl;
    std::cout << "a | b: " << (a | b) << std::endl;
    std::cout << "a ^ b: " << (a ^ b) << std::endl;
    std::cout << "~a: " << (~a) << std::endl;
    std::cout << "a << b: " << (a << b) << std::endl;
    std::cout << "a >> b: " << (a >> b) << std::endl;

    // assignment operator
    std::cout << "\nassignment operator" << std::endl;
    std::cout << "a = 10, b = 20" << std::endl;
    std::cout << "a += b: " << (a += b) << std::endl;
    std::cout << "a -= b: " << (a -= b) << std::endl;
    std::cout << "a *= b: " << (a *= b) << std::endl;
    std::cout << "a /= b: " << (a /= b) << std::endl;
    std::cout << "a %= b: " << (a %= b) << std::endl;
    return 0;
}