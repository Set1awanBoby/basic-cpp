/*
Union adalah tipe data yang berisi sekumpulan variabel yang dibungkus
jadi satu dan memiliki alamat memori yang sama.

Union sebenarnya mirip seperti struct dan class.
Namun berbeda dalam cara memberikan alamat memori.

Mengapa kita membutuhkan union?

Misalnya kita akan membuat game, lalu ingin menyimpan data senjata yang dimiliki pemain.
Anggap saja pemain punya dua senjata, yakni: pistol dan pisau.

struct Senjata
{
    string nama;
    int jumlah_peluru;
    int ketajaman;
};
/*
Perhatikan variabel jumlah_peluru dan ketajaman. Variabel ini dibutuhkan masing-masing jenis senjata.
Pistol membutuhkan jumlah_peluru dan pisau membutuhkan ketajaman.

Jika pemain cuma punya pistol, berarti variabel ketajaman akan sia-sia. Begitu sebaliknya.
Nah biar tidak sia-sia, kita harus menyimpan variabel jumlah_peluru dan ketajaman dalam satu alamat memori.

struct Senjata
{
    string nama;
    union
    {
        int jumlah_peluru;
        int ketajaman;
    }
};

Dengan begini, variabel jumlah_peluru dan ketajaman akan menggunakan satu alamat memori yang sama.
Ini tentunya akan lebih efisien.
*/

#include <iostream>
#include <string>

struct Notification
{
    enum
    {
        EMAIL,
        SMS
    } type;
    std::string title;
    std::string message;
    union
    {
        char *phone_number;
        char *email_address;
    };
};

int main()
{
    Notification sms = {
        Notification::SMS,
        "Greetings",
        "Selamat pagi mas",
        "08123456789"};

    Notification email = {
        .type = Notification::EMAIL,
        .title = "Bill",
        .message = "Tolong bayar utang anda mas",
        .email_address = "bobyganteng@example.com"};

    // menampilkan pesan
    std::cout << "=-=-=Notification SMS=-=-=" << std::endl;
    std::cout << "to: " << sms.phone_number << std::endl;
    std::cout << "message: " << sms.message << std::endl;

    std::cout << "\n";

    std::cout << "=-=-=Notification EMAIL=-=-=" << std::endl;
    std::cout << "to: " << email.email_address << std::endl;
    std::cout << "message: " << email.message << std::endl;

    return 0;
}
