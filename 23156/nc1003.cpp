// https://ac.nowcoder.com/acm/contest/23156/1003
// 模拟战役

// DNF
// Not Submitted
// FUCK... Coding in a mess
// Refactor it

//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_set>
//#include <utility>
//#include <optional>
//#include <algorithm>
//#include <functional>
//
//#define IVS_N 4
//
//int eGlobalCounter, qGlobalCounter;
//std::vector<int> eBlockData, qBlockData;
//
//const std::vector<std::pair<int, int>> offsetData{{1,  1},
//                                                  {1,  0},
//                                                  {1,  -1},
//                                                  {0,  -1},
//                                                  {-1, -1},
//                                                  {-1, 0},
//                                                  {-1, 1},
//                                                  {0,  1}};
//
//template<>
//struct std::hash<std::pair<int, int>> {
//    inline auto operator()(const std::pair<int, int> &p) const {
//        return ((std::hash<int>()(p.first)) << 1) ^ std::hash<int>()(p.second);
//    }
//};
//
//inline auto operator+(const std::pair<int, int> &pa, const std::pair<int, int> &pb)
//-> std::pair<int, int> {
//    return {pa.first + pb.first, pa.second + pb.second};
//}
//
//inline bool dfs(std::unordered_set<std::pair<int, int>> &data, const std::optional<std::pair<int, int>> &lastPos,
//                int &globalCounter, std::vector<int> &globalCounterContainer) {
//    if (data.empty())
//        return false;
//
//    std::pair<int, int> lastAvailablePos;
//    if (lastPos.has_value()) {
//        ++globalCounter;
//        lastAvailablePos = lastPos.value();
//    } else {
//        globalCounterContainer.push_back(globalCounter + 1);
//        globalCounter = 0;
//        lastAvailablePos = *data.begin();
//    }
//    data.erase(lastAvailablePos);
//
//    for (const auto &offsetPos: offsetData) {
//        auto iter = data.find(lastAvailablePos + offsetPos);
//        if (iter != data.end())
//            dfs(data, *iter, globalCounter);
//    }
//    return true;
//}
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//
//    int m;
//    std::cin >> m;
//
//    std::unordered_set<std::pair<int, int>> eData, qData;
//    std::string strTmp;
//    for (int i = 1; i <= IVS_N; ++i) {
//        std::cin >> strTmp;
//        for (int j = 0; j < m; ++j)
//            if (strTmp[j] == '*')
//                eData.emplace(i, j + 1);
//    }
//    for (int i = 1; i <= IVS_N; ++i) {
//        std::cin >> strTmp;
//        for (int j = 0; j <= m; ++j)
//            if (strTmp[j] == '*')
//                qData.emplace(i, j + 1);
//    }
//
//    int eNum = 0, qNum = 0;
//
//    while (dfs(eData, std::nullopt)) {
//        ++eNum;
//    }
//    while (dfs(qData, std::nullopt)) {
//        ++qNum;
//    }
//
//    std::ranges::sort(eBlockData, std::greater());
//    std::ranges::sort(qBlockData);
//
//}

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <optional>
#include <numeric>

#define IVS_N 4

const std::vector<std::pair<int, int>> offsetPosSet{{0,  1},
                                                    {1,  1},
                                                    {1,  0},
                                                    {1,  -1},
                                                    {0,  -1},
                                                    {-1, -1},
                                                    {-1, 0},
                                                    {-1, 1}};

template<>
struct std::hash<std::pair<int, int>> {
    auto operator()(const std::pair<int, int> &p) const {
        return (std::hash<int>()(p.first) << 1) ^ std::hash<int>()(p.second);
    }
};

auto operator+(const std::pair<int, int> &a, const std::pair<int, int> &b)
-> std::pair<int, int> {
    return {a.first + b.first, a.second + b.second};
}

std::unordered_set<std::pair<int, int>> eData, qData;

int dfs(std::unordered_set<std::pair<int, int>> &data, const std::optional<std::pair<int, int>> &lastPos) {
    if (data.empty())
        return 0;
    int retVal = 1;

    std::pair<int, int> presentPos;
    if (lastPos.has_value())
        presentPos = lastPos.value();
    else
        presentPos = *data.begin();
    data.erase(presentPos);

    for (const auto &offsetPos: offsetPosSet) {
        auto iter = data.find(presentPos + offsetPos);
        if (iter != data.end())
            retVal += dfs(data, *iter);
    }
    return retVal;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int m;
    std::cin >> m;

    std::string strTmp;
    for (int i = 1; i <= IVS_N; ++i) {
        std::cin >> strTmp;
        for (int j = 0; j < m; ++j)
            if (strTmp[j] == '*')
                eData.emplace(i, j + 1);
    }
    for (int i = 1; i <= IVS_N; ++i) {
        std::cin >> strTmp;
        for (int j = 0; j < m; ++j)
            if (strTmp[j] == '*')
                qData.emplace(i, j + 1);
    }

    std::vector<int> eBlockData, qBlockData;
    while (true) {
        int retVal = dfs(eData, std::nullopt);
        if (retVal == 0)
            break;
        else
            eBlockData.push_back(retVal);
    }
    while (true) {
        int retVal = dfs(qData, std::nullopt);
        if (retVal == 0)
            break;
        else
            qBlockData.push_back(retVal);
    }
    if (eBlockData.size() > qBlockData.size()) {
        std::cout << -1 << std::endl;
        return 0;
    }

    /**
     * Oh no
     * Nowcoder doesn't support std::ranges::sort()
     * ...
     */
    //std::ranges::sort(qBlockData);
    std::sort(qBlockData.begin(), qBlockData.end());

    auto iter = qBlockData.begin() + (long long) eBlockData.size() - 1;
    auto res = std::accumulate(iter, qBlockData.end(), 0);
    std::cout << res;
    return 0;
}
