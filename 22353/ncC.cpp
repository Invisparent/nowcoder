// https://ac.nowcoder.com/acm/contest/22353/C
// [NOIP2015]跳石头

// 是哪个大聪明把第40行二分的按位左移的1写成2了，然后卡了半天啊？
// 是哪个大聪明啊？啊？Invisparent你说说是谁啊？

#include <iostream>
#include <vector>

int rockMaxNum;
std::vector<int> rockDat;

inline bool legalCheck(int targetDistance) {
    int rockRemoveCounter = 0;
    auto iterA = rockDat.cbegin(), iterB = rockDat.cbegin() + 1;
    while (iterB < rockDat.cend()) {
        while (iterB < rockDat.cend() && *iterB - *iterA < targetDistance) {
            ++iterB;
            ++rockRemoveCounter;
        }
        iterA = iterB;
        ++iterB;
    }
    return rockRemoveCounter <= rockMaxNum;
}

int main() {
    int length, rockNum;
    std::cin >> length >> rockNum >> rockMaxNum;
    if (rockNum == 0) {
        std::cout << length;
        return 0;
    }
    rockDat = std::vector<int>(rockNum + 2);
    for (int t = 1; t <= rockNum; ++t)
        std::cin >> rockDat[t];
    rockDat[0] = 0;
    rockDat[rockNum + 1] = length;
    int lBound = 1, rBound = length, mBound;
    while (lBound <= rBound) {
        mBound = (lBound + rBound) >> 1;
        if (legalCheck(mBound + 1))
            lBound = mBound + 1;
        else if (!legalCheck(mBound))
            rBound = mBound - 1;
        else
            break;
    }
    std::cout << mBound;
    return 0;
}
