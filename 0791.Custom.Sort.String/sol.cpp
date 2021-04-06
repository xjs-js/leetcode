/**
 * @date: 2021-04-06 19:08
 */


class Solution {
public:
    string customSortString(string S, string T) {
        int* weight = new int[26];
        
        for (int i = 0; i < 26; ++i) {
            weight[i] = 26;
        }

        for (int i = 0; i < S.size(); ++i) {
            const char& c = S[i];
            weight[c - 'a'] = i;
        }

        sort(T.begin(), T.end(), [&](const char& left, const char& right) {
            return weight[left-'a'] < weight[right-'a'];
        });

        return T;
    }
};
