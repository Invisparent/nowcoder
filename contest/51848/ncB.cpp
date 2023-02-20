//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <algorithm>
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//
//    int n;
//    std::cin >> n;
//    std::vector<long long> data(n);
//    for (int t = 0; t < n; ++t)
//        std::cin >> data[t];
//    long long minVal = data.front(), maxVal = data.front();
//    long long minPos, maxPos;
//    for (long long t = 0; t < n; ++t) {
//        if (data[t] < minVal) {
//            minVal = data[t];
//            minPos = t;
//        }
//        if (data[t] > maxVal) {
//            maxVal = data[t];
//            maxPos = t;
//        }
//        if (data[t] == minVal)
//            if (std::abs(n / 2 - t) > std::abs(n / 2 - minPos))
//                minPos = t;
//        if (data[t] == maxVal)
//            if (std::abs(n / 2 - t) > std::abs(n / 2 - maxPos))
//                maxPos = t;
//    }
//    if (std::abs(n / 2 - minPos) > std::abs(n / 2 - maxPos))
//        std::cout << std::max(n - minPos - 1, minPos - 1);
//    else
//        std::cout << std::max(n - maxPos - 1, maxPos - 1);
//    return 0;
//}

#include <cstdio>
#include <vector>
#include <algorithm>

inline int xread() {
    int retVal = 0;
    char ch = (char) getchar();

    while (ch < '0' || ch > '9')
        ch = (char) getchar();

    while (ch >= '0' && ch <= '9') {
        retVal = (retVal << 1) + (retVal << 3) + ch - '0';
        ch = (char) getchar();
    }

    return retVal;
}

int main() {
    int n = xread();

    int v;
    int minVal = 0x3f3f3f3f, maxVal = -1;
    std::vector<int> minPos, maxPos;
    for (int t = 1; t <= n; ++t) {
        v = xread();
        if (v < minVal) {
            minVal = v;
            minPos.clear();
            minPos.push_back(t);
        } else if (v == minVal)
            minPos.push_back(t);

        if (v > maxVal) {
            maxVal = v;
            maxPos.clear();
            maxPos.push_back(t);
        } else if (v == maxVal)
            maxPos.push_back(t);
    }

    printf("%d", std::max(n - std::min(minPos.front(), maxPos.front()), std::max(minPos.back(), maxPos.back()) - 1));
    return 0;
}
