class Solution {
public:
    int thirdMax(vector<int>& nums) {        
        int a = INT_MIN, b = INT_MIN, c = INT_MIN;
        int count = 0; // a,b,c中有效的个数
        
        int n = nums.size();
        bool minAppear = false;
        
        for (int i = 0; i < n; ++i) {
            int curNum = nums[i];
            
            if (curNum == INT_MIN && !minAppear) {
                ++count;
                minAppear = true;
                continue;
            } else {
                if (curNum == a || curNum == b || curNum == c) {
                    continue;
                }
            }
            
            // 不同
            ++count;
            
            if (curNum < a) {
                continue;
            } else if (curNum < b) {
                a = curNum;
            } else if (curNum < c) {
                a = b;
                b = curNum;
            } else {
                a = b;
                b = c;
                c = curNum;
            }
        }
        
        if (count < 3) {
            return c;
        } else{
            return a;
        }
    }
};
