#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

inline bool isWinner(const std::vector<std::string> &vs, char ch) {
    for (const std::string &s: vs)
        if (std::all_of(s.begin(), s.end(), [&](const char &inch) { return inch == ch; }))
            return true;
    for (int t = 0; t < 3; ++t)
        if (vs[0][t] == vs[1][t] && vs[1][t] == vs[2][t] && vs[2][t] == ch)
            return true;
    if (vs[0][0] == vs[1][1] && vs[1][1] == vs[2][2] && vs[2][2] == ch)
        return true;
    if (vs[2][0] == vs[1][1] && vs[1][1] == vs[0][2] && vs[1][1] == ch)
        return true;
    return false;
}

inline void judge(const std::vector<std::string> &vs) {
    bool a = isWinner(vs, 'A'), b = isWinner(vs, 'B');
    if (a && b)
        std::cout << "invalid" << std::endl;
    else if (a)
        std::cout << "Yes" << std::endl;
    else if (b)
        std::cout << "No" << std::endl;
    else
        std::cout << "draw" << std::endl;
}


int main() {
    int T;
    std::cin >> T;
    for (int i = 0; i < T; ++i) {
        std::vector<std::string> vs(3);
        for (int t = 0; t < 3; ++t)
            std::cin >> vs[t];
        judge(vs);
    }
    return 0;
}
