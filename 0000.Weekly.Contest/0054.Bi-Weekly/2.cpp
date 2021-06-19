// https://leetcode-cn.com/problems/find-the-student-that-will-replace-the-chalk/

typedef long long LL;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        
        int n = chalk.size();
        LL sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += chalk[i];
        }
        
        int left = k % sum;
        do {
            for (int i = 0; i < n; ++i) {
                int need = chalk[i];
                
                if (need > left) {
                    return i;
                }
                
                left -= need;
            }
        } while (left > 0);
        
        return 0;
    }
};
