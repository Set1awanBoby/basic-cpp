#include <iostream>
#include <vector>
#include <algorithm>
int main()
{

    auto angka = 8;
    auto PI = 3.14;

    std::cout << angka << std::endl;
    std::cout << PI << std::endl;
    std::cout << "\n";

    std::vector<int> vector1 = {1, 2, 3, 4, 5};
    std::cout << vector1.size() << std::endl;
    vector1.resize(4);
    vector1.shrink_to_fit();
    std::cout << vector1.capacity() << std::endl;

    for (auto i = vector1.begin(); i != vector1.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << "\n";

    std::vector<int>
        vector2 = {10, 20, 30, 40, 50};
    // std::vector<int>::iterator maxElement = -> jika tidak menggunakan auto
    auto maxElement = std::max_element(vector2.begin(), vector2.end());
    std::cout << "max element: " << *maxElement << std::endl;
    std::cout << "\n";

    auto hasil = [](int a, int b)
    { return a + b; };

    std::cout << "hasil: " << hasil(5, 20) << std::endl;

    std::vector<int> vector3 = {12, 13, 14, 15, 16};

    for (auto element : vector3)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";

    return 0;
}