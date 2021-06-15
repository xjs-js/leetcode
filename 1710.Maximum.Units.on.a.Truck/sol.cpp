class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& lhs, vector<int>& rhs){
            return lhs[1] > rhs[1];
        });

        int relt = 0;
        for (int i = 0; i < boxTypes.size(); ++i) {
            if (truckSize <= 0) {
                return relt;
            }

            int curNum = boxTypes[i][0];
            int curRelt = boxTypes[i][1];
            if (truckSize >= curNum) {
                relt += curNum * curRelt;
                truckSize -= curNum;
            } else {
                relt += truckSize * curRelt;
                truckSize = 0;
            }
        }
        return relt;
    }
};
