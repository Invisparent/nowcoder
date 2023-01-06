#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int r = 0;
    for (int i = 0; i * 5 <= n; ++i)
        for (int j = 0; j * 2 + i * 5 <= n; ++j)
            ++r;
    std::cout << r;
    return 0;
}
