// https://ac.nowcoder.com/acm/contest/23156/1008
// 「金」点石成金

#include <stdio.h>

#define maxn 17

typedef struct stone {
    int a, b, c, d;
} stone;

int n;
long long res = -1;
stone data[maxn];

int xread() {
    int retVal = 0;
    char ch = (char) getchar();
    while (ch < '0' || ch > '9')
        ch = (char) getchar();
    while (ch >= '0' && ch <= '9') {
        retVal = (retVal << 3) + (retVal << 1) + ch - '0';
        ch = (char) getchar();
    }
    return retVal;
}

int i32max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

long long i64max(long long a, long long b) {
    if (a > b)
        return a;
    return b;
}

void dfs(int layer, int wealthVal, int magicVal) {
    if (layer > n) {
        res = i64max(res, (long long) wealthVal * magicVal);
        return;
    }

    // Umm...
    // Fuck u
//    if (magicVal > 0) {
//        int wealthRemain = wealthVal + data[layer].a;
//        int magicRemain = i32max(0, magicVal - data[layer].b);
//        dfs(layer + 1, wealthRemain, magicRemain);
//    }
//    if (wealthVal > 0) {
//        int magicRemain = magicVal + data[layer].c;
//        int wealthRemain = i32max(0, wealthVal - data[layer].d);
//        dfs(layer + 1, wealthRemain, magicRemain);
//    }
    dfs(layer + 1, wealthVal + data[layer].a, i32max(0, magicVal - data[layer].b));
    dfs(layer + 1, i32max(0, wealthVal - data[layer].d), magicVal + data[layer].c);
}

int main() {
    n = xread();
    for (int t = 1; t <= n; ++t) {
        data[t].a = xread();
        data[t].b = xread();
        data[t].c = xread();
        data[t].d = xread();
    }

    dfs(1, 0, 0);

    printf("%lld", res);
    return 0;
}
