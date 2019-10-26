// Roman.to.Integer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <string>

class Solution {
private:
    std::map<char, int> _RomanMap;
public:
    Solution() {
        _RomanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
    }

    int romanToInt(std::string s) {
        int returnResult = 0;

        int i = 0;
        while (i != s.size()) {
            char c = s[i];

            if (c == 'I' && i != s.size() - 1 && s[i + 1] == 'V') { returnResult += 4; i += 2; }
            else if (c == 'I' && i != s.size() - 1 && s[i + 1] == 'X') { returnResult += 9; i += 2; }
            else if (c == 'X' && i != s.size() - 1 && s[i + 1] == 'L') { returnResult += 40; i += 2; }
            else if (c == 'X' && i != s.size() - 1 && s[i + 1] == 'C') { returnResult += 90; i += 2; }
            else if (c == 'C' && i != s.size() - 1 && s[i + 1] == 'D') { returnResult += 400; i += 2; }
            else if (c == 'C' && i != s.size() - 1 && s[i + 1] == 'M') { returnResult += 900; i += 2; }
            else {
                returnResult += _RomanMap.at(c);
                i = i + 1;
            }
        }
        return returnResult;
    }
};


int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage : a.exe IVX" << std::endl;
        return 1;
    }
    Solution s;
    std::string romanStr(argv[1]);
    //std::string romanStr("MCDLXXVI");
    std::cout << s.romanToInt(romanStr) << std::endl;
}