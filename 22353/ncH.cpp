// https://ac.nowcoder.com/acm/contest/22353/H
// [NOIP2012]借教室

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

int dayNum, queryNum;
std::vector<int> roomDat;
std::vector<std::pair<int, std::pair<int, int>>> queryDat;
std::unordered_map<int, bool> checkDat;

// legalCheck includes the parameter query itself
inline bool legalCheck(const int &query) {
    auto checkIter = checkDat.find(query);
    if (checkIter != checkDat.end())
        return checkIter->second;
    // Align to pfd[1]
    std::vector<long long> pfd(dayNum + 1);
    for (int t = 1; t <= query; ++t) {
        pfd[queryDat[t].second.first] += queryDat[t].first;
        if (queryDat[t].second.second + 1 <= dayNum)
            pfd[queryDat[t].second.second + 1] -= queryDat[t].first;
    }
    for (int t = 1; t <= dayNum; ++t)
        pfd[t] += pfd[t - 1];
    for (int t = 1; t <= dayNum; ++t)
        if (pfd[t] > roomDat[t]) {
            checkDat[query] = false;
            return false;
        }
    checkDat[query] = true;
    return true;
}

int main() {
    // GVI
    std::cin >> dayNum >> queryNum;
    // First day align to roomDat[1]
    roomDat = std::vector<int>(dayNum + 1);
    for (int t = 1; t <= dayNum; ++t)
        std::cin >> roomDat[t];
    // First query align to queryDat[1]
    queryDat = std::vector<std::pair<int, std::pair<int, int>>>(queryNum + 1);
    for (int t = 1; t <= queryNum; ++t)
        std::cin >> queryDat[t].first >> queryDat[t].second.first >> queryDat[t].second.second;
    // Done

    /**
     *  Check the first query below before binarySearch is completely wrong
     *  First query may not request the room on the first day
     *  And the binarySearch is well-defined to deal with this situation
     */
//    // Check if the first query is legal
//    if (queryDat.front().first > roomDat.front()) {
//        std::cout << -1 << std::endl << 1;
//        return 0;
//    }

    // Check if the final query is legal
    if (legalCheck(queryNum)) {
        std::cout << 0;
        return 0;
    }

    /**
     *  Also redundant
     */
//    checkDat[1] = true;

    checkDat[queryNum] = false;
    int l = 1, r = queryNum, m;
    while (true) {
        m = (l + r) >> 1;
        if (legalCheck(m))
            l = m + 1;
        else if (!legalCheck(m - 1))
            r = m - 1;
        else
            break;
    }
    std::cout << -1 << std::endl << m;
    return 0;
}
