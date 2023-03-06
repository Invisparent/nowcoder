#include <iostream>
#include <string>

const std::string ta = "Association_for_Computing_Machinery";
const std::string tb = "Air_Combat_Maneuvering";
std::string str;

inline bool ivsMatch(const std::string &src, const std::string &target) {
    auto flagIter = src.begin();
    while (flagIter != src.end()) {
        auto travIter = flagIter;
        auto tgtIter = target.begin();
        while (travIter != src.end() && tgtIter != target.end())
            if (*travIter == *tgtIter) {
                ++travIter;
                ++tgtIter;
            } else
                break;
        if (tgtIter == target.end())
            return true;
        ++flagIter;
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> str;
    bool resa = ivsMatch(str, ta);
    bool resb = ivsMatch(str, tb);

    if (resa == resb)
        std::cout << "NO";
    else
        std::cout << "YES";
    return 0;
}
