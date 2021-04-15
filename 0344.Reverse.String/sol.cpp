/**
 * @date: 2021-04-15 23:17 Thur.
 */

class Solution {
public:
    void reverseString(vector<char>& s) {
        int N = s.size();
        
        for (int i = 0; i < N/2; ++i) {
            swap(s[i], s[N-1-i]);
        }
    }
};