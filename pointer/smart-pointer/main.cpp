/*
Smart Pointer adalah kelas pembungkus di atas pointer yang bertindak
sebagai pointer tetapi secara otomatis mengelola memori yang ditunjuknya.
Kelas ini memastikan bahwa memori didealokasi dengan benar ketika
tidak lagi dibutuhkan, sehingga mencegah kebocoran memori.
Kelas ini merupakan bagian dari berkas header <memory>.

Smart pointer diimplementasikan sebagai templat sehingga
kita dapat membuat smart pointer ke semua jenis memori.

- std::auto_ptr -> auto_ptr adalah smart pointer yang secara otomatis
        mengelola masa pakai objek yang dialokasikan secara dinamis.
        pointer ini mengambil alih kepemilikan objek yang ditunjuknya,
        memastikan objek tersebut dihapus secara otomatis ketika auto_ptr
        keluar dari cakupan.

- std::unique_ptr -> unique_ptr hanya menyimpan satu pointer pada satu waktu.
        Kita tidak dapat menyalin unique_ptr, hanya mentransfer kepemilikan objek
        ke unique_ptr lain menggunakan metode move().

- std::shared_ptr -> Dengan menggunakan shared_ptr, lebih dari satu pointer
        dapat menunjuk ke objek yang sama pada satu waktu, dan akan
        mempertahankan penghitung referensi menggunakan metode use_count().

- std::weak_ptr -> weak_ptr adalah smart pointer yang menyimpan referensi
        non-kepemilikan ke suatu objek. Ini jauh lebih mirip dengan shared_ptr,
        tetapi tidak akan menyimpan penghitung referensi. Dalam hal ini,
        pointer tidak akan memiliki basis kepemilikan pada objek tersebut.
        Alasannya adalah untuk menghindari ketergantungan melingkar yang disebabkan
        oleh dua atau lebih objek yang saling menunjuk menggunakan shared_ptr.
*/
#include <iostream>
#include <memory>
#include <string>

class Rectangle
{
    int length;
    int width;

public:
    Rectangle(int l, int w) : length(l), width(w) {}

    int luas()
    {
        return length * width;
    }
};

class Circle
{
    int rad;

public:
    Circle(int r) : rad(r) {}

    int luas()
    {
        return 3.14 * rad * rad;
    }
};

class Square
{
    int sisi;

public:
    Square(int s) : sisi(s) {}

    int luas()
    {
        return sisi * sisi;
    }
};

class Siswa
{
    std::string nama;

public:
    Siswa(std::string n) : nama(n)
    {
        std::cout << "nama pelajar ditambahkan: " << nama << std::endl;
    }

    ~Siswa()
    {
        std::cout << "info dihapus: " << nama << std::endl;
    }

    void show()
    {
        std::cout << "Nama siswa adalah: " << nama << std::endl;
    }
};

class Node
{
    std::string nama;

public:
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> previous;
    Node(std::string n) : nama(n)
    {
        std::cout << "Node sudah dibuat " << nama << std::endl;
    }

    ~Node()
    {
        std::cout << "Node dari " << nama << " sudah dihancurkan" << std::endl;
    }
};

int main()
{
    // auto_ptr
    /*
    std::auto_ptr<int> ptr1(new int(10));
    std::cout << *ptr1 << std::endl; // -> 10

    std::auto_ptr<int> ptr2 = ptr1;
    std::cout << *ptr2 << std::endl; // -> 10
    std::cout << "\n";
    */

    // unique_ptr
    std::unique_ptr<Rectangle> rectangle1(new Rectangle(10, 5));
    std::cout << rectangle1->luas(); // -> 50
    std::cout << "\n";
    std::unique_ptr<Rectangle> rectangle2;

    rectangle2 = move(rectangle1);
    std::cout << rectangle2->luas(); // -> 50
    std::cout << "\n";
    std::cout << "\n";

    std::unique_ptr<Siswa> siswa1 = std::make_unique<Siswa>("Boby");
    siswa1->show();
    std::unique_ptr<Siswa> siswa2 = std::move(siswa1);
    if (siswa1 == nullptr)
    {
        std::cout << "siswa1 null dipindah ke siswa2" << std::endl;
    }
    siswa2->show();
    std::cout << "\n";

    // shared_ptr
    std::shared_ptr<Circle> circle1(new Circle(7)); // (1)
    std::cout << circle1->luas() << std::endl;      // -> 153

    std::shared_ptr<Circle> circle2; // (2)
    circle2 = circle1;
    std::cout << circle2->luas() << std::endl; // -> 153
    std::cout << circle1->luas() << std::endl; // -> 153
    std::cout << circle1->luas() << std::endl; // -> 153
    std::cout << circle1.use_count();          // -> 2
    std::cout << "\n";
    std::cout << "\n";

    std::shared_ptr<Siswa> siswa_pertama = std::make_shared<Siswa>("Wonyoung");
    {
        std::shared_ptr<Siswa> siswa_kedua = siswa_pertama;
        std::cout << "pembagian shared pointer adalah: " << siswa_pertama.use_count() << std::endl; // 2
        siswa_kedua->show();
    }

    std::cout << "hasil dari shared count sekarang adalah " << siswa_pertama.use_count() << std::endl; // 1
    std::cout << "\n";

    // weak_ptr
    std::shared_ptr<Square> square1(new Square(6));
    std::weak_ptr<Square> square2(square1);
    std::cout << square1->luas() << std::endl;

    std::cout << square2.use_count();
    std::cout << "\n";

    std::shared_ptr<Node> node1 = std::make_shared<Node>("Node_pertama");
    std::shared_ptr<Node> node2 = std::make_unique<Node>("Node_Kedua");

    node1->next = node2;
    node2->previous = node1;
    std::cout << "\n";
    return 0;
}