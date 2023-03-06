#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

inline bool operator<(const std::string &a, const std::string &b) {
    int index = (int) std::min(a.size(), b.size());
    for (int t = 0; t < index; ++t)
        if (a[t] < b[t])
            return true;
        else if (a[t] > b[t])
            return false;

    return a.size() < b.size();
}

void solve() {
    int n, q;
    std::cin >> n >> q;

    std::unordered_map<std::string, std::string> data;
    std::string a, b;
    for (int t = 0; t < n; ++t) {
        std::cin >> a >> b;
        auto iter = data.find(a);
        if (iter != data.end()) {
            if (b < iter->second)
                iter->second = std::move(b);
        } else
            data.emplace(std::move(a), std::move(b));
    }

    for (int t = 0; t < q; ++t) {
        std::cin >> a;
        auto iter = data.find(a);
        if (iter == data.end())
            std::cout << "Not your business, don't ask more!\n";
        else
            std::cout << iter->second << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int tt;
    std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}
