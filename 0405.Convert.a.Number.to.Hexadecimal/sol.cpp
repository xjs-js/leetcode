class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }

        bool isNeg = num < 0 ? true : false;
        num = abs(num);

        // 先转换成二进制
        string binStr = "";
        while (num) {
            if (num % 2 == 0) {
                binStr = "0" + binStr;
            } else {
                binStr = "1" + binStr;
            }
            num /= 2;
        }

        int len = binStr.size();
        int left = 32 - len;
        binStr = string(left, '0') + binStr;

        vector<char> arr(binStr.begin(), binStr.end());
        // 取反加一
        if (isNeg) {
            reverse(arr.begin(), arr.end());
            for (int i = 0; i < arr.size(); ++i) {
                arr[i] = (arr[i] == '0') ? '1' : '0';
            }

            if (arr[0] - '0' + 1 == 2) {
                arr[0] = '0';
                int c = 1;
                int i = 1;
                while (c) {
                    int num = (arr[i]-'0') + c;
                    arr[i] = num % 2 + '0';
                    c = num / 2;
                    ++i;
                }
            } else {
                arr[0] = '1';
            }
            reverse(arr.begin(), arr.end());
        }

        string relt;
        vector<char> dict{'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        for (int i = 0; i + 3 <= 31; i+=4) {
            int num_1 = arr[i] - '0';
            int num_2 = arr[i+1] - '0';
            int num_3 = arr[i+2] - '0';
            int num_4 = arr[i+3] - '0';

            int decimal = num_1 * 8 + num_2 * 4 + num_3 * 2 + num_4;
            relt += dict[decimal];
        }
        int i = 0;
        while (i + 1 < relt.size() && relt[i] == '0') {
            ++i;
        }
        return relt.substr(i);
    }
};

