/**
 * @date: 2021-04-13 22:50 Tue
 */

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {        
        for (int i = 0; i < words.size(); ++i) {
            string& word = words[i];
            reverse(word.begin(), word.end());
        }
        
        sort(words.begin(), words.end());
        
        int i = 0;
        int count = 0;
        while (i < words.size()) {
            string cur = words[i];
            if (i + 1 < words.size()) {
                string next = words[i+1];
                if (next.find(cur) != 0) {
                    count += (cur.size() + 1);
                }
            } else {
                count += (cur.size() + 1);
            }
            ++i;
        }
        
        return count;
    }
};