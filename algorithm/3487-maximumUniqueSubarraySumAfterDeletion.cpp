#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
#include <functional> // untuk max_element

int maxSum(std::vector<int> &nums)
{
    // jika nums empty akan langsung selesai
    if (nums.empty())
    {
        return 0;
    }
    // maxSum diinisialisasi dengan INT_MIN agar saat
    // seluruh angka di array negatif, nilai terbesar tetap terambil.
    // Contoh: nums = [-20, -5] → harus return -5.
    int maxSum = INT_MIN;

    // memulai subarray dari posisi i.
    for (int i = 0; i < nums.size(); ++i)
    {
        // seen = untuk menyimpan angka unik di subarray yang sedang dibangun
        std::unordered_set<int> seen;
        // currentSum = sum dari subarray yang dimulai di index i
        int currentSum = 0;
        // loop kedua (nested loop) dari j = i hingga akhir array.
        // ini akan mencoba membangun subarray continuous mulai dari index i ke kanan.
        for (int j = i; j < nums.size(); ++j)
        {
            // jika angka di index j negatif, maka anggap angka tersebut
            // "dihapus", dan tidak dimasukkan ke subarray.
            if (nums[j] < 0)
                // kita melewati (skip) angka negatif ini, karena soal memperbolehkan
                // "delete elements".
                continue;
            // Jika angka nums[j] sudah ada di set seen
            //(sudah muncul sebelumnya di subarray ini), artinya ini duplikat.
            if (seen.find(nums[j]) != seen.end())
                // maka kita skip (continue) angka duplikat ini agar
                // subarray yang terpilih hanya berisi angka unik.
                continue;

            // tambahkan angka nums[j] ke set seen (angka unik dalam subarray).
            seen.insert(nums[j]);
            // tambahkan nilai angka tersebut ke currentSum
            currentSum += nums[j];
            // update maxSum jika currentSum sekarang lebih besar dari maxSum sebelumnya.
            maxSum = std::max(maxSum, currentSum);
        }
    }

    // jika semua angka di array negatif, maka maxSum masih INT_MIN.
    if (maxSum == INT_MIN)
    {
        // maka kembalikan elemen terbesar di array sebagai hasil.
        // contoh: nums = [-10, -20] → hasil harus -10
        return *max_element(nums.begin(), nums.end());
    }

    // return nilai maxSum yang sudah dihitung.
    return maxSum;
}

int main()
{
    std::vector<int> numsPositif = {4, 0, 0, 13, 1};
    std::vector<int> numsNegatif = {-100, -200, -20, -10, -3};
    std::vector<int> numsCampur = {2, -1, 3, 2, -5, 4};
    int resultPositif = maxSum(numsPositif);
    int resultNegatif = maxSum(numsNegatif);
    int resultCampur = maxSum(numsCampur);
    std::cout << resultPositif << std::endl;
    std::cout << resultNegatif << std::endl;
    std::cout << resultCampur << std::endl;
    return 0;
}

/*
nums positif ->
{4, 0, 0, 13, 1}

iterasi outer loop (i=0):
    start subarray dari index 0 → nums[0] = 4
    seen = {}
    currentSum = 0
i = 0 ->
j = 0; nums[0] = 4; -> insert 4; seen {4}; currentSum = 4; maxSum = 4
j = 1; nums[1] = 0; -> insert 0; seen {0,4}; currentSum = 4+0; maxSum = 4
j = 2; nums[2] = 0; -> skip duplicate; seen {0,4}; currentSum = 4; maxSum = 4
j = 3; nums[3] = 13; -> skip duplicate; seen {0,4,13}; currentSum = 4+13; maxSum = 17
j = 4; nums[4] = 1; -> skip duplicate; seen {0,1,4,13}; currentSum = 17+1; maxSum = 18

i = 1 ->
j = 1; nums[1] = 0; -> insert 0; seen {0}; currentSum = 0; maxSum = 18;
j = 2; nums[2] = 0; -> skip duplicate; seen {0}; currentSum = 0; maxSum = 18;
j = 3; nums[3] = 13; -> insert(13); seen {0,13}; currentSum = 0+13; maxSum = 18;
j = 3; nums[4] = 1; -> insert(1); seen {0,1,13}; currentSum = 13+1; maxSum = 18;

dst...
i = 4 ->
j = 4; nums[4] = 1; -> insert(1); seen {1}; currentSum = 1; maxSum = 18
maxSum = 18;

nums negatif ->
maxSum tidak akan pernah terupdate dari INT_MIN maka ->
masuk ke if statement
*max_element(nums.begin(), nums.end()) akan mencari angka terbesar.
{-100, -200, -20, -10, -3}
output = -3;

nums campur ->
{2, -1, 3, 2, -5, 4}

iterasi outer loop (i=0):
    start subarray dari index 0 → nums[0] = 2
    seen = {}
    currentSum = 0
i = 0 ->
j = 0; nums[0] = 2; -> insert 2; seen {2}; currentSum = 2; maxSum = 2
j = 1; nums[1] = -1; -> skip negatif; seen {2}; currentSum = 2; maxSum = 2
j = 2; nums[2] = 3; -> insert 3; seen {2,3}; currentSum = 2+3; maxSum = 5
j = 3; nums[3] = 2; -> skip duplicate; seen {2,3}; currentSum = 5; maxSum = 5
j = 4; nums[4] = -5; -> skip negatif; seen {2,3}; currentSum = 5; maxSum = 5
j = 5; nums[5] = 4; -> insert 4; seen {2,3,4}; currentSum = 5+4; maxSum = 9

dst..
i = 5 ->
j = 5; nums[5] = 4; -> insert 4; seen {4}; currentSum = 4; maxSum = 9
maxSum = 9;
*/