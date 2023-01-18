// https://ac.nowcoder.com/acm/contest/46810/D

//#include <bits/stdc++.h>
//
//#define maxn 200005
//
//int node[maxn], energy[maxn], pathLen[maxn];
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//
//    int n;
//    std::cin >> n;
//    for (int t = 2; t <= n; ++t)
//        std::cin >> node[t];
//    for (int t = 1; t <= n; ++t)
//        std::cin >> energy[t];
//    std::sort(std::begin(node) + 2, std::begin(node) + n + 1);
//    std::sort(std::begin(energy) + 1, std::begin(energy) + n + 1, std::greater());
//    for (int t = n; t >= 1; --t) {
//        int p = t;
//        while (p) {
//            p = node[p];
//            ++pathLen[t];
//        }
//    }
//    std::sort(std::begin(pathLen) + 1, std::begin(pathLen) + n + 1, std::greater());
//    long long r = 0;
//    for (int t = 1; t <= n; ++t)
//        r += energy[t] * pathLen[t];
//    std::cout << r;
//    return 0;
//}

#include <bits/stdc++.h>

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


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n = fread();
    std::vector<int> node(n + 1), energy(n + 1);
    for (int t = 2; t <= n; ++t)
        node[t] = fread();
    for (int t = 1; t <= n; ++t)
        energy[t] = fread();
    std::vector<int> pathLen(n + 1);
    for (int t = n; t >= 1; --t) {
        int p = t;
        while (p) {
            p = node[p];
            ++pathLen[t];
        }
    }
    std::sort(pathLen.begin() + 1, pathLen.end(), std::greater());
    std::sort(energy.begin() + 1, energy.end(), std::greater());
//    for (int t = 1; t <= n; ++t)
//        std::cout << pathLen[t] << std::endl;
    long long r = 0;
    for (int t = 1; t <= n; ++t)
        r += pathLen[t] * energy[t];
    std::cout << r;
    return 0;
}
