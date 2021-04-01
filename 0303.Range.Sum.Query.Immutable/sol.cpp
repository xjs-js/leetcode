/**
 * @date: 2021-04-01 20:20
 * @note: 这题好简单，我没看错吧，哈哈哈
 */


class NumArray {
private:
    vector<int> _nums;
public:
    NumArray(vector<int>& nums) 
        : _nums(nums)
    {

    }
    
    int sumRange(int left, int right) {
        int result = 0;
        for (int i = left; i <= right; ++i) {
            result += _nums[i];
        }
        return result;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
