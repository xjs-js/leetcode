/**
 * @date: 2021-04-14 15:10 Wen
 * @url: https://www.acwing.com/problem/content/144/
 * @name: 前缀统计
 */


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <chrono>

using namespace std;

struct TrieNode {
    TrieNode* child[26];
    int count;
    int end;
    TrieNode() {
        end = 0;
        count = 0;
        for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }
    }

    TrieNode* insert(char c) {
        if (!child[c-'a']) {
            child[c-'a'] = new TrieNode;
            ++count;
        }
        return child[c-'a'];
    }

    TrieNode* get(char c) {
        return child[c-'a'];
    }
};

class Solution {
public:
    TrieNode* root;
    Solution() {
        root = new TrieNode;
    }

    /** 向前缀树中插入一个单词 */
    void insert(string str) {
        TrieNode* p = root;
        for (int i = 0; i < str.size(); ++i) {
            char c = str[i];
            p = p->insert(c);
        }
        ++p->end;
    }

    /** 返回前缀树中有多少个字符串是T的前缀 */
    int count(string T) {
        TrieNode* p = root;
        int count = 0;
        for (int i = 0; i < T.size(); ++i) {
            char c = T[i];
            if (!p->get(c)) {
                return count;
            } else {
                p = p->get(c);
                count += p->end;
            }
        }
        return count;
    }
};


int main(int argc, char* argv[]) {
    int N = 0, M = 0;
    cin >> N >> M;
    string str;
    Solution sol;
    for (int i = 0; i < N; ++i) {
        cin >> str;
        sol.insert(str);
    }

    for (int i = 0; i < M; ++i) {
        cin >> str;
        cout << sol.count(str) << endl;
    }

    return 0;
}