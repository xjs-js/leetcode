#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        std::vector<string> tokens;

        // split preorder string        
        std::string delim = ",";
        size_t start = 0;
        size_t end = preorder.find(delim);
        int numOfNull = 0;      // num of "#"
        while (end != std::string::npos) {
            std::string token = preorder.substr(start, end-start);
            tokens.push_back(token);
            if (token == "#")
                ++ numOfNull;

            start = end + delim.length();
            end = preorder.find(delim, start);
        }

        std::string lastToken = preorder.substr(start,  end-start);
        tokens.push_back(lastToken);
        if (lastToken == "#")
            ++numOfNull;

        int numOfNode = tokens.size() - numOfNull;

        if (numOfNode + 1 != numOfNull)
            return false;

        stack<string> tree;

        int i = 0;
        while (i != tokens.size()) {
            std::string curToken = tokens.at(i);

            if (curToken == "#") {
                if (tree.empty()) {
                    tree.push("#");
                    ++i;
                    continue;
                }

                std::string firstTokenInTree = tree.top();
                if (firstTokenInTree == "#") {
                    tree.pop();

                    if (tree.empty())
                        return false;

                    std::string secondTokenInTree = tree.top();
                    if (secondTokenInTree == "#") {
                        return false;
                    }
                    else {
                        tree.pop();
                        insert(tree);
                    }

                }
                else {  // firstTokenInTree is a num
                    tree.push(curToken);
                }
            }
            else { // curToken is a num
                tree.push(curToken);
            }

            ++i;
        }



        return tree.size() == 1 && tree.top() == "#";
    }

    bool insert(std::stack<std::string>& tree) {
        if (tree.empty()) {
            tree.push("#");
            return true;
        }

        std::string firstElement = tree.top();
        if (firstElement == "#") {
            if (tree.size() >= 2) {
                tree.pop();
                std::string secondElement = tree.top();
                if (secondElement != "#") {
                    tree.pop();
                    return insert(tree);
                }
            }
            else {
                return false;
            }
        }
        else {
            tree.push("#");
            return true;
        }

        return false;
    }
};


int main(int argc, char* argv[])
{
    Solution sol;

//    std::cout << sol.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << std::endl;
//    std::cout << sol.isValidSerialization("1,#")  << std::endl;
    std::cout << sol.isValidSerialization("#")  << std::endl;
//    std::cout << sol.isValidSerialization("9,2,#,#,#,#,3") << std::endl;
    return 0;
}