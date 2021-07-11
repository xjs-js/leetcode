class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());

        int n = citations.size();
        for (int i = n-1; i >= 0; --i) {
            int curRelt = n - i;
            if (citations[i] < curRelt) {
                continue;
            } else {
                if (i - 1 >= 0) {
                    if (citations[i-1] <= curRelt) {
                        return curRelt;
                    }
                } else {
                    return curRelt;
                }
            }
        }
        return 0;
    }
};
