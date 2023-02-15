// https://ac.nowcoder.com/acm/contest/23156/1011
// 幸运数字II

// Multiple Solutions
// Naive

// 你是不是看错题了
// ...

//#include <iostream>
//#include <string>
//#include <algorithm>
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//
//    long long l, r;
//    std::cin >> l >> r;
//
//    std::string str;
//    while (true) {
//        str = std::to_string(l);
//        if (!std::all_of(str.begin(), str.end(), [](const auto &ch) { return ch == '4' || ch == '7'; }))
//            ++l;
//        else
//            break;
//    }
//
//    long long res = std::stoll(str);
//    while (std::stoll(str) < r) {
//        bool hasNextPerm = std::next_permutation(str.begin(), str.end());
//        if (hasNextPerm)
//            res += std::stoll(str);
//        else {
//            if (std::all_of(str.begin(), str.end(), [](const auto &ch) { return ch == '7'; }))
//                str = std::string(str.size() + 1, '4');
//            else {
//                int sz4 = (int) std::count(str.begin(), str.end(), '4');
//                int sz7 = (int) std::count(str.begin(), str.end(), '7');
//                str = std::string(sz4 - 1, '4') + std::string(sz7 + 1, '7');
//            }
//            res += std::stoll(str);
//        }
//    }
//
//    std::cout << res + std::stoll(str);
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//int layer;
//long long l, r;
//std::string str;
//std::vector<long long> data;
//
//void dfs() {
//    if (std::stoll(str) > r * 10)
//        return;
//    data.push_back(std::stoll(str));
//    str.push_back('4');
//    dfs();
//    str.back() = '7';
//    dfs();
//    str.pop_back();
//}
//
//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    std::cout.tie(nullptr);
//
//    std::cin >> l >> r;
//
//    // This variable is used to generate the first lucky number
//    long long c = l;
//    while (true) {
//        str = std::to_string(c);
//        if (!std::all_of(str.begin(), str.end(), [](const auto &ch) { return ch == '4' || ch == '7'; }))
//            ++c;
//        else
//            break;
//    }
//
//    dfs();
//    std::sort(data.begin(), data.end());
//    long long res = 0;
//    res += (data.front() - l + 1) * data.front();
//    for (int t = 1; t < data.size(); ++t) {
//        if (data[t] <= r)
//            res += (data[t] - data[t - 1]) * data[t];
//        else {
//            res += (r - data[t - 1]) * data[t];
//        }
//    }
//    std::cout << res;
//    return 0;
//}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define IVS_LB ((long long) 4)
#define IVS_RB ((long long) 5e9)

std::string str;
std::vector<long long> data;

void dfs() {
    if (!str.empty()) {
        if (std::stoll(str) > IVS_RB)
            return;
        data.push_back(std::stoll(str));
    }

    str.push_back('4');
    dfs();
    str.back() = '7';
    dfs();
    str.pop_back();
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    dfs();
    std::sort(data.begin(), data.end());

    long long l, r;
    std::cin >> l >> r;

    // Guess what will happen when remove this?
    if (r < IVS_LB) {
        std::cout << 4 * (r - l + 1);
        return 0;
    }

    int t = 0;
    long long res = 0;
    while (data[t] < l)
        ++t;

    /**
     * Without the code below
     * It'll be Partial Accepted ( 85% )
     * When l < data[t] and also r < data[t]
     * Input: 1000000000 1000000000 (1e9)
     * Output: -5888888888
     * ...
     */
    if (r < data[t]) {
        std::cout << data[t] * (r - l + 1);
        return 0;
    }

    res += (data[t] - l + 1) * data[t];
    ++t;
//    while (data[t] < r) {
//        res += (data[t] - data[t - 1]) * data[t];
//        ++t;
//    }
//    res += (data[t] - r) * data[t];
    while (true) {
        if (data[t] <= r)
            res += (data[t] - data[t - 1]) * data[t];
        else {
            res += (r - data[t - 1]) * data[t];
            break;
        }
        ++t;
    }

    std::cout << res;
    return 0;
}
