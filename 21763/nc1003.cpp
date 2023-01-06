// https://ac.nowcoder.com/acm/contest/21763/1003

#include <iostream>
#include <iterator>

inline long long gcd(long long a, long long b) {
    while (b ^= a ^= b ^= a %= b);
    return a;
}

int main() {
    std::cout << gcd(*std::istream_iterator<long long>(std::cin), *std::istream_iterator<long long>(std::cin));
    return 0;
}
