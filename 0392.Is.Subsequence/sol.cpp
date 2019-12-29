#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

/**
 * check whether c is in str starts from beg postion
 *
 * 
 * @param  str : input str
 * @param  len : length of str
 * @param  c   : char to find
 * @param  beg : start position
 */
int check_in(const std::string& str, int len, char c, int beg)
{
    int pos = beg;
    
    while (pos != len)
    {
        if (str[pos] == c)
        {
            return pos;
            break;
        }
        ++pos;
    }

    return -1;
}

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int s_len = s.size();
        int t_len = t.size();
        int last_index = -1;
        while (i != s_len)
        {
            char c = s[i];
            int result = check_in(t, t_len, c, last_index+1);
            printf("find %c at %d\n", c, result);
            if (result == -1)
            {
                return false;
            }
            last_index = result;
            ++i;
        }
        return true;
    } 
};

int main(int argc, char* argv[])
{
    std::string s = "axc";
    std::string t = "ahbgdc";

    Solution sol;
    if (sol.isSubsequence(s, t))
    {
        std::cout << "true" << std::endl;    
    }
    else
    {
        std::cout << "false" << std::endl;
    }
    
    return 0;
}
