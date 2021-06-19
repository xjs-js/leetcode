// https://leetcode-cn.com/problems/substrings-of-size-three-with-distinct-characters/

class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        
        int count = 0;
        for (int i = 0; i + 2 < n; ++i) {
            string substr = s.substr(i, 3);
            if (substr[0] != substr[1] && substr[1] != substr[2] && substr[0] != substr[2]) {
                ++count;
            }
        }
        
        return count;
    }
};