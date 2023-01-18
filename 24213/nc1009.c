// https://ac.nowcoder.com/acm/contest/24213/1009
// [NOIP2008]传球游戏

#include <stdio.h>

#define maxn 35

long long dp[maxn][maxn];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    dp[2][1] = 1;
    dp[n][1] = 1;
    for (int t = 2; t <= m; ++t)
        for (int k = 1; k <= n; ++k)
            if (k == 1)
                dp[k][t] = dp[2][t - 1] + dp[n][t - 1];
            else if (k == n)
                dp[k][t] = dp[k - 1][t - 1] + dp[1][t - 1];
            else
                dp[k][t] = dp[k - 1][t - 1] + dp[k + 1][t - 1];
    printf("%lld", dp[1][m]);
    return 0;
}
