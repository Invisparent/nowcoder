// https://ac.nowcoder.com/acm/contest/24213/1014
// 小A买彩票

// Multiple Solutions
// DP

// Partial Accepted
// Just use long double instead?

//#include <stdio.h>
//
//#define maxT 31
//#define maxW 121
//
//long long dp[maxT][maxW];
//
//int max(int a, int b) {
//    if (a > b)
//        return a;
//    return b;
//}
//
//long long gcd(long long a, long long b) {
//    while (b ^= a ^= b ^= a %= b);
//    return a;
//}
//
//int main() {
//    int n;
//    scanf("%d", &n);
//    dp[1][1] = 1;
//    dp[1][2] = 1;
//    dp[1][3] = 1;
//    dp[1][4] = 1;
//    for (int i = 2; i <= n; ++i)
//        for (int j = 1; j <= 120; ++j)
//            if (!(i == 1 && j >= 1 && j <= 4))
//                for (int x = max(0, j - 4); x < j; ++x)
//                    dp[i][j] += dp[i - 1][x];
//    long long res = 0, d = 1;
//    for (int t = 3 * n; t <= 4 * n; ++t)
//        res += dp[n][t];
//    for (int t = 1; t <= n; ++t)
//        d *= 4;
//    long long x = gcd(res, d);
//    printf("%lld/%lld", res / x, d / x);
//    return 0;
//}

#include <stdio.h>

#define maxT 31
#define maxW 121

long long dp[maxT][maxW];

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

long long gcd(long long a, long long b) {
    while (b ^= a ^= b ^= a %= b);
    return a;
}

int main() {
    int n;
    scanf("%d", &n);
    /**
     *  When n comes to ZERO,
     *  It should be 1/1 instead of 0/1
     *  In naive solution, the program will output 1/1 when n==0
     *  But when it comes to DP, it will be 0/1
     *  What the fuck
     *  "只要我不买我就不会亏.jpg"
     */
    if (n == 0) {
        printf("1/1");
        return 0;
    }
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 1;
    dp[1][4] = 1;
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= 120; ++j)
            if (!(i == 1 && j >= 1 && j <= 4))
                for (int x = max(0, j - 4); x < j; ++x)
                    dp[i][j] += dp[i - 1][x];
    long long res = 0, d = 1;
    for (int t = 3 * n; t <= 4 * n; ++t)
        res += dp[n][t];
    for (int t = 1; t <= n; ++t)
        d *= 4;
    long long x = gcd(res, d);
    printf("%lld/%lld", res / x, d / x);
    return 0;
}
