// https://ac.nowcoder.com/acm/contest/22353/D
// [USACO 2017 Dec P]Greedy Gift Takers

// DNF
// Partial Accpeted

//#include <iostream>
//#include <vector>
//#include <unordered_map>
//
//int cowNum;
//std::vector<int> cowDat;
//std::unordered_map<int, bool> checkCowDat;
//
//inline bool checkCow(int cowPos) {
//    // cowPos should start by zero
//    auto iter = checkCowDat.find(cowPos);
//    if (iter != checkCowDat.end())
//        return iter->second;
//    std::vector<int> vCounter(cowPos);
//    for (int t = 0; t < cowPos; ++t)
//        if (cowDat[t] < t)
//            ++vCounter[cowDat[t]];
//    for (int t = 1; t < cowPos; ++t)
//        vCounter[t] += vCounter[t - 1];
//    for (int t = 0; t < cowPos; ++t)
//        if (vCounter[t] > t) {
//            checkCowDat[cowPos] = false;
//            return false;
//        }
//    checkCowDat[cowPos] = true;
//    return true;
//}
//
//
//int main() {
//    checkCowDat[0] = true;
//    std::cin >> cowNum;
//    cowDat = std::vector<int>(cowNum);
//    for (int t = 0; t < cowNum; ++t)
//        std::cin >> cowDat[t];
//    for (int &i: cowDat)
//        i = cowNum - i - 1;
//    if (checkCow(cowNum - 1)) {
//        std::cout << 0;
//        return 0;
//    }
//    int l = 1, r = cowNum - 1, m;
//    while (true) {
//        m = (l + r) >> 1;
//        if (!checkCow(m - 1))
//            r = m - 1;
//        else if (checkCow(m))
//            l = m + 1;
//        else
//            break;
//    }
//    std::cout << cowNum - m;
//    return 0;
//}
