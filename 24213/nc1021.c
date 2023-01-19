// https://ac.nowcoder.com/acm/contest/24213/1021
// 失衡天平

#include <stdio.h>
#include <string.h>

#define maxm 105
#define maxn 105
#define OFFSET 11000

int dat[maxn], dp[maxn][maxm * maxn * 2 + 50];

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int main() {
    memset(dp, -0x3f, sizeof(dp));
    int n, m;
    scanf("%d%d", &n, &m);
    for (int t = 1; t <= n; ++t)
        scanf("%d", &dat[t]);
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][OFFSET + dat[i]] = dat[i];
        dp[i][OFFSET - dat[i]] = dat[i];
        dp[i][OFFSET] = 0;
        for (int j = -n * maxm; j <= n * maxm; ++j)
            // What the fuck
            dp[i][OFFSET + j] =
                    max(dp[i][OFFSET + j],
                        max(dp[i - 1][OFFSET + j],
                            max(dp[i - 1][OFFSET + j + dat[i]], dp[i - 1][OFFSET + j - dat[i]]) + dat[i]));
    }
    // DEBUG ONLY
//    for (int i = 0; i <= n; ++i) {
//        for (int j = OFFSET - m * n; j <= OFFSET + m * n; ++j)
//            printf("%d ", dp[i][j]);
//        printf("\n");
//    }
    int res = -0x3f3f3f3f;
    for (int t = OFFSET - m; t <= OFFSET + m; ++t)
        res = max(res, dp[n][t]);
    printf("%d", res);
    return 0;
}
