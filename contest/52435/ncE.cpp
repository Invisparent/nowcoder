#include <iostream>
#include <vector>

#define IVS_LIM ((long long)1e9)

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long n;
    std::cin >> n;

    std::vector<long long> data(n);
    for (auto t = 0; t < n; ++t)
        std::cin >> data[t];

    long long tmp = 1;
    int zn = 0;
    for (const auto &x: data) {
        tmp *= x;
        while (tmp % 10 == 0) {
            ++zn;
            tmp /= 10;
        }
        if (tmp > IVS_LIM * 10000)
            tmp %= IVS_LIM;
    }

    while (tmp % 10 == 0) {
        ++zn;
        tmp /= 10;
    }

    double res = 1.;
    for (const auto &x: data) {
        res *= (double) x;
        if (res > 1e10)
            res /= 1e5;
    }

    auto str = std::to_string(res);

    std::cout << str[0] << str[1] << str[2] << std::endl << zn;
    return 0;
}
