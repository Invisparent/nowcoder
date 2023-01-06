// https://ac.nowcoder.com/acm/contest/21763/1004

#include <iostream>
#include <set>
#include <utility>

struct customCompare {
    bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b) const {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;
    std::multiset<std::pair<int, int>, customCompare> sp;
    int a, b;
    while (std::cin >> a >> b)
        sp.insert(std::pair<int, int>(a, b));
    m *= 1.5;
    auto iter = sp.begin();
    int t = 1;
    for (; t < m; ++t)
        ++iter;
    auto xiter = iter;
    ++xiter;
    while (xiter != sp.end() && xiter->second == iter->second) {
        ++iter;
        ++xiter;
        ++t;
    }
    std::cout << iter->second << ' ' << t << std::endl;
    for (const std::pair<int, int> &p: sp)
        if (p.second >= iter->second)
            std::cout << p.first << ' ' << p.second << std::endl;
        else
            break;
    return 0;
}
