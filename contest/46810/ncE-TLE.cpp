// https://ac.nowcoder.com/acm/contest/46810/E

#include <bits/stdc++.h>

long long n, l, r;

inline long long calculate(const long long &m) {
    return n / m + m - 1;
}

inline void solve() {
    std::cin >> n >> l >> r;
    if (r == 1) {
        std::cout << r << std::endl;
        return;
    }
    if (calculate(r - 1) > calculate(r)) {
        std::cout << r << std::endl;
        return;
    }
    long long m;
    --r;
    while (l <= r) {
        m = (l + r) >> 1;
        if (calculate(m) > calculate(m + 1))
            l = m + 1;
        else if (calculate(m) < calculate(m + 1))
            r = m - 1;
        else
            break;
    }
    long long minVal = LONG_LONG_MAX, res;
    for (long long t = l; t <= r; ++t) {
        if (calculate(t) < minVal) {
            minVal = calculate(t);
            res = t;
        }
    }
    std::cout << res << std::endl;
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
