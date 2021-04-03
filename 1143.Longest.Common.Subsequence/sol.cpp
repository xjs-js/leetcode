/**
 * @date: 2021-04-03 22:23
 * @note: 不会，看了wikipedia的讲解
 */

#include "../headers.h"

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        int** lcs;
        lcs = new int*[n+1];
        for (int i = 0; i <= n; ++i) {
            lcs[i] = new int[m+1];
        }

        for (int i = 0; i <= m; ++i)
            lcs[0][i] = 0;

        for (int i = 0; i <= n; ++i)
            lcs[i][0] = 0;

        for (int i = 1; i <= n; ++i) {
            char left = text2[i-1];
            for (int j = 1; j <= m; ++j) {
                char right = text1[j-1];
                if (left == right) {
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                } else {
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
                }
            }
        }

        int result = lcs[n][m];
        for (int i = 0; i <= n; ++i) {
            delete[] lcs[i];
        }
        delete[] lcs;
        return result;
    }
};


int main(int argc, char* argv[])
{

    Solution sol;
    string str1("abc");
    string str2("def");
    cout << sol.longestCommonSubsequence(str1, str2) << endl;
    return 0;
}