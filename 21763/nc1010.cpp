// https://ac.nowcoder.com/acm/contest/21763/1010

// 说好的狗都不写呢~

#include <iostream>
#include <vector>
#include <array>
#include <string>

int hanoiNum;
bool reversePrint;

inline void printHanoi_innerPrinter(int diskLength, bool printFrontDot) {
    if (diskLength == 0)
        std::cout << std::string(hanoiNum + 1 - !printFrontDot, '.') << '|' << std::string(hanoiNum + 1, '.');
    else
        std::cout << std::string(hanoiNum - diskLength + 1 - !printFrontDot, '.')
                  << std::string(2 * diskLength + 1, '*') << std::string(hanoiNum - diskLength + 1, '.');
}

inline void printHanoi_eofLinePrinter() {
    std::cout << std::string(6 * hanoiNum + 7, '-');
}

inline void printHanoi_eofDotPrinter() {
    std::cout << std::string(6 * hanoiNum + 7, '.');
}

inline void printHanoi(const std::array<std::vector<int>, 3> &dat) {
    printHanoi_eofDotPrinter();
    std::cout << std::endl;
    printHanoi_innerPrinter(0, true);
    printHanoi_innerPrinter(0, false);
    printHanoi_innerPrinter(0, false);
    std::cout << std::endl;
    int diskLength, x;
    for (int t = hanoiNum - 1; t >= 0; --t) {
        for (int i = 0; i < 3; ++i) {
            if (reversePrint)
                if (i == 1)
                    x = 2;
                else if (i == 2)
                    x = 1;
                else
                    x = 0;
            else
                x = i;
            diskLength = t > static_cast<int>(dat[x].size()) - 1 ? 0 : dat[x][t];
            printHanoi_innerPrinter(diskLength, i == 0);
            std::cout << std::flush;
        }
        if (t)
            std::cout << std::endl;
    }
}

inline void moveHanoi_byStep(std::array<std::vector<int>, 3> &dat, int a, int b) {
    printHanoi(dat);
    std::cout << std::endl;
    printHanoi_eofLinePrinter();
    std::cout << std::endl;
    dat[b].push_back(dat[a].back());
    dat[a].pop_back();
}

inline void moveHanoi(std::array<std::vector<int>, 3> &dat, int depth, int originalPillar, int targetPillar) {
    if (depth == 1) {
        moveHanoi_byStep(dat, originalPillar, targetPillar);
        return;
    }
    int intermediatePillar = 0;
    while (intermediatePillar == originalPillar || intermediatePillar == targetPillar)
        ++intermediatePillar;
    moveHanoi(dat, depth - 1, originalPillar, intermediatePillar);
    moveHanoi_byStep(dat, originalPillar, targetPillar);
    moveHanoi(dat, depth - 1, intermediatePillar, targetPillar);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin >> hanoiNum;
    reversePrint = hanoiNum % 2;
    std::array<std::vector<int>, 3> dat{};
    for (int t = hanoiNum; t > 0; --t)
        dat[0].push_back(t);
    moveHanoi(dat, hanoiNum, 0, 2);
    printHanoi(dat);
    return 0;
}
