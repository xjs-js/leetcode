/*
 * date : 2018/05/07
 */


static vector<string> _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return vector<string>{};
}();


class Solution {
public:
    string addBinary(string a, string b) {
        string short_str = a.size() < b.size() ? a : b;
        string long_str = a.size() >= b.size() ? a : b;
        while(short_str.length() < long_str.size())
            short_str = "0" + short_str;
    
        int carry = 0;
        string relt = "";
        for (int i = long_str.size() - 1; i >= 0; i--) {
            carry = (short_str[i]-'0') + (long_str[i]-'0') + carry;
            relt = to_string(carry % 2) + relt;
            carry /= 2;
        }
        
        relt = (carry==0) ? relt : (to_string(carry) + relt);
        
        return relt;
    }
};
