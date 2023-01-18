// https://ac.nowcoder.com/acm/contest/24213/1013
// 数学考试

// Wrong Answer

//#include <stdio.h>
//#include <limits.h>
//
//#define maxn 200005
//
//int dat[maxn];
//long long pfs[maxn], dpl[maxn], dpr[maxn];
//
//long long max(long long a, long long b) {
//    if (a > b)
//        return a;
//    return b;
//}
//
//void solve() {
//    int n, k;
//    scanf("%d%d", &n, &k);
//    for (int t = 0; t <= n + 5; ++t) {
//        dpl[t] = LLONG_MIN;
//        dpr[t] = LLONG_MIN;
//    }
//    for (int t = 1; t <= n; ++t)
//        scanf("%d", &dat[t]);
//    for (int t = 1; t <= n; ++t)
//        pfs[t] = pfs[t - 1] + dat[t];
//    for (int t = k; t <= n; ++t)
//        dpl[t] = max(dpl[t - 1], pfs[t] - pfs[t - k]);
//    for (int t = n - k + 1; t >= k; --t)
//        dpr[t] = max(dpr[t + 1], pfs[t + k - 1] - pfs[t - 1]);
//    /**
//     *  Don't forget points may all negative
//     */
//    long long res = LLONG_MIN;
//    for (int t = k; t <= n - k + 1; ++t)
//        res = max(res, dpl[t] + dpr[t + 1]);
//    printf("%lld\n", res);
//}
//
//int main() {
//    int tt;
//    scanf("%d", &tt);
//    while (tt--)
//        solve();
//    return 0;
//}

#include <stdio.h>
#include <limits.h>

#define maxn 200005

int dat[maxn];
long long pfs[maxn], dpl[maxn], dpr[maxn];

long long max(long long a, long long b) {
    if (a > b)
        return a;
    return b;
}

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int t = 0; t <= n + 5; ++t) {
        dpl[t] = LLONG_MIN;
        dpr[t] = LLONG_MIN;
    }
    for (int t = 1; t <= n; ++t)
        scanf("%d", &dat[t]);
    for (int t = 1; t <= n; ++t)
        pfs[t] = pfs[t - 1] + dat[t];
    for (int t = k; t <= n; ++t)
        dpl[t] = max(dpl[t - 1], pfs[t] - pfs[t - k]);
    for (int t = n - k + 1; t >= k + 1; --t) // DIFF
        dpr[t] = max(dpr[t + 1], pfs[t + k - 1] - pfs[t - 1]);
    /**
     *  Don't forget points may all negative
     */
    long long res = LLONG_MIN;
    for (int t = k; t <= n - k; ++t) // DIFF
        res = max(res, dpl[t] + dpr[t + 1]);
    printf("%lld\n", res);
}

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solve();
    return 0;
}
