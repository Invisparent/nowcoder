#include <iostream>
#include <vector>
#include <algorithm>

inline long long climb(std::vector<int>::iterator iterA, std::vector<int>::iterator iterB) {
    if (iterA + 1 == iterB)
        return 0;
    if (*(iterA + 1) >= *iterA)
        return *(iterA + 1) - *iterA + climb(iterA + 1, iterB);
    auto targetIter = std::find_if(iterA + 1, iterB, [&](const int &ini) {
        return ini >= *iterA;
    });
    if (targetIter != iterB)
        return *targetIter - *iterA + climb(targetIter, iterB);
    else {
        targetIter = iterA + 1;
        for (auto xverseIter = iterA + 1; xverseIter != iterB; ++xverseIter)
            if (*xverseIter > *targetIter)
                targetIter = xverseIter;
        return *iterA - *targetIter + climb(targetIter, iterB);
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> vi(n);
    for (int t = 0; t < n; ++t)
        std::cin >> vi[t];
    std::cout << vi.front() + vi.back() + climb(vi.begin(), vi.end());
    return 0;
}
