/**
 * @date: 2021-04-05 21:54
 * @note: 写完就去洗澡
 * @note: 洗完澡接着写
 */

#include "../headers.h"

class Solution {
private:
    // 根据二进制的bit位，将S变换，插入到结果中
    void InsertResult(vector<string>& result, string S, vector<int>& indexArr, bitset<12> bin) {
        int n = indexArr.size();

        for (int i = 0; i < n; ++i) {
            if (bin[i]) {
                int index = indexArr[i];
                char old = S[index];
                // 大写 <=> 小写 相互转换
                if (islower(old)) {
                    S[index] = toupper(old);
                } else {
                    S[index] = tolower(old);
                }
            }
        }

        result.emplace_back(S);
    }

public:
    vector<string> letterCasePermutation(string S) {
        // 找出所有字母的下标
        vector<int> indexArr;  
        for (size_t i = 0; i < S.size(); ++i) {
            const char& c = S[i];
            if (isalpha(c)) {
                indexArr.emplace_back(i);
            }
        }


        int n = indexArr.size();
        // 没有字母直接返回原字符串
        vector<string> result;
        if (n == 0) {
            result.emplace_back(S);
            return result;
        }

        // 找排列，根据二进制的值来映射
        uint64_t N = pow(2, n) - 1;
        for (int i = 0; i <= N; ++i) {
            bitset<12> bin(i);
            InsertResult(result, S, indexArr, bin);
        }

        return result;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;
    string str("a1b2");
    auto StrArr = sol.letterCasePermutation(str);

    PrintArray(StrArr);
    return 0;
}
