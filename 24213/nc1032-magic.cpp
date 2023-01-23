// https://ac.nowcoder.com/acm/contest/24213/1032
// 迁徙过程中的河流

// Multiple Solutions
// Magic Solution

#include <iostream>
#include <vector>
#include <algorithm>

int n;
std::vector<int> dat;

long long solve(int pos) {
    if (pos == 2)
        return dat[2];
    else if (pos == 3)
        return dat[1] + dat[2] + dat[3];
    else
        // ...
        // 无力吐槽自己写的bug...
        // return std::min(dat[1] + 2 * dat[2] + dat[n], 2 * dat[1] + dat[n - 1] + dat[n]) + solve(n - 2);
        // 卧槽你改bug还不改干净是吧
        // return std::min(dat[1] + 2 * dat[2] + dat[n], 2 * dat[1] + dat[n - 1] + dat[n]) + solve(pos - 2);
        // ...
        return solve(pos - 2) + std::min(dat[1] + 2 * dat[2] + dat[pos],
                                         2 * dat[1] + dat[pos - 1] + dat[pos]);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n;
    if (n == 1) {
        std::cin >> n;
        std::cout << n;
        return 0;
    }
    dat = std::vector<int>(n + 1);
    for (int t = 1; t <= n; ++t)
        std::cin >> dat[t];
    std::sort(dat.begin(), dat.end());
    std::cout << solve(n);
    return 0;
}
