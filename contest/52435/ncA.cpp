// 好家伙，手写编译器前端是吧

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <unordered_set>
#include <algorithm>

std::string str;

const std::unordered_set<std::string> keyList{"begin", "call", "const", "do", "else", "end", "if", "procedure", "read",
                                              "return", "then", "var", "while", "write"};
const std::unordered_set<std::string> opList{"+", "-", "*", "/", ":=", "=", "#", "<", "<=", ">", ">=", "(", ")", ";",
                                             ".", ","};
const std::unordered_set<char> charSet{'+', '-', '*', '/', ':', '=', '#', '<', '>', '(', ')', ';', '.', ','};

inline bool isLegalIdentifier(const std::string &inStr) {
    if ((!std::isalpha(inStr.front())) && inStr.front() != '_')
        return false;

    for (const char &ch: inStr)
        if ((!std::isalpha(ch)) && (!std::isdigit(ch)) && ch != '_')
            return false;

    return true;
}

inline bool isLegalNum(const std::string &inStr) {
    return std::all_of(inStr.begin(), inStr.end(), [](const auto &ch) -> bool {
        return std::isdigit(ch);
    });
}

inline bool belongToIdentifier(char ch) {
    if (std::isdigit(ch))
        return true;
    if (std::isalpha(ch))
        return true;
    if (ch == '_')
        return true;
    return false;
}

void analyzer(std::string inStr) {
    if (inStr.back() == ';' || inStr.back() == '.' || inStr.back() == ',')
        inStr.pop_back();
    auto keyIter = keyList.find(inStr);
    auto opIter = opList.find(inStr);
    if (keyIter != keyList.end())
        std::cout << inStr << '\n';
    else if (opIter != opList.end())
        std::cout << inStr << '\n';
    else {
        if (inStr.front() == '-') {
            std::cout << "-\n";
            inStr.erase(inStr.begin());
            analyzer(inStr);
        }
        if (isLegalIdentifier(inStr)) {
            std::cout << "IDENTIFIER " << inStr << '\n';
            return;
        } else if (isLegalNum(inStr)) {
            std::cout << "NUMBER " << inStr << '\n';
            return;
        } else {
            // Type judge

            auto finalIter = inStr.begin(), travIter = inStr.begin() + 1;
            if (std::isdigit(*finalIter)) {
                while (std::isdigit(*travIter))
                    ++travIter;
                std::cout << "NUMBER " << '\n';
                analyzer({travIter, inStr.end()});
                return;
            } else if (std::isalpha(*finalIter) || *finalIter == '_') {
                while (belongToIdentifier(*travIter))
                    ++travIter;
                std::cout << "IDENTIFIER " << std::string(finalIter, travIter) << '\n';
                analyzer({travIter, inStr.end()});
                return;
            }

            auto charIter = charSet.find(inStr.front());
            if (charIter == charSet.end()) {
                std::cout << "ILLEGAL " << inStr.front() << '\n';
                analyzer({inStr.begin() + 1, inStr.end()});
            } else {
                if (inStr.size() == 1) {
                    auto xIter = opList.find(inStr);
                    if (xIter != opList.end())
                        std::cout << inStr << '\n';
                    else
                        std::cout << "ILLEGAL " << inStr << '\n';
                    return;
                }
                std::string tmpStr(2, 'x');
                tmpStr[0] = inStr[0];
                tmpStr[1] = inStr[1];
                auto tmpIter = opList.find(tmpStr);
                if (tmpIter != opList.end()) {
                    std::cout << tmpStr << '\n';
                    analyzer({inStr.begin() + 2, inStr.end()});
                }
            }
        }
    }
}

void solve() {
    if (str.empty())
        return;

    std::stringstream ss(str);
    std::istream_iterator<std::string> stringIter(ss), eof;
    std::vector<std::string> data(stringIter, eof);

    for (const auto &x: data) {
        analyzer(x);
        if (x.back() == '.')
            std::cout << ".\n";
        else if (x.back() == ',')
            std::cout << ",\n";
        else if (x.back() == ';')
            std::cout << ";\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    while (std::getline(std::cin, str))
        solve();

    return 0;
}
