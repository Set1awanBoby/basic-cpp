/*
header <ctime> :
- time_t -> tipe data untuk menyimpan waktu dalam bentuk epoch (detik sejak 1 Jan 1970).
- time() -> mengambil waktu sekarang (epoch time).
- localtime() -> mengubah time_t menjadi waktu lokal (struct tm).
- gmtime() -> mengubah time_t menjadi waktu UTC.
- strftime() -> memformat waktu menjadi string.
- difftime() ->  menghitung selisih waktu dalam detik.
- asctime() -> mengubah struktur tm, yang mewakili waktu yang dipecah
            (misalnya, tahun, bulan, hari, jam, menit, detik),
            menjadi string gaya C yang dapat dibaca manusia

format strftime:
%d -> Hari (01-31)
%m -> Bulan (01-12)
%Y -> Tahun (4 digit)
%H -> Jam (00-23)
%M -> Menit (00-59)
%S -> Detik (00-59)
%A -> Nama hari penuh
%B -> Nama bulan penuh

header <chrono> :
Waktu sekarang -> std::chrono::system_clock::now()
Durasi -> std::chrono::duration
std::chrono::time_point
*/

#include <iostream>
#include <ctime>
#include <chrono>

int main()
{
    time_t tanggalSekarang = time(0);
    std::tm *waktuLokal = localtime(&tanggalSekarang);

    std::cout << "waktu sekarang adalah: " << asctime(waktuLokal);
    std::cout << "Tahun " << 1900 + waktuLokal->tm_year << std::endl;
    std::cout << "Bulan " << 1 + waktuLokal->tm_mon << std::endl;
    std::cout << "Hari " << waktuLokal->tm_mday << std::endl;
    std::cout << "Jam " << waktuLokal->tm_hour << std::endl;
    std::cout << "Menit " << waktuLokal->tm_min << std::endl;
    std::cout << "Detik " << waktuLokal->tm_sec << std::endl;
    std::cout << "\n";

    char bufferKata[80];
    std::strftime(bufferKata, 80, "%d-%m-%Y %H:%M:%S", waktuLokal);

    std::cout << "tanggal yang sudah diformat: " << bufferKata << std::endl;
    std::cout << "\n";

    std::chrono::system_clock::time_point sekarang = std::chrono::system_clock::now();

    time_t waktuSekarang = std::chrono::system_clock::to_time_t(sekarang);
    std::cout << "waktu sekarang adalah: " << std::ctime(&waktuSekarang);
    return 0;
}