/**
 * @date: 2021-04-02 14:58
 * @note: 写完这题估计就不写了
 */


class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count;
        unordered_map<int, int> len;
        unordered_map<int, int> first;

        int result = nums.size();
        int max_count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            ++count[num];
            max_count = max(max_count, count[num]);
            
            if (first.find(num) == first.end()) {
                first[num] = i;
                len[num] = 1;
            } else {
                len[num] = i - first[num] + 1;
            }
        }


        auto it = count.begin();
        int min_len = nums.size();
        while (it != count.end()) {
            if (it->second == max_count) {
                min_len = min(min_len, len[it->first]);
            }
            ++it;
        }

        return min_len;
    }
};
