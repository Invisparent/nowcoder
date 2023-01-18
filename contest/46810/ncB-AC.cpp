// https://ac.nowcoder.com/acm/contest/46810/B

#include <bits/stdc++.h>

void solve() {
    long long n;
    std::cin >> n;
    long long la, ra, lb, rb;
    std::cin >> la >> ra >> lb >> rb;
    if (la > ra) {
        std::swap(la, ra);
        std::swap(lb, rb);
    }
    lb = n - lb;
    rb = n - rb;
    std::swap(lb, rb);
    if (lb > ra || la > rb) {
        std::cout << 0 << std::endl;
        return;
    }
    std::cout << std::min({rb - lb + 1, ra - la + 1, ra - lb + 1, rb - la + 1}) << std::endl;

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long tt;
    std::cin >> tt;
    while (tt--)
        solve();
    return 0;
}
