// https://ac.nowcoder.com/acm/contest/24213/1002
// 舔狗舔到最后一无所有

#include <iostream>

#define mod static_cast<long long>(1e9+7)

int main() {
    long long dat[100001]{0, 3, 9, 24};
    for (int t = 4; t <= 100000; ++t)
        dat[t] = ((dat[t - 1] * 3 % mod - dat[t - 3] * 2 % mod) + mod) % mod;
    int tt, n;
    std::cin >> tt;
    while (tt--) {
        std::cin >> n;
        std::cout << dat[n] << std::endl;
    }
    return 0;
}

// Another version

//#include <iostream>
//
//#define mod static_cast<long long>(1e9+7)
//
//int main() {
//    long long dat[100001]{0, 1, 3, 8};
//    for (int t = 4; t <= 100000; ++t)
//        dat[t] = ((dat[t - 1] * 3 % mod - dat[t - 3] * 2 % mod) + mod) % mod;
//    int tt, n;
//    std::cin >> tt;
//    while (tt--) {
//        std::cin >> n;
//        std::cout << dat[n] * 3 % mod << std::endl;
//    }
//    return 0;
//}
