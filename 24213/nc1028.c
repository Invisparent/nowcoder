// https://ac.nowcoder.com/acm/contest/24213/1028
// wyh的问题

// DNF

//#include <stdio.h>
//#include <string.h>
//
//#define maxn 1005
//
//int ddat[maxn], wdat[maxn], pfs[maxn];
//int dp[maxn][maxn][2];
//
//int min(int a, int b) {
//    if (a < b)
//        return a;
//    return b;
//}
//
//int max(int a, int b) {
//    if (a > b)
//        return a;
//    return b;
//}
//
//int solve() {
//    int n, m;
//    if (scanf("%d%d", &n, &m) == EOF)
//        return 0;
//    memset(dp, 0x3f, sizeof(dp));
//    // What are you doing ??
////    dp[m][m][0] = 0;
////    dp[m][m][1] = 0;
//    dp[ddat[m]][ddat[m]][0] = 0;
//    dp[ddat[m]][ddat[m]][1] = 0;
//    for (int t = 1; t <= n; ++t)
//        scanf("%d%d", &ddat[t], &wdat[t]);
//    int d = ddat[n];
//    pfs[0] = 0;
//    for (int i = 1, j = 1; i <= d; ++i)
//        if (ddat[j] == i) {
//            pfs[i] = pfs[i - 1] + wdat[j];
//            ++j;
//        } else
//            pfs[i] = pfs[i - 1];
//    int sigma = pfs[n];
//    for (int l = 2; l <= d; ++l)
//        for (int i = 0; i + l - 1 <= d; ++i) {
//            int j = i + l - 1;
//            dp[i][j][0] = min(dp[i + 1][j][0] + sigma - (pfs[j] - pfs[i]),
//                              dp[i + 1][j][1] + l * (sigma - (pfs[j] - pfs[i])));
//            dp[i][j][1] = min(dp[i][j - 1][1] + sigma - (pfs[j] - pfs[i]),
//                              dp[i][j - 1][0] + l * (sigma - (pfs[j] - pfs[i])));
//        }
//    printf("%d", min(dp[0][d][0], dp[0][d][1]));
//    return 1;
//}
//
//int main() {
//    while (solve());
//    return 0;
//}

#include <stdio.h>
#include <string.h>

#define maxn 1005

int ddat[maxn], wdat[maxn], pfs[maxn];
int dp[maxn][maxn][2];

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

int solve() {
    int n, m;
    if (scanf("%d%d", &n, &m) == EOF)
        return 0;
    memset(dp, 0x3f, sizeof(dp));
    for (int t = 1; t <= n; ++t)
        scanf("%d%d", &ddat[t], &wdat[t]);
    pfs[0] = 0;
    for (int t = 1; t <= n; ++t)
        pfs[t] = pfs[t - 1] + wdat[t];
    dp[m][m][0] = 0;
    dp[m][m][1] = 0;
    int sigma = pfs[n];
    for (int len = 2; len <= n; ++len)
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            dp[i][j][0] = min(dp[i + 1][j][0] + (ddat[i + 1] - ddat[i]) * (sigma - (pfs[j] - pfs[i])),
                              dp[i + 1][j][1] + (ddat[j] - ddat[i]) * (sigma - (pfs[j] - pfs[i])));
            // What the fuck are you doing ??
//            dp[i][j][1] = min(dp[i][j - 1][1] + (ddat[j] - ddat[j - 1]) * (sigma - (pfs[j] - pfs[i])),
//                              dp[i][j - 1][0] + (ddat[j] - ddat[i]) * (sigma - (pfs[j] - pfs[i])));
            dp[i][j][1] = min(dp[i][j - 1][1] + (ddat[j] - ddat[j - 1]) * (sigma - (pfs[j - 1] - pfs[i - 1])),
                              dp[i][j - 1][0] + (ddat[j] - ddat[i]) * (sigma - (pfs[j - 1] - pfs[i - 1])));
        }
    // What the fuuuuuuuck are you dooooooing ?????????
    // printf("%d", min(dp[1][n][0], dp[1][n][1]));
    printf("%d\n", min(dp[1][n][0], dp[1][n][1]));
    return 1;
}

int main() {
    while (solve());
    return 0;
}
