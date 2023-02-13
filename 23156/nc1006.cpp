// https://ac.nowcoder.com/acm/contest/23156/1006
// 送外卖

// DNF
// See nc1006.c

//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_set>
//#include <optional>
//
//int n;
//std::string dfsPath;
//std::vector<std::optional<int>> dataA, dataB;
//std::unordered_set<int> traveledNode;
//
//std::optional<int> dfs(int pos) {
//
//}
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//
//    std::cin >> n;
//    dataA = std::vector<std::optional<int>>(n + 2, 0);
//    dataB = std::vector<std::optional<int>>(n + 2, 0);
//    for (int t = 1; t <= n; ++t)
//        std::cin >> dataA[t].value();
//    for (int t = 1; t <= n; ++t)
//        std::cin >> dataB[t].value();
//    for (int t = 1; t <= n; ++t) {
//        if (t + dataA[t].value() < 1 && t + dataA[t].value() > n)
//            dataA[t] = std::nullopt;
//        if (t + dataB[t].value() < 1 && t + dataB[t].value() > n)
//            dataB[t] = std::nullopt;
//    }
//
//    auto res = dfs(1);
//
//}
