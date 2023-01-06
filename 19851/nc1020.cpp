#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
    std::cout << std::fixed << std::setprecision(4);
    long long n, T, C;
    std::cin >> n >> T >> C;
    std::vector<std::pair<long long, long long>> dat(n);
    for (long long t = 0; t < n; ++t)
        std::cin >> dat[t].first >> dat[t].second;
    if (std::all_of(dat.begin(), dat.end(), [&](const std::pair<long long, long long> &p) { return p.first == T; })) {
        std::cout << "Possible" << std::endl << static_cast<double>(T);
        return 0;
    }
    bool isGreaterThanTank = dat.front().first > T;
    if (!std::all_of(dat.begin(), dat.end(),
                     [&](const std::pair<long long, long long> &p) { return p.first > T == isGreaterThanTank; })) {
        std::cout << "Impossible";
        return 0;
    }
    if (isGreaterThanTank) {
        std::sort(dat.begin(), dat.end(),
                  [](const std::pair<long long, long long> &a, const std::pair<long long, long long> &b) {
                      return a.first < b.first;
                  });
        long long targetTemperature = dat.front().first;
        long double waterRequired = 0.0;
        std::for_each(dat.begin(), dat.end(), [&](const std::pair<long long, long long> &p) {
            if (p.first == targetTemperature)
                return;
            waterRequired +=
                    (p.first - targetTemperature) * static_cast<long double>(p.second) / (targetTemperature - T);
        });
        if (waterRequired > C)
            std::cout << "Impossible";
        else
            std::cout << "Possible" << std::endl << static_cast<long double>(targetTemperature);
        return 0;
    } else {
        std::sort(dat.begin(), dat.end(),
                  [](const std::pair<long long, long long> &a, const std::pair<long long, long long> &b) {
                      return a.first > b.first;
                  });
        long long targetTemperature = dat.front().first;
        long double waterRequired = 0.0;
        std::for_each(dat.begin(), dat.end(), [&](const std::pair<long long, long long> &p) {
            if (p.first == targetTemperature)
                return;
            waterRequired +=
                    (p.first - targetTemperature) * static_cast<long double>(p.second) / (targetTemperature - T);
        });
        if (waterRequired > C)
            std::cout << "Impossible";
        else {
            long double sigmaNumerator = T * C, sigmaDenominator = C;
            std::for_each(dat.begin(), dat.end(), [&](const std::pair<long long, long long> &p) {
                sigmaNumerator += p.first * p.second;
                sigmaDenominator += p.second;
            });
            std::cout << "Possible" << std::endl << sigmaNumerator / sigmaDenominator;
        }
        return 0;
    }
}
