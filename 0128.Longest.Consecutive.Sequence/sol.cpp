class Solution {
public:
    // 返回以curNum开始的答案
    int dfs(unordered_set<int>& st, unordered_map<int, int>& count, int curNum) {
        int next = curNum + 1;
        // next访问过，直接计算答案。访问过可能
        if (count[next]) { 
            count[curNum] = 1 + count[next];
            return count[curNum];
        } else {
            // 没访问过，可能1.不在nums中，2.确实没访问过
            if (!st.count(next)) {
                count[curNum] = 1;
                return 1;
            } else {
                // 开始dfs
                int curRelt = 1;
                while (!count[next]) {
                    count[next] = 1;
                    ++curRelt;
                    ++next;
                    if (!st.count(next)) {
                        break;
                    }
                }
                if (st.count(next)) {
                    curRelt += count[next];
                }
                count[curNum] = curRelt;
                return count[curNum];
            }
        }
    }

    // 类似于dfs剪枝
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        // count[i] == 0, 表示i没有被访问过
        // count[i] >= 1, 表示i被访问过。如果i是端点，表示长度
        unordered_map<int, int> count;

        int relt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int curNum = nums[i];
            // 访问过，则跳过。跳过的是中间节点
            if (count[curNum]) {
                continue;
            }
            
            relt = max(relt, dfs(st, count, curNum));
        }
        return relt;
    }
};
