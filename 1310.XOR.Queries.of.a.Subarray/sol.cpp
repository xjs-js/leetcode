class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> xorsum(n);
        
        xorsum[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            xorsum[i] = arr[i] ^ xorsum[i-1];
        }
        
        int m = queries.size();
        vector<int> relt(m);
        for (int i = 0; i < m; ++i) {
            int first = queries[i][0];
            int second = queries[i][1];
            
            if (first == 0) {
                relt[i] = xorsum[second];
            } else {
                relt[i] = xorsum[second] ^ xorsum[first - 1];
            }
        }
        return relt;
    }
};
