// https://ac.nowcoder.com/acm/contest/24213/1020
// CSL分苹果

// 你直接苹果总质量除以个2，然后dp不去求了

// Wrong Answer
// Example:
// 6
// 1 1 4 5 1 4
//
// hhh

//#include <stdio.h>
//
//#define maxn 105
//#define maxN 5005
//
//int dat[maxn], dp[maxN];
//
//int max(int a, int b) {
//    if (a > b)
//        return a;
//    return b;
//}
//int main() {
//    int n, sigma = 0;
//    scanf("%d", &n);
//    for (int t = 1; t <= n; ++t) {
//        scanf("%d", &dat[t]);
//        sigma += dat[t];
//    }
//    int N = sigma / 2;
//    for (int i = 1; i <= n; ++i)
//        for (int j = N; j >= dat[i]; --j)
//            dp[j] = max(dp[j], dp[j - dat[i]] + dat[i]);
//    printf("%d %d", dp[n], sigma - dp[n]);
//    return 0;
//}

#include <stdio.h>

#define maxn 105
#define maxN 5005

int dat[maxn], dp[maxN];

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int main() {
    int n, sigma = 0;
    scanf("%d", &n);
    for (int t = 1; t <= n; ++t) {
        scanf("%d", &dat[t]);
        sigma += dat[t];
    }
    int N = sigma / 2;
    for (int i = 1; i <= n; ++i)
        for (int j = N; j >= dat[i]; --j)
            dp[j] = max(dp[j], dp[j - dat[i]] + dat[i]);
    /**
     *  What the fuck are you doing ?????
     */
    // printf("%d %d", dp[n], sigma - dp[n]);
    printf("%d %d", dp[N], sigma - dp[N]);
    return 0;
}
