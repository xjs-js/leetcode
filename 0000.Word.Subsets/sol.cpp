#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isMatch(const string& str, const unordered_map<char, int> charCount) {
        unordered_map<char, int> innerCount;
        for (const char& c: str) {
            ++innerCount[c];
        }

        for (auto it = charCount.begin(); it != charCount.end(); ++it) {
            if (it->second > innerCount[it->first]) {
                return false;
            }
        }

        return true;
    }

    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        unordered_map<char, int> charCount;

        for (size_t i = 0; i < B.size(); ++i) {
            string& str = B[i];

            unordered_map<char, int> innerCount;
            for (const char& c: str) {
                ++innerCount[c];
            }

            for (auto it = innerCount.begin(); it != innerCount.end(); ++it) {
                charCount[it->first] = max(charCount[it->first], it->second);
            }
        }

        vector<string> result;
        for (size_t i = 0; i < A.size(); ++i) {
            if (isMatch(A[i], charCount)) {
                result.push_back(A[i]);
            }
        }

        return result;
    }
};


int main(int argc, char* argv[]) {
    std::vector<string> A {"amazon","apple","facebook","google","leetcode"};
    std::vector<string> B {"lo","eo"};

    Solution solution;
    std::vector<std::string> result = solution.wordSubsets(A, B);
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}