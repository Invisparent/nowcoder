// https://ac.nowcoder.com/acm/contest/24213/1010
// 「木」迷雾森林

// 再不记得改maxn，拖出去打死

#include <stdio.h>

#define maxn 3005
#define mod 2333

int dat[maxn][maxn], dp[maxn][maxn];

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = m; i >= 1; --i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &dat[i][j]);
    dp[1][1] = 1;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if ((i == 1 && j == 1) || dat[i][j] == 1)
                continue;
            else
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
    printf("%d", dp[m][n]);
    return 0;
}
