class Solution {
public:
    int scoreOfParentheses(string S) {
        int total = 0;
        
        int n = S.size();
        vector<int> score(n, 0);
        stack<int> sk;
        for (int i = 0; i < S.size(); ++i) {
            char c = S[i];
            
            if (c == '(') {
                sk.push(i);
                score[i] = total;
            } else {
                int index = sk.top();
                sk.pop();
                
                int delta = total - score[index];
                if (delta == 0) {
                    total += 1;
                } else {
                    total += delta;
                }
            }
        }
        
        return total;
    }
};
