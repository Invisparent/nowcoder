// https://ac.nowcoder.com/acm/contest/24213/1012
// [NOIP1999]拦截导弹

#include <stdio.h>
#include <limits.h>

#define maxn 100005

int dat[maxn], dpd[maxn], dpu[maxn];

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int main() {
    int n = 1;
    while (scanf("%d", &dat[n]) != EOF) {
        dpd[n] = 1;
        dpu[n] = 1;
        ++n;
    }
    --n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i - 1; ++j)
            if (dat[j] >= dat[i])
                dpd[i] = max(dpd[i], dpd[j] + 1);
    int resA = INT_MIN;
    for (int t = 1; t <= n; ++t)
        resA = max(resA, dpd[t]);

    /**
     *  Naive...
     */
//    int res = 1;
//    for (int t = 2; t <= n; ++t)
//        if (dat[t] > dat[t - 1])
//            ++res;
//    printf("%d\n%d", dpd[n], res);

/**
 *  Dilworth's Theorem:
 *  狄尔沃斯定理:
 *
 *  最少的不上升子序列的个数 == 最长上升子序列的长度
 *  最少的上升子序列的个数 == 最长不上升子序列的长度
 *  最少的不下降子序列的个数 == 最长下降子序列的长度
 *  最少的下降子序列的个数 == 最长不下降子序列的长度
 *
 *  不用你感觉这么写是对的，它就是对的……
 */

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i - 1; ++j)
            if (dat[i] > dat[j])
                dpu[i] = max(dpu[i], dpu[j] + 1);
    int resB = INT_MIN;
    for (int t = 1; t <= n; ++t)
        resB = max(resB, dpu[t]);
    printf("%d\n%d", resA, resB);
    return 0;
}
