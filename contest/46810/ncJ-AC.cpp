// https://ac.nowcoder.com/acm/contest/46810/J

#include <bits/stdc++.h>

#define maxn 100005

void solve() {
    int n;
    std::cin >> n;
    long long r = 0;
    int i;
    for (int t = 1; t <= n; ++t) {
        std::cin >> i;
        r += 2ll * n * std::abs(i);
    }
    std::cout << r << std::endl;
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
