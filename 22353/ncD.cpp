// https://ac.nowcoder.com/acm/contest/22353/D
// [USACO 2017 Dec P]Greedy Gift Takers

// rnm总算过了
// 以后别给自己找事，垃圾算法题没必要非得为了省那一个空间，数组都从0开始

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

#include <iostream>
#include <vector>
#include <unordered_map>

int cowNum;
std::vector<int> cowDat;
std::unordered_map<int, bool> legalDat;

inline bool legalCheck(const int &cowPos) {
    auto iter = legalDat.find(cowPos);
    if (iter != legalDat.end())
        return iter->second;
    // First position align to insertCounter[1]
    std::vector<int> insertCounter(cowPos);
    for (int t = 1; t < cowPos; ++t)
        if (cowDat[t] < cowPos)
            ++insertCounter[cowDat[t]];
    for (int t = 1; t < cowPos; ++t)
        insertCounter[t] += insertCounter[t - 1];
    for (int t = 1; t < cowPos; ++t)
        if (insertCounter[t] >= t) {
            legalDat[cowPos] = false;
            return false;
        }
    legalDat[cowPos] = true;
    return true;
}

int main() {
    // Global variable initialization
    legalDat[1] = true;
    std::cin >> cowNum;
    cowDat = std::vector<int>(cowNum + 1);
    for (int t = 1; t <= cowNum; ++t)
        // First cow align to cowDat[1]
        std::cin >> cowDat[t];
    for (int t = 1; t <= cowNum; ++t)
        cowDat[t] = cowNum - cowDat[t];
    // Done

    int l = 2, r = cowNum, m;
    while (true) {
        m = (l + r) >> 1;
        if (!legalCheck(m - 1))
            r = m - 1;
        else if (legalCheck(m))
            l = m + 1;
        else
            break;
    }
    std::cout << cowNum - m + 1;
    return 0;
}
