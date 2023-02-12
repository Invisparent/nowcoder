// https://ac.nowcoder.com/acm/contest/23156/1002
// 走出迷宫

// Multiple Solutions
// DFS

// DNF

#include <stdio.h>
#include <stdint.h>

#define maxn 505

int n;

/**
 * Data:
 * 0: Empty
 * 1: Blocked
 * 2: Start
 * 3: End
 * 0x3f: Bound
 */
uint8_t data[maxn][maxn];

int xread() {
    int retVal = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9') {
        retVal = (retVal << 1) + (retVal << 3) + ch - '0';
        ch = getchar();
    }
    return retVal;
}

void strread(uint8_t *ptr, int strlen) {

}

void solve() {

}

int main() {
    int tt = xread();
    n = xread();
    while (tt--)
        solve();
    return 0;
}
