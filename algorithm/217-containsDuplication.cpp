#include <iostream>
#include <vector>
#include <unordered_set>
/*
Dalam C++, unordered_set adalah kontainer asosiatif tak berurutan yang
menyimpan elemen-elemen unik. Tidak seperti set, kontainer ini menyimpan
elemen-elemennya menggunakan hashing. Hal ini menyediakan operasi pencarian,
penyisipan, dan penghapusan rata-rata waktu konstan O(1), tetapi elemen-elemennya
tidak diurutkan dalam urutan tertentu.
*/

// menggunakan fungsi bool karena akan mengembalikan nilai true atau false yang akan digunakan
bool containsDuplicate(std::vector<int> &nums)
{
    std::unordered_set<int> seenNum;
    for (int num : nums)
    {

        // cek apakah num sudah pernah dimasukan kedalam set
        if (seenNum.find(num) != seenNum.end())
        {
            // -> {1}
            return 1; // Jika ditemukan, maka true dikembalikan.
        }

        seenNum.insert(num); // set kedalam unordered_set
        // -> {1, 2, 3, 4}
    }

    return 0; // Jika loop selesai tanpa menemukan duplikat, maka false dikembalikan.
}

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 1};

    if (containsDuplicate(nums))
    {
        std::cout << "Ada duplikasi\n";
    }
    else
    {
        std::cout << "Tidak ada duplikasi\n";
    }

    return 0;
}

/*
Iterasi 1: num = 1
    find(1) → tidak ditemukan → lanjut
    insert(1) → set jadi {1}

Iterasi 2: num = 2
    find(2) → tidak ditemukan → lanjut
    insert(2) → set jadi {1, 2}

Iterasi 3: num = 3
    find(3) → tidak ditemukan → lanjut
    insert(3) → set jadi {1, 2, 3}

Iterasi 4: num = 4
    find(4) → tidak ditemukan → lanjut
    insert(4) → set jadi {1, 2, 3, 4}

Iterasi 5: num = 1
    find(1) → ditemukan! → return true
*/