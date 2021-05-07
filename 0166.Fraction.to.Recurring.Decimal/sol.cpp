class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) { return "0"; }
        
        // 最后结果是否是负数
        bool isNeg = (numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0);
        
        uint64_t a = abs(numerator);
        uint64_t b = abs(denominator);
        
        string relt("");
        // 整数部分
        relt += to_string(a / b);
        
        // 小数部分
        uint64_t x = a % b;
        // 余数
        vector<int> remain;
        unordered_map<int, int> dict; // Key: 循环结，Value: 对应remain中的下标
        
        // x == 0，表示能够整除，没有循环结
        // x 在 dict中，表示该循环结已经计算过，无需再进入循环
        while (x != 0 && (dict.find(x) == dict.end())) {
            dict[x] = remain.size();
            
            x = x * 10;
            remain.push_back(x / b);
            x = x % b;
        }
        
        // 拼接余数部分
        int splitIdx = x == 0 ? -1 : dict[x];
        for (int i = 0; i < remain.size(); ++i) {
            if (i == 0) {
                relt += ".";
            }
            
            if (i == splitIdx) {
                relt += "(";
            }
            relt += to_string(remain[i]);
        }
        if (splitIdx != -1) relt += ")";
        
        // 负数在前面加上负号
        if (isNeg) {
            relt = "-" + relt;
        }
        return relt;
    }
};
