#define ll long long int

class Solution {
public:
    int _count;
    
    // 判断数字是否是回文字符串
    // 双指针法
    bool isPalindromes(ll i) {
        string s = to_string(i);

        int beg = 0;
        int end = s.size() - 1;
        while (beg < end) {
            if (s[beg] != s[end]) {
                return false;
            }
            --end;
            ++beg;
        }

        return true;
    }

    // 构造长度为len的回文数字
    void construct(int len, ll l, ll r) {
        if (len == 1) {
            for (int i = 0; i <= 9; ++i) {
                if (i*i >= l && i*i <= r && isPalindromes(i * i)) {
                    ++_count;
                }
            }
            return ;
        } else {
                // 左半边长度
                int half = len / 2;
                // 左半边最小值
                ll left = 1 * pow(10, half - 1);
                // 左半边最大值
                ll top = 1 * pow(10, half) - 1;
                do {
                    string left_str = to_string(left);
                    string right_str = left_str;
                    reverse(right_str.begin(), right_str.end());
                    
                    string str;
                        
                    if (len % 2 == 1) {
                        for (int i = 0; i <= 9; ++i) {
                            str = left_str + to_string(i) + right_str;
                            ll num = atoll(str.c_str());
                            if (num * num >= l && num * num <= r && isPalindromes(num*num)) {
                                ++_count;
                            } else if (num * num > r) {
                                return ;
                            }
                        }
                    } else {
                        str = left_str + right_str;
                        ll num = atoll(str.c_str());
                        if (num * num >= l && num * num <= r && isPalindromes(num*num)) {
                            ++_count;
                        } else if (num * num > r) {
                            return ;
                        }
                    }
                        
                    ++left;
                } while (left <= top);
            }
    }

    int superpalindromesInRange(string left, string right) {
        _count = 0;
        
        ll l = atoll(left.c_str());
        ll r = atoll(right.c_str());

        // 构造n位数的回文数字
        int len_beg = max((int)left.size() / 2, 1);
        int len_end = max((int)right.size() / 2, 1) + 1;

        int i = len_beg;
        while (i <= len_end) {
            construct(i, l, r);
            ++i;
        }

        return _count;
    }
};
