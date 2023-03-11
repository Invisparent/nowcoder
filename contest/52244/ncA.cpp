//#include <iostream>
//#include <vector>
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//
//    int n;
//    std::cin >> n;
//    std::vector<int> vi(n);
//    for (int t = 0; t < n; ++t)
//        std::cin >> vi[t];
//
//    int res = 0;
//    for (int i = 0; i < vi.size(); ++i) {
//        for (int j = 0; j < vi.size(); ++j)
//            if (vi[i] == vi[j])
//                ++res;
//    }
//
//    std::cout << res;
//
//    return 0;
//}

#include <iostream>
#include <unordered_map>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    int i;
    std::unordered_map<int, int> data;
    for (int t = 0; t < n; ++t) {
        std::cin >> i;
        ++data[i];
    }

    long long res = 0;
    for (const auto &p: data)
        res += (long long) p.second * p.second;

    std::cout << res;

    return 0;
}
