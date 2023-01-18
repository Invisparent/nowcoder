// https://ac.nowcoder.com/acm/contest/24213/1011
// [NOIP2004]合唱队形

#include <stdio.h>
#include <limits.h>

#define maxn 105

int dat[maxn], dpl[maxn], dpr[maxn];

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int t = 1; t <= n; ++t) {
        scanf("%d", &dat[t]);
        dpl[t] = 1;
        dpr[t] = 1;
    }
    // LIS
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i - 1; ++j)
            if (dat[i] > dat[j])
                dpl[i] = max(dpl[j] + 1, dpl[i]);
    for (int i = n; i >= 1; --i)
        for (int j = n; j >= i + 1; --j)
            if (dat[i] > dat[j])
                dpr[i] = max(dpr[j] + 1, dpr[i]);
    int res = INT_MIN;
    for (int t = 1; t <= n; ++t)
        res = max(res, dpl[t] + dpr[t]);
    printf("%d", n - res + 1);
    return 0;
}
