// https://ac.nowcoder.com/acm/contest/22353/G
// [CQOI2010]扑克牌

// 好像没有你想的那么简单哦~

// Partial Accepted

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//int main() {
//    int catNum, jokerNum;
//    std::vector<int> catDat;
//    std::cin >> catNum >> jokerNum;
//    catDat = std::vector<int>(catNum);
//    for (int t = 0; t < catNum; ++t)
//        std::cin >> catDat[t];
//    std::sort(catDat.begin(), catDat.end());
//    if (catNum == 1) {
//        std::cout << catDat.front() + jokerNum;
//        return 0;
//    }
//    int jokerUsed = 0, traverseIndex = 1, delta;
//    auto iterA = catDat.begin(), iterB = catDat.begin() + 1;
//    while (iterB != catDat.end()) {
//        delta = (*iterB - *iterA) * traverseIndex;
//        if (delta <= jokerNum - jokerUsed)
//            jokerUsed += delta;
//        else
//            break;
//        ++iterA;
//        ++iterB;
//        ++traverseIndex;
//    }
//    std::cout << *iterA + (jokerNum - jokerUsed) / catNum;
//    return 0;
//}

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

long long catNum, jokerNum;
std::vector<long long> catDat;
std::unordered_map<long long, bool> legalDat;

inline bool legalCheck(const long long &targetSetNum) {
    auto legalIter = legalDat.find(targetSetNum);
    if (legalIter != legalDat.end())
        return legalIter->second;
    long long jokerUsed = 0, jokerDelta;
    std::for_each(catDat.cbegin(), catDat.cend(), [&](const long long &ini) {
        jokerDelta = targetSetNum - ini;
        if (jokerDelta > 0)
            jokerUsed += jokerDelta;
    });
    bool result = jokerUsed <= jokerNum && jokerUsed <= targetSetNum;
    legalDat[targetSetNum] = result;
    return result;
}

int main() {
    // GVI
    legalDat[0] = true;
    std::cin >> catNum >> jokerNum;
    catDat = std::vector<long long>(catNum);
    for (long long t = 0; t < catNum; ++t)
        std::cin >> catDat[t];
    // Done

    // The right bound should be 7.5e8 + 1, not 5e8 + 1
    long long l = 1, r = 7.5e8 + 1, m;
    while (true) {
        m = (l + r) >> 1;
        if (legalCheck(m))
            l = m + 1;
        else if (!legalCheck(m - 1))
            r = m - 1;
        else
            break;
    }
    std::cout << m - 1;
    return 0;
}
