// https://ac.nowcoder.com/acm/contest/22353/E
// [USACO 2010 Feb S]Chocolate Eating

// 这玩意tm竟然是二分...6

// Partial Accepted

//#include <iostream>
//#include <vector>
//#include <unordered_map>
//
//long long chocolateNum, dayNum;
//std::vector<int> chocolateDat, chocolateConsumed;
//std::unordered_map<long long, bool> legalCheckDat;
//
//inline bool legalCheck(const long long &minHappiness) {
//    auto fastCalcIter = legalCheckDat.find(minHappiness);
//    if (fastCalcIter != legalCheckDat.end())
//        return fastCalcIter->second;
//    // Global variable initialization
//    chocolateConsumed.clear();
//    chocolateConsumed.reserve(dayNum);
//    // Done
//
//    int prevDay = 1;
//    long long prevHappiness = 0;
//    auto chocolateIter = chocolateDat.cbegin();
//    while (prevDay <= dayNum && chocolateIter != chocolateDat.cend()) {
//        prevHappiness /= 2;
//        while (chocolateIter != chocolateDat.cend() && prevHappiness < minHappiness) {
//            prevHappiness += *chocolateIter;
//            chocolateConsumed.push_back(prevDay);
//            ++chocolateIter;
//        }
//        if (prevHappiness >= minHappiness)
//            ++prevDay;
//    }
//    bool result = prevDay > dayNum;
//    legalCheckDat[minHappiness] = result;
//    return result;
//}
//
//int main() {
//    // Global variable initialization
//    std::cin >> chocolateNum >> dayNum;
//    chocolateDat = std::vector<int>(chocolateNum);
//    legalCheckDat[0] = true;
//    // Done
//
//    for (int t = 0; t < chocolateNum; ++t)
//        std::cin >> chocolateDat[t];
//    long long lBound = 0, rBound = 5e1 + 1, mBound;
//    while (lBound <= rBound) {
//        mBound = (lBound + rBound) >> 1;
//        if (legalCheck(mBound + 1))
//            lBound = mBound + 1;
//        else if (!legalCheck(mBound))
//            rBound = mBound - 1;
//        else
//            break;
//    }
//    std::cout << mBound << std::endl;
//    for (const int &i: chocolateConsumed)
//        std::cout << i << std::endl;
//    return 0;
//}

#include <iostream>
#include <vector>
#include <unordered_map>

int chocolateNum, dayNum;
std::vector<int> chocolateDat, chocolateEatLog;
std::unordered_map<long long, bool> legalDat;

inline bool legalCheck(long long targetMinHappiness) {
    auto legalIter = legalDat.find(targetMinHappiness);
    if (legalIter != legalDat.end())
        return legalIter->second;

    // Global variable initialization
    chocolateEatLog.clear();
    chocolateEatLog.reserve(dayNum);
    // Done

    int prevDay = 1;
    long long prevHappiness = 0;
    auto chocolateIter = chocolateDat.cbegin();
    while (prevDay <= dayNum) {
        prevHappiness /= 2;
        while (prevHappiness < targetMinHappiness && chocolateIter != chocolateDat.cend()) {
            prevHappiness += *chocolateIter;
            chocolateEatLog.push_back(prevDay);
            ++chocolateIter;
        }
        if (prevHappiness >= targetMinHappiness)
            ++prevDay;
        else
            break;
    }
    if (prevDay > dayNum) {
        legalDat[targetMinHappiness] = true;
        return true;
    }
    legalDat[targetMinHappiness] = false;
    return false;
}

int main() {
    // Global variable initialization
    std::cin >> chocolateNum >> dayNum;
    chocolateDat = std::vector<int>(chocolateNum);
    for (int t = 0; t < chocolateNum; ++t)
        std::cin >> chocolateDat[t];
    legalDat[0] = true;
    // Done

    long long l = 1, r = 5e10 + 1, m;
    while (true) {
        m = (l + r) >> 1;
        if (legalCheck(m + 1))
            l = m + 1;
        else if (!legalCheck(m))
            r = m - 1;
        else
            break;
    }
    std::cout << m << std::endl;
    for (const int &i: chocolateEatLog)
        std::cout << i << std::endl;
    return 0;
}
