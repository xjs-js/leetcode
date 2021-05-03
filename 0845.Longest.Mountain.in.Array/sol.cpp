class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> left(n, 0);
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i-1]) {
                left[i] = left[i-1] + 1;
            } else {
                left[i] = 0;
            }
        }
        
        vector<int> right(n, 0);
        int relt = 0;
        for (int i = n-2; i >= 0; --i) {
            if (arr[i] > arr[i+1]) {
                right[i] = right[i+1] + 1;
            } else {
                right[i] = 0;
            }
            if (right[i] > 0 && left[i] > 0 && right[i] + left[i] + 1 >= 3) {
                relt = max(relt, right[i] + left[i] + 1);
            }
        }
        return relt;
    }
};
