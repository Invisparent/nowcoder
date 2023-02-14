// https://ac.nowcoder.com/acm/contest/23156/1009
// [SDOI2016]齿轮

// DNF
// Wrong Answer

//#include <iostream>
//#include <vector>
//#include <utility>
//
//#define IVS_BEGIN_POS 1
//
//struct Chain {
//    int v;
//    int x;
//    int y;
//};
//
//int n, m, no;
//std::vector<bool> visitedNode;
//std::vector<std::vector<Chain>> data;
//
///**
// * cfg:
// * When the beginning gear turns cfg.first deg
// * The last gear turns cfg.second deg
// */
//inline bool dfs(int pos, std::pair<__int128, __int128> cfg, int len) {
//    visitedNode[pos] = true;
//    if (len == n) {
//        for (const auto &c: data[pos])
//            if (c.v == IVS_BEGIN_POS)
//                if (cfg.first * c.x == cfg.second * c.y)
//                    return true;
//        for (const auto &c: data[pos])
//            if (c.v == IVS_BEGIN_POS)
//                if (cfg.first * c.x == cfg.second * c.y)
//                    return true;
//    }
//
//    for (const auto &c: data[pos]) {
//        if (!visitedNode[c.v])
//            if (dfs(c.v, {cfg.first * c.x, cfg.second * c.y}, len + 1))
//                return true;
//    }
//
//    visitedNode[pos] = false;
//    return false;
//}
//
//inline void solve() {
//    std::cin >> n >> m;
//    visitedNode = std::vector<bool>(n + 1, false);
//    data = std::vector<std::vector<Chain>>(n + 1);
//
//    int u, v, x, y;
//    // Something you've lost there...
////    for (int t = 0; t < m; ++t) {
////        std::cin >> u >> v >> x >> y;
////        data[u].emplace_back(Chain{v, x, y});
////    }
//    for (int t = 0; t < m; ++t) {
//        std::cin >> u >> v >> x >> y;
//        data[u].emplace_back(Chain{v, x, y});
//        data[v].emplace_back(Chain{u, y, x});
//    }
//
//    if (dfs(IVS_BEGIN_POS, {1, 1}, 1))
//        std::cout << "Case #" << ++no << ": Yes" << std::endl;
//    else
//        std::cout << "Case #" << ++no << ": No" << std::endl;
//}
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//
//    int tt;
//    std::cin >> tt;
//    while (tt--)
//        solve();
//    return 0;
//}
