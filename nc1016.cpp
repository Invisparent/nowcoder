#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    if ((s.back() - '0') % 2)
        std::cout << -1;
    else
        std::cout << 1;
    return 0;
}
