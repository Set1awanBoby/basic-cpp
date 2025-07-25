#include <iostream>
#include <vector>
#include <utility>

std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;

    // looping sampai left lebih besar dari right
    while (left < right)
    {
        // jika angka yang dijumlahkan lebih besar dari target
        // right di kurangi 1;
        if (nums[left] + nums[right] > target)
        {
            right--;
        }
        // jika angka yang dijumlahkan lebih kecil dari target
        // left di tambah 1;
        else if (nums[left] + nums[right] < target)
        {
            left++;
        }
        // jika mencapai target akan mereturn array dari index
        // dan langsung di tambah 1
        else
        {
            return std::vector<int>{++left, ++right};
        }
    }
    // jika left sudah lebih besar dari right dan tidak ada hasil
    // akan mereturn null
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
    return 0;
}