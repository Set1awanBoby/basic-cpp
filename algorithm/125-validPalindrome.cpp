#include <iostream>
#include <string>
#include <cctype> // untuk isalnum dan tolower

/*
isalnum -> true jika mengandung a-z, A-Z, 0-9
        -> false jika mengandung spasi, koma, dan simbol simbol
tolower -> mengubah kapital menjadi lowercase/huruf kecil
*/
bool isPalindrome(std::string s)
{
    int left{0}, right = s.size() - 1;

    while (left < right)
    {
        // Skip non-alphanumeric characters from left
        if (!std::isalnum(s[left]))
        {
            left++;
            continue;
        }
        // Skip non-alphanumeric characters from right
        else if (!std::isalnum(s[right]))
        {
            right--;
            continue;
        }

        // Compare characters (ignoring case)
        else if (std::tolower(s[left]) != std::tolower(s[right]))
        {
            return false;
        }

        left++;
        right--;
    }
    return true;
}

int main()
{
    std::string s = "A-b:A";
    if (isPalindrome(s))
    {
        std::cout << "valid" << std::endl;
    }
    else
    {
        std::cout << "invalid" << std::endl;
    }
    return 0;
}

/*
s = "A-b:A";
iterasi ke-1 ->
left 0; Right 4
s[0] = 'A'; s[4] = 'A'
isalnum(left) -> true; isalnum(right) -> true
tolower(left) 'a'; tolower(right) 'a';
match -> Yes
left++; right--;

iterasi ke-2 ->
left = 1; right = 3
s[1] = '-'; s[3] = ':';
isalnum(left) -> false; isalnum(right) -> false
-
-
left++; skip '-'

iterasi ke-3 ->
left = 2; right = 3;
s[2] = 'b'; s[3] = ':';
isalnum(left) -> true; isalnum(right) -> false
tolower(left) 'b'; -
-
right--; skip ':'

iterasi ke-4 ->
left = 2; right = 2;
s[2] = 'b'' s[2] = 'b';
isalnum(left) -> true; isalnum(right) -> true
tolower(left) 'b'; tolower(right) 'b';
match -> Yes
left++; right--

left = 3; right = 2
loop stop -> left > right;


*/