// https://ac.nowcoder.com/acm/contest/22353/F
// 华华给月月准备礼物

#include <iostream>
#include <vector>
#include <unordered_map>

int stickNum, stickExpected;
std::vector<int> stickDat;
std::unordered_map<long long, bool> legalDat;

inline bool legalCheck(const long long &stickLen) {
    auto iter = legalDat.find(stickLen);
    if (iter != legalDat.end())
        return iter->second;
    long long stickPrev = 0;
    for (const int &i: stickDat)
        stickPrev += i / stickLen;
    bool result = stickPrev >= stickExpected;
    legalDat[stickLen] = result;
    return result;
}

int main() {
    // Global Variable Initialization
    legalDat[0] = true;
    std::cin >> stickNum >> stickExpected;
    stickDat = std::vector<int>(stickNum);
    for (int t = 0; t < stickNum; ++t)
        std::cin >> stickDat[t];
    // Done

    long long l = 1, r = 2e14, m;
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
