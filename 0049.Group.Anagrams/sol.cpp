// 2023-11-23 21:06

class Solution {
private:
    string getHash(string& str) {
        string relt;
        vector<int> count(26, 0);
        for (char c : str)
            ++count[c - 'a'];
        
        for (int i = 0; i < 26; ++i) {
            int j = count[i];
            while(j--) {
                relt += ('a' + i);
            }
        }
        return relt;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group;

        for (string& str : strs) {
            string hashStr = getHash(str);
            group[hashStr].push_back(str);
        }

        auto it = group.begin();
        vector<vector<string>> relt;
        while (it != group.end()) {
            relt.push_back(it->second);
            ++it;
        }
        return relt;
    }
};
