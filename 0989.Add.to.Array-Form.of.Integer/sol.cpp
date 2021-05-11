class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int c = 0;
        int i = num.size()-1;
        while (i >= 0 || k > 0) {
            if (c == 0 && k == 0) {
                break;
            }
            
            if (i >= 0) {
                int digit = k % 10;
                num[i] += (digit + c);
                if (num[i] >= 10) {
                    c = 1;
                    num[i] = num[i] % 10;
                } else {
                    c = 0;
                }
                k /= 10;
                --i;
            } else {
                c += k;
                break;
            }
        }
        
        while (c) {
            num.insert(num.begin(), c % 10);
            c /= 10;
        }
        
        return num;
    }
};
