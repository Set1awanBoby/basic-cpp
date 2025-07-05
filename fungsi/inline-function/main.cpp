/*
Fungsi inline adalah fungsi yang diberi petunjuk kepada kompilator
agar kode fungsi langsung disisipkan (di-expand) ke tempat fungsi dipanggil,
alih-alih melakukan call.

- Menghindari overhead dari pemanggilan fungsi
- Lebih efisien untuk fungsi-fungsi kecil yang sering dipanggil

Note:
- inline hanyalah saran — kompilator boleh mengabaikannya jika dianggap tidak efisien.
- Tidak cocok untuk fungsi besar karena bisa membuat ukuran binary membengkak

Analogi:
Fungsi normal: Kamu menulis satu paragraf dan bilang "lihat halaman 10".
Fungsi inline: Kamu menyalin isi halaman 10 langsung ke posisi sekarang.

*/

#include <iostream>

inline int tambah(int a, int b)
{
    return a + b;
}

// fungsi di dalam class termasuk inline function
class Hitung
{
private:
    int nilai1, nilai2;

public:
    Hitung(int a, int b) : nilai1(a), nilai2(b) {};

    int tambah()
    {
        return nilai1 + nilai2;
    }
};

class Lingkaran
{
private:
    double rad;

public:
    Lingkaran(double r) : rad(r) {}

    void setRad(double r) // -> setter
    {
        rad = r;
    }

    double kalkulasiRadius() const // -> getter
    {
        return rad;
    }

    double kalkulasi() const
    {
        return 3.14159 * rad * rad;
    }
};

int main()
{
    int a = 5, b = 10;
    std::cout << tambah(a, b) << std::endl;
    std::cout << "\n";

    Hitung tambah1(50, 50);
    std::cout << tambah1.tambah() << std::endl;
    std::cout << "\n";

    Lingkaran l(5.0);
    std::cout << l.kalkulasiRadius() << std::endl;
    std::cout << l.kalkulasi() << std::endl;

    return 0;
}