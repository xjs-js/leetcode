/**
 * @date: 2021-04-16 14:33 Fri.
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int N = strs.size();
        
        if (N == 0) {
            return "";
        }
        if (N == 1) {
            return strs[0];
        }
        
        sort(strs.begin(), strs.end());
        
        string first = strs[0];
        int i = 1;
        string curLongest;
        while (i <= first.size()) {
            string prefix = first.substr(0, i);
            
            for (int j = 0; j < strs.size(); ++j) {
                if (strs[j].substr(0, i) != prefix) {
                    return curLongest;
                }
            }
            
            curLongest = prefix;
            ++i;
        }
        
        return curLongest;
        
    }
};