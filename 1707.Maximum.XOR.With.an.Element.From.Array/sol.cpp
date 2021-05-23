struct Trie {
    // 左子树指向表示 0 的子节点
    Trie* left = nullptr;
    // 右子树指向表示 1 的子节点
    Trie* right = nullptr;

    int minNum;
    Trie() : minNum(1e9+10) {}
};

class Solution {
private:
    Trie* root = new Trie;    
    static constexpr int HIGH_BIT = 30;    
public:
    void add(int num) {
        Trie* cur = root;
        for (int k = HIGH_BIT; k >= 0; --k) {
            int bit = (num >> k) & 1;
            if (bit == 0) {
                if (!cur->left) {
                    cur->left = new Trie();
                }
                cur = cur->left;
                cur->minNum = min(cur->minNum, num);
            }
            else {
                if (!cur->right) {
                    cur->right = new Trie();
                }
                cur = cur->right;
                cur->minNum = min(cur->minNum, num);
            }
        }
    }

    int check(int num, int limit) {
        Trie* cur = root;
        int x = 0;
        for (int k = HIGH_BIT; k >= 0; --k) {
            int bit = (num >> k) & 1;
        
            
            if (bit == 0) {
                // a_i 的第 k 个二进制位为 0，应当往表示 1 的子节点 right 走
                if (cur->right && cur->right->minNum <= limit) {
                    cur = cur->right;
                    x = x * 2 + 1;
                }
                else {
                    if (cur->left && cur->left->minNum <= limit) {
                        cur = cur->left;
                        x = x * 2;
                    } else {
                        return -1;
                    }
                }
            }
            else {
                // a_i 的第 k 个二进制位为 1，应当往表示 0 的子节点 left 走
                if (cur->left && cur->left->minNum <= limit) {
                    cur = cur->left;
                    x = x * 2 + 1;
                }
                else {
                    if (cur->right && cur->right->minNum <= limit) {
                        cur = cur->right;
                        x = x * 2; 
                    } else {
                        return -1;
                    }
                }
            }
        }
        return x;
    }  
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> relt;
        
        for (int i = 0; i < nums.size(); ++i) {
            add(nums[i]);
        }
        
        for (int i = 0; i < queries.size(); ++i) {
            relt.push_back(check(queries[i][0], queries[i][1]));
        }
        
        return relt;
    }
};
