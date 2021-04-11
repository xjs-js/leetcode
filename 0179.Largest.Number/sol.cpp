/**
 * @date: 2021-04-12 00:09 Mon.
 * @name: 最大数
 * @url: https://leetcode-cn.com/problems/largest-number/
 */

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](const int& left, const int& right){
            string new_1 = to_string(left) + to_string(right);
            string new_2 = to_string(right) + to_string(left);
            
            if (new_1 > new_2)  return true;
            else return false;
        });

        // PrintArray(nums);

        string result;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (result.empty() && nums[i] == 0) {
                continue;
            }
            result += to_string(nums[i]);
        }
        
        if (result.empty()) {
            return "0";
        }
        return result;
    }
};