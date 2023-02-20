#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::string data, target;
    std::cin >> data >> target;

    std::string o;
    for (const char &ch: data)
        if (std::isalpha(ch))
            o.push_back(ch);

    for (auto iter = o.begin(); iter != o.end(); ++iter) {
        auto iterA = iter, iterB = target.begin();
        while (iterA != o.end() && iterB != target.end())
            if (*iterA == *iterB) {
                ++iterA;
                ++iterB;
            } else
                break;
        if (iterB == target.end()) {
            std::cout << "YES";
            return 0;
        }
    }
    std::cout << "NO";
    return 0;
}
