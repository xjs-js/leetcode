int MOD = (1e9 + 7);

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int64_t relt = 0;
        int n = arr.size();
        
        stack<int> sk;
        // 左边大与等于的数
        vector<int> leftRelt(n, 0);
        for (int i = 0; i < arr.size(); ++i) {
            int curRelt = 0;
            while (!sk.empty() && arr[sk.top()] >= arr[i]) {
                curRelt += (1 + leftRelt[sk.top()]);
                sk.pop();
            }
            leftRelt[i] = curRelt;
            sk.push(i);
        }

        while (!sk.empty()) {
            sk.pop();
        }

        // 右边大于的数
        vector<int> rightRelt(n, 0);
        for (int i = n-1; i >= 0; --i) {
            int curRelt = 0;
            while (!sk.empty() && arr[sk.top()] > arr[i]) {
                curRelt += (1 + rightRelt[sk.top()]);
                sk.pop();
            }
            rightRelt[i] = curRelt;
            sk.push(i);
        }


        for (int i = 0; i < n; ++i) {
            int leftLen = leftRelt[i];
            int rightLen = rightRelt[i];

            relt = (relt % MOD + arr[i] % MOD) % MOD;
            relt = (relt % MOD + arr[i] * leftLen % MOD) % MOD;
            relt = (relt % MOD + arr[i] * rightLen % MOD) % MOD;
            relt = (relt % MOD + (int64_t)arr[i] * leftLen  * rightLen % MOD) % MOD;
        }
        return relt;
    }
};
