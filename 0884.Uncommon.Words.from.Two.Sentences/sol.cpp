class Solution {
public:
    void split(string& str, unordered_map<string,int>& count) {
        string c = " ";
        size_t beg = 0;
        size_t end = str.find(c);
        while (end != string::npos) {
            string token = str.substr(beg, end - beg);
            if (token.size()) {
                ++count[token];
            }
            beg = end + 1;
            end = str.find(c, beg);
        }
        
        string token = str.substr(beg);
        if (token.size()) {
            ++count[token];
        }
        
    }
    
    // 将s1和s2中所有的单词计数，最后返回出现一次的
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> count;
        split(s1, count);
        split(s2, count);
        
        auto it = count.begin();
        vector<string> relt;
        while (it != count.end()) {
            if (it->second == 1) {
                relt.emplace_back(it->first);
            }
            
            ++it;
        }
        return relt;
    }
};
