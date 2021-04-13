/**
 * @date: 2021-04-14 00:35 Wen
 */

struct TrieNode {
    int count;
    TrieNode* child[26];
    
    TrieNode() {
        count = 0;
        for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }
    }
    
    TrieNode* insert(char c) {
        if (child[c-'a'] == nullptr) {
            child[c-'a'] = new TrieNode;
            ++count;
        }
        return child[c-'a'];
    }
    
    TrieNode* get(char c) {
        return child[c-'a'];
    }
    
};

class Trie {
public:
    TrieNode* root;
    unordered_set<string> dict;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            p = p->insert(c);
        }
        dict.insert(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return dict.count(word);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (int i = 0; i < prefix.size(); ++i) {
            char c = prefix[i];
            if (p->get(c) == nullptr) {
                return false;
            }
            p = p->get(c);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */