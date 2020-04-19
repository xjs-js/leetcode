class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int len = nums.size();
        if (len == 0) {
            return result;
        }

        int* left_to_right = new int[len];
        int* right_to_left = new int[len];

        for (size_t i = 0; i < len; ++i) {
            left_to_right[i] = 0;
            right_to_left[i] = 0;
        }

        int cur_num = 1;
        for (size_t i = 0; i < len; ++i) {
            left_to_right[i] = cur_num;
            cur_num = cur_num * nums.at(i);
        }

        int rev_cur_num = 1;
        for (int i = len-1; i > 0; --i) {
            rev_cur_num = rev_cur_num * nums.at(i);
            right_to_left[i] = rev_cur_num;
        }

        for (int i = 0; i < len-1; ++i) {
            result.push_back(left_to_right[i] * right_to_left[i+1]);
        }
        result.push_back(left_to_right[len-1]);

        return result;
    }
};