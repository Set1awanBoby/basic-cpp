#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>

int longestConsecutive(std::vector<int> &nums)
{
    // jika nums empty langsung selesai programnya / keluar
    if (nums.empty())
    {
        return 0;
    }

    std::unordered_set<int> numSet;
    // loop untuk mengisi numSet dengan nums
    for (int i = 0; i < nums.size(); ++i)
    {
        // serta menghapus elemen duplikat
        numSet.insert(nums[i]);
    }

    // inisialisasi longest subsequence dengan 1
    // (karena minimal jika ada angka pasti ada 1 elemen sendiri).
    int longSub = 1;

    // loop semua angka di numSet
    for (int num : numSet)
    {
        // jika num - 1 ada diset, berarti num bukan starting point, jadi diskip
        // cth -> angka 3 -> jika ada angka 2 diset, berarti 3 bukan awal sequence
        if (numSet.count(num - 1))
        {
            continue;
        }
        // jika num adalah starting point (tidak ada num - 1 diset)
        else
        {
            int currentNum = num;
            int currentSub = 1;
            // cek berapa panjang consecutive sequence-nya dengan loop
            // selama currentNum + 1 ada diset
            while (numSet.count(currentNum + 1))
            {
                currentNum++;
                currentSub++;
            }
            // update hasil longSub jika lebih panjang
            longSub = std::max(longSub, currentSub);
        }
    }
    // return hasilnya
    return longSub;
}

int main()
{

    std::vector<int> nums = {100, 4, 200, 1, 3, 2};

    std::cout << longestConsecutive(nums) << std::endl;

    return 0;
}

/*
nums = {100,4,200,1,3,2}
numSet = {100,4,200,1,3,2}

num = 100
    cek apakah numSet punya 99 → tidak ada → ini starting point sequence.
    currentNum = 100, currentSub = 1.
    cek numSet.count(101) → false → sequence stop di sini.
    longSub = max(1, 1) → 1.

num = 4
    cek apakah numSet punya 3 → ada → skip (karena bukan starting point).

num = 200
    cek apakah numSet punya 199 → tidak ada → starting point
    currentNum = 200, currentSub = 1.
    cek numSet.count(201) → false → sequence stop.
    longSub = max(1, 1) → tetap 1.

num = 1
    cek apakah numSet punya 0 → tidak ada → starting point!
    currentNum = 1, currentSub = 1.
    cek numSet.count(2) → true → currentNum = 2 → currentSub = 2.
    cek numSet.count(3) → true → currentNum = 3 → currentSub = 3.
    cek numSet.count(4) → true → currentNum = 4 → currentSub = 4.
    Cek numSet.count(5) → false → stop.
    longSub = max(1, 4) → longSub = 4.

num = 3
    cek apakah numSet punya 2 → ada → skip.

num = 2
    cek apakah numSet punya 1 → ada → skip.

longSub = 4.
sequence terpanjang: {1, 2, 3, 4} → panjangnya 4.
*/