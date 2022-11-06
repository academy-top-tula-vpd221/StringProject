#include <iostream>
#include "String.h"

int main()
{
    String s = "Hello";
    std::cout << s << "\n";

    String s1 = " world";

    s += s1;
    std::cout << s << "\n";

    s += " and people";
    std::cout << s << "\n";
    
    s += '!';
    std::cout << s << "\n";
}
