// https://ac.nowcoder.com/acm/contest/24213/1005
// 花店橱窗

#include <stdio.h>

int dat[101][101];
long long dp[101][101];

void print(int f, long long r) {
    if (!f)
        return;
    for (int t = f;; ++t)
        if (dp[f][t] == r) {
            // 递归的时候把下面那两行换换就可以做到正向输出或者反向输出了
            print(f - 1, r - dat[f][t]);
            printf("%d ", t);
            break;
        }
}

int main() {
    int f, v;
    scanf("%d%d", &f, &v);
    for (int i = 1; i <= f; ++i)
        for (int j = 1; j <= v; ++j) {
            scanf("%d", &dat[i][j]);
            dp[i][j] = -0x3f3f3f3f;
        }
    for (int i = 1; i <= f; ++i)
        for (int j = 1; j <= v; ++j)
            for (int k = i - 1; k <= j - 1; ++k)
                if (dp[i][j] < dp[i - 1][k] + dat[i][j])
                    dp[i][j] = dp[i - 1][k] + dat[i][j];
    long long r = 0;
    for (int t = f; t <= v; ++t)
        if (dp[f][t] > r)
            r = dp[f][t];
    printf("%lld\n", r);
    print(f, r);
    return 0;
}
