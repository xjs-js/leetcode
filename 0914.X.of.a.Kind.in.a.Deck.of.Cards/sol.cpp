class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> count;
        for (int i : deck) {
            ++count[i];
        }

        vector<int> nums;
        auto it = count.begin();
        while (it != count.end()) {
            nums.push_back(it->second);
            ++it;
        }
        sort(nums.begin(), nums.end());

        if (nums[0] < 2) {
            return false;
        }

        for (int k = 2; k <= nums[0]; ++k) {
            bool isAll = true;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] % k != 0) {
                    isAll = false;
                    break;
                }
            }
            if (isAll) return true;
        }


        return false;
    }
};
