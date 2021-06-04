class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st;
        unordered_set<string> deadlocks(deadends.begin(), deadends.end());
        queue<string> que;
        que.push("0000");

        int steps = 0;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                string str = que.front();
                que.pop();
                if (st.count(str)) {
                    continue;
                }
                st.insert(str);
//                cout << str << endl;


                if (str == target) {
                    return steps;
                } else if (deadlocks.count(str)) {
                    continue;
                } else {
                    for (int i = 0; i < str.size(); ++i) {
                        if (str[i] == '0') {
                            str[i] = '1';
                            if (!st.count(str)) que.push(str);
                            str[i] = '9';
                            if (!st.count(str)) que.push(str);
                            str[i] = '0';
                        } else if (str[i] == '9') {
                            str[i] = '8';
                            if (!st.count(str)) que.push(str);
                            str[i] = '0';
                            if (!st.count(str)) que.push(str);
                            str[i] = '9';
                        } else {
                            str[i] = str[i] + 1;
                            if (!st.count(str)) que.push(str);
                            str[i] -= 2;
                            if (!st.count(str)) que.push(str);
                            str[i] += 1;
                        }
                    }
                }
            }
            ++steps;
        }

        return -1;
    }
};
