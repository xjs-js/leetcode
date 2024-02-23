class Solution {
private:
    unordered_map<int, vector<int>> _index;
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int val = nums[i];
            _index[val].push_back(i);
        }
    }
    
    int pick(int target) {
        vector<int>& avaIndexs = _index[target];

        std::mt19937 rng(std::random_device{}());

        // Create a distribution in the range of the vector indices
        std::uniform_int_distribution<std::mt19937::result_type> dist(0, avaIndexs.size() - 1);

        // Generate a random index and use it to pick an element from the vector
        int randomElement = avaIndexs[dist(rng)];

        return randomElement;
    }
};
