#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        std::queue<string> tokens;

        // split preorder string        
        string delim = ",";
        size_t start = 0;
        size_t end = preorder.find(delim);
        int numOfNull = 0;      // num of "#"
        while (end != std::string::npos) {
            string token = preorder.substr(start, end-start);
            tokens.push(token);
            if (token == "#")
                ++ numOfNull;

            start = end + delim.length();
            end = preorder.find(delim, start);
        }

        string lastToken = preorder.substr(start,  end-start);
        tokens.push(lastToken);
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

        return tokens.size() == 1 && tokens.front() == "#";
    }

    bool filter(queue<string>& tokens)
    {
        queue<string> after;
        bool isFind = false;
        while (!tokens.empty()) {
            string front = tokens.front();
            tokens.pop();
            if (front == "#")
                after.push(front);
            else {  // front is a number 
                if (tokens.size() >= 2) {
                    string next_first = tokens.front();
                    if (next_first == "#") {
                        tokens.pop();
                        string next_second = tokens.front();
                        if (next_second == "#") {
                            tokens.pop();
                            after.push("#");
                            isFind = true;
                        } else {
                            after.push(front);
                            after.push("#");
                        }
                    }
                    else {
                        after.push(front);
                    }
                }
                else {
                    after.push(front);
                }
            }
        }
        tokens = after;
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