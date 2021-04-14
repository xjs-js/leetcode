/**
 * @date: 2021-04-13 16:13 Wen
 */


class Solution {
public:
    vector<string> _result;

    void isLegal(string str, int pos, bool& legal, string& after) {
        string left = str.substr(0, pos);
        string right = str.substr(pos);

        if (atoi(right.c_str()) == 0) {
            legal = false;
            return;
        }

        if (left.size() > 1 && left[0] == '0') {
            legal = false;
            return;
        }

        if (right[right.size() - 1] == '0') {
            legal = false;
            return;
        }



        after = left;
        after += ".";
        after += right;

        legal = true;

    }

    void split(string S, int leftLen, int rightLen) {
        string leftStr = S.substr(0, leftLen);
        string rightStr = S.substr(leftLen, rightLen);
        // cout << leftStr << "," << rightStr << endl;

        if (leftStr.length() > 1 && atoi(leftStr.c_str()) == 0) {
            return;
        }

        if (rightStr.length() > 1 && atoi(rightStr.c_str()) == 0) {
            return ;
        }

        for (int j = 1; j <= leftStr.size(); ++j) {
            string pointLeft;
            if (j == leftStr.size()) {
                pointLeft = leftStr;

                if (pointLeft.size() > 1 && pointLeft[0] == '0') {
                    continue;
                }

            } else {
                bool legal = false;
                isLegal(leftStr, j, legal, pointLeft);
                if (!legal) {
                    continue;
                }
            }
            // cout << pointLeft << endl;

            for (int k = 1; k <= rightStr.size(); ++k) {
                string pointRight;
                if (k == rightStr.size()) {
                    pointRight = rightStr;

                    if (pointRight.size() > 1 && pointRight[0] == '0') {
                        continue;
                    }

                } else {
                    bool legal = false;
                    isLegal(rightStr, k, legal, pointRight);
                    if (!legal) {
                        continue;
                    }
                }

                string result = "(";
                result += pointLeft;
                result += ", ";
                result += pointRight;
                result += ")";
                _result.emplace_back(result);
            }

        }
    }

    vector<string> ambiguousCoordinates(string S) {
        int N = S.size() - 2;

        for (int i = 1; i <= N-1; ++i) {
            int leftLen = i;
            int rightLen = N - leftLen;
            split(S.substr(1, N), leftLen, rightLen);
        }

        return _result;
    }
};