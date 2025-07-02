/*
1. mengakses data yang di buat dalam fungsi
2. mengelola memori dinamis
3. efesiensi

1. memori lokal (tidak disarankan)
2. memori dinamis (new)
3. memori global atau statis

*/

#include <iostream>

// konsep dinamis
int *buatArr(int ukuran)
{
    int *arr = new int[ukuran];
    for (int i = 0; i < ukuran; i++)
    {
        arr[i] = i + 1;
    }
    return arr;
}

// konsep local (tidak disarankan)
/*
int *returnLocalPointer()
{
    int x = 42;
    return &x;
}
    */

int *returnStaticPointer()
{
    static int x = 42; // -> static untuk memastikan bahwa
                       // variabel ada di memori setelah fungsi selesai
    return &x;
}

struct Point
{
    int x, y;
};

Point *buatPoint(int a, int b)
{
    Point *p = new Point;
    p->x = a;
    p->y = b;

    return p;
}

int main()
{
    int ukuran = 10;
    int *arr = buatArr(ukuran);

    std::cout << "array yang dibuat oleh fungsi: " << std::endl;
    for (int i = 0; i < ukuran; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << "\n";

    delete[] arr;

    /*
    int *localPointer = returnLocalPointer();
    std::cout << "nilai: " << *localPointer << std::endl; -> akan menampilkan error
    */

    int *staticPointer = returnStaticPointer();
    std::cout << "nilai: " << *staticPointer << std::endl;

    std::cout << "\n";

    Point *p = buatPoint(10, 20);
    std::cout << "Point: (" << p->x << ", " << p->y << ")" << std::endl;

    delete p;

    return 0;
}
