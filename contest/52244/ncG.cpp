//#include <iostream>
//#include <vector>
//
//long long main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//
//    long long n;
//    std::cin >> n;
//    std::vector<long long> data(n);
//
//    for (long long t = 0; t < n; ++t)
//        std::cin >> data[t];
//
//    long long res = 0;
//    for (const auto &a: data)
//        for (const auto &b: data)
//            if ((a ^ b) == (a + b))
//                ++res;
//
//    std::cout << res;
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//
//long long main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//
//    long long n;
//    std::cin >> n;
//    std::vector<long long> vi(n);
//    for (long long t = 0; t < n; ++t)
//        std::cin >> vi[t];
//
//    long long res = 0;
//    for (long long i = 0; i < vi.size(); ++i) {
//        for (long long j = 0; j < vi.size(); ++j)
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

    long long n;
    std::cin >> n;
    long long i;
    std::unordered_map<long long, long long> data;
    for (long long t = 0; t < n; ++t) {
        std::cin >> i;
        ++data[i];
    }

    long long res = 0;
    for (auto iterA = data.begin(); iterA != data.end(); ++iterA)
        for (auto iterB = data.begin(); iterB != data.end(); ++iterB)
            if ((iterA->first ^ iterB->first) == iterA->first + iterB->first)
                res += iterA->second * iterB->second;

    std::cout << res;

    return 0;
}
