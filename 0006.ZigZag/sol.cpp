/**
 * @date: 2021-04-16 11:05 Fri.
 */

class Solution {
public:
    string convert(string s, int numRows) {
        int N = s.size();
        
        int i = 0;
        vector<vector<int>> matrix(numRows);
        while (true) {
            
            for (int j = 0; i < N && j < numRows; ++j) {
                matrix[j].emplace_back(s[i++]);
            }
            
            for (int j = numRows-2; j > 0 && i < N; --j) {
                matrix[j].emplace_back(s[i++]);
            }
            
            if (i >= N) {
                break;
            }
        }

        string result;
        for (int j = 0; j < numRows; ++j) {
            for (int k = 0; k < matrix[j].size(); ++k) {
                result += matrix[j][k];
            }
        }
        return result;
    }
};