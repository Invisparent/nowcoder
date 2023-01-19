// https://ac.nowcoder.com/acm/contest/24213/1015
// 购物

// Multiple Solutions
// DP

// DNF

//#include <stdio.h>
//
//#define maxn 6
//
///**
// *  dp[days, candyBought]
// */
//int dat[maxn][maxn], pfs[maxn][maxn], dp[maxn][maxn];
//
//int min(int a, int b);
//
//int max(int a, int b);
//
//void mergeSort_merge(int *lbegin, int const *lend, int *rbegin, int const *rend);
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
//void mergeSort(int *begin, int *end) {
//    if (begin == end)
//        return;
//    int *lend = begin + (end - begin) / 2, *rbegin = lend + 1;
//    mergeSort(begin, lend);
//    mergeSort(rbegin, end);
//    mergeSort_merge(begin, lend, rbegin, end);
//}
//
//void mergeSort_merge(int *lbegin, int const *lend, int *rbegin, int const *rend) {
//    int cacheDat[rend - lbegin + 1];
//    int *cachePtr = cacheDat, *writePtr = lbegin;
//    while (lbegin <= lend && rbegin <= rend)
//        if (*lbegin <= *rbegin)
//            *cachePtr++ = *lbegin++;
//        else
//            *cachePtr++ = *rbegin++;
//    while (lbegin <= lend)
//        *cachePtr++ = *lbegin++;
//    while (rbegin <= rend)
//        *cachePtr++ = *rbegin++;
//    for (int *ptr = cacheDat; ptr < cachePtr; ++ptr)
//        *writePtr++ = *ptr;
//}
//
//int main() {
//    int n, m;
//    scanf("%d%d", &n, &m);
//    for (int i = 0; i < maxn; ++i)
//        for (int j = 0; j < maxn; ++j)
//            dp[i][j] = 0x3f3f3f3f;
//    for (int i = 1; i <= n; ++i)
//        for (int j = 1; j <= m; ++j)
//            scanf("%d", &dat[i][j]);
//    for (int t = 1; t <= n; ++t)
//        mergeSort(&dat[t][0], &dat[t][t + m - 1]);
//    for (int i = 1; i <= n; ++i)
//        for (int j = 1; j <= m; ++j)
//            pfs[i][j] = pfs[i][j - 1] + dat[i][j];
//    for (int t = 1; t <= m; ++t)
//        dp[1][t] = pfs[1][t];
//    for (int i = 2; i <= n; ++i)
//        for (int j = i; j <= n; ++j)
//            for (int k = max(i - 1, j - m); k <= j; ++k)
//                dp[i][j] = min(dp[i][j], dp[i - 1][k] + (j - k) * (j - k) + pfs[i][j - k]);
//    printf("%d", dp[n][m]);
//    return 0;
//}
