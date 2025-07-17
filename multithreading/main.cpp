/*
Multithreading adalah teknik di mana program dibagi menjadi unit-unit eksekusi
yang lebih kecil yang disebut thread. Setiap thread berjalan secara independen
tetapi berbagi sumber daya seperti memori, sehingga tugas-tugas dapat dilakukan
secara bersamaan. Hal ini membantu meningkatkan kinerja dengan memanfaatkan
beberapa inti CPU secara efisien. Dukungan multithreading diperkenalkan
di C++11 dengan diperkenalkannya berkas header <thread>.

*/
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <vector>

void show1()
{
    std::cout << "Hello ini pake threading" << std::endl;
};

void show2(int jumlah, const std::string &pesan)
{
    for (int i = 0; i < jumlah; ++i)
    {
        std::cout << pesan << std::endl;
    }
};

void delay()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Print setelah 2 detik" << std::endl;
}

void hasilPerThread(const std::vector<int> &vec, int start, int end, int &hasil)
{
    hasil = 0;
    for (int i = start; i < end; ++i)
    {
        hasil += vec[i];
    }
};

int main()
{
    std::thread t(show1);
    t.join();
    std::cout << "Hello ini dari main thread" << std::endl;

    std::cout << "\n";

    std::thread thread_kita(show2, 5, "ini kata dari threading");
    thread_kita.join();

    std::cout << "\n";

    std::thread thread_anonym([]()
                              { std::cout << "ini adalah output dari fungsi anonymus" << std::endl; });

    thread_anonym.join();

    std::cout << "\n";

    std::thread thread_delay(delay);
    thread_delay.join();

    std::cout << "\n";

    std::vector<int> vec(1000000, 1);

    int hasil1 = 0, hasil2 = 0;
    std::thread thread1(hasilPerThread, std::cref(vec), 0, vec.size() / 2, std::ref(hasil1));
    std::thread thread2(hasilPerThread, std::cref(vec), vec.size() / 2, vec.size(), std::ref(hasil2));

    thread1.join();
    thread2.join();

    int hasilSemua = hasil1 + hasil2;
    std::cout << "Hasil: " << hasilSemua << std::endl;
    return 0;
}