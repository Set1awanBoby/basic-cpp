#include <iostream>
#include <string>

bool isAnagram(std::string s, std::string t)
{
    // jika panjang berbeda langsung mereturn false
    if (s.length() != t.length())
    {
        return 0;
    }
    // membuat sebuah array untuk 26 huruf a-z
    // default nya 0 pada 26 huruf pada array
    int charCount[26]{}; // anggap hanya ada lowercase

    // menambahkan satu-persatu jumlah char di 's' dan mengurangi satu-persatu pada 't'
    for (int i = 0; i < s.length(); ++i)
    {
        // akan mengubah karakter menjadi indeks (misalnya 'a' jadi 0, 'b' jadi 1, dst).
        charCount[s.at(i) - 'a']++;
        charCount[t.at(i) - 'a']--;
    }

    // Jika ada satu pun karakter yang jumlahnya tidak nol, berarti s dan t bukan anagram.
    for (int count : charCount)
    {

        if (count != 0)
        {
            return 0;
        }
    }
    std::cout << "\n";
    return 1; // semua count nol, jadi 't' adalah sebuah anagram dari 's'
}

int main()
{
    std::string s = "anagram";
    std::string t = "nagaram";

    if (isAnagram(s, t))
    {
        std::cout << "t merupakan anagram dari s" << std::endl;
    }
    else
    {
        std::cout << "t bukan anagram dari s" << std::endl;
    }

    return 0;
}

/*
iterasi ke-0 ->
charCount[0]++;  // karena s[0] = 'a' -> index 0 = 1
charCount[13]--; // karena t[0] = 'n' -> index 13 = -1

iterasi ke-1 ->
charCount[13]++; // tambah 1 karena 'n' dari s -> index 13 = -1 + 1 = 0
charCount[0]--;  // kurangi 1 karena 'a' dari t -> index 0 = 1 - 1 = 0

iterasi ke-2 ->
charCount[0]++;  // huruf 'a' dari s -> index 0 = 0 + 1 = 1
charCount[6]--;  // huruf 'g' dari t -> index 6 = -1

iterasi ke-3 ->
charCount[6]++; // huruf 'g' dari s -> index 6 = -1 + 1 = 0
charCount[0]--; // huruf 'a' dari t -> index 0 = 1 - 1 = 0

iterasi ke-4 ->
charCount[17]++; // huruf 'r' dari s
charCount[17]--; // huruf 'r' dari t
-> karena sama sudah pasti 0 index 17 = 1 - 1 = 0

iterasi ke-5
charCount[0]++;
charCount[0]--;
-> karena index 0 sudah 0 maka sudah pasti 0

iterasi ke-6
charCount[12]++;
charCount[12]--;
-> sudah pasti 0
*/