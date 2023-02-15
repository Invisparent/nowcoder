// https://ac.nowcoder.com/acm/contest/23156/1012
// [NOIP2017]奶酪

// DNF
// See nc1012.c

// Partial Accepted (70%) & TLE
// ...?

//#include <iostream>
//#include <vector>
//
//struct pos_t {
//    pos_t() = default;
//
//    pos_t(int ix, int iy, int iz, bool ib = false, bool ie = false) : x(ix), y(iy), z(iz), beg(ib), end(ie) {}
//
//    int x, y, z;
//    bool beg, end;
//};
//
//int n, h, r;
//std::vector<pos_t> data;
//std::vector<bool> visited;
//
//inline int pwr(int x) {
//    return x * x;
//}
//
//inline bool isIntersect(const pos_t &a, const pos_t &b) {
//    return pwr(r * 2) >= pwr(a.x - b.x) + pwr(a.y - b.y) + pwr(a.z - b.z);
//}
//
//bool dfs(int prevPos) {
//    if (data[prevPos].end)
//        return true;
//
//    visited[prevPos] = true;
//
//    for (int t = 0; t < n; ++t)
//        // What the fuck ???
//        //if (!visited[prevPos])
//        if (!visited[t])
//            if (isIntersect(data[prevPos], data[t]))
//                if (dfs(t))
//                    return true;
//
//    visited[prevPos] = false;
//    return false;
//}
//
//void solve() {
//    std::cin >> n >> h >> r;
//
//    data = std::vector<pos_t>(n);
//    visited = std::vector<bool>(n, false);
//
//    for (int t = 0; t < n; ++t) {
//        std::cin >> data[t].x >> data[t].y >> data[t].z;
//        if (isIntersect(data[t], pos_t{data[t].x, data[t].y, -r}))
//            data[t].beg = true;
//        else
//            data[t].beg = false;
//        if (isIntersect(data[t], pos_t(data[t].x, data[t].y, h + r)))
//            data[t].end = true;
//        else
//            data[t].end = false;
//    }
//
//    /**
//     * You only tried one begPos
//     * ...
//     */
////    int begPos = 0;
////    while (!data[begPos].beg)
////        ++begPos;
////
////    if (dfs(begPos))
////        std::cout << "Yes" << std::endl;
////    else
////        std::cout << "No" << std::endl;
//
//    for (auto t = 0; t < data.size(); ++t)
//        if (data[t].beg)
//            if (dfs(t)) {
//                std::cout << "Yes" << std::endl;
//                return;
//            }
//
//    std::cout << "No" << std::endl;
//}
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//
//    int tt;
//    std::cin >> tt;
//
//    while (tt--)
//        solve();
//
//    return 0;
//}

// Partial Accepted (80%) & TLE
// ...

//#include <iostream>
//#include <vector>
//#include <unordered_set>
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
//int n, h, r;
//std::vector<bool> visited;
//std::vector<pos_t> data;
//std::vector<std::vector<int>> link;
//std::vector<int> begPos;
////std::unordered_set<int> endPos;
//std::vector<bool> endPos;
//
//inline auto pwr(int x) {
//    return x * x;
//}
//
//inline auto isIntersect(const pos_t &a, const pos_t &b) {
//    return pwr(2 * r) >= pwr(a.x - b.x) + pwr(a.y - b.y) + pwr(a.z - b.z);
//}
//
//bool dfs(int prevPos) {
//    if (endPos[prevPos])
//        return true;
//
//    visited[prevPos] = true;
//
//    for (const auto &nextPos: link[prevPos])
//        if (!visited[nextPos])
//            if (dfs(nextPos))
//                return true;
//
//    visited[prevPos] = false;
//
//    return false;
//}
//
//void solve() {
//    std::cin >> n >> h >> r;
//
//    visited = decltype(visited)(n, false);
//    data = decltype(data)(n);
//    link = decltype(link)(n);
//
//    /**
//     * You... Forget something...
//     * Wrong Answer...
//     */
//    begPos.clear();
//    endPos = decltype(endPos)(n, false);
//
//    for (int t = 0; t < n; ++t) {
//        std::cin >> data[t].x >> data[t].y >> data[t].z;
//        if (data[t].z <= r)
//            begPos.push_back(t);
//        if (h - data[t].z <= r)
//            endPos[t] = true;
//    }
//
//    for (int i = 0; i < n; ++i)
//        for (int j = i + 1; j < n; ++j)
//            if (isIntersect(data[i], data[j])) {
//                link[i].push_back(j);
//                link[j].push_back(i);
//            }
//
//    for (const auto &bp: begPos)
//        if (dfs(bp)) {
//            std::cout << "Yes" << std::endl;
//            return;
//        }
//
//    std::cout << "No" << std::endl;
//}
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//
//    int tt;
//    std::cin >> tt;
//
//    while (tt--)
//        solve();
//
//    return 0;
//}

// Partial Accepted (90%) & TLE
// ...????????????
// Replace int with long long

//#include <iostream>
//#include <vector>
//#include <unordered_set>
//
//struct pos_t {
//    pos_t() = default;
//
//    pos_t(long long ix, long long iy, long long iz) : x(ix), y(iy), z(iz) {}
//
//    long long x;
//    long long y;
//    long long z;
//};
//
//long long n, h, r;
//std::vector<bool> visited;
//std::vector<pos_t> data;
//std::vector<std::vector<long long>> link;
//std::vector<long long> begPos;
////std::unordered_set<long long> endPos;
//std::vector<bool> endPos;
//
//inline auto pwr(long long x) {
//    return x * x;
//}
//
//inline auto isIntersect(const pos_t &a, const pos_t &b) {
//    return pwr(2 * r) >= pwr(a.x - b.x) + pwr(a.y - b.y) + pwr(a.z - b.z);
//}
//
//bool dfs(long long prevPos) {
//    if (endPos[prevPos])
//        return true;
//
//    visited[prevPos] = true;
//
//    for (const auto &nextPos: link[prevPos])
//        if (!visited[nextPos])
//            if (dfs(nextPos))
//                return true;
//
//    visited[prevPos] = false;
//
//    return false;
//}
//
//void solve() {
//    std::cin >> n >> h >> r;
//
//    visited = decltype(visited)(n, false);
//    data = decltype(data)(n);
//    link = decltype(link)(n);
//
//    /**
//     * You... Forget something...
//     * Wrong Answer...
//     */
//    begPos.clear();
//    endPos = decltype(endPos)(n, false);
//
//    for (long long t = 0; t < n; ++t) {
//        std::cin >> data[t].x >> data[t].y >> data[t].z;
//        if (data[t].z <= r)
//            begPos.push_back(t);
//        if (h - data[t].z <= r)
//            endPos[t] = true;
//    }
//
//    for (long long i = 0; i < n; ++i)
//        for (long long j = i + 1; j < n; ++j)
//            if (isIntersect(data[i], data[j])) {
//                link[i].push_back(j);
//                link[j].push_back(i);
//            }
//
//    for (const auto &bp: begPos)
//        if (dfs(bp)) {
//            std::cout << "Yes" << std::endl;
//            return;
//        }
//
//    std::cout << "No" << std::endl;
//}
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//
//    long long tt;
//    std::cin >> tt;
//
//    while (tt--)
//        solve();
//
//    return 0;
//}
