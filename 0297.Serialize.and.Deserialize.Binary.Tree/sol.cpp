/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> nodeVals;
        
        queue<TreeNode*> que;
        que.push(root);
        do {
            queue<TreeNode*> innerQue;
            vector<string> innerVal;
            bool hasChild = false;
            while (!que.empty()) {
                TreeNode* front = que.front();
                que.pop();
                if (front) {
                    nodeVals.push_back(to_string(front->val));
                    innerQue.push(front->left);
                    innerQue.push(front->right);
                    if (front->left || front->right) {
                        hasChild = true;
                    }
                } else {
                    nodeVals.push_back("$");
                }
            }
            
            if (hasChild) {
                que = innerQue;
            } else {
                break;
            }
        } while (!que.empty());
        
        string result;
        for (int i = 0; i < nodeVals.size(); ++i) {
            result += nodeVals[i];
            if (i != nodeVals.size() - 1) {
                result += ",";
            }
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty() || data == "$") {
            return nullptr;
        }
        
        // 分割字符串
        int beg = 0;
        string delim = ",";
        size_t end = data.find(delim, beg);
        vector<string> nodeVals;
        while (end != string::npos) {
            string token = data.substr(beg, end-beg);
            nodeVals.push_back(token);
            beg = end + delim.size();
            end = data.find(delim, beg);
        }
        string token = data.substr(beg);
        nodeVals.push_back(token);
        
        int rootVal = atoi(nodeVals[0].c_str());
        TreeNode* root = new TreeNode(rootVal);
        
        // 构建树
        int i = 1;
        vector<TreeNode*> lastLevel;    // 上一层的非空节点
        lastLevel.push_back(root);
        while (i < nodeVals.size()) {
            vector<TreeNode*> curLevel; // 这一层的非空节点
            for (int j = 0; j < lastLevel.size(); ++j) {
                TreeNode* leftTree = nullptr;
                string leftVal = nodeVals[i++];
                if (leftVal != "$") {
                    leftTree = new TreeNode(atoi(leftVal.c_str()));
                    curLevel.push_back(leftTree);
                }
                lastLevel[j]->left = leftTree;

                TreeNode* rightTree = nullptr;
                string rightVal = nodeVals[i++];
                if (rightVal != "$") {
                    rightTree = new TreeNode(atoi(rightVal.c_str()));
                    curLevel.push_back(rightTree);
                }
                lastLevel[j]->right = rightTree;
            }
            lastLevel = curLevel;
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));