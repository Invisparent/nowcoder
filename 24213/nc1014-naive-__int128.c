// https://ac.nowcoder.com/acm/contest/24213/1014
// 小A买彩票

// Multiple Solutions
// Naive using __int128

#include <stdio.h>

__int128 fact[31];

__int128 gcd(__int128 a, __int128 b) {
    while (b ^= a ^= b ^= a %= b);
    return a;
}

__int128 xread() {
    int sgn = 1;
    __int128 retVal = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            sgn = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        retVal = (retVal << 1) + (retVal << 3) + ch - '0';
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

int main() {
    fact[0] = 1;
    fact[1] = 1;
    for (int t = 2; t <= 30; ++t)
        fact[t] = fact[t - 1] * t;
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("1/1");
        return 0;
    }
    __int128 u = 0, d = 1;
    for (int t = 1; t <= n; ++t)
        d *= 4;
    for (int a = 0; a <= n; ++a)
        for (int b = 0; a + b <= n; ++b)
            for (int c = 0; a + b + c <= n; ++c) {
                int k = n - a - b - c;
                if (2 * a + b <= k)
                    u += fact[n] / (fact[a] * fact[b] * fact[c] * fact[k]);
            }
    __int128 x = gcd(u, d);
    xprint(u / x);
    printf("/");
    xprint(d / x);
    return 0;
}
