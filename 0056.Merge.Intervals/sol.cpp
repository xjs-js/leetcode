// 2023/11/23 20:17
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

/**
 * @date: 2021-04-18 23:22
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> result;
        result.emplace_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); ++i) {
            vector<int>& last = result[result.size()-1];
            
            vector<int>& cur = intervals[i];
            
            if (cur[0] > last[1]) {
                result.emplace_back(cur);
            } else {
                last[1] = max(last[1], cur[1]);
            }
        }
        
        return result;
    }
};
