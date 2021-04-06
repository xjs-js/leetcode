/**
 * @date: 2021-04-06 18:57
 * @note: 写完就去吃饭
 */
#include "../headers.h"
class Solution {
public:
    /** 直接暴力就完事儿了 */
    bool rotateString(string A, string B) {
        if (A.size() != B.size()) {
            return false;
        }

        if (A == B) {
            return true;
        }

        int N = A.size();
        int i = 0;
        while (i < N-1) {
            string subStr = A.substr(1);
            string rotate = subStr + A[0];
            if (rotate == B) {
                return true;
            }
            A = rotate;
            ++i;
        }

        return false;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;
    string A("abcde");
    string B("cdeab");
    cout << std::boolalpha << sol.rotateString(A, B) << endl;
    return 0;
}
