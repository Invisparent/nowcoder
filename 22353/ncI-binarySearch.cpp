// https://ac.nowcoder.com/acm/contest/22353/I
// K-th Number

// Multiple Solutions
// By binarySearch

// Wrong Answer
// Fuck you

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//
//std::unordered_map<long long, bool> fastCallDat;
//
///**
// *  Return if there are at least M numbers greater or equal to targetNum
// */
//inline bool query_innerChecker
//        (const std::vector<long long> &rawDat, const long long &K, const long long &M, const long long &targetNum) {
//    auto fastCallIter = fastCallDat.find(targetNum);
//    if (fastCallIter != fastCallDat.end())
//        return fastCallIter->second;
//    long long r = 0, counter = 0;
//    auto iterA = rawDat.cbegin(), iterB = rawDat.cbegin();
//    // [ *iterA , *iterB )
//    while (iterB - iterA < K) {
//        if (*iterB >= targetNum)
//            ++counter;
//        ++iterB;
//    }
//    while (iterB != rawDat.cend()) {
//        if (counter >= K)
//            r += rawDat.cend() - iterB + 1;
//        if (*iterB >= targetNum)
//            ++counter;
//        if (*iterA >= targetNum)
//            --counter;
//        ++iterA;
//        ++iterB;
//    }
//    bool result = r >= M;
//    fastCallDat[targetNum] = result;
//    return result;
//}
//
//inline long long query
//        (const std::vector<long long> &rawDat, const long long &nNum, const long long &K, const long long &M) {
//    // GVI
//    fastCallDat.clear();
//    // Done
//
//    long long l = 0, r = nNum - 1, m;
//    while (true) {
//        m = (l + r) >> 1;
//        if (query_innerChecker(rawDat, K, M, rawDat[m + 1]))
//            l = m + 1;
//        else if (!query_innerChecker(rawDat, K, M, rawDat[m]))
//            r = m - 1;
//        else
//            break;
//    }
//    return m;
//}
//
//int main() {
//    long long testcaseNum;
//    std::cin >> testcaseNum;
//    long long N, K, M;
//    while (std::cin >> N >> K >> M) {
//        std::vector<long long> rawDat(N);
//        for (long long t = 0; t < N; ++t)
//            std::cin >> rawDat[t];
//        std::sort(rawDat.begin(), rawDat.end());
//        std::cout << query(rawDat, N, K, M) << std::endl;
//    }
//    return 0;
//}

// Wrong Answer * 2
// ...
// Debug for 3 days and failed...

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//
//long long N, K, M;
//std::vector<long long> rawDat, sortedDat;
//std::unordered_map<long long, long long> fastCall;
//
//inline long long query_innerCalculator(const long long &targetNum) {
//    auto fastCallIter = fastCall.find(targetNum);
//    if (fastCallIter != fastCall.end())
//        return fastCallIter->second;
//    auto iterA = rawDat.cbegin(), iterB = rawDat.cbegin();
//    // counter: How many number greater than targetNum
//    long long counter = 0, r = 0;
//    // [ iterA , iterB )
//    while (iterB != rawDat.cend()) {
//        while (iterB != rawDat.cend() && counter < K) {
//            if (*iterB > targetNum)
//                ++counter;
//            ++iterB;
//        }
//        while (iterA < iterB && counter >= K) {
//            r += rawDat.cend() - iterB + 1;
//            if (*iterA > targetNum)
//                --counter;
//            ++iterA;
//        }
//    }
//    fastCall[targetNum] = r;
//    return r;
//}
//
//inline long long query() {
//    // GVI
//    fastCall.clear();
//    // Done
//
//    if (M == 1)
//        return sortedDat[N - K];
//    long long l = 0, r = N - 2, m;
//    while (l <= r) {
//        m = (l + r) >> 1;
//        if (query_innerCalculator(sortedDat[m + 1]) > M)
//            l = m + 1;
//        else if (query_innerCalculator(sortedDat[m]) <= M)
//            r = m - 1;
//        else
//            break;
//    }
//    return sortedDat[m];
//}
//
//int main() {
//    std::cin >> N;
//    // GVI
//    while (std::cin >> N >> K >> M) {
//        rawDat = std::vector<long long>(N);
//        // Done
//
//        for (auto t = 0; t < N; ++t)
//            std::cin >> rawDat[t];
//        sortedDat = rawDat;
//        std::sort(sortedDat.begin(), sortedDat.end());
//        std::cout << query() << std::endl;
//    }
//    return 0;
//}

// Minimal code

#include <iostream>
#include <vector>

int N, K;
long long M;
std::vector<int> rawDat;

/**
 * @param targetNum
 * @return Check when targetNum is the M-th Number,
 *         whether the amount of K-th Number is GREATER OR EQUAL TO M
 *  It's obvious when the condition above is false
 *  The targetNum will not be the M-th Number
 *  And using this to deploy binarySearch
 */
inline bool legalCheck(const int &targetNum) {
    long long result = 0;
    // Using pfs
    std::vector<int> cache(N + 1);
    for (int t = 1; t <= N; ++t)
        cache[t] = cache[t - 1] + (rawDat[t] >= targetNum);
    int l = 1;
    for (int r = K; r <= N; ++r) {
        while (cache[r] - cache[l - 1] >= K)
            ++l;
        /**
         *  Why result += l - 1 ?
         *  Just see the while loop condition and ++l
         *  And you'll get why l should minus 1
         */
        result += l - 1;
    }
    return result >= M;
}

int main() {
    int testcaseNum;
    std::cin >> testcaseNum;
    while (std::cin >> N >> K >> M) {
        // First element align to rawDat[1]
        rawDat = std::vector<int>(N + 1);
        int l = 1, r = 1, m;
        // for (int t = 0; t <= N; ++t) {...}
        // What are you doing...
        for (int t = 1; t <= N; ++t) {
            std::cin >> rawDat[t];
            r = std::max(rawDat[t], r);
        }
        /**
         *  Pay attention to this special binarySearch
         *  Approach from the left
         *  It has many benefits...
         *  Just simulate it in your mind...
         */
        while (l < r) {
            /**
             *  Guarantee m is always closer to r
             *  In the final loop
             *  It should be
             *  l == n, r == n + 1, m == n + 1 or m == r
             *  And then r = m - 1, l == r
             *  Loop done, l will always be in the correct position
             */
            m = (l + r + 1) >> 1;
            if (legalCheck(m))
                l = m;
            else
                r = m - 1;
        }
        std::cout << l << std::endl;
    }
    return 0;
}

// Inspired from https://blog.csdn.net/qq_52093121/article/details/121249685

//#include<bits/stdc++.h>
//
//using namespace std;
//#define endl "\n"
//typedef long long ll;
//const int N = 1e5 + 10;
//ll n, m, k, t;
//int a[N];
//int s[N];//1-i多少个数大于等于x
//
//bool check(int x) {
//    ll sum = 0;
//    for (int i = 1; i <= n; i++) {
//        s[i] = s[i - 1] + (a[i] >= x);
//    }
//    int l = 1;
//    for (int r = k; r <= n; r++)//想想这里怎么做
//    {
//        while (s[r] - s[l - 1] >= k) l++;
//        sum += l - 1;
//    }
//    return sum >= m;
//}
//
//int main() {
//    scanf("%lld", &t);
//    while (t--) {
//        scanf("%lld%lld%lld", &n, &k, &m);
//        int l = 1, r = 1;
//        for (int i = 1; i <= n; i++) {
//            scanf("%d", &a[i]);
//            r = max(r, a[i]);
//        }
//        //b m个数大于等于x
//        while (l < r) {
//            int mid = l + r + 1 >> 1;
//            if (check(mid)) l = mid;
//            else r = mid - 1;
//        }
//        cout << l << endl;
//    }
//    return 0;
//}
