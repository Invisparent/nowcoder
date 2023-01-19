// https://ac.nowcoder.com/acm/contest/24213/1019
// [NOIP2006]开心的金明

// 就这?? (滑稽)

#include <stdio.h>

#define maxn 30005
#define maxm 30

int datValue[maxm], datPwr[maxm];
long long dp[maxn];

long long max(long long a, long long b) {
    if (a > b)
        return a;
    return b;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int t = 1; t <= m; ++t)
        scanf("%d%d", &datValue[t], &datPwr[t]);
    for (int i = 1; i <= m; ++i)
        for (int j = n; j >= datValue[i]; --j)
            dp[j] = max(dp[j], dp[j - datValue[i]] + datValue[i] * datPwr[i]);
    printf("%lld", dp[n]);
    return 0;
}
