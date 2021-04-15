/**
 * @date: 2021-04-15 22:57 Thur.
 */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> left(nums1.begin(), nums1.end());
        
        unordered_set<int> result;
        for (int i = 0; i < nums2.size(); ++i) {
            if (left.count(nums2[i])) {
                result.insert(nums2[i]);
            }
        }
        
        vector<int> rlt(result.begin(), result.end());
        return rlt;
    }
};