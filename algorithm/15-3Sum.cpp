#include <iostream>
#include <vector>
#include <algorithm>

/*
Given an integer array nums, return all the triplets
[nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k,
and nums[i] + nums[j] + nums[k] == 0.
*/

// deklarasi fungsi
void twoSum2(std::vector<int> &nums, int i, std::vector<std::vector<int>> &result);

std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    // sorting nums dari kecil ke besar
    std::sort(nums.begin(), nums.end()); // sort array ascending
    std::vector<std::vector<int>> result;

    // loop dari i = 0 sampai nums[i] > 0
    // karena kalau nums[i] > 0, kombinasi triplet berikutnya pasti
    // hasilnya lebih dari 0
    for (int i = 0; i < nums.size() && nums[i] <= 0; ++i)
    {
        // skip duplikat (kalau nums[i] == nums[i - 1], lanjutkan loop)
        if (i == 0 || nums[i] != nums[i - 1])
        {
            // panggil twoSum2() untuk mencari dua angka lagi yang
            // hasilnya -nums[i];
            twoSum2(nums, i, result);
        }
    }
    return result;
}

void twoSum2(std::vector<int> &nums, int i, std::vector<std::vector<int>> &result)
{
    int left = i + 1;            // angka kedua mulai dari i + 1;
    int right = nums.size() - 1; // angka ketiga dari ujung kanan

    while (left < right)
    {
        // hitung jumlah triplet
        int sum = nums[i] + nums[left] + nums[right];
        // jika sum < 0 → kita butuh angka lebih besar → left++
        if (sum < 0)
        {
            left++;
        }
        // jika sum > 0 → kita butuh angka lebih kecil → right--
        else if (sum > 0)
        {
            right--;
        }
        // jika sum == 0 → ketemu triplet → simpan ke result.
        else
        {
            result.push_back({nums[i], nums[left++], nums[right--]});

            // setelah menemukan triplet, skip angka duplicate (biar hasil unik).
            while (left < right && nums[left] == nums[left - 1])
            {
                left++;
            }
            while (left < right && nums[right] == nums[right + 1])
            {
                right--;
            }
        }
    }
}

int main()
{
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> result = threeSum(nums);

    for (auto r : result)
    {
        std::cout << " [ ";
        for (int num : r)
        {
            std::cout << num << " ";
        }

        std::cout << " ] ";
    }

    return 0;
}