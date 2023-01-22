// https://ac.nowcoder.com/acm/contest/24213/1026
// 合并回文子串

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define maxn 52

int8_t dp[maxn][maxn][maxn][maxn];

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

void solve() {
    memset(dp, 0, sizeof(dp));
    char s1[maxn], s2[maxn];
    scanf("%s%s", s1 + 1, s2 + 1);
    int l1 = (int) strlen(s1 + 1), l2 = (int) strlen(s2 + 1);
    int res = 0;
    for (int i = 0; i <= l1; ++i) // s1.len
        for (int j = 0; j <= l2; ++j) // s2.len
            for (int p = 1; p + i - 1 <= l1; ++p) // s1.beginPos
                for (int q = 1; q + j - 1 <= l2; ++q) { // s2.beginPos
                    int x = p + i - 1; // s1.endPos
                    int y = q + j - 1; // s2.endPos
                    if (i + j <= 1)
                        dp[p][x][q][y] |= 1;
                    else {
                        if (s1[p] == s1[x])
                            dp[p][x][q][y] |= dp[p + 1][x - 1][q][y];
                        if (s2[q] == s2[y])
                            dp[p][x][q][y] |= dp[p][x][q + 1][y - 1];
                        if (s1[p] == s2[y])
                            dp[p][x][q][y] |= dp[p + 1][x][q][y - 1];
                        if (s1[x] == s2[q])
                            dp[p][x][q][y] |= dp[p][x - 1][q + 1][y];
                    }
                    if (dp[p][x][q][y])
                        res = max(res, i + j);
                }
    printf("%d\n", res);
}

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solve();
    return 0;
}
