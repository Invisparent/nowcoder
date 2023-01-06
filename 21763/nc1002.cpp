// https://ac.nowcoder.com/acm/contest/21763/1002

#include <iostream>
#include <vector>

inline long long calculate(const std::vector<long long> &inVll, long long val) {
    if (val == 0 || val == 1)
        return inVll[val];
    return calculate(inVll, val / 2) + calculate(inVll, val % 2);
}

inline long long qpow(long long x, long long y) {
    long long r = 1;
    while (y) {
        if (y & 1)
            r *= x;
        x *= x;
        y >>= 1;
    }
    return r;
}

int main() {
    std::vector<long long> vll{0, 1};
    long long n;
    std::cin >> n;
    while (std::cin >> n) {
        long long x = calculate(vll, n);
        std::cout << x << ' ' << qpow(2, x) - 1 << std::endl;
    }
}
