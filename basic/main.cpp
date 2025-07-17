#include <iostream>

int main()
{
    // cout adalah charachter output
    std::cout << "Hello World" << std::endl;

    // konstan literal :
    std::cout << "2.71828" << std::endl;       // 2.71828
    std::cout << "2" << std::endl;             // 2
    std::cout << 'a' << std::endl;             // a
    std::cout << "boby ganteng" << std::endl;  // boby ganteng
    std::cout << true << std::endl;            // 1
    std::cout << false << std::endl;           // 0
    std::cout << "boby\nganteng" << std::endl; // boby
                                               // ganteng
    std::cout << nullptr << std::endl;         // nullptr, 0

    /*
    keyword:
        1. control keyword
            => if, else, while, for, do, switch, case, default
        2. operator keyword
            => new, delete, sizeof
        3. access specifier
            => public, private, protected
        4. exception handling
            => try, catch, throw
        5. function modifiers
            => inline, virtual, override
    */
    return 0; // program selesai
}