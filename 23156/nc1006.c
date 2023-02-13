// https://ac.nowcoder.com/acm/contest/23156/1006
// 送外卖

#include <stdio.h>
#include <stdint.h>

#define maxn 100010

int n;

/**
 * Data
 */
int a[maxn], b[maxn];

char str[maxn];

/**
 * Array isVisited (iv):
 * 0: Never accessed
 * 1: Accessed
 * 2: Infinite Loop
 */
uint8_t iv[maxn];
uint8_t hasInfiniteLoop = 0;

int xread() {
    int retVal = 0, sgn = 1;
    char ch = (char) getchar();

    while (ch < '0' || ch > '9') {
        if (ch == '-')
            sgn = -1;
        ch = (char) getchar();
    }

    while (ch >= '0' && ch <= '9') {
        retVal = (retVal << 3) + (retVal << 1) + ch - '0';
        ch = (char) getchar();
    }

    return sgn * retVal;
}

/**
 * @param pos
 * @param step
 * @return Has any solution
 */
uint8_t dfs(int pos, int step) {
    if (pos < 1 || pos > n)
        return 0;

    if (pos == n) {
        str[pos] = '\0';
        return 1;
    }

    ++iv[pos];
    if (iv[pos] > 1)
        return 0;
    if (dfs(pos + a[pos], step + 1)) {
        str[step - 1] = 'a';
        if (iv[pos] > 1)
            hasInfiniteLoop = 1;
        return 1;
    } else if (dfs(pos + b[pos], step + 1)) {
        str[step - 1] = 'b';
        if (iv[pos] > 1)
            hasInfiniteLoop = 1;
        return 1;
    }
    return 0;
}

int main() {
    n = xread();
    for (int t = 1; t <= n; ++t)
        a[t] = xread();
    for (int t = 1; t <= n; ++t)
        b[t] = xread();

    uint8_t hasSolution = dfs(1, 1);
    if (hasSolution)
        if (hasInfiniteLoop)
            printf("Infinity!");
        else
            printf("%s", str);
    else
        printf("No solution!");
}
