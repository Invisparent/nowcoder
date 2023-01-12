// https://ac.nowcoder.com/acm/contest/22353/A
// [USACO 2009 Dec S]Music Notes

// 噫，std::lower_bound()真香

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<long long> noteDat;

inline int binarySearch(const long long &query) {
    auto iter = std::lower_bound(noteDat.begin(), noteDat.end(), query);
    return iter - noteDat.begin() + (*iter == query);
}

int main() {
    int noteNum, beatNum;
    std::cin >> noteNum >> beatNum;

    // Global variable initialization
    noteDat = std::vector<long long>(noteNum + 1);
    noteDat[0] = 0;
    for (int t = 1; t <= noteNum; ++t)
        std::cin >> noteDat[t];
    for (int t = 1; t <= noteNum; ++t)
        noteDat[t] += noteDat[t - 1];
    // Done

    long long query;
    while (std::cin >> query)
        std::cout << binarySearch(query) << std::endl;
    return 0;
}
