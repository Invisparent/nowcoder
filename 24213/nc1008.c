// https://ac.nowcoder.com/acm/contest/24213/1008
// [NOIP2002]过河卒

// 艹，起始位置竟然是 (0, 0)

#include <stdio.h>
#include <math.h>

#define maxn 25

long long dp[maxn][maxn];

int main() {
    int n, m, x, y;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    ++n;
    ++m;
    ++x;
    ++y;
    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if ((i == x && j == y) || ((abs(x - i) + abs(y - j) == 3) && x != i && y != j) || (i == 1 && j == 1))
                continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    printf("%lld", dp[n][m]);
    return 0;
}
