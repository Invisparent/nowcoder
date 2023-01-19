// https://ac.nowcoder.com/acm/contest/24213/1018
// [NOIP2005]采药

// 这不和上一道一样么hhh

#include <stdio.h>

#define maxt 1005
#define maxm 105

int datTime[maxm], datValue[maxm], dp[maxt];

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int main() {
    int t, m;
    scanf("%d%d", &t, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d", &datTime[i], &datValue[i]);
    for (int i = 1; i <= m; ++i)
        for (int j = t; j >= datTime[i]; --j)
            /**
             *  What are you doing???
             */
            // dp[j] = max(dp[j], dp[i - datTime[i]] + datValue[i]);
            dp[j] = max(dp[j], dp[j - datTime[i]] + datValue[i]);
    printf("%d", dp[t]);
    return 0;
}
