#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

long long a1, b1, c1;
long long a2, b2, c2;

inline bool f1(long long x, long long y) {
    return a1 * x + b1 * y + c1 > 0;
}

inline bool f2(long long x, long long y) {
    return a2 * x + b2 * y + c2 > 0;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int tt;
    std::cin >> tt >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    std::array<long long, 4> data{};
    long long a, b;
    for (int t = 0; t < tt; ++t) {
        std::cin >> a >> b;
        bool res1 = f1(a, b);
        bool res2 = f2(a, b);
        if (res1 && res2)
            ++data[0];
        else if ((!res1) && (!res2))
            ++data[1];
        else if (res1)
            ++data[2];
        else
            ++data[3];
    }

    std::sort(data.begin(), data.end());

    std::for_each(data.begin(), data.end(), [](const auto &x) {
        std::cout << x << ' ';
    });

    return 0;
}
