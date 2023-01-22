// https://ac.nowcoder.com/acm/contest/24213/1029
// [NOIP2007]矩阵取数游戏

#include <stdio.h>
#include <string.h>

#define maxn 85
#define maxm 85

int n, m;
int dat[maxn][maxm];
__int128 dp[maxm][maxm];
__int128 i128inf;

__int128 xmax(__int128 a, __int128 b) {
    if (a > b)
        return a;
    return b;
}

__int128 xread() {
    __int128 retVal = 0;
    int sgn = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            sgn = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        retVal = (retVal << 1) + (retVal << 3) + ch - 48;
        ch = getchar();
    }
    return sgn * retVal;
}

void xprint(__int128 dat) {
    if (dat < 0) {
        putchar('-');
        dat = -dat;
    }
    if (dat > 9)
        xprint(dat / 10);
    putchar(dat % 10 + '0');
}

__int128 solve(int t) {
    memset(dp, 0, sizeof(dp));
    for (int v = 1; v <= m; ++v) {
        dp[v][0] = -i128inf;
        dp[0][v] = -i128inf;
        // Don't forget to initialize another two edges !
        dp[v][m + 1] = -i128inf;
        dp[m + 1][v] = -i128inf;
    }
    __int128 pwr = 1;
    for (int len = m - 1; len > 0; --len) {
        pwr *= 2;
        for (int i = 1; i + len - 1 <= m; ++i) {
            int j = i + len - 1;
            // What the fuuuuuuuuuck ??????????
            // Debug about 2 hours and just find this ... ????????
            // Fuuuuuuuck
            // dp[i][j] = xmax(dp[i - 1][j] + dat[t][i - 1], dp[i][j + 1] + dat[t][j + 1]) * pwr;
            dp[i][j] = xmax(dp[i - 1][j] + dat[t][i - 1] * pwr, dp[i][j + 1] + dat[t][j + 1] * pwr);
        }
    }
    pwr *= 2;
    __int128 res = -i128inf;
    for (int v = 1; v <= m; ++v)
        res = xmax(res, dp[v][v] + dat[t][v] * pwr);
    return res;
}

int main() {
    i128inf = 0x3f3f3f3f3f3f3f3f;
    i128inf <<= 63;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &dat[i][j]);
    __int128 res = 0;
    for (int t = 1; t <= n; ++t)
        res += solve(t);
    xprint(res);
    return 0;
}
