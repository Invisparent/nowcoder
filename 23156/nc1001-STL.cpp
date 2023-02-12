// https://ac.nowcoder.com/acm/contest/23156/1001
// 老子的全排列呢

// Multiple Solutions
// STL

// 想不到吧，劳资有STL

#include <iostream>
#include <string>
#include <algorithm>

inline void printStr(const std::string &str) {
    for (int t = 0; t < 8; ++t) {
        putchar(str[t]);
        if (t != 7)
            putchar(' ');
    }
    putchar('\n');
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string str = "12345678";
    printStr(str);
    while (std::next_permutation(str.begin(), str.end()))
        printStr(str);
    return 0;
}
