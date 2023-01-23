// https://ac.nowcoder.com/acm/contest/24213/1030
// 石子合并

// Partial Accepted

//#include <stdio.h>
//#include <string.h>
//
//#define maxn 205
//
//int n;
//int dat[maxn], pfs[maxn];
//int dp[maxn][maxn];
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
//int sigma(int i, int j) {
//    if (i <= j)
//        return pfs[j] - pfs[i - 1];
//    else
//        return pfs[n] - (pfs[i - 1] - pfs[j]);
//}
//
//int main() {
//    scanf("%d", &n);
//    for (int t = 1; t <= n; ++t) {
//        scanf("%d", &dat[t]);
//        pfs[t] = pfs[t - 1] + dat[t];
//    }
//
//    // minVal
//
//    for (int t = 1; t <= n; ++t) {
//        dp[0][t] = 0x3f3f3f3f;
//        dp[t][0] = 0x3f3f3f3f;
//    }
//    // 给你讲个鬼故事
//    // n堆石子绕圆形操场摆放
//    // hhh
////    for (int len = 2; len <= n; ++len)
////        for (int i = 1; i + len - 1 <= n; ++i) {
////            int j = i + len - 1;
////            dp[i][j] = min(dp[i + 1][j] + (pfs[j] - pfs[i]) + dat[i],
////                           dp[i][j - 1] + (pfs[j - 1] - pfs[i - 1]) + dat[j]);
////        }
//    for (int len = 2; len <= n; ++len)
//        for (int i = 1; i <= n; ++i) {
//            int j = i + len - 1;
//            if (j > n) {
//                j %= n;
//                // ???????
//                // Wo cao ni ma
//                // int x = i + i > n ? 1 : i + 1;
//                int x = i + 1 > n ? 1 : i + 1;
//                int y = j - 1 < 1 ? n : j - 1;
//                dp[i][j] = min(dp[x][j] + sigma(x, j) + dat[i],
//                               dp[i][y] + sigma(i, y) + dat[j]);
//            } else
//                dp[i][j] = min(dp[i + 1][j] + sigma(i + 1, j) + dat[i],
//                               dp[i][j - 1] + sigma(i, j - 1) + dat[j]);
//        }
//    int resMin = dp[1][n];
//    for (int i = 2, j = 1; i <= n; ++i, ++j)
//        resMin = min(resMin, dp[i][j]);
//
//    // maxVal
//
//    memset(dp, 0, sizeof(dp));
//    for (int t = 1; t <= n; ++t) {
//        dp[0][t] = -0x3f3f3f3f;
//        dp[t][0] = -0x3f3f3f3f;
//    }
//    // 给你讲个鬼故事
//    // n堆石子绕圆形操场摆放
//    // hhh
////    for (int len = 2; len <= n; ++len)
////        for (int i = 1; i + len - 1 <= n; ++i) {
////            int j = i + len - 1;
////            dp[i][j] = max(dp[i + 1][j] + (pfs[j] - pfs[i]) + dat[i],
////                           dp[i][j - 1] + (pfs[j - 1] - pfs[i - 1]) + dat[j]);
////        }
//    for (int len = 2; len <= n; ++len)
//        for (int i = 1; i <= n; ++i) {
//            int j = i + len - 1;
//            if (j > n) {
//                j %= n;
//                // ???????
//                // Wo cao ni ma
//                // int x = i + i > n ? 1 : i + 1;
//                int x = i + 1 > n ? 1 : i + 1;
//                int y = j - 1 < 1 ? n : j - 1;
//                dp[i][j] = max(dp[x][j] + sigma(x, j) + dat[i],
//                               dp[i][y] + sigma(i, y) + dat[j]);
//            } else
//                dp[i][j] = max(dp[i + 1][j] + sigma(i + 1, j) + dat[i],
//                               dp[i][j - 1] + sigma(i, j - 1) + dat[j]);
//        }
//    int resMax = dp[1][n];
//    for (int i = 2, j = 1; i <= n; ++i, ++j)
//        resMax = max(resMax, dp[i][j]);
//
//    printf("%d\n%d", resMin, resMax);
//    return 0;
//}
