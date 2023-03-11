#include <iostream>
#include <string>

void solve() {
    int n;
    std::cin >> n;

    std::string str;
    std::cin >> str;
    std::string o;
    o.push_back(str.front());
    int op = 1;

    while (o != str) {
        int oBeg = 0, strBeg = (int) o.size();
        while (oBeg < o.size() && strBeg < str.size() && o[oBeg] == str[strBeg]) {
            ++oBeg;
            ++strBeg;
        }
        if (oBeg)
            o += std::string(o.begin(), o.begin() + oBeg);
        else
            o += str[strBeg];
        ++op;
    }

    std::cout << op << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int tt;
    std::cin >> tt;
    while (tt--)
        solve();

    return 0;
}
