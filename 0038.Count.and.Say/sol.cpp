// 2019-01-16
// https://leetcode.com/problems/count-and-say/


#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    string calc(string in_str)
    {
        string out_str = "";
        int length = in_str.length();
        int count = 1;
        char cur_char = in_str[0];
        for (int i = 1; i < length; ++i)
        {
            if ( in_str[i] == in_str[i-1] )
                count = count + 1;
            if ( in_str[i] != in_str[i-1] ) {
                out_str = out_str + to_string(count) + cur_char;
                count = 1;
                cur_char = in_str[i];
            }
        }
        out_str = out_str + to_string(count) + cur_char;
        
        return out_str;
    }

    string countAndSay(int n) {
        if (n == 1)     return "1";
        if (n == 2)     return "11";
        if (n == 3)     return "21";
        if (n == 4)     return "1211";
        if (n == 5)     return "111221";

        int delta = n - 5;
        string out_str = "111221";
        while (delta--) {
            out_str = calc(out_str);
        }

        return out_str;
    }

};

int main()
{
    Solution s;
    cout << s.countAndSay(6);
    return 0;
}