// https://ac.nowcoder.com/acm/contest/24213/1032
// 迁徙过程中的河流

// Multiple Solutions
// DP

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    if (n == 1) {
        std::cin >> n;
        std::cout << n;
        return 0;
    }
    if (n == 2) {
        std::cin >> n >> n;
        std::cout << n;
        return 0;
    }

    std::vector<int> dat(n + 1);
    for (int t = 1; t <= n; ++t)
        std::cin >> dat[t];
    std::sort(dat.begin(), dat.end());

    std::vector<int> dp(n + 1);
    dp[1] = dat[1];
    dp[2] = dat[2];
    for (int t = 3; t <= n; ++t)
        // Just think why ...
        dp[t] = std::min(dp[t - 2] + dat[1] + 2 * dat[2] + dat[t],
                         dp[t - 1] + dat[1] + dat[t]);
    std::cout << dp[n];
    return 0;
}
