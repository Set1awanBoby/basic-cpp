/*
metode lama: char nama[] = "boby"
metode baru: std::string nama = "boby"

*/

#include <iostream>
#include <string>

int main()
{
    std::string kata = "boby ganteng bgt";
    std::cout << kata[0] << std::endl;                    // index ke-0 -> b
    std::cout << kata.length() << std::endl;              // panjang string 16
    std::cout << kata.size() << std::endl;                // panjang string 16
    std::cout << kata[kata.length() - 1] << std::endl;    // index terakhir -> t
    std::cout << kata.at(kata.length() - 1) << std::endl; // index terakhir -> t

    std::cout << "\n";

    // menggabungkan string
    // + / append();
    std::string port = "5000";
    std::string http = "http://localhost:";
    std::string url_1 = http + port;
    std::string url_2 = http.append(port);

    std::cout << url_1 << std::endl;
    std::cout << url_2 << std::endl;

    std::cout << "\n";

    // memotong string
    // substr(awal(index), panjang(length string dari index awal));
    std::string potong = kata.substr(5, 11);
    std::cout << potong << std::endl;
    // boby ganteng bgt
    // ganteng bgt -> g = 5 panjang = 11 (di hitung dari g mulai dari 1)

    std::cout << "\n";

    // mencari posisi kata
    // find(kata);

    size_t pos = kata.find("bgt");
    std::cout << pos << std::endl; // b -> index ke 13

    if (pos != std::string::npos)
    {
        std::cout << pos << std::endl;
    }
    else
    {
        std::cout << "Kata tidak ditemukan" << std::endl;
    }

    std::cout << "\n";
    // mengganti sebuah kata
    // replace(index, panjang, "kata baru");

    std::string kata_baru = kata.replace(5, 11, "byutipul");
    std::cout << kata_baru << std::endl;
    std::cout << "\n";

    // menghapus kata
    std::string kataHello = "hello, world";
    kataHello.erase(5, 7);
    std::cout << kataHello << std::endl;
    std::cout << "\n";

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

    std::cout << "\n";
    // compare() ->  0 = sama, -1 = lebih kecil, 1 = lebih besar

    int hasil1 = kata1.compare(kata2);
    int hasil2 = kata1.compare(kata3);
    std::cout << hasil1 << std::endl; // 0
    std::cout << hasil2 << std::endl; // -1
    std::cout << "\n";

        for (char c : kata1)
    {
        std::cout << c << " "; // -> b o b y  g a n t e n g
    }

    std::cout << "\n";

    // konversi string ke integer
    std::string angkastr = "1234";
    int str_to_num = std::stoi(angkastr);
    std::cout << str_to_num << std::endl;

    // konversi integer ke string
    int angka = 123456;
    std::string num_to_str = std::to_string(angka);
    std::cout << num_to_str + " " + "boby" << std::endl;

    return 0;
}