class Solution {
public:
    string convertToTitle(int columnNumber) {
        string relt;
        while (columnNumber) {
            int c = columnNumber  % 26;
            if (c == 0) {
                relt += 'Z';
            } else {
                relt += c - 1 + 'A';
            }
            if (columnNumber >= 0 && columnNumber <= 26) {
                break;
            } else {
                columnNumber -= (relt[relt.size()-1] - 'A');
                columnNumber /= 26;
            }
        }
        reverse(relt.begin(), relt.end());
        return relt;
    }
};
