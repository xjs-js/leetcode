class Solution {
public:
    void split(vector<int>& first, vector<int>& second, vector<string>& strNums, vector<int>& nums, int j) {
        do {
            first.clear();
            second.clear();
            for (int i = 0; i < strNums.size(); ++i) {
                string& str = strNums[i];
                if (str[j] == '1') {
                    first.push_back(nums[i]);
                } else {
                    second.push_back(nums[i]);
                }
            }
            ++j;
        } while (second.size() == 0 && j < 32);
    }
    
    
    int findMaximumXOR(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        
        
        int relt = 0;
        int index = 31;
        vector<string> strNums;
        for (int i = 0; i < nums.size(); ++i) {
            string str = bitset<32>(nums[i]).to_string();
            strNums.push_back(str);
            int j = 0;
            for (; j < str.size(); ++j) {
                if (str[j] == '1') {
                    break;
                }
            }
            index = min(index, j);
        }
        
        vector<int> first;
        vector<int> second;
        
        split(first, second, strNums, nums, index);
        
        for (int f : first) {
            for (int s : second) {
                relt = max(relt, f ^ s);
            }
        }
        

        
        return relt;
    }
};
