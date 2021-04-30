class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        unordered_map<int, int> dict;  
        
        for (int i = 0; i < indexes.size(); ++i) {
            dict[indexes[i]] = i;
        }
        
        string relt = "";
        
        int i = 0;
        while (i < S.size()) {
            if (dict.find(i) != dict.end()) {
                int index = dict[i];
                string source = sources[index];
                if (S.substr(i, source.size()) == source) {
                    relt += targets[index];
                    i += source.size();
                } else {
                    relt += S[i];
                    ++i;
                }
            } else {
                relt += S[i];
                ++i;
            }
        }
        return relt;
    }
};

