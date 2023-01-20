// https://ac.nowcoder.com/acm/contest/22353/J
// [NOIP2011]聪明的质监员

#include <stdio.h>
#include <limits.h>
#include <string.h>

#define maxn 200010
#define maxm 200010

int n, m;
long long s;
int datw[maxn], datv[maxn], rl[maxm], rr[maxm];
long long pfsw[maxn], pfsv[maxn];

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

long long xabs(long long x) {
    if (x < 0)
        return -x;
    return x;
}

long long solve(int x) {
    memset(pfsw, 0, sizeof(pfsw));
    memset(pfsv, 0, sizeof(pfsv));
    for (int t = 1; t <= n; ++t)
        if (datw[t] >= x) {
            pfsw[t] += pfsw[t - 1] + 1;
            pfsv[t] += pfsv[t - 1] + datv[t];
        } else {
            pfsw[t] = pfsw[t - 1];
            pfsv[t] = pfsv[t - 1];
        }
    long long res = 0;
    for (int t = 1; t <= m; ++t)
        res += (pfsv[rr[t]] - pfsv[rl[t] - 1]) * (pfsw[rr[t]] - pfsw[rl[t] - 1]);
    return res;
}

int main() {
    int l = INT_MAX, r = INT_MIN;
    scanf("%d%d%lld", &n, &m, &s);
    for (int t = 1; t <= n; ++t) {
        scanf("%d%d", &datw[t], &datv[t]);
        l = min(l, datw[t]);
        r = max(r, datw[t]);
    }
    for (int t = 1; t <= m; ++t)
        scanf("%d%d", &rl[t], &rr[t]);
    int mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (solve(mid) >= s)
            l = mid;
        else
            r = mid - 1;
    }
    long long resl = xabs(solve(l) - s), resr = xabs(solve(l + 1) - s);
    if (resl < resr)
        printf("%lld", resl);
    else
        printf("%lld", resr);
    return 0;
}
