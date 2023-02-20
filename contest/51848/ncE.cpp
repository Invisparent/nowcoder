#include <iostream>
#include <algorithm>

inline void solve() {
    long long a, b;
    std::cin >> a >> b;
    if (a == b) {
        if (a % 3 == 2)
            std::cout << "niuniu\n";
        else
            std::cout << "niumei\n";
        return;
    }
    long long r = std::min(a, b);
    if (r % 3)
        std::cout << "niuniu\n";
    else
        std::cout << "niumei\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int tt;
    std::cin >> tt;
    while (tt--)
        solve();
    return 0;
}
