class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int relt = 0;
        int curRelt = 0;
        
        unordered_set<int> st;
        
        int i = 0;
        curRelt = nums[i];
        st.insert(nums[i]);
        relt = max(relt, curRelt);
        
        int j = i + 1;
        while (j < nums.size()) {
            if (st.count(nums[j]) == 0) {
                st.insert(nums[j]);
                curRelt += nums[j];
                relt = max(relt, curRelt);
                ++j;
            } else {
                while (nums[i] != nums[j]) {
                    curRelt -= nums[i];
                    auto it = st.find(nums[i]);
                    st.erase(it);   
                    ++i;
                }
                ++i;
                ++j;
            }
        }
        
        return relt;
    }
};
