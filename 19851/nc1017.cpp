#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

std::vector<std::pair<int, std::string>> globalDat;

// 就1000个数据20次查询，用啥哈希啊，直接暴力淦它~

inline std::string enquiry(int x, int k) {
    int t = 0;
    for (const std::pair<int, std::string> &p: globalDat) {
        if (p.first % 10000 == x)
            ++t;
        if (t == k)
            return p.second;
    }
    return "114514";
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::pair<int, std::string> p;
    for (int t = 0; t < n; ++t) {
        std::cin >> p.second >> p.first;
        globalDat.push_back(p);
    }
    std::sort(globalDat.begin(), globalDat.end(),
              [](const std::pair<int, std::string> &a, const std::pair<int, std::string> &b) {
                  return a.first < b.first;
              });
    while (std::cin >> m >> n)
        std::cout << enquiry(n, m) << std::endl;
    return 0;
}
