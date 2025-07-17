/*
Sinyal adalah interupsi yang memaksa OS untuk menghentikan tugas yang
sedang berlangsung dan melanjutkan tugas yang telah menerima interupsi.
Interupsi ini dapat menghentikan layanan di program OS mana pun.

Demikian pula, C++ juga menawarkan berbagai sinyal yang dapat ditangkap
dan diproses dalam program. Setiap sinyal memiliki perilaku default-nya sendiri.

Program di atas mencetak pernyataan tersebut secara terus-menerus.
Ketika Anda menekan (Ctrl+C), sinyal SIGINT dihasilkan, dan program pun berakhir.

Berikut adalah daftar berbagai sinyal bermanfaat dan operasinya yang
disediakan C++ bagi pengguna.

- SIGABRT -> Penghentian abnormal dipicu oleh fungsi abort()
- SIGFPE -> Pengecualian titik mengambang (misalnya, pembagian dengan nol atau luapan)
- SIGILL -> Instruksi ilegal, biasanya disebabkan oleh instruksi mesin yang tidak valid
- SIGINT -> Sinyal interupsi dikirim saat CTRL + C ditekan oleh pengguna
- SIGSEGV -> Kesalahan segmentasi disebabkan oleh akses memori dengan cara yang tidak valid
- SIGTERM -> Permintaan penghentian dikirim melalui kill atau metode lainnya
- SIGKILL -> Sinyal mematikan untuk penghentian paksa suatu proses
- SIGQUIT -> Sinyal keluar (mirip dengan SIGINT tetapi menyebabkan pembuangan inti).
- SIGCHLD -> Proses anak diakhiri atau dihentikan.
- SIGSTOP -> Sinyal berhenti yang menghentikan proses. Sinyal ini tidak dapat ditangkap atau diabaikan.
- SIGSYS -> Panggilan sistem salah (panggilan sistem tidak valid dipanggil).
- SIGUSR1 -> Sinyal yang ditentukan pengguna 1, tersedia untuk penggunaan aplikasi

*/

#include <iostream>
#include <csignal>
#include <cstdlib>

void sinyalHandler(int angkaSignal)
{
    std::cout << "sinyal interrupt " << angkaSignal << " diterima" << std::endl;
    std::cout << "membersihkan proses" << std::endl;
    std::exit(angkaSignal);
};

int main()
{
    /*
    std::signal(SIGINT, sinyalHandler);
    std::cout << "gunakan perintah ctrl + c untuk trigger si SIGINT" << std::endl;

    while (true)
    {
    };
    */
    /*
    std::signal(SIGINT, sinyalHandler);
    std::cout << "ngeraise SIGTERM sinyal" << std::endl;
    std::raise(SIGTERM);
    std::cout << "program tetap berjalan setelah sinyal handling" << std::endl;
   */
    std::signal(SIGFPE, sinyalHandler);
    int a = 10, b = 0;

    std::cout << "coba bagikan angka 10 dan 0" << std::endl;
    int hasil = a / b;
    std::cout << hasil << std::endl;
    return 0;
}
