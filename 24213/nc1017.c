// https://ac.nowcoder.com/acm/contest/24213/1017
// [NOIP2001]装箱问题

// Partial Accepted
// 这好像……是"有无数个给定大小的石头"的解捏

//#include <stdio.h>
//
//#define maxv 20005
//#define maxn 35
//
//int dat[maxn], dp[maxv];
//
//int max(int a, int b) {
//    if (a > b)
//        return a;
//    return b;
//}
//
//int main() {
//    int v, n;
//    scanf("%d%d", &v, &n);
//    for (int t = 1; t <= n; ++t)
//        scanf("%d", &dat[t]);
//    for (int t = 1; t <= v; ++t)
//        for (int k = 1; k <= n; ++k)
//            if (t - dat[k] >= 0)
//                dp[t] = max(dp[t], dp[t - dat[k]] + dat[k]);
//    printf("%d", v - dp[v]);
//    return 0;
//}

#include <stdio.h>

#define maxv 20005
#define maxn 35

int dat[maxn], dp[maxv];

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int main() {
    int v, n;
    scanf("%d%d", &v, &n);
    for (int t = 1; t <= n; ++t)
        scanf("%d", &dat[t]);
    for (int i = 1; i <= n; ++i)
        /**
         *  To avoid one chest being calculated twice
         *  The for loop must from the top to the bottom
         */
        // for (int k = dat[i]; k <= v; ++k)
        for (int k = v; k >= dat[i]; --k)
            dp[k] = max(dp[k], dp[k - dat[i]] + dat[i]);
    printf("%d", v - dp[v]);
    return 0;
}
