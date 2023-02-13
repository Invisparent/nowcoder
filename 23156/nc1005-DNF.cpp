// https://ac.nowcoder.com/acm/contest/23156/1005
// [NOIP2014]寻找道路

// DNF
// Not Submitted & Self-Test Failed
// 你是不是想的太简单了点

//#include <iostream>
//#include <unordered_map>
//#include <unordered_set>
//#include <queue>
//#include <utility>
//#include <optional>
//
//int s, t;
//std::unordered_set<int> legalNode, traveledNode;
//std::unordered_map<int, std::unordered_set<int>> seqData, revData;
//std::queue<std::pair<int, int>> bfsQueue;
//
//void phase1_dfs(int prevPos) {
//    traveledNode.insert(prevPos);
//    legalNode.insert(prevPos);
//    for (const auto &nextPos: revData[prevPos])
//        if (traveledNode.find(nextPos) == traveledNode.end())
//            phase1_dfs(nextPos);
//}
//
//std::optional<int> phase2_bfs() {
//    while (!bfsQueue.empty()) {
//        auto prevPos = bfsQueue.front();
//        if (prevPos.first == t)
//            return prevPos.second;
//        traveledNode.insert(prevPos.first);
//        bfsQueue.pop();
//
//        for (const auto &nextPos: seqData[prevPos.first])
//            if (legalNode.find(nextPos) != legalNode.end() && traveledNode.find(nextPos) == traveledNode.end())
//                bfsQueue.emplace(nextPos, prevPos.second + 1);
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
//
//    int a, b;
//    for (int x = 0; x < m; ++x) {
//        std::cin >> a >> b;
//        seqData[a].insert(b);
//        revData[b].insert(a);
//    }
//    std::cin >> s >> t;
//
//    phase1_dfs(t);
//    traveledNode.clear();
//    for (auto iter = seqData.begin(); iter != seqData.end();)
//        if (legalNode.find(iter->first) == legalNode.end())
//            iter = seqData.erase(iter);
//        else
//            ++iter;
//    bfsQueue.emplace(s, 0);
//
//    auto res = phase2_bfs();
//    if (res.has_value())
//        std::cout << res.value() << std::endl;
//    else
//        std::cout << -1 << std::endl;
//    return 0;
//}

// DNF
// Not Submitted & Self-Test Failed
// ...

//#include <iostream>
//#include <unordered_set>
//#include <unordered_map>
//#include <utility>
//#include <optional>
//#include <queue>
//
//int s, t;
//std::unordered_set<int> traveledNode, legalNode;
//std::unordered_map<int, std::unordered_set<int>> seqData, revData;
//std::unordered_map<int, int> seqQueryCounter, revQueryCounter;
//std::queue<std::pair<int, int>> bfsQueue;
//
//void phase1_seqDfs(int prevPos) {
//    /**
//     * Nowcoder doesn't support std::unordered_set<T>.contains()
//     * ...
//     */
//    //if (traveledNode.contains(prevPos))
//    if (traveledNode.find(prevPos) != traveledNode.end())
//        return;
//    traveledNode.insert(prevPos);
//
//    for (const auto &nextPos: seqData[prevPos]) {
//        ++seqQueryCounter[nextPos];
//        phase1_seqDfs(nextPos);
//    }
//}
//
//void phase2_revDfs(int prevPos) {
//    // ...
//    //if (traveledNode.contains(prevPos))
//    if (traveledNode.find(prevPos) != traveledNode.end())
//        return;
//    traveledNode.insert(prevPos);
//
//    for (const auto &nextPos: revData[prevPos]) {
//        ++revQueryCounter[nextPos];
//        phase2_revDfs(nextPos);
//    }
//}
//
//std::optional<int> phase3_bfs() {
//    while (!bfsQueue.empty()) {
//        auto prevData = bfsQueue.front();
//        if (prevData.first == t)
//            return prevData.second;
//        bfsQueue.pop();
//        for (const auto &nextPos: seqData[prevData.first])
//            // ...
//            //if (legalNode.contains(nextPos))
//            if (legalNode.find(nextPos) != legalNode.end())
//                bfsQueue.emplace(nextPos, prevData.second + 1);
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
//
//    int a, b;
//    for (int x = 0; x < m; ++x) {
//        std::cin >> a >> b;
//        seqData[a].insert(b);
//        revData[b].insert(a);
//    }
//    std::cin >> s >> t;
//
//    phase1_seqDfs(s);
//
//    traveledNode.clear();
//
//    phase2_revDfs(t);
//
//    for (const auto &queryCounter: seqQueryCounter)
//        if (queryCounter.second == revQueryCounter[queryCounter.first])
//            legalNode.insert(queryCounter.first);
//    legalNode.insert(s);
//    legalNode.insert(t);
//    for (auto iter = seqData.begin(); iter != seqData.end();)
//        if (legalNode.find(iter->first) == legalNode.end())
//            iter = seqData.erase(iter);
//        else
//            ++iter;
//    traveledNode.clear();
//    bfsQueue.emplace(s, 0);
//
//    auto res = phase3_bfs();
//    if (res.has_value())
//        std::cout << res.value() << std::endl;
//    else
//        std::cout << -1 << std::endl;
//    return 0;
//}
