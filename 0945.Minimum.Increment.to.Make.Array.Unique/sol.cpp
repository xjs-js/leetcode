class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int, int> count;
        for (int i = 0; i < nums.size(); ++i) {
            ++count[nums[i]];
        }

        auto it = count.begin();
        int cur = -1;
        int relt = 0;
        while (it != count.end()) {
            int c = it->second;
            if (it->first > cur) {
                cur = it->first + c - 1;
                relt += (0 + c-1) * c / 2;
            } else {
                /* 等差数列 */
                relt += (2*cur + c + 1 - 2*it->first) * c / 2;
                cur = cur + c;
            }
            
            ++it;
        }
        return relt;
    }
};
