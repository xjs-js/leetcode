typedef long long int LL;

class Solution {
public:
    int nextLarger(vector<int>& nums, int& beg) {
        int i = beg;
        while (i < nums.size()) {
            if (i + 1 < nums.size()) {
                if (nums[i] > nums[i+1]) {
                    beg = i;
                    return nums[i];
                }
            } else {
                beg = i;
                return nums[i];
            }
            ++i;
        }
        beg = i;
        return -1;
    }
    
    int nextLess(vector<int>& nums, int& beg) {
        int i = beg;
        while (i < nums.size()) {
            if (i + 1 < nums.size()) {
                if (nums[i] < nums[i+1]) {
                    beg = i;
                    return nums[i];
                }
            } else {
                beg = i;
                return nums[i];
            }
            ++i;
        }
        beg = i;
        return -1;
    }
    
    
    long long maxAlternatingSum(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        int beg = 0;
        LL relt = 0;
        LL acc = 0;
        
        int next = nextLarger(nums, beg);
        acc += next;
        relt = max(relt, acc);
        
        
        while (beg < nums.size()) {
            int tmp = beg;
            tmp++;
            int n_less = nextLess(nums, tmp);
            tmp++;
            int n_larger = nextLarger(nums, tmp);
            if (n_less != -1 && n_larger != -1) {
                acc += (LL)(n_larger - n_less);
                relt = max(relt, acc);
                beg = tmp;
            } else {
                break;
            }
        }
        
        return relt;
    }
};