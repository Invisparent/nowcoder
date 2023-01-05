#include <iostream>
#include <string>

std::string maxLexSubstr(std::string::const_iterator iterA, std::string::const_iterator iterB) {
    if (iterA == iterB)
        return {};
    auto traverseIter = iterA, maxIter = iterA;
    char maxChar = *traverseIter;
    while (traverseIter != iterB) {
        if (*traverseIter > maxChar) {
            maxChar = *traverseIter;
            maxIter = traverseIter;
        }
        ++traverseIter;
    }
    return maxChar + maxLexSubstr(maxIter + 1, iterB);
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::cout << maxLexSubstr(s.cbegin(), s.cend());
    return 0;
}
