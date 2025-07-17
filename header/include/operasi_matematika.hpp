#ifndef OPERASI_MATEMATIKA_HPP_
#define OPERASI_MATEMATIKA_HPP_

int tambah(int a, int b);
int kurang(int a, int b);

template <typename T>
T luas_sisi(T sisi)
{
    return sisi * sisi;
};

#endif