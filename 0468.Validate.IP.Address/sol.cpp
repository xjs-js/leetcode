#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool isIPv4Token(const string& token) {
        size_t N = token.size();
        if (N > 3 || N == 0) {
            return false;
        }

        for (size_t i = 0; i < N; ++i) {
            char c = token[i];
            if (c < '0' || c > '9') {
                return false;
            }
        }
        
        
        int num = atoi(token.c_str());
    
        if (num < 0 || num > 255) {
            return false;
        }

        if (num == 0 && token != "0") {
            return false;
        }

        if (token.size() > 1 && token[0] == '0') {
            return false;
        }

        return true;
    }

    bool isIPv4(const string& IP) {
        string delim = ".";
        size_t start = 0;
        size_t end = IP.find(delim);
        int count = 0;
        while (end != std::string::npos) {
            string str = IP.substr(start, end - start);
            ++count;

            if (!isIPv4Token(str)) {
                return false;
            }

            start = end + delim.length();
            end = IP.find(delim, start);
        }

        string str = IP.substr(start, end);
        if (!isIPv4Token(str)) {
            return false;
        }

        if (count != 3) {
            return false;
        }

        return true;
    }

    bool isIPv6Token(const string& str) {
        size_t N = str.size();

        if (N > 4 || N == 0) {
            return false;
        }

        for (size_t i = 0; i < N; ++i) {
            char c = str[i];

            if (!(c >= '0' && c <= '9' 
                    || c >= 'a' && c <= 'f'
                    || c >= 'A' && c <= 'F')) {
                    return false;
                }
        }

        return true;
    }


    bool isIPv6(const string& IP) {
        string delim = ":";
        size_t start = 0;
        size_t end = IP.find(delim);
        int count = 0;
        while (end != std::string::npos) {
            string str = IP.substr(start, end - start);
            ++count;

            if (!isIPv6Token(str)) {
                return false;
            }

            start = end + delim.length();
            end = IP.find(delim, start);
        }

        string str = IP.substr(start, end);
        if (!isIPv6Token(str)) {
            return false;
        }

        if (count != 7) {
            return false;
        }

        return true;
    }


public:
    string validIPAddress(string IP) {
        if (isIPv4(IP)) {
            return "IPv4";
        }

        if (isIPv6(IP)) {
            return "IPv6";
        }

        return "Neither";
    }
};

int main(int argc, char* argv[]) {
    Solution sol;
    // std::cout << sol.validIPAddress("172.16.254.1") << std::endl;
    // std::cout << sol.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334") << std::endl;
    // std::cout << sol.validIPAddress("256.256.256.256") << std::endl;
    // std::cout << sol.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334:") << std::endl;
    std::cout << sol.validIPAddress("01.01.01.01") << std::endl;
    return 0;
}