// https://ac.nowcoder.com/acm/contest/23156/1004
// Jelly

// Rewritten in C
// See nc1004.c

// MLE
// ...?

//#include <iostream>
//#include <vector>
//#include <string>
//#include <queue>
//#include <utility>
//#include <optional>
//
//struct pos_t {
//    pos_t() = default;
//
//    pos_t(int ix, int iy, int iz) : x(ix), y(iy), z(iz) {}
//
//    int x;
//    int y;
//    int z;
//};
//
//inline auto operator+(const pos_t &a, const pos_t &b)
//-> pos_t {
//    return {a.x + b.x, a.y + b.y, a.z + b.z};
//}
//
//inline auto operator==(const pos_t &a, const pos_t &b) {
//    return a.x == b.x && a.y == b.y && a.z == b.z;
//}
//
//std::vector<pos_t> offsetPosData{{1,  0,  0},
//                                 {-1, 0,  0},
//                                 {0,  1,  0},
//                                 {0,  -1, 0},
//                                 {0,  0,  1},
//                                 {0,  0,  -1}};
//
//pos_t targetPos;
//std::vector<std::vector<std::vector<bool>>> isVisited;
//std::vector<std::vector<std::string>> jellyData;
//std::queue<std::pair<pos_t, int>> bfsQueue;
//
//std::optional<int> bfs() {
//    while (!bfsQueue.empty()) {
//        auto presentPos = bfsQueue.front();
//        if (presentPos.first == targetPos) {
//            return presentPos.second;
//        }
//        bfsQueue.pop();
//        for (const auto &offsetPos: offsetPosData) {
//            auto newPos = presentPos.first + offsetPos;
//            if (!isVisited[newPos.x][newPos.y][newPos.z] && jellyData[newPos.x][newPos.y][newPos.z] != '*')
//                bfsQueue.emplace(pos_t{newPos.x, newPos.y, newPos.z}, presentPos.second + 1);
//        }
//    }
//    return std::nullopt;
//}
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//
//    int n;
//    std::cin >> n;
//    targetPos = {n, n, n};
//    isVisited = std::vector<std::vector<std::vector<bool>>>
//            (n + 2, std::vector<std::vector<bool>>(n + 2, std::vector<bool>(n + 2, false)));
//    jellyData = std::vector<std::vector<std::string>>(n + 2, std::vector<std::string>(n + 2));
//    std::string boundaryString = std::string(n + 2, '*');
//    for (int t = 0; t <= n + 1; ++t) {
//        jellyData[0][t] = boundaryString;
//        jellyData[n + 1][t] = boundaryString;
//        jellyData[t][0] = boundaryString;
//        jellyData[t][n + 1] = boundaryString;
//    }
//    std::string strTmp;
//    for (int i = 1; i <= n; ++i)
//        for (int j = 1; j <= n; ++j) {
//            std::cin >> strTmp;
//            jellyData[i][j] = '*' + strTmp + '*';
//        }
//
//    bfsQueue.emplace(pos_t(1, 1, 1), 1);
//    auto res = bfs();
//    if (res.has_value())
//        std::cout << res.value() << std::endl;
//    else
//        std::cout << -1 << std::endl;
//    return 0;
//}

// MLE * 2
// emmm...

//#include <iostream>
//#include <vector>
//#include <string>
//#include <queue>
//#include <utility>
//#include <optional>
//
//struct pos_t {
//    pos_t() = default;
//
//    pos_t(int ix, int iy, int iz) : x(ix), y(iy), z(iz) {}
//
//    int x;
//    int y;
//    int z;
//};
//
//inline auto operator+(const pos_t &a, const pos_t &b)
//-> pos_t {
//    return {a.x + b.x, a.y + b.y, a.z + b.z};
//}
//
//inline auto operator==(const pos_t &a, const pos_t &b) {
//    return a.x == b.x && a.y == b.y && a.z == b.z;
//}
//
//std::vector<pos_t> offsetPosData{{1,  0,  0},
//                                 {-1, 0,  0},
//                                 {0,  1,  0},
//                                 {0,  -1, 0},
//                                 {0,  0,  1},
//                                 {0,  0,  -1}};
//
//pos_t targetPos;
//std::vector<std::vector<std::vector<bool>>> isVisited;
//
///**
// * jellyData Defs:
// * true: Available jelly
// * false: Bad jelly OR boundary
// */
//std::vector<std::vector<std::vector<bool>>> jellyData;
//std::queue<std::pair<pos_t, int>> bfsQueue;
//
//std::optional<int> bfs() {
//    while (!bfsQueue.empty()) {
//        auto presentPos = bfsQueue.front();
//        if (presentPos.first == targetPos) {
//            return presentPos.second;
//        }
//        bfsQueue.pop();
//        for (const auto &offsetPos: offsetPosData) {
//            auto newPos = presentPos.first + offsetPos;
//            if (!isVisited[newPos.x][newPos.y][newPos.z] && jellyData[newPos.x][newPos.y][newPos.z])
//                bfsQueue.emplace(pos_t{newPos.x, newPos.y, newPos.z}, presentPos.second + 1);
//        }
//    }
//    return std::nullopt;
//}
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//
//    int n;
//    std::cin >> n;
//    targetPos = {n, n, n};
//    isVisited = std::vector<std::vector<std::vector<bool>>>
//            (n + 2, std::vector<std::vector<bool>>(n + 2, std::vector<bool>(n + 2, false)));
//    jellyData = isVisited;
//    std::string strTmp;
//    for (int i = 1; i <= n; ++i)
//        for (int j = 1; j <= n; ++j) {
//            std::cin >> strTmp;
//            for (int k = 0; k < n; ++k)
//                if (strTmp[k] == '.')
//                    jellyData[i][j][k + 1] = true;
//        }
//
//    bfsQueue.emplace(pos_t(1, 1, 1), 1);
//    auto res = bfs();
//    if (res.has_value())
//        std::cout << res.value() << std::endl;
//    else
//        std::cout << -1 << std::endl;
//    return 0;
//}
