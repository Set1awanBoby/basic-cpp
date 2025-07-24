#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

std::vector<int> topKFrequent(std::vector<int> &nums, int k)
{
    // jika k sama dengan pajang nums akan langsung mereturn nums tsb
    if (k == nums.size())
    {
        return nums;
    }
    std::unordered_map<int, int> count;
    for (int n : nums)
    {
        // mengisi count dengan menghitung jumlah kemunculan tiap angka dalam nums.
        count[n]++;
    }

    // lambda function untuk custom urutan di priority queue:
    // elemen dengan frekuensi lebih kecil akan berada di atas (min-heap).
    // count[a] > count[b] artinya a dianggap lebih "besar" dari b.
    auto cmp = [&count](int a, int b)
    {
        return count[a] > count[b];
    };

    // membuat min-heap berisi angka dari nums
    // secara default, priority_queue adalah max-heap (elemen terbesar di atas),
    // tapi kita ubah jadi min-heap dengan comparator cmp.
    std::priority_queue<int, std::vector<int>, decltype(cmp)> heap(cmp);

    // loop semua angka yang sudah dihitung frekuensinya.
    for (auto entry : count)
    {
        // heap.push(entry.first) → masukkan angka (bukan frekuensinya).
        heap.push(entry.first);
        // Jika ukuran heap lebih dari k, kita buang elemen paling kecil frekuensinya (heap.pop()).
        if (heap.size() > k)
        {
            heap.pop();
        }
        // hasil akhirnya: heap berisi k angka dengan frekuensi tertinggi.
    }

    // ambil semua angka dari heap dan masukkan ke dalam hasil.
    std::vector<int> ans;
    while (!heap.empty())
    {
        ans.push_back(heap.top());
        heap.pop();
    }

    return ans;
}

int main()
{
    std::vector<int> nums = {4, 1, -1, 2, -1, 2, 3};
    int k = 2;
    std::vector<int> result = topKFrequent(nums, k);

    for (int n : result)
    {
        std::cout << n << " ";
    }

    return 0;
}

/*
Iterasi:
input: nums = {1,1,1,2,2,3}, k = 2

step 1 ->
count = {
    1: 3,
    2: 2,
    3: 1
}

step 2 ->
heap.push(1) → heap = [1]
heap.push(2) → heap = [2,1] (karena frekuensi 2 < 1, jadi 2 di atas)
heap.push(3) → heap = [3,1,2] (ukuran > 2, buang elemen teratas)

Sekarang heap = [1, 2] (angka 1 dan 2 frekuensinya paling tinggi)

step 3 ambil heap ->
ans = []
heap.pop() → 1 → ans = [1]
heap.pop() → 2 → ans = [1, 2]


*/