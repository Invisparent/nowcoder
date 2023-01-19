// https://ac.nowcoder.com/acm/contest/24213/1016
// 牛牛的纪念品

// Partial Accepted

//#include <stdio.h>
//#include <string.h>
//
//#define maxm 105
//#define maxn 10005
//
//int dp[maxm][maxn];
//
//int max(int a, int b) {
//    if (a > b)
//        return a;
//    return b;
//}
//
//int main() {
//    memset(dp, -0x3f, sizeof(dp));
//    int n, m, k;
//    scanf("%d%d%d", &n, &m, &k);
//    for (int t = 1; t <= n; ++t)
//        scanf("%d", &dp[1][t]);
//    for (int i = 2; i <= m; ++i)
//        for (int j = (i - 1) * k + 1; j <= n; ++j)
//            for (int x = (i - 2) * k + 1; x <= j - k; ++x)
//                dp[i][j] = max(dp[i][j], dp[i - 1][x] + dp[1][j]);
//    printf("%d", dp[m][n]);
//    return 0;
//}

#include <stdio.h>
#include <string.h>

#define maxm 105
#define maxn 10005

int dat[maxn], dp[maxm][maxn];

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int main() {
    memset(dp, -0x3f, sizeof(dp));
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int t = 1; t <= n; ++t)
        scanf("%d", &dat[t]);
    for (int t = 1; t <= n; ++t)
        dp[1][t] = max(dp[1][t - 1], dat[t]);
    for (int i = 2; i <= m; ++i)
        /**
         *  Warning:
         *  SEGSEV if in the next loop you initialize j = 1
         *  Because you're trying to access dp[i - 1][j - k]
         *  Where j - k < 0
         *  And will lead to Undefined Behavior
         */
        // for (int j = 1; j <= n; ++j)
        for (int j = k + 1; j <= n; ++j)
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - k] + dat[j]);
    printf("%d", dp[m][n]);
    return 0;
}
