class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int count[26];
        memset(count, 0, sizeof count);

        int curCount[26];
        for (int i = 0; i < words2.size(); ++i) {
            string& str = words2[i];
            memset(curCount, 0, sizeof curCount);

            for (int j = 0; j < str.size(); ++j) {
                ++curCount[str[j] - 'a'];
            }
            
            for (int j = 0; j < 26; ++j) {
                if (curCount[j] > count[j]) {
                    count[j] = curCount[j];
                }
            }
        }

        vector<string> relt;
        for (int i = 0; i < words1.size(); ++i) {
            string& str = words1[i];
            memset(curCount, 0, sizeof curCount);

            for (int j = 0; j < str.size(); ++j) {
                ++curCount[str[j] - 'a'];
            }

            bool canMatch = true;
            for (int j = 0; j < 26; ++j) {
                if (curCount[j] < count[j]) {
                    canMatch = false;
                    break;
                }
            }

            if (canMatch) {
                relt.push_back(str);
            }
        }
        return relt;
    }
};
