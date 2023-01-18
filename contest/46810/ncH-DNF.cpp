// https://ac.nowcoder.com/acm/contest/46810/H

#include <bits/stdc++.h>

void solve() {
    int n, i;
    std::cin >> n;
    std::unordered_map<int, int> dat;
    for (int t = 0; t < n; ++t) {
        std::cin >> i;
        ++dat[i];
    }
    auto iter = dat.cbegin();
    std::vector<int> stat(dat.size());
    int index = 0;
    while (iter != dat.cend())
        stat[index] = (*iter++).second;
    std::sort(stat.begin(), stat.end());

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
