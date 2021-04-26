class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> relt;
        
        int i = 0;
        int n = s.size();
        while (i < n) {
            int j = i + 1;
            while (j < n && s[j] == s[i])
                ++j;
            
            if (j - i >= 3) {
                relt.push_back({i, j-1});
            }
            i = j;
        }
        
        return relt;
    }
};