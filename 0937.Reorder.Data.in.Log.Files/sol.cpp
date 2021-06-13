class Solution {
public:
    bool isDigit(const string& str) {
        int n = str.size();
        if (str[n-1] >= '0' && str[n-1] <= '9') {
            return true;
        }
        return false;
    }

    vector<string> reorderLogFiles(vector<string>& logs) {
        int n = logs.size();

        vector<string> letters;   // letter logs
        vector<string> digits;  // digit logs
        for (int i = 0; i < n; ++i) {
            string& str = logs[i];

            if (isDigit(str)) {
                digits.push_back(str);
            } else {
                letters.push_back(str);
            }
        }

        sort(letters.begin(), letters.end(), [](const string& lhs, const string& rhs){
            size_t i = lhs.find(" ");
            string newL = lhs.substr(i);

            i = rhs.find(" ");
            string newR = rhs.substr(i);

            if (newL == newR) {
                return lhs < rhs;
            } else {
                return newL < newR;
            }
        });

        for (int i = 0; i < digits.size(); ++i)
            letters.push_back(digits[i]);

        return letters;
    }
};
