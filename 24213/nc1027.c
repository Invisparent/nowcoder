// https://ac.nowcoder.com/acm/contest/24213/1027
// 猜数游戏2

#include <stdio.h>
#include <string.h>

#define maxn 1005

int adat[maxn], bdat[maxn], dp[maxn][maxn];

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

void solve() {
    memset(dp, 0, sizeof(dp));
    int n;
    scanf("%d", &n);
    for (int t = 1; t <= n; ++t)
        scanf("%d", &adat[t]);
    for (int t = 1; t <= n; ++t)
        scanf("%d", &bdat[t]);
    for (int t = 1; t <= n; ++t) {
        dp[t][0] = dp[t - 1][0] + adat[t] * bdat[t];
        dp[0][t] = dp[0][t - 1] + adat[n - t + 1] * bdat[t];
    }
    for (int i = 1; i <= n; ++i)
        /**
         *  Aha, Segmentation Fault is coming !!!
         */
        // for (int j = 1; j <= n; ++j)
        for (int j = 1; i + j <= n; ++j)
            dp[i][j] = max(dp[i][j],
                           max(dp[i - 1][j] + adat[i] * bdat[i + j], dp[i][j - 1] + adat[n - j + 1] * bdat[i + j]));
    int res = 0;
    for (int i = 0; i <= n; ++i)
        res = max(res, dp[i][n - i]);
    printf("%d\n", res);
}

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solve();
    return 0;
}
