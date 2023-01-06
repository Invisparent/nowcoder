#include <iostream>
#include <string>
#include <vector>

#define modNum 20010905

int main() {
    std::string s;
    std::cin >> s;
    std::vector<long long> vll(8);
    for (char &ch: s) {
        ch = std::tolower(ch);
        switch (ch) {
            case 'i':
                ++vll[0];
                break;
            case 'l':
                vll[1] = (vll[1] + vll[0]) % modNum;
                break;
            case 'o':
                vll[2] = (vll[2] + vll[1]) % modNum;
                vll[6] = (vll[6] + vll[5]) % modNum;
                break;
            case 'v':
                vll[3] = (vll[3] + vll[2]) % modNum;
                break;
            case 'e':
                vll[4] = (vll[4] + vll[3]) % modNum;
                break;
            case 'y':
                vll[5] = (vll[5] + vll[4]) % modNum;
                break;
            case 'u':
                vll[7] = (vll[7] + vll[6]) % modNum;
                break;
            default:
                continue;
        }
    }
    std::cout << vll[7];
    return 0;
}