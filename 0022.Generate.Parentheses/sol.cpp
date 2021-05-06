class Solution {
private:
    vector<string> _relt;
    
public:
    /**
     * s: 当前构成的字符串
     * leftCount: s中左括号的个数
     * left: 剩余可用的左括号个数
     * right: 剩余可用的右括号个数
     */
    void make(string s, int leftCount, int left, int right) {
        if (left == 0  && right == 0) {
            _relt.emplace_back(s);
            return;
        }
        
        if (left > 0) {
            make(s + "(", leftCount + 1, left-1, right);
        }
        
        if (right > 0 && leftCount > 0) {
            make(s + ")", leftCount - 1, left, right - 1);
        }
        
    }
    
    
    vector<string> generateParenthesis(int n) {
        make("", 0, n, n);
        
        return _relt;
    }
};
