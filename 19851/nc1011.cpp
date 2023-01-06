#include <iostream>
#include <string>
#include <vector>

inline std::string sPlus(const std::string &s1, const std::string &s2) {
    std::string r(s1.size() + 1, '0');
    std::string::const_reverse_iterator iterA = s1.crbegin(), iterB = s2.crbegin();
    int x, t = r.size() - 1;
    while (iterB != s2.crend()) {
        x = *iterA + *iterB - '0' - '0';
        if (x > 9)
            ++r[t - 1];
        r[t] += x % 10;
        ++iterA;
        ++iterB;
        --t;
    }
    while (iterA != s1.crend()) {
        x = r[t] + *iterA - '0' - '0';
        if (x > 9)
            ++r[t - 1];
        r[t] = x % 10 + '0';
        ++iterA;
        --t;
    }
    if (r.front() == '0')
        r.erase(r.begin());
    return r;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> vs(n + 1);
    vs[0] = "0", vs[1] = "2", vs[2] = "6";
    for (int t = 3; t <= n; ++t)
        vs[t] = sPlus(sPlus(vs[t - 1], vs[t - 1]), "2");
    std::cout << vs[n];
    return 0;
}
