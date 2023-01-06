// https://ac.nowcoder.com/acm/contest/21763/1001

#include <iostream>
#include <string>

inline int calculate(int n) {
    if (n < 10)
        return n;
    std::string s = std::to_string(n);
    int r = 0;
    for (const char &ch: s)
        r += ch - '0';
    return calculate(r);
}

int main() {
    int n;
    std::cin >> n;
    std::cout << calculate(n);
    return 0;
}
