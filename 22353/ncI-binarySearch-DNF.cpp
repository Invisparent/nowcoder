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

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//
//long long N, K, M;
//std::vector<long long> rawDat;
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
//        return rawDat[N - K];
//    long long l = 1, r = N - 2, m;
//    while (true) {
//        m = (l + r) >> 1;
//        if (query_innerCalculator(m + 1) > M)
//            l = m + 1;
//        else if (query_innerCalculator(m) <= M)
//            r = m - 1;
//        else
//            break;
//    }
//    return rawDat[m];
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
//        std::sort(rawDat.begin(), rawDat.end());
//        std::cout << query() << std::endl;
//    }
//    return 0;
//}
