// https://ac.nowcoder.com/acm/contest/24213/1022
// Music Problem

// 怎么感觉和上一道天平的题有点像捏

// Partial Accepted

//#include <stdio.h>
//#include <string.h>
//
//#define maxn 100010
//#define maxd 3610
//#define mod 3600
//
//char dp[maxd];
//int dat[maxn];
//
//void solve() {
//    int n;
//    scanf("%d", &n);
//    if (n >= 3600) {
//        printf("YES\n");
//        return;
//    }
//    for (int t = 1; t <= n; ++t) {
//        scanf("%d", &dat[t]);
//        dat[t] %= mod;
//        if (!dat[t]) {
//            printf("YES\n");
//            return;
//        }
//    }
//    memset(dp, 0, sizeof(dp));
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j < 3600; ++j)
//            if (dp[j] == 1)
//                dp[(j + dat[i]) % mod] = 1;
//        if (dp[0]) {
//            printf("YES\n");
//            return;
//        }
//        dp[dat[i]] = 1;
//    }
//    printf("NO\n");
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
#include <string.h>
#include <stdint.h>

#define maxn 3605
#define mod 3600

int dat[maxn];
int8_t dp[maxn];

/**
 *  WARNING:
 *  If you don't use this cache, a single music may be calculated twice or more
 */
int8_t cache[maxn];

void solve() {
    int n;
    scanf("%d", &n);
    // What the fuck... Just think why...
    if (n >= 3600) {
        printf("YES\n");
        // And... You seem to forget something...
        // return;
        for (int t = 1; t <= n; ++t)
            scanf("%d", &dat[0]);
        return;
    }
    for (int t = 1; t <= n; ++t) {
        scanf("%d", &dat[t]);
        dat[t] %= mod;
        if (!dat[t]) {
            printf("YES\n");
            return;
        }
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        memset(cache, 0, sizeof(cache));
        for (int j = 1; j < 3600; ++j)
            if (dp[j])
                cache[(j + dat[i]) % mod] |= (int8_t) 1;
        for (int t = 0; t < 3600; ++t)
            dp[t] |= cache[t];
        if (dp[0]) {
            printf("YES\n");
            return;
        }
        dp[dat[i]] |= (int8_t) 1;
    }
    printf("NO\n");
}

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solve();
    return 0;
}
