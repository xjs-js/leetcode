#include <iostream>
#include <string>
#include <cstdlib>
#include <stack>
#include <deque>

using namespace std;


int strToInt(const std::string& str)
{
    return atoi(str.c_str());
}

class Solution {
public:
    int calculate(string s) {
        deque<int> nums;
        deque<char> symbol;

        int i = 0;
        int first_num = -1;
        while (i < s.size() && s[i] == ' ')
            ++i;
        
        int j = i+1;
        while (j < s.size() && (s[j] != '+' && s[j] != '-' && s[j] != '*' && s[j] != '/') )
            ++j;
        
        first_num = strToInt(s.substr(i, j-i));

        if (j == s.size()) {
            return first_num;
        }

        nums.push_back(first_num);

        while (j < s.size()) {
            char c = s[j];
            int k = j + 1;
            while (k < s.size() && (s[k] != '+' && s[k] != '-' && s[k] != '*' && s[k] != '/') )
                ++k;

            int nextNum = strToInt(s.substr(j+1, k-j-1));

            if (c == '+' || c == '-') {
                symbol.push_back(c);
                nums.push_back(nextNum);
            }

            else {
                int preNum = nums.back();
                nums.pop_back();

                int result = 0;
                if (c == '/')
                    result = preNum / nextNum;
                else if (c == '*')
                    result = preNum * nextNum;
                
                nums.push_back(result);
            }
            j = k;
        }


        while (!symbol.empty()) {
            char s = symbol.front();
            symbol.pop_front();

            int num1 = nums.front();
            nums.pop_front();

            int num2 = nums.front();
            nums.pop_front();

            int result = 0;
            if (s == '-')
                result = num1 - num2;
            else if (s == '+')
                result = num1 + num2;

            nums.push_front(result);
        }

        return nums.front();
    }
};



int main(int argc, char* argv[])
{
    Solution sol;
    std::cout << sol.calculate("3+2*2") << std::endl;
    std::cout << sol.calculate(" 3/2 ") << std::endl;
    std::cout << sol.calculate(" 3+5 / 2 ") << std::endl;
    std::cout << sol.calculate("1-1+1") << std::endl;
    return 0;
}