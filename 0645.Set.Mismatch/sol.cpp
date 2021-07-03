class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> arr;
        int n = nums.size();
        for (int i = 0; i < n; ++i) arr.insert(i+1);

        vector<int> relt;
        for (int i = 0; i < n; ++i) {
            if (arr.count(nums[i])) {
                arr.erase(nums[i]);
            } else {
                relt.push_back(nums[i]);
            }
        }

        relt.push_back(*(arr.begin()));
        return relt;
    }
};
