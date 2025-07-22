#include <iostream>

void bubbleSort(int n[], int k)
{
    for (int i = 0; i < k - 1; ++i)
    {
        for (int j = 0; j < k - i - 1; ++j)
        {
            if (n[j] > n[j + 1])
            {
                int temp = n[j];
                n[j] = n[j + 1];
                n[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n[5] = {5, 2, 3, 4, 1};
    int k = sizeof(n) / sizeof(n[0]);
    bubbleSort(n, k);

    for (int i = 0; i < k; ++i)
    {
        std::cout << n[i] << " ";
    }

    return 0;
}