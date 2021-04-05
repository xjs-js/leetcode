/**
 * @date: 2021-04-05 15:52
 * @note: 老经典题目了
 */

#include "../headers.h"

class Solution {
private:
    // beg 表示第一个可以压栈的下标
    bool PushStack(stack<int>& sk, vector<int>& pushed, int& beg, int target) {
        if (beg == pushed.size()) {
            return false;
        }

        while (beg < pushed.size() && pushed[beg] != target) {
            sk.push(pushed[beg]);
            ++beg;
        }

        if (beg == pushed.size()) {
            return false;
        }

        ++beg;
        return true;
    }

public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> sk;
        int beg = 0;
        for (int i = 0; i < popped.size(); ++i) {
            int curPop = popped[i];

            if (sk.empty()) {
                // 压栈，直到找到curPop                
                if (!PushStack(sk, pushed, beg, curPop)) {
                    return false;
                }
            } else {
                int top = sk.top(); // 栈顶元素
                if (top == curPop) {
                    sk.pop();
                }
                else {
                    // 压栈，直到找到curPop
                    if (!PushStack(sk, pushed, beg, curPop)) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;
    vector<int> left{1,2,3,4,5};
    vector<int> right{4,3,5,1,2};
    cout << std::boolalpha << sol.validateStackSequences(left, right) << endl;
    return 0;
}