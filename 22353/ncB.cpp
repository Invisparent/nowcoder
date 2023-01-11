// https://ac.nowcoder.com/acm/contest/22353/B
// 完全平方数

#include <iostream>
#include <cmath>

int main() {
    int a, b;
    std::cin >> a;
    int c, d;
    while (std::cin >> a >> b) {
        c = static_cast<int>(sqrt(a));
        d = static_cast<int>(sqrt(b));
        std::cout << d - c + (c * c == a) << std::endl;
    }
    return 0;
}
