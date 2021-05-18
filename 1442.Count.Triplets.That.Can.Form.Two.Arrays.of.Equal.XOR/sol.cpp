class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> xorSum(n, 0);
        
        xorSum[0] = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            xorSum[i] = arr[i] ^ xorSum[i-1];
        }
        
        int relt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j; k < n; ++k) {
                    int a = (i == 0) ? xorSum[j-1] : xorSum[j-1] ^ xorSum[i-1];
                    int b = xorSum[k] ^ xorSum[j-1];
                    if (a == b) {
                        ++relt;
                    }
                }
            }
        }
        return relt;
    }
};
