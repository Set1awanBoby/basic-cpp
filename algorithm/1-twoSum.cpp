#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    // membuat hashMap untuk menyimpan number dan index
    std::unordered_map<int, int> map;

    // iterasi array dari nums
    for (int i = 0; i < nums.size(); ++i)
    {
        // menghitung complement dari number sekarang
        int complement = target - nums[i];

        // cek jika complement sudah ada di map
        if (map.count(complement))
        {
            // jika menemukan, kembalikan index dari complement dan number sekarang
            return std::vector<int>{map.at(complement), i};
        }

        // jika tidak, tambahkan number sekarang dan index ke map
        map[nums[i]] = i;
    }
    // kembalikan empty array jika tidak ada solusi
    return {};
}

int main()
{
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = twoSum(nums, target);

    for (auto r : result)
    {
        std::cout << r << " ";
    }
    std::cout << '\n';
    for (auto r : result)
    {
        std::cout << nums[r] << " ";
    }

    return 0;
}

/*
iterasi ke-0 ->
complement = 9 - 2 = 7
map.count(7) -> belum ada
map[2] = 0

iterasi ke-1 ->
complement 9 - 7 = 2
map.count(2) -> ada -> map[2] = 0

return {0,1}
0 merupakan isi dari map[2] yaitu 0
dan 1 merupakan iterasi ke-1
*/