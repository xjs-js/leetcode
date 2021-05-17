class Solution {
public:
    int longestStrChain(vector<string>& words) {
        map<int, vector<string>> dict;
        for (int i = 0; i < words.size(); ++i) {
            string s = words[i];
            dict[s.size()].push_back(s);
        }
        
        unordered_map<string, int> relt;
        relt[""] = 0;
        int maxLen = 0;
        auto it = dict.begin();
        while (it != dict.end()) {
            int len = it->first;
            vector<string>& arr = it->second;
            
            for (int i = 0; i < arr.size(); ++i) {
                string lhs = arr[i];
                int curLen = 0;                
                for (int j = 0; j < lhs.size(); ++j) {
                    string substr = lhs.substr(0, j) + lhs.substr(j+1);
                    if (relt[substr]) {
                        curLen = max(curLen, relt[substr]);
                    }
                }
                relt[lhs] = curLen + 1;
                maxLen = max(maxLen, relt[lhs]);
            }
            
            ++it;
        }
        return maxLen;
    }
};
