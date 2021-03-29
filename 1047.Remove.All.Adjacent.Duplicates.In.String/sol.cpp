#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> sk;

        for (size_t i = 0; i < S.size(); ++i) {
            char c = S[i];
            if (sk.empty()) {
                sk.push(c);
            } else {
                char top = sk.top();
                if (top == c) {
                    sk.pop();
                } else {
                    sk.push(c);
                }
            }
        }

        string result;
        while (!sk.empty()) {
            char top = sk.top();
            result += top;
            sk.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};


int main(int argc, char* argv[]) {
    Solution sol;
    cout << sol.removeDuplicates("abbaca") << endl;
    return 0;
}