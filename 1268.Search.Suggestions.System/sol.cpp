struct TrieNode {
    TrieNode* child[26];
    set<string> arr;
    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }        
    }
};

class TrieTree {
private:
    TrieNode* _root;
public:
    TrieTree(): _root(new TrieNode) {
        
    }

    void Add(const string& str) {
        TrieNode* cur = _root;
        for (int i = 0; i < str.size(); ++i) {
            if (!cur->child[str[i] - 'a']) {
                cur->child[str[i] - 'a'] = new TrieNode;
            }
            cur = cur->child[str[i] - 'a'];
            cur->arr.insert(str);
        }
    }
    
    vector<string> Search(const string& str) {
        TrieNode* cur = _root;
        for (int i = 0; i < str.size(); ++i) {
            if (cur->child[str[i] - 'a']) {
                cur = cur->child[str[i] - 'a'];
            } else {
                return {};
            }
        }
        
        set<string> arr = cur->arr;
        if (cur->arr.size() > 3) {
            auto end = arr.begin();
            ++end;
            ++end;
            ++end;
            vector<string> varr(arr.begin(), end);
            return varr;
        } else {
            vector<string> varr(arr.begin(), arr.end());
            return varr;
        }
    }
};



class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieTree tree;
        for (auto &s : products) {
            tree.Add(s);
        }
        
        vector<vector<string>> relt;
        for (int i = 1; i <= searchWord.size(); ++i) {
            vector<string> curRelt = tree.Search(searchWord.substr(0, i));
            relt.push_back(curRelt);
        }
        
        return relt;
    }
};
