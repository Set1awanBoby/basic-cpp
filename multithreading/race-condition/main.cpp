/*
Ketika 2 thread dijalankan secara bersamaan mengakses sumber daya bersama
dengan cara yang secara tidak sengaja menghasilkan hasil yang berbeda,
bergantung pada pengaturan waktu thread atau proses, hal ini menimbulkan
Race Condition
*/
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

int hitung = 0;
std::mutex mtx;
// Kelas std::mutex adalah primitif sinkronisasi yang menyediakan
// mekanisme penguncian yang dapat digunakan untuk melindungi data bersama
// agar tidak diakses secara bersamaan oleh beberapa thread.

void hasilHitung(int iterasi)
{
    for (int i = 0; i < iterasi; ++i)
    {
        std::lock_guard<std::mutex> lock(mtx);
        ++hitung;
    }
};

int main()
{

    std::thread thread1(hasilHitung, 1000000);
    std::thread thread2(hasilHitung, 1000000);

    thread1.join();
    thread2.join();

    std::cout << "hasil: " << hitung << std::endl;
    // jika tidak menggunakan mutex akan menghasilkan hasil yang tidak pasti

    return 0;
}