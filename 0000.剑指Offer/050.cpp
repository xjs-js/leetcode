#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        char result = ' ';
        if (s.empty()) {
            return result;
        }

        int* count = new int[26];
        for (int i = 0; i < 26; ++i) {
            count[i] = 0;
        }
        int N = s.size();
        for (int i = 0; i < N; ++i) {
            char c = s[i];
            ++count[c-'a'];
        }

        for (int i = 0; i < N; ++i) {
            char c = s[i];
            if (count[c-'a'] == 1) {
               return c;
            }
        }
        delete[] count;
        return result;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;
    string str = "leetcode";
    std::cout << sol.firstUniqChar(str) << std::endl;
    return 0;
}