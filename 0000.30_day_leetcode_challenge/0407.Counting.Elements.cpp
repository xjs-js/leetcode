class Solution {
public:
    int countElements(vector<int>& arr) {
        int* nums = new int[1001];
        memset(nums, 0, 1001);

        auto it = arr.begin();
        while (it != arr.end()) {
            nums[*it] = 1;
            ++it;
        }

        it = arr.begin();
        int result = 0;
        while (it != arr.end()) {
            if (*it + 1 <= 1000 && nums[*it+1] == 1) {
                ++result;
            }
            ++it;
        }

        delete[] nums;
        return result;
    }
};