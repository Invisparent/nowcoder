// https://ac.nowcoder.com/acm/contest/21763/1007

//#include <iostream>
//#include <vector>
//
//int main() {
//    int n;
//    std::cin >> n;
//    std::vector<int> vi(n);
//    for (int t = n - 1; t >= 0; --t)
//        std::cin >> vi[t];
//    long long r = 0;
//    for (auto iterA = vi.begin(); iterA != vi.end(); ++iterA)
//        for (auto iterB = iterA + 1; iterB != vi.end(); ++iterB)
//            if (*iterB > *iterA)
//                ++r;
//    std::cout << r;
//    return 0;
//}

// A much faster version using mergeSort

#include <iostream>
#include <vector>

long long swapCounter = 0;

inline int fread() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void mergeSort_merge(std::vector<int>::iterator iterA, std::vector<int>::iterator iterB,
                            std::vector<int>::iterator iterC) {
    if (iterA == iterB && iterB == iterC)
        return;
    if (*(iterB - 1) <= *iterB)
        return;
    std::vector<int> vi(iterC - iterA);
    auto cacheWriteIter = vi.begin(), rawWriteIter = iterA, midPointIter = iterB, endPointIter = iterC;
    while (iterA != midPointIter && iterB != endPointIter) {
        if (*iterA > *iterB) {
            *cacheWriteIter++ = *iterB++;
            swapCounter += midPointIter - iterA;
        } else
            *cacheWriteIter++ = *iterA++;
    }
    while (iterA == midPointIter && iterB != endPointIter)
        *cacheWriteIter++ = *iterB++;
    while (iterB == endPointIter && iterA != midPointIter)
        *cacheWriteIter++ = *iterA++;
    for (const int &ini: vi)
        *rawWriteIter++ = ini;

}

inline void mergeSort(std::vector<int>::iterator iterA, std::vector<int>::iterator iterB) {
    if (iterA + 2 > iterB)
        return;
    mergeSort(iterA, iterA + (iterB - iterA) / 2);
    mergeSort(iterA + (iterB - iterA) / 2, iterB);
    mergeSort_merge(iterA, iterA + (iterB - iterA) / 2, iterB);
}

int main() {
    int n = fread();
    std::vector<int> vi(n);
    for (int t = 0; t < n; ++t)
        vi[t] = fread();
    mergeSort(vi.begin(), vi.end());
    std::cout << swapCounter;
    return 0;
}
