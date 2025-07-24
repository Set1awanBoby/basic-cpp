#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(std::vector<int> &nums)
{
    // inisialisasi result dengan nilai awal 1, supaya bisa dikali langsung.
    std::vector<int> result(nums.size(), 1);

    int pre = 1,  // pre: prefix product (hasil kali angka sebelah kiri index)
        post = 1; // post: postfix product (hasil kali angka sebelah kanan index)

    // prefix (kiri ke kanan)
    for (int i = 0; i < nums.size(); ++i)
    {
        result[i] = pre;
        pre = nums[i] * pre;
    }

    // postfix (kanan ke kiri)
    for (int i = nums.size() - 1; i >= 0; --i)
    {
        result[i] = result[i] * post;
        post = post * nums[i];
    }

    // kembalikan nilai result
    return result;
};

int main()
{
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> result = productExceptSelf(nums);

    for (int n : result)
    {
        std::cout << n << " ";
    }

    return 0;
}

/*
prefix ->
    i = 0 ->
    result[0] = 1;
    pre = 1 * 1; pre = 1;

    i = 1 ->
    result[1] = 1;
    pre = 2 * 1; pre = 2;

    i = 2 ->
    result[2] = 2;
    pre = 3 * 2; pre = 6;

    i = 3 ->
    result[3] = 6;

postfix ->
    i = 3 ->
    result[3] = 6 * 1; result[3] = 6;
    post = 1 * 4; post = 4;

    i = 2 ->
    result[2] = 2 * 4; result[2] = 8;
    post = 4 * 3; post = 12;

    i = 1 ->
    result[1] = 1 * 12; result[1] = 12;
    post = 12 * 2; post = 24;

    i = 0 ->
    result[0] = 1 * 24; result[0] = 24;

kembailikan result = {24, 12, 8, 6};
*/