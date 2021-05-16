class Solution {
public:
    // 是否是整数（带符号）
    bool isInteger(string s) {
        if (s.size() == 0) {
            return true;
        }
        
        if (s[0] == '+' || s[0] == '-') {
            s = s.substr(1);
        }
        
        int n = s.size();
        
        if (n == 0) {
            return false;
        }
        
        for (int i = 0; i < n; ++i) {
            if (s[i] < '0' || s[i] > '9') {
                return false;
            }
        }
        
        return true;
    }
    
    // 是否是整数不带符号
    bool isInteger2(string s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] < '0' || s[i] > '9') {
                return false;
            }
        }
        
        return true;
    }
    
    
    
    
    // 是否是小数字
    bool isFloat(string s) {
        if (s[0] == '+' || s[0] == '-') {
            s = s.substr(1);
        }
        size_t pointPos = s.find(".");
        if (pointPos == string::npos) {
            return false;
        } else {
            string firstPart = s.substr(0, pointPos);
            string secondPart = s.substr(pointPos+1);
            if (firstPart.size() == 0 && secondPart.size() == 0) {
                return false;
            } else {
                return isInteger2(firstPart) && isInteger2(secondPart);
            }
        }
        
        return false;
    }
    
    bool isNumber(string s) {
        // e 的 位置
        size_t posE = s.find("e");
        if (posE == string::npos) {
            posE = s.find("E");
        }
        
        
        if (posE == string::npos) { // 没有e
            // 要么是整数要么是小数
            return isInteger(s) || isFloat(s);
        } else {
            string firstPart = s.substr(0, posE);
            string secondPart = s.substr(posE + 1);
            if (firstPart.size() > 0 && secondPart.size() > 0) {
                return (isInteger(firstPart) || isFloat(firstPart)) && isInteger(secondPart);
            } else {
                return false;
            }
            
            
        }
        
        return false;
    }
};
