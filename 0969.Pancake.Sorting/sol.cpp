class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> relt;
        int j = n-1;
        while (j > 0) {
            int maxNum = -1;
            int maxIndex = -1;
            for (int i = 0; i <= j; ++i) {
                if (arr[i] > maxNum) {
                    maxNum = arr[i];
                    maxIndex = i;
                }
            }
            cout << maxIndex <<  ", " << j << endl;
            if (j == maxIndex) {
                --j;
                continue;
            } else {
                if (maxIndex != 0) {
                    relt.push_back(maxIndex+1);
                    reverse(arr.begin(), arr.begin() + maxIndex + 1);
                }
                relt.push_back(j+1);
                reverse(arr.begin(), arr.begin() + j + 1);
                --j;
            }
        }

        return relt;
    }
};
