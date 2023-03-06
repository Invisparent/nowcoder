// 好家伙，你搁这让我写编译器前端呢

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <unordered_set>
#include <algorithm>

std::string str;
std::unordered_set<std::string> varList;
const std::unordered_set<std::string> opList{"+", "-", "*", "/", ":=", "=", "#", "<", "<=", ">", ">=", "(", ")", ";",
                                             ".", ","};
const std::unordered_set<std::string> keyList{"begin", "call", "const", "do", "else", "end", "if", "procedure", "read",
                                              "return", "then", "var", "while", "write"};
const std::unordered_set<char> xOpList{'+', '-', '*', '/', ':', '=', '#', '<', '>', '(', ')', ';', '.', ','};

inline bool isLegal(char ch) {
    if (std::isalpha(ch))
        return true;
    if (std::isdigit(ch))
        return true;
    if (ch == '_')
        return true;
    return false;
}

void solve() {
    if (str.empty())
        return;

    std::stringstream ss(str);
    std::istream_iterator<std::string> stringIter(ss), eof;
    std::vector<std::string> data(stringIter, eof);

    char backChar = 'x';
    if (data.back().back() == ';' || data.back().back() == ',' || data.back().back() == '.')
        backChar = data.back().back();

    for (auto &x: data)
        if (x.back() == ';' || x.back() == ',' || x.back() == '.')
            x.pop_back();

    if (data.front() == "var") {
        std::cout << "var\n";
        for (int t = 1; t < data.size(); ++t) {
            std::cout << "IDENTIFIER " << data[t] << '\n';
            if (t + 1 != data.size())
                std::cout << ",\n";
        }
        std::cout << ";\n";
        return;
    }

    if (data.front() == "begin") {
        std::cout << data.front() << '\n';
        return;
    }

    for (const auto &x: data) {
        if (x.front() == '+' || x.front() == '-') {
            std::string st(x.begin() + 1, x.end());

        }
        auto opIter = opList.find(x);
        auto keyIter = keyList.find(x);
        if (opIter != opList.end())
            std::cout << x << '\n';
        else if (keyIter != keyList.end())
            std::cout << x << '\n';
        else {
            if (std::all_of(x.begin(), x.end(), [](const auto &ch) -> bool {
                return std::isdigit(ch);
            }))
                std::cout << "NUMBER " << x << '\n';
            else if (std::all_of(x.begin(), x.end(), [](const auto &ch) -> bool {
                return std::isalpha(ch) || ch == '_';
            }))
                std::cout << "IDENTIFIER " << x << '\n';
            else {
//                auto xIter = x.begin();
//                while (xIter != x.end()) {
//                    if (*xIter == '+' || *xIter == '-' || *xIter == '*' || *xIter == '/' || *xIter == '=' ||
//                        *xIter == '#') {
//                        std::cout << *xIter << '\n';
//                        ++xIter;
//                        continue;
//                    }
//                    if (!isLegal(*xIter)) {
//                        std::cout << "ILLEGAL " << *xIter << '\n';
//                        ++xIter;
//                        continue;
//                    }
//                    auto xFlagIter = xIter + 1;
//                    while (xFlagIter != x.end())
//                        if (isLegal(*xFlagIter))
//                            ++xFlagIter;
//                        else
//                            break;
//                    if (std::isalpha(*xIter) || *xIter == '_')
//                        std::cout << "IDENTIFIER " << std::string(xIter, xFlagIter) << '\n';
//                    else
//                        std::cout << "NUMBER " << std::string(xIter, xFlagIter) << '\n';
//                    xIter = xFlagIter;
//
//                }
                auto xIter = x.begin();
                std::string newStr;
                newStr.push_back(x.front());
                for (int t = 1; t < x.size(); ++t) {
                    auto xOpIter = xOpList.find(x[t]);
                    auto xPrevIter = xOpList.find(x[t]);
                    if ((xOpIter == xOpList.end()) != (xPrevIter == xOpList.end()))
                        newStr.push_back(' ');
                    newStr.push_back(x[t]);
                }
                std::string tmpStr = str;
                str = newStr;
                solve();
                str = tmpStr;
            }
        }
    }
    if (backChar != 'x')
        std::cout << backChar << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    while (std::getline(std::cin, str))
        solve();

    return 0;
}
