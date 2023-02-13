// https://ac.nowcoder.com/acm/contest/23156/1007
// 迷宫

// DNF
// Not Submitted

//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_set>
//#include <queue>
//#include <optional>
//#include <utility>
//#include <cstdint>
//
//std::vector<std::string> data;
//std::queue<std::pair<std::pair<int, int>, int>> bfsQueue;
//std::pair<int, int> begPos, endPos, keyPos;
//
//const std::vector<std::pair<int, int>> offsetData{{1,  0},
//                                                  {0,  1},
//                                                  {-1, 0},
//                                                  {0,  -1}};
//
//inline bool operator==(const std::pair<int, int> &a, const std::pair<int, int> &b) {
//    return a.first == b.first && a.second == b.second;
//}
//
//inline auto operator+(const std::pair<int, int> &a, const std::pair<int, int> &b)
//-> std::pair<int, int> {
//    return {a.first + b.first, a.second + b.second};
//}
//
//template<>
//struct std::hash<std::pair<int, int>> {
//    auto operator()(const std::pair<int, int> &p) const {
//        return (std::hash<int>()(p.first) << 1) ^ std::hash<int>()(p.second);
//    }
//};
//
//std::unordered_set<std::pair<int, int>> traveledPos;
//
///**
// * @param stat
// * 0: Find keyPos
// * 1: Find endPos with key
// * 2: Find endPos without key
// */
//std::optional<int> bfs(uint8_t stat) {
//    /**
//     * BeginPos should be the first element of bfsQueue
//     */
//    std::pair<int, int> targetPos;
//    char targetChar;
//    bool hasKey;
//    if (stat == 0) {
//        targetPos = keyPos;
//        targetChar = 'K';
//        hasKey = false;
//    } else if (stat == 1) {
//        targetPos = endPos;
//        targetChar = 'E';
//        hasKey = true;
//    } else {
//        targetPos = endPos;
//        targetChar = 'E';
//        hasKey = false;
//    }
//
//    while (!bfsQueue.empty()) {
//        auto prevData = bfsQueue.front();
//        if (prevData.first == targetPos)
//            return prevData.second;
//        traveledPos.emplace(prevData.first);
//        bfsQueue.pop();
//
//        for (const auto &offsetPos: offsetData) {
//            auto nextPos = prevData.first + offsetPos;
//            char ch = data[nextPos.first][nextPos.second];
//            if (hasKey) {
//                if (ch != 'W')
//                    bfsQueue.emplace(nextPos, prevData.second + 1);
//            } else if (ch != 'W' && ch != 'D')
//                bfsQueue.emplace(nextPos, prevData.second + 1);
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
//    int n, m;
//    std::cin >> n >> m;
//    data = std::vector<std::string>(n);
//    for (int t = 0; t < n; ++t)
//        std::cin >> data[t];
//    for (int i = 1; i < n; ++i)
//        for (int j = 1; j < m; ++j)
//            if (data[i][j] == 'S')
//                begPos = {i, j};
//            else if (data[i][j] == 'E')
//                endPos = {i, j};
//            else if (data[i][j] == 'K')
//                keyPos = {i, j};
//
//    bfsQueue.emplace(begPos, 0);
//    auto res1 = bfs(0);
//    if (res1.has_value()) {
//        bfsQueue = decltype(bfsQueue)();
//        bfsQueue.emplace(keyPos, 0);
//        auto res2 = bfs(1);
//        bfsQueue = decltype(bfsQueue)();
//        bfsQueue.emplace(begPos, 0);
//        auto res3 = bfs(2);
//
//        if (res3.has_value())
//            std::cout << std::min(res1.value() + res2.value(), res3.value());
//        else if (res2.has_value())
//            std::cout << res1.value() + res2.value();
//        else
//            std::cout << -1;
//        return 0;
//    } else {
//        bfsQueue = decltype(bfsQueue)();
//        bfsQueue.emplace(begPos, 0);
//        auto res3 = bfs(2);
//        if (res3.has_value())
//            std::cout << res3.value();
//        else
//            std::cout << -1;
//    }
//    return 0;
//}

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <utility>
#include <optional>
#include <climits>

std::vector<std::string> data;

inline auto operator+(const std::pair<int, int> &a, const std::pair<int, int> &b)
-> std::pair<int, int> {
    return {a.first + b.first, a.second + b.second};
}

inline bool operator==(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    return a.first == b.first && a.second == b.second;
}

std::vector<std::pair<int, int>> offsetData{{0,  1},
                                            {-1, 0},
                                            {0,  -1},
                                            {1,  0}};

template<>
struct std::hash<std::pair<int, int>> {
    inline auto operator()(const std::pair<int, int> &p) const {
        return (std::hash<int>()(p.first) << 1) ^ std::hash<int>()(p.second);
    }
};

std::optional<int> bfs(const std::pair<int, int> &begPos, const std::pair<int, int> &endPos, bool hasKey) {
    std::queue<std::pair<std::pair<int, int>, int>> queue;
    queue.emplace(begPos, 0);
    std::unordered_set<std::pair<int, int>> traveledNode;

    while (!queue.empty()) {
        auto prevPos = queue.front().first;
        auto prevStep = queue.front().second;
        if (prevPos == endPos)
            return prevStep;
        traveledNode.insert(prevPos);
        queue.pop();

        for (const auto &offsetPos: offsetData) {
            auto nextPos = prevPos + offsetPos;
            char ch = data[nextPos.first][nextPos.second];
            if (ch == 'W' || (ch == 'D' && !hasKey))
                continue;
            if (traveledNode.find(nextPos) == traveledNode.end())
                queue.emplace(nextPos, prevStep + 1);
        }
    }
    return std::nullopt;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    data = std::vector<std::string>(n);
    for (int t = 0; t < n; ++t)
        std::cin >> data[t];

    std::pair<int, int> begPos, endPos, keyPos;
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
            if (data[i][j] == 'S')
                begPos = {i, j};
            else if (data[i][j] == 'E')
                endPos = {i, j};
            else if (data[i][j] == 'K')
                keyPos = {i, j};

    auto res1 = bfs(begPos, keyPos, false);
    auto res2 = bfs(keyPos, endPos, true);
    auto res3 = bfs(begPos, endPos, false);

    if ((!res1.has_value() || !res2.has_value()) && !res3.has_value())
        std::cout << -1 << std::endl;
    else {
        int res = INT_MAX;
        if (res1.has_value() && res2.has_value())
            res = std::min(res, res1.value() + res2.value());
        if (res3.has_value())
            res = std::min(res, res3.value());
        std::cout << res << std::endl;
    }
    return 0;
}
