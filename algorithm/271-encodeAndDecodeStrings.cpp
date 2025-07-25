#include <iostream>
#include <string>
#include <vector>

/*
encode -> menggabungkan vector of strings menjadi satu string
(dengan delimiter unik).

decode -> memisahkan string tersebut kembali menjadi vector of strings

teknik ini sering digunakan di soal "Encode dan Decode Strings"
*/

std::string encode(std::vector<std::string> &strs)
{
    // jika vector kosong, return karakter 258 sebagai penanda "list kosong";
    if (strs.empty())
    {
        return std::string(1, (char)258);
    }

    // gunakan karakter 257 sebagai delimiter antar string
    // (anggap karakter ini tidak pernah ada diinput)
    char separate = (char)257;
    std::string sb;

    // gabungkan setiap string di vector strs,
    // dan tambahkan delimiter setelahnya
    for (std::string s : strs)
    {
        sb += s;
        sb += separate;
    }

    // hapus delimiter terakhir
    // (karena setelah string terakhir tidak butuh seperator lagi)
    sb.pop_back();
    return sb;
}

std::vector<std::string> decode(std::string s)
{
    // jika string s adalah karakter 258, berarti itu adalah tanda khusus list konsong
    // -> return vector kosong.
    if (s == std::string(1, (char)258))
    {
        return std::vector<std::string>{};
    }

    // inisialisasi vector hasil dan string
    char separate = (char)257;
    std::vector<std::string> result;
    // current untuk membangun kata perkata
    std::string current;

    for (char c : s)
    {
        // jika karakter adalah delimiter
        // -> push current ke hasil dan reset current
        if (c == separate)
        {
            result.push_back(current);
            current.clear();
        }
        // jika bukan -> tambahkan ke current
        else
        {
            current += c;
        }
    }
    // setelah loop selesai jangan lupa push string terakhir
    result.push_back(current);

    return result;
}

int main()
{
    // vector dari strings
    std::vector<std::string> strs = {"Hello", "World", "!"};

    // gabungakan vector menjadi satu strings
    std::string encoded = encode(strs);
    std::cout << "Encoded String: ";
    for (auto c : encoded)
    {
        if (c == (char)257)
        {
            std::cout << "[257]";
        }
        else if (c == (char)258)
        {
            std::cout << "[258]";
        }
        else
        {
            std::cout << c;
        }
    }
    std::cout << "\n";

    // pisahkan kembali menjadi vector strings
    std::vector<std::string> decoded = decode(encoded);

    // print hasil decode
    std::cout << "Decoded Strings: \n";
    for (auto str : decoded)
    {
        std::cout << str << '\n';
    }

    return 0;
}