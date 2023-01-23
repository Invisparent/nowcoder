// https://ac.nowcoder.com/acm/contest/24213/1014
// 小A买彩票

// Multiple Solutions
// Naive using double

#include <stdio.h>

/**
 *  WARNING:
 *  fact(21) > LLONG_MAX
 *  So, you have to use long double...
 */
//long long fact[31];
long double fact[31];

long long gcd(long long a, long long b) {
    while (b ^= a ^= b ^= a %= b);
    return a;
}

int main() {
    int n;
    scanf("%d", &n);
    /**
     *  WARNING:
     *  To keep the precision,
     *  Using long double instead of long long
     *  is NECESSARY
     */
    long double d = 1, u = 0;
    for (int t = 1; t <= n; ++t)
        d *= 4;
    fact[0] = 1.;
    fact[1] = 1.;
    for (int t = 2; t <= 30; ++t)
        fact[t] = fact[t - 1] * t;
    for (int a = 0; a <= n; ++a)
        for (int b = 0; b <= n - a; ++b)
            for (int c = 0; c <= n - a - b; ++c) {
                int d = n - a - b - c;
                if (a * 2 + b <= d)
                    u += fact[n] / (fact[a] * fact[b] * fact[c] * fact[d]); // What the fuck
            }
    long long x = gcd(u, d);
    /**
     *  And there should be a type conversion
     */
    printf("%lld/%lld", (long long) u / x, (long long) d / x);
    return 0;
}
