// https://ac.nowcoder.com/acm/contest/22353/J
// [NOIP2011]聪明的质监员

// Rewritten in C
// See ncJ.c

// DNF
// Wrong Answer

//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <utility>
//
///**
// *  oreDat: std::vector<std::pair<oreWeight, oreValue>>, first element align to oreDat[1]
// *  rangeDat: [L, R], first element align to rangeDat[1]
// */
//std::vector<std::pair<int, int>> oreDat, rangeDat;
//std::vector<std::pair<int, long long>> pfsDat;
//
///**
// *  Legacy version
// *  O(n^2), Partial Accepted & TLE
// */
////inline long long W(const int &target) {
////    long long r = 0, sigmaTag, sigmaValue;
////    // !!!
////    // DO NOT PASS REFERENCE !!!
////    // !!!
////    for (std::pair<int, int> range: rangeDat) {
////        sigmaTag = 0;
////        sigmaValue = 0;
////        while (range.first <= range.second) {
////            if (oreDat[range.first].first >= target) {
////                ++sigmaTag;
////                sigmaValue += oreDat[range.first].second;
////            }
////            ++range.first;
////        }
////        r += sigmaTag * sigmaValue;
////    }
////    return r;
////}
//
///**
// *  Wrong version of pfs
// */
//
/////**
//// *  Using pfs
//// */
////inline long long W(const int &target) {
////    // GVI
////    pfsDat = std::vector<std::pair<int, long long>>(oreDat.size());
////    for (int t = 1; t < oreDat.size(); ++t) {
////        if (oreDat[t].first >= target) {
////            ++pfsDat[t].first;
////            pfsDat[t].second = oreDat[t].second;
////        }
////        pfsDat[t].first += pfsDat[t - 1].first;
////        pfsDat[t].second += pfsDat[t - 1].second;
////    }
////    // Done
////
////    long long r = 0;
////    for (const std::pair<int, int> &range: rangeDat)
////        r += (pfsDat[range.second].first - pfsDat[range.first - 1].first) *
////             (pfsDat[range.second].second - pfsDat[range.first - 1].second);
////    return r;
////}
//
///**
// *  Also Wrong Answer
// */
//
//inline long long W(const int &target) {
//    // GVI
//    pfsDat = std::vector<std::pair<int, long long>>(oreDat.size());
//    for (int t = 1; t < oreDat.size(); ++t) {
//        pfsDat[t].first = pfsDat[t - 1].first + (oreDat[t].first >= target);
//        pfsDat[t].second = pfsDat[t - 1].second + (oreDat[t].first >= target) * oreDat[t].second;
//    }
//    // Done
//
//    long long r = 0;
//    for (const std::pair<int, int> &range: rangeDat)
//        r += (pfsDat[range.second].first - pfsDat[range.first - 1].first) *
//             (pfsDat[range.second].second - pfsDat[range.first - 1].second);
//    return r;
//}
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//    int n, m;
//    long long S;
//    std::cin >> n >> m >> S;
//    int l = 0, r = 0, mid;
//
//    // GVI
//    // First ore align to oreDat[1]
//    oreDat = std::vector<std::pair<int, int>>(n + 1);
//    // First range align to rangeDat[1]
//    rangeDat = std::vector<std::pair<int, int>>(m + 1);
//    for (int t = 1; t <= n; ++t) {
//        std::cin >> oreDat[t].first >> oreDat[t].second;
//        if (oreDat[t].first > r)
//            r = oreDat[t].first;
//    }
//    for (int t = 1; t <= m; ++t)
//        std::cin >> rangeDat[t].first >> rangeDat[t].second;
//    // Done
//
//    while (l < r) {
//        mid = (l + r + 1) >> 1;
//        if (W(mid) > S)
//            l = mid;
//        else
//            r = mid - 1;
//    }
//    std::cout << std::min(std::abs(S - W(l)), std::abs(S - W(l + 1)));
//    return 0;
//}
