#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <array>
#include <sstream>
/*
std::stringstream adalah bagian dari library <sstream>.
Ini adalah kelas stream (mirip seperti cin dan cout) tetapi digunakan
untuk menulis dan membaca string seolah-olah itu adalah stream data.

Bayangkan stringstream seperti "wadah" yang bisa kamu isi dengan berbagai
data (angka, string, dll), lalu hasilnya bisa kamu ambil sebagai sebuah
string lengkap
*/
std::vector<std::vector<std::string>> groupAnagram(std::vector<std::string> &strs)
{
    // jika strs kosong, langsung return array kosong
    if (strs.empty())
    {
        return std::vector<std::vector<std::string>>{};
    }

    std::unordered_map<std::string, std::vector<std::string>> ansMap;

    int count[26]{}; // -> default bernilai 0

    for (std::string s : strs)
    {
        // count berfungsi sebagai counter huruf a–z, karena anagram punya huruf sama.
        std::array<int, 26> count = {};

        for (char c : s)
        {
            // ini menambah jumlah karakter pada array count
            // 'c' - 'a' adalah index huruf ke berapa dari 'a'
            count[c - 'a']++;
        }

        // kunci dibuat dari pola frekuensi.
        // misalnya "eat" hasilnya: #1#0#0#0#1#0...#1... (dari a-z)
        std::stringstream ss;
        for (int i = 0; i < 26; ++i)
        {
            ss << '#' << count[i];
        }

        // dua string yang merupakan anagram akan menghasilkan key yang sama.
        std::string key = ss.str();

        // masukan string kedalam map dengan kunci hasil frekuensi
        ansMap[key].push_back(s);
        // jika key sudah ada, langsung .push_back() ke vector nya
    }

    // ambil semua grup string dari map lalu masukan ke hasil akhir result
    std::vector<std::vector<std::string>> result;
    for (auto entry : ansMap)
    {
        result.push_back(std::move(entry.second));
    }

    return result;
}

int main()
{
    std::vector<std::string> anagram = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> result = groupAnagram(anagram);

    for (auto group : result)
    {
        std::cout << "[ ";
        for (auto word : group)
        {
            std::cout << word << " ";
        }
        std::cout << "]";
    }

    return 0;
}

/*
iterasi ke-1 ->
s = "eat"
count -> a = 1, e = 1, t = 1
key ->#1#0#0#0#1.....#1
ansMap[key] -> ["eat"]

iterasi ke-2 ->
s = "tea"
count sama seperti "eat"
key sama
ansMap[key] -> ["eat","tea"]

iterasi ke-3:
s = "tan"
count → a=1, n=1, t=1
key beda → ansMap[key] = ["tan"]

iterasi ke-4:
s = "ate"
key sama seperti "eat"
ansMap[key] → ["eat", "tea", "ate"]

iterasi ke-5:
s = "nat"
key sama seperti "tan"
ansMap → ["tan", "nat"]

iterasi ke-6:
s = "bat"
key baru → ["bat"]
*/