/*
static member function adalah fungsi anggota dari class yang:
1. Tidak terikat ke objek tertentu
2. Dapat dipanggil tanpa membuat objek class
3. Hanya bisa mengakses member yanh juga static
4. Tidak punya akses ke this
5. Berguna untuk utilitas

*/

#include <iostream>

class HitungObjek
{
private:
    static int hitung_objek;

public:
    HitungObjek()
    {
        ++hitung_objek;
    }

    ~HitungObjek()
    {
        --hitung_objek;
    }

    static int beriHitungObjek()
    {
        return hitung_objek;
    }
};

int HitungObjek::hitung_objek = 0;

int main()
{
    // 0
    std::cout << "jumlah objek saat ini: " << HitungObjek::beriHitungObjek() << std::endl;

    HitungObjek obj1, obj2;
    // 2
    std::cout << "jumlah objek setelah ini: " << HitungObjek::beriHitungObjek() << std::endl;
    { // 3
        HitungObjek obj3;
        std::cout << "jumlah objek setelah ini: " << HitungObjek::beriHitungObjek() << std::endl;
    }
    // 2
    std::cout << "jumlah objek setelah ini: " << HitungObjek::beriHitungObjek() << std::endl;
    return 0;
}