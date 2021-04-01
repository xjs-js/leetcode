/**
 * @date: 2021-04-01 23:15
 */


class Solution {
private:
    unordered_map<int, int> _memo;

public:
    int getIndex(vector<int>& nums, int index) {
        int curNum = nums[index];
        int N = nums.size();
        if (_memo.find(curNum) == _memo.end()) {
            int i = 1;
            while (i <= N-1) {
                int innerIndex = (index + i) % nums.size();
                if (nums[innerIndex] > nums[index]) {
                    _memo[curNum] = (index + i);
                    break;
                } 
                ++i;
            }
            // not found
            if (i == N) {
                _memo[curNum] = -1;
            }
            return _memo[curNum];
        } else {
            int prev = _memo[curNum];
            if (prev > index) {
                return prev;
            } else {
                int i = 1;
                while (i <= N-1) {
                    int innerIndex = (index+i) % nums.size();
                    if (nums[innerIndex] > nums[index]) {
                        _memo[curNum] = (index + i);
                        break;
                    }
                    ++i;
                }
                return _memo[curNum];
            }
        }

        return -1;
    }

    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result;
        for (size_t i = 0; i < nums.size(); ++i) {
            int index = getIndex(nums, i);
            if (index == -1) {
                result.emplace_back(-1);
            } else {
                result.emplace_back(nums[index % nums.size()]);
            }
        }

        return result;
    }
};


