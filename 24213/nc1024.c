// https://ac.nowcoder.com/acm/contest/24213/1024
// [NOIP2006]金明的预算方案

/**
 *  Happy Chinese New Year !!
 *
 *  Thank you, Wang Feng and Chen Shuling
 *  For your hard work and generosity
 *  Especially the unconditional love
 *  They all helped me a lot in the past eighteen years
 *  Without any of them, I can't be what I am now
 *  I promise I'll try my best to go further in Computer Science in the new year
 *  And become more steady when facing difficulties and conflicts ...
 *
 *  And my grandfather, my grandmother, ...
 *
 *  And all of my relatives...
 *
 *  And all of my friends...
 *  Especially You Ming, who gave me lots of help in algorithm
 *  And Chen Yuguang & Yang Runze
 *  And more ...
 *
 *  And all of my teachers ...
 *
 *  And all of them who helped me in the past eighteen years ...
 *
 *  Best wishes to all of you !
 *
 */

// Partial Accepted

//#include <stdio.h>
//
//#define maxn 32010
//#define maxm 65
//
//typedef struct x {
//    int v, p, q, f1, f2;
//} x;
//
//int dp[maxn];
//x dat[maxm], mdat[maxm];
//
//int max(int a, int b) {
//    if (a > b)
//        return a;
//    return b;
//}
//
//int main() {
//    int n, m;
//    scanf("%d%d", &n, &m);
//    int v = 0;
//    for (int t = 1; t <= m; ++t)
//        scanf("%d%d%d", &dat[t].v, &dat[t].p, &dat[t].q);
//    for (int t = 1; t <= m; ++t)
//        if (dat[t].q != 0)
//            if (dat[dat[t].q].f1 == 0)
//                dat[dat[t].q].f1 = dat[t].q;
//            else
//                dat[dat[t].q].f2 = dat[t].q;
//    for (int t = 1; t <= m; ++t)
//        if (dat[t].q == 0)
//            mdat[++v] = dat[t];
//    for (int i = 1; i <= v; ++i) {
//        int vm = mdat[i].v;
//        int va = vm + dat[mdat[i].f1].v;
//        int vb = vm + dat[mdat[i].f2].v;
//        int vab = vm + dat[mdat[i].f1].v + dat[mdat[i].f2].v;
//        int xm = mdat[i].v * mdat[i].p;
//        int xa = xm + dat[mdat[i].f1].v * dat[mdat[i].f1].p;
//        int xb = xm + dat[mdat[i].f2].v * dat[mdat[i].f2].p;
//        int xab = xm + dat[mdat[i].f1].v * dat[mdat[i].f1].p + dat[mdat[i].f2].v * dat[mdat[i].f2].p;
//        for (int j = n; j >= vm; --j) {
//            if (j >= vab)
//                dp[j] = max(dp[j], dp[j - vab] + xab);
//            if (j >= va)
//                dp[j] = max(dp[j], dp[j - va] + xa);
//            if (j >= vb)
//                dp[j] = max(dp[j], dp[j - vb] + xb);
//            dp[j] = max(dp[j], dp[j - vm] + xm);
//        }
//    }
//    printf("%d", dp[n]);
//    return 0;
//}

#include <stdio.h>
#include <string.h>

#define maxn 32010
#define maxm 65

typedef struct x {
    int v, p, q, f1, f2;
} x;

int dp[maxn];
x dat[maxm], mdat[maxm];

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int main() {
    memset(dp, -0x3f, sizeof(dp));
    dp[0] = 0;
    int n, m;
    scanf("%d%d", &n, &m);
    int v = 0;
    for (int t = 1; t <= m; ++t)
        scanf("%d%d%d", &dat[t].v, &dat[t].p, &dat[t].q);
    for (int t = 1; t <= m; ++t)
        if (dat[t].q != 0)
            // What are you doing ???
            // if (dat[dat[t].q].f1 == 0)
            //     dat[dat[t].q].f1 = dat[t].q; // It should be t, NOT dat[t].q
            // else
            //     dat[dat[t].q].f2 = dat[t].q; // Also t, NOT dat[t].q, an index point to itself
            if (dat[dat[t].q].f1 == 0)
                dat[dat[t].q].f1 = t;
            else
                dat[dat[t].q].f2 = t;

    for (int t = 1; t <= m; ++t)
        if (dat[t].q == 0)
            mdat[++v] = dat[t];
    for (int i = 1; i <= v; ++i) {
        int vm = mdat[i].v;
        int va = vm + dat[mdat[i].f1].v;
        int vb = vm + dat[mdat[i].f2].v;
        int vab = vm + dat[mdat[i].f1].v + dat[mdat[i].f2].v;
        int xm = mdat[i].v * mdat[i].p;
        int xa = xm + dat[mdat[i].f1].v * dat[mdat[i].f1].p;
        int xb = xm + dat[mdat[i].f2].v * dat[mdat[i].f2].p;
        int xab = xm + dat[mdat[i].f1].v * dat[mdat[i].f1].p + dat[mdat[i].f2].v * dat[mdat[i].f2].p;
        for (int j = n; j >= vm; --j) {
            if (j >= vab && dp[j - vab] != dp[maxn - 1])
                dp[j] = max(dp[j], dp[j - vab] + xab);
            if (j >= va && dp[j - va] != dp[maxn - 1])
                dp[j] = max(dp[j], dp[j - va] + xa);
            if (j >= vb && dp[j - vb] != dp[maxn - 1])
                dp[j] = max(dp[j], dp[j - vb] + xb);
            if (dp[j - vm] != dp[maxn - 1])
                dp[j] = max(dp[j], dp[j - vm] + xm);
        }
    }
    // What the fuck are you doing ???
    // printf("%d", dp[n]);
    int res = 0;
    for (int t = 1; t <= n; ++t)
        res = max(res, dp[t]);
    printf("%d", res);
    return 0;
}
