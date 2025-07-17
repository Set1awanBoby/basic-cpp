/*
Alokasi memori dinamis adalah proses pengalokasian memori saat program dijalankan.
Proses ini memungkinkan programmer untuk memesan sebagian memori selama
eksekusi program, menggunakannya sesuai kebutuhan, dan kemudian mengosongkannya
untuk keperluan lain. Memori ini dialokasikan di memori Heap program,
alih-alih memori Stack. Proses ini sangat berguna dalam kasus-kasus seperti:

- Ketika kamu tidak yakin dengan ukuran array yang kamu butuhkan
- Menerapkan pada data struktur seperti linked list, trees, etc.
- Dalam program yang complex akan membutuhkan memory management yang efisien

new, delete
int *valPoint = new int;
*valPoint = 22;
delete valPoint;

int *arrPoint = new int[5];
delete[] arrPoint;
*/

#include <iostream>

int main()
{
    int *angka = new int;
    *angka = 10;

    std::cout << *angka << std::endl;

    delete angka;
    angka = nullptr;
    std::cout << "\n";

    int ukuran;
    std::cout << "masukan ukuran array: ";
    std::cin >> ukuran;

    int *arrDinamis = new int[ukuran];
    for (int i = 0; i < ukuran; i++)
    {
        arrDinamis[i] = (i + 1) * 10;
    }

    for (int i = 0; i < ukuran; ++i)
    {
        std::cout << arrDinamis[i] << " ";
    }

    delete[] arrDinamis;
    arrDinamis = nullptr;

    return 0;
}
