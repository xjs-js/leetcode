struct TrieNode {
    TrieNode* child[26];
    vector<int> weights;
    
    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }
    }
    
    TrieNode* insert(char c, int w) {
        if (child[c-'a'] == nullptr) {
            child[c-'a'] = new TrieNode;
        }
        child[c-'a']->weights.push_back(w);
        return child[c-'a'];
    }
    
    TrieNode* get(char c) {
        return child[c-'a'];
    }
    
    vector<int>& getWeights() {
        return weights;
    }
};



class Trie {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word, int w) {
        TrieNode* p = root;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            p = p->insert(c, w);
        }
    }
    
    vector<int> getWeights(string prefix) {
        TrieNode* p = root;

        for (int i = 0; i < prefix.size(); ++i) {
            char c = prefix[i];
            if (p->get(c) == nullptr) {
                return {};
            }
            p = p->get(c);
        }
        return p->getWeights();
    }
};


class WordFilter {
private:
    Trie* _prefixTree;
    Trie* _suffixTree;
public:
    WordFilter(vector<string>& words) {
        _prefixTree = new Trie;
        _suffixTree = new Trie;
        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            _prefixTree->insert(word, i);
            reverse(word.begin(), word.end());
            _suffixTree->insert(word, i);
        }
    }
    
    int f(string prefix, string suffix) {
        vector<int> preWeight = _prefixTree->getWeights(prefix);
        reverse(suffix.begin(), suffix.end());
        vector<int> suffixWeight = _suffixTree->getWeights(suffix);
        if (preWeight.empty() || suffixWeight.empty()) {
            return -1;
        }
        
        int i = preWeight.size() - 1;
        int j = suffixWeight.size() - 1;
        while (i >= 0 && j >= 0) {
            if (preWeight[i] == suffixWeight[j]) {
                return preWeight[i];
            } else if (preWeight[i] > suffixWeight[j]) {
                --i;
            } else {
                --j;
            }
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
