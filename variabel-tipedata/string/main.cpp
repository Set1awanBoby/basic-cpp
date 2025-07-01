/*
metode lama: char nama[] = "boby"
metode baru: std::string nama = "boby"

*/

#include <iostream>
#include <string>

int main()
{
    std::string kata = "boby ganteng bgt";
    std::cout << kata[5] << std::endl;

    // menggabungkan string
    // + / append();
    std::string port = "5000";
    std::string http = "http://localhost:";
    std::string url_1 = http + port;
    std::string url_2 = http.append(port);

    std::cout << url_1 << std::endl;
    std::cout << url_2 << std::endl;

    // memotong string
    // substr(awal(index), panjang(length string dari index awal));
    std::string potong = kata.substr(5, 11);
    std::cout << potong << std::endl;
    // boby ganteng bgt
    // ganteng bgt -> g = 5 panjang = 11 (di hitung dari g mulai dari 1)

    // mencari posisi kata
    // find(kata);

    size_t pos = kata.find("bgt");
    std::cout << pos << std::endl; // b -> index ke 13

    // mengganti sebuah kata
    // replace(index, panjang, "kata baru");

    std::string kata_baru = kata.replace(5, 11, "byutipul");
    std::cout << kata_baru << std::endl;

    // komparasi string
    // ==, !=, <, >, <=, >=
    // compare();

    std::string kata1 = "boby ganteng";
    std::string kata2 = "boby ganteng";
    std::string kata3 = "boby keren";

    if (kata1 == kata2) // true
    {
        std::cout << "kata sama" << std::endl;
        std::cout << "panjang kata sama" << std::endl;
    }

    else // false
    {
        std::cout << "kata tidak sama" << std::endl;
        std::cout << "panjang kata tidak sama" << std::endl;
    }

    // compare() ->  0 = sama, -1 = lebih kecil, 1 = lebih besar

    int hasil1 = kata1.compare(kata2);
    int hasil2 = kata1.compare(kata3);
    std::cout << hasil1 << std::endl; // 0
    std::cout << hasil2 << std::endl; // -1

    return 0;
}