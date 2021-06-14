class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // 双指针
        int i = 0; int j = 0;
        int n = pushed.size();

        stack<int> sk;
        unordered_set<int> st;
        while (i < n && j < n) {
            while (i < n && pushed[i] != popped[j]) {
                sk.push(pushed[i]);
                st.insert(pushed[i]);
                ++i;
            }
            if (i == n) {
                return false;
            }
            ++j;
            while (j < n && st.count(popped[j])) {
                if (!sk.empty() && sk.top() == popped[j]) {
                    sk.pop();
                    ++j;
                } else {
                    return false;
                }
            }
            ++i;
        }

        return true;
    }
};
