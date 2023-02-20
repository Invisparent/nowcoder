//#include <iostream>
//#include <vector>
//#include <unordered_set>
//
//const std::unordered_set<int> pwr{1, 2, 4, 8, 16, 32, 64};
//
//int main() {
//    std::cout << "1 0" << std::endl;
//    for (int tt = 2; tt <= 50; ++tt) {
//        int res = 0;
//        std::vector<int> vi(tt + 1);
//        for (int t = 1; t <= tt; ++t)
//            vi[t] = t;
//        for (int i = 1; i <= tt; ++i)
//            for (int j = i + 1; j <= tt; ++j)
//                if (pwr.find(vi[j] - vi[i]) != pwr.end())
//                    ++res;
//        std::cout << tt << ' ' << res << std::endl;
//    }
//    return 0;
//}

//#include <iostream>
//
//int main() {
//    int val = 1;
//    while (val < 1e9) {
//        std::cout << val << ',';
//        val *= 2;
//    }
//    return 0;
//}
//
//
//#include <iostream>
//#include <vector>
//
//const std::vector<long long> pwr{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536,
//                                 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432,
//                                 67108864, 134217728, 268435456, 536870912};
//
//long long getPair(const long long &lim) {
//    long long res = 0;
//    for (const auto &p: pwr) {
//        if (p > lim)
//            break;
//        res += lim - p;
//    }
//    return res;
//}
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//
//    long long n, k;
//    std::cin >> n >> k;
//    if (n == 1 && k) {
//        std::cout << "-1";
//        return 0;
//    }
//    if (k == 0) {
//        for (int t = 1; t <= n; ++t)
//            std::cout << t << ' ';
//        return 0;
//    }
//
//    long long l = 1, r = n, m;
//    while (l <= r) {
//        m = (l + r) / 2;
//        if (getPair(m) < k)
//            l = m + 1;
//        else if (getPair(m) > k)
//            r = m - 1;
//        else {
//            for (long long t = m; t > 0; --t)
//                std::cout << t << ' ';
//            for (long long t = m + 1; t <= n; ++t)
//                std::cout << t << ' ';
//            return 0;
//        }
//    }
//    std::cout << -1;
//    return 0;
//}

#include <iostream>
#include <vector>
#include <utility>

#define IVS_N ((int)1e6+5)

const std::vector<long long> pwr{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536,
                                 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432,
                                 67108864, 134217728, 268435456, 536870912};
std::vector<std::pair<long long, long long>> final;
std::vector<long long> fc(IVS_N);

inline void printArray(long long a, long long b) {
    while (a >= b) {
        std::cout << a << ' ';
        --a;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    fc[0] = 0;
    fc[1] = 0;
    fc[2] = 1;

    long long n, k;
    std::cin >> n >> k;
    int fcIndex = 3;
    for (; fcIndex < IVS_N; ++fcIndex) {
        int i = 1;
        while (pwr[i + 1] <= fcIndex - 1)
            ++i;
        fc[fcIndex] = fc[fcIndex - 1] + i + 1;
    }
//    for (int t = 1; t <= 50; ++t)
//        std::cout << t << ' ' << fc[t] << std::endl;
    if (fc[n] < k) {
        std::cout << -1 << std::endl;
        return 0;
    }
    long long travPos = std::upper_bound(fc.begin(), fc.end(), k) - fc.begin() + 5;
    while (k) {
        while (fc[travPos] > k) {
            --travPos;
        }
        k -= fc[travPos];
        final.emplace_back(n, travPos);
        n = n - travPos;
    }
    for (int t = 1; t <= n; ++t)
        std::cout << t << ' ';
    for (const auto &p: final)
        printArray(p.first, p.second);
    return 0;
}
