/*
1. masalah dengan sub array atau substring tetap(fixed size)
2. massalah dengan subarray atau substring dinamis (variables size)
*/

#include <iostream>
#include <climits>

int maxHasilSubArray(int arr[], int n, int k)
{
    int maxHasil = INT_MIN, window_hasil = 0;

    for (int i = 0; i < k; i++)
    {
        window_hasil += arr[i];
    }

    for (int i = k; i < n; i++)
    {
        window_hasil += arr[i] - arr[i - k];
        maxHasil = std::max(maxHasil, window_hasil);
    }
    return maxHasil;
}

int main()
{
    int arr[] = {2, 1, 5, 1, 4, 3, 2, 7};
    int k = 2, n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "max dari subarray dari size " << k << " adalah: " << maxHasilSubArray(arr, n, k) << std::endl;
    /*
    3 + 5 - 2 = 6;
    6 + 1 - 1 = 6;
    6 + 4 - 5 = 5;
    5 + 3 - 1 = 7;
    7 + 2 - 4 = 5;
    5 + 7 - 3 = 9;
    */
    return 0;
}