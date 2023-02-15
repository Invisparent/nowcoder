// https://ac.nowcoder.com/acm/contest/23156/1014
// wyh的迷宫

// Multiple Solutions
// DFS

// 我希望我没有看错题
// ...

// DNF
// Partial Accepted (50%) & TLE
// ..................................................................

//#include <stdio.h>
//#include <string.h>
//#include <stdint.h>
//
//#define IVS_N 1005
//
//int n, m;
//// endI, endJ
//int ei, ej;
//uint8_t visited[IVS_N][IVS_N];
//
//int xread() {
//    int retVal = 0;
//    char ch = (char) getchar();
//
//    while (ch < '0' || ch > '9')
//        ch = (char) getchar();
//
//    while (ch >= '0' && ch <= '9') {
//        retVal = (retVal << 3) + (retVal << 1) + ch - '0';
//        ch = (char) getchar();
//    }
//
//    return retVal;
//}
//
//uint8_t dfs(int pi, int pj) {
//    if (pi == ei && pj == ej)
//        return 1;
//
//    visited[pi][pj] = 1;
//
//    if (!visited[pi + 1][pj])
//        if (dfs(pi + 1, pj))
//            return 1;
//    if (!visited[pi][pj + 1])
//        if (dfs(pi, pj + 1))
//            return 1;
//    if (!visited[pi - 1, pj])
//        if (dfs(pi - 1, pj))
//            return 1;
//    if (!visited[pi][pj - 1])
//        if (dfs(pi, pj - 1))
//            return 1;
//
//    visited[pi][pj] = 0;
//
//    return 0;
//}
//
//void solve() {
//    n = xread();
//    m = xread();
//
//    memset(visited, 0, sizeof(visited));
//    for (int t = 0; t <= n; ++t) {
//        visited[t][0] = 1;
//        visited[t][m + 1] = 1;
//    }
//    for (int t = 0; t <= m; ++t) {
//        visited[0][t] = 1;
//        visited[n + 1][t] = 1;
//    }
//
//    // begI, begJ
//    int bi, bj;
//    char ch;
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= m; ++j) {
//            ch = (char) getchar();
//            if (ch == 's') {
//                bi = i;
//                bj = j;
//            } else if (ch == 't') {
//                ei = i;
//                ej = j;
//            }
//                // OK you are right...
////            else if (ch == 'x') {
////                visited[i + 1][j] = 1;
////                visited[i - 1][j] = 1;
////                visited[i][j + 1] = 1;
////                visited[i][j - 1] = 1;
////            }
//            else if (ch == 'x')
//                visited[i][j] = 1;
//        }
//        getchar();
//    }
////    visited[ei][ej] = 0;
//
//    if (dfs(bi, bj))
//        printf("YES\n");
//    else
//        printf("NO\n");
//}
//
//int main() {
//    int tt = xread();
//
//    while (tt--)
//        solve();
//
//    return 0;
//}
