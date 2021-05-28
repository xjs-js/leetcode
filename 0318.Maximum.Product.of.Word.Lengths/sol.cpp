class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();

        vector<vector<int>> m(n, vector<int>(26, 0));

        int relt = 0;
        for (int i = 0; i < n; ++i) {
            string str = words[i];
            for (int j = 0; j < str.size(); ++j) {
                ++m[i][str[j]-'a'];
            }
            for (int k = i-1; k >= 0; --k) {
                bool isFind = true;
                for (int l = 0; l < 26; ++l) {
                    if (m[i][l] > 0 && m[k][l] > 0) {
                        isFind =false;
                        break;
                    }
                }
                if (isFind) {
                    relt = max(relt, (int)words[k].size() * (int)words[i].size());
                }
            }
        }

        return relt;
    }
};
