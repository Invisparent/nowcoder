// https://ac.nowcoder.com/acm/contest/24213/1023
// 美味菜肴

// Partial Accepted

//#include <stdio.h>
//#include <string.h>
//
//#define maxn 55
//#define maxt 1000010
////#define maxt 80
//
//int decay[maxn], dp[maxt];
//
//typedef struct x {
//    int no, val, time;
//} x;
//
//x dish[maxn];
//
//int max(int a, int b) {
//    if (a > b)
//        return a;
//    return b;
//}
//
//int main() {
//    memset(dp, -0x3f, sizeof(dp));
//    int n, m, T;
//    scanf("%d%d%d", &n, &m, &T);
//    for (int t = 1; t <= n; ++t)
//        scanf("%d", &decay[t]);
//    for (int t = 1; t <= m; ++t)
//        scanf("%d%d%d", &dish[t].no, &dish[t].val, &dish[t].time);
//    for (int i = 1; i <= m; ++i) {
//        if (dish[i].time <= T) {
//            for (int j = T; j >= dish[i].time; --j)
//                if (dp[j - dish[i].time] != dp[maxt - 1])
//                    dp[j] = max(dp[j], dp[j - dish[i].time] + dish[i].val - j * decay[dish[i].no]);
//            dp[dish[i].time] = max(dp[dish[i].time], dish[i].val - dish[i].time * decay[dish[i].no]);
//        }
//    }
//    for (int t = T; t >= 1; --t)
//        if (dp[t] != dp[maxt - 1]) {
//            printf("%d", dp[t]);
//            return 0;
//        }
//}

// DNF

//#include <stdio.h>
//
////#define maxt 100010
//#define maxt 80
//#define maxn 55
//
//int d[maxn], dp[maxt];
//
//typedef struct x {
//    int decay, val, time;
//} x;
//
//x dat[maxn];
//
//int max(int a, int b) {
//    if (a > b)
//        return a;
//    return b;
//}
//
//int main() {
//    for (int t = 0; t < maxt; ++t)
//        dp[t] = -0x3f3f3f3f;
//    int n, m, T;
//    scanf("%d%d%d", &n, &m, &T);
//    for (int t = 1; t <= n; ++t)
//        scanf("%d", &d[t]);
//    for (int t = 1; t <= m; ++t)
//        scanf("%d%d%d", &dat[t].decay, &dat[t].val, &dat[t].time);
//    for (int t = 1; t <= m; ++t)
//        dat[t].decay = d[dat[t].decay];
//    dp[0] = 0;
//    for (int i = 1; i <= m; ++i) {
//        for (int j = T; j >= dat[i].time; --j)
//            if (dp[j - dat[i].time] != -0x3f3f3f3f)
//                dp[j] = max(dp[j], dp[j - dat[i].time] + dp[dat[i].val] - j * dat[i].decay);
//
//    }
//    for (int t = T; t > 0; --t)
//        if (dp[t] != -0x3f3f3f3f) {
//            printf("%d", dp[t]);
//            return 0;
//        }
//}
