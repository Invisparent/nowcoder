// https://ac.nowcoder.com/acm/contest/23156/1012
// [NOIP2017]奶酪

// Partial Accepted & TLE
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
//    return 0;
//}
