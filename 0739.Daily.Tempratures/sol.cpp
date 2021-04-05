/**
 * @date: 2021-04-05 10:24
 * @note: 清明节最后一天
 */

class Solution {
public:
    /**
     * 这应该用单调栈，从后向前遍历
     * 从栈底到栈顶单调递减
     */
    vector<int> dailyTemperatures(vector<int>& T) {
        int N = T.size();
        vector<int> result(N);

        stack<int> sk;  // 存放下标

        for (int i = N-1; i >= 0; --i) {
            int curT = T[i];
            if (sk.empty()) {
                sk.push(i);
                result[i] = 0;
            } else {
                int index = sk.top();
                int topT = T[index];
                if (curT < topT) {
                    sk.push(i);
                    result[i] = index - i;
                } else {
                    while (!sk.empty() && curT >= topT) {
                        sk.pop();
                        if (!sk.empty()) {
                            index = sk.top();
                            topT = T[index];
                        }
                    }
                    
                    if (sk.empty()) {
                        sk.push(i);
                        result[i] = 0;
                    } else {
                        sk.push(i);
                        result[i] = index - i;
                    }
                }
            }
        }

        return result;

    }
};
