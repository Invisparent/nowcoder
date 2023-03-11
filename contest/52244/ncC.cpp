//#include <iostream>
//
//#define IVS_LIM ((int)10000)
//
//int n, tt;
//bool data[IVS_LIM][IVS_LIM];
//
//inline void ivsSet(const int x, const int y) {
//    for (int t = 1; t <= n; ++t) {
//        data[x][t] = true;
//        data[t][y] = true;
//    }
//
//    int ix = x - 1, iy = y - 1;
//    while (ix > 0 && iy > 0) {
//        data[ix][iy] = true;
//        --ix;
//        --iy;
//    }
//
//    ix = x - 1;
//    iy = y + 1;
//    while (ix > 0 && iy <= n) {
//        data[ix][iy] = true;
//        --ix;
//        ++iy;
//    }
//
//    ix = x + 1;
//    iy = y - 1;
//    while (ix <= n && iy > 0) {
//        data[ix][iy] = true;
//        ++ix;
//        --iy;
//    }
//
//    ix = x + 1;
//    iy = y + 1;
//    while (ix <= n && iy <= n) {
//        data[ix][iy] = true;
//        ++ix;
//        ++iy;
//    }
//}
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//
//    std::cin >> n >> tt;
//
//    int a, b;
//    for (int t = 0; t < tt; ++t) {
//        std::cin >> a >> b;
//        if (!data[a][b]) {
//            std::cout << "Yes\n";
//            ivsSet(a, b);
//        } else
//            std::cout << "No\n";
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <unordered_set>
//
//int n, tt;
//std::vector<bool> failedRow(1e6 + 5);
//std::vector<std::unordered_set<int>> data(1e6 + 5);
//
//inline bool ivsCheck(int x, int y) {
//    if (failedRow[x])
//        return false;
//
//    auto iter = data[x].find(y);
//    if (iter != data[x].end())
//        return false;
//    else
//        return true;
//}
//
//inline void ivsInsert(int x, int y) {
//    failedRow[x] = true;
//
//    for (int t = 1; t <= n; ++t)
//        data[t].insert(y);
//
//    int ix = x - 1, iy = y - 1;
//    while (ix > 0 && iy > 0) {
//        if (!failedRow[ix])
//            data[ix].insert(iy);
//        --ix;
//        --iy;
//    }
//
//    ix = x - 1;
//    iy = y + 1;
//    while (ix > 0 && iy <= n) {
//        if (!failedRow[ix])
//            data[ix].insert(iy);
//        --ix;
//        ++iy;
//    }
//
//    ix = x + 1;
//    iy = y - 1;
//    while (ix <= n && iy > 0) {
//        if (!failedRow[ix])
//            data[ix].insert(iy);
//        ++ix;
//        --iy;
//    }
//
//    ix = x + 1;
//    iy = y + 1;
//    while (ix <= n && iy <= n) {
//        if (!failedRow[ix])
//            data[ix].insert(iy);
//        ++ix;
//        ++iy;
//    }
//}
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//
//    std::cin >> n >> tt;
//    int a, b;
//    for (int t = 0; t < tt; ++t) {
//        std::cin >> a >> b;
//        if (ivsCheck(a, b)) {
//            ivsInsert(a, b);
//            std::cout << "Yes\n";
//        } else
//            std::cout << "No\n";
//    }
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <unordered_set>
//
//int n, tt;
//std::vector<bool> failedRow(1e6 + 5), failedCol(1e6 + 5);
//std::vector<std::unordered_set<int>> data(1e6 + 5);
//
//inline bool ivsCheck(int x, int y) {
//    if (failedRow[x])
//        return false;
//    if (failedCol[y])
//        return false;
//
//    auto iter = data[x].find(y);
//    if (iter != data[x].end())
//        return false;
//    else
//        return true;
//}
//
//inline void ivsInsert(int x, int y) {
//    failedRow[x] = true;
//
//    for (int t = 1; t <= n; ++t)
//        data[t].insert(y);
//
//    int ix = x - 1, iy = y - 1;
//    while (ix > 0 && iy > 0) {
//        if (!failedRow[ix])
//            data[ix].insert(iy);
//        --ix;
//        --iy;
//    }
//
//    ix = x - 1;
//    iy = y + 1;
//    while (ix > 0 && iy <= n) {
//        if (!failedRow[ix])
//            data[ix].insert(iy);
//        --ix;
//        ++iy;
//    }
//
//    ix = x + 1;
//    iy = y - 1;
//    while (ix <= n && iy > 0) {
//        if (!failedRow[ix])
//            data[ix].insert(iy);
//        ++ix;
//        --iy;
//    }
//
//    ix = x + 1;
//    iy = y + 1;
//    while (ix <= n && iy <= n) {
//        if (!failedRow[ix])
//            data[ix].insert(iy);
//        ++ix;
//        ++iy;
//    }
//}
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//
//    std::cin >> n >> tt;
//    int a, b;
//    for (int t = 0; t < tt; ++t) {
//        std::cin >> a >> b;
//        if (ivsCheck(a, b)) {
//            ivsInsert(a, b);
//            std::cout << "Yes\n";
//        } else
//            std::cout << "No\n";
//    }
//    return 0;
//}

#include <iostream>
#include <vector>

#define IVS_H ((int)1e6+50)
#define IVS_X ((int)2e6+50)
#define IVS_OS ((int)1e6+25)

int n, tt;

std::vector<bool> fRow(IVS_H), fCol(IVS_H), fx(IVS_X), fy(IVS_X);

inline int ivs2x(int x, int y) {
    return y - x + IVS_OS;
}

inline int ivs2y(int x, int y) {
    return x + y;
}

inline bool ivsCheck(int x, int y) {
    if (fRow[x])
        return false;
    if (fCol[y])
        return false;
    if (fx[ivs2x(x, y)])
        return false;
    if (fy[ivs2y(x, y)])
        return false;

    return true;
}

inline void ivsInsert(int x, int y) {
    fRow[x] = true;
    fCol[y] = true;
    fx[ivs2x(x, y)] = true;
    fy[ivs2y(x, y)] = true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> tt;
    int a, b;
    for (int t = 0; t < tt; ++t) {
        std::cin >> a >> b;
        if (ivsCheck(a, b)) {
            std::cout << "Yes\n";
            ivsInsert(a, b);
        } else
            std::cout << "No\n";
    }

    return 0;
}
