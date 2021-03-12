#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        std::vector<string> tokens;

        // split preorder string        
        string delim = ",";
        size_t start = 0;
        size_t end = preorder.find(delim);
        int numOfNull = 0;      // num of "#"
        while (end != std::string::npos) {
            string token = preorder.substr(start, end-start);
            tokens.push_back(token);
            if (token == "#")
                ++ numOfNull;

            start = end + delim.length();
            end = preorder.find(delim, start);
        }

        string lastToken = preorder.substr(start,  end-start);
        tokens.push_back(lastToken);
        if (lastToken == "#")
            ++numOfNull;

        int numOfNode = tokens.size() - numOfNull;
        // 第一次check： 非空节点的数量 + 1 = 空节点的数量
        if (numOfNode + 1 != numOfNull)
            return false;
        
        bool isFind = true;
        while (isFind) {
            isFind = filter(tokens);
        }

        return tokens.size() == 1 && tokens.at(0) == "#";
    }

    bool filter(vector<string>& tokens)
    {
        bool isFind = false;

        int i = 0;
        while (i != tokens.size()) {
            string curToken = tokens.at(i);
            if (curToken == "#") {
                ++i;
                continue;
            } else {  // curToken is a number
                if (i + 1 < tokens.size() && i + 2 < tokens.size()) {
                    string next_first = tokens.at(i + 1);
                    string next_second = tokens.at(i + 2);
                    if (next_first == "#" && next_second == "#") {
                        isFind = true;
                        tokens.erase(tokens.begin() + i, tokens.begin() + i + 2);
                        ++i;
                    }
                    else {
                        ++i;
                    }
                }
                else {
                    ++i;
                }
            }
        }

        return isFind;
    }

};


int main(int argc, char* argv[])
{
    Solution sol;

    // std::cout << sol.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << std::endl;
    // std::cout << sol.isValidSerialization("1,#")  << std::endl;
    // std::cout << sol.isValidSerialization("#")  << std::endl;
    std::cout << sol.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << std::endl;
    return 0;
}