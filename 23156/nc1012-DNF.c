// https://ac.nowcoder.com/acm/contest/23156/1012
// [NOIP2017]奶酪

// DNF
// Partial Accepted (80%) & TLE
// Fuuuuuuuuuuck

//#include <stdio.h>
//#include <string.h>
//#include <stdint.h>
//
//#define IVS_N 1005
//
//typedef struct pos_t {
//    long long x;
//    long long y;
//    long long z;
//} pos_t;
//
//long long n, h, r;
//pos_t data[IVS_N];
//uint8_t visited[IVS_N];
//uint8_t endPos[IVS_N];
//
//uint8_t dfs(int prevPos) {
//    if (endPos[prevPos])
//        return 1;
//
//    visited[prevPos] = 1;
//
//    for (int t = 0; t < n; ++t)
//        if (!visited[t])
//            if ((r * 2) * (r * 2) >= (data[t].x - data[prevPos].x) * (data[t].x - data[prevPos].x) +
//                                     (data[t].y - data[prevPos].y) * (data[t].y - data[prevPos].y) +
//                                     (data[t].z - data[prevPos].z) * (data[t].z - data[prevPos].z))
//                if (dfs(t))
//                    return 1;
//
//    visited[prevPos] = 0;
//
//    return 0;
//}
//
//void solve() {
//    scanf("%lld%lld%lld", &n, &h, &r);
//
//    memset(visited, 0, sizeof(visited));
//    memset(endPos, 0, sizeof(endPos));
//
//    for (int t = 0; t < n; ++t) {
//        scanf("%lld%lld%lld", &data[t].x, &data[t].y, &data[t].z);
//        if (h - data[t].z <= r)
//            endPos[t] = 1;
//    }
//
//    for (int t = 0; t < n; ++t)
//        if (data[t].z <= r)
//            if (dfs(t)) {
//                printf("Yes\n");
//                return;
//            }
//
//    printf("No\n");
//}
//
//int main() {
//    int tt;
//    scanf("%d", &tt);
//
//    while (tt--)
//        solve();
//
//    return 0;
//}
