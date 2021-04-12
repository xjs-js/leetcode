/**
 * @date: 2021-04-12
 * @name: 情感丰富的文字 
 */

class Solution {
public:
    vector<pair<char, int>> split(string& S) {
        vector<pair<char, int>> result;
        
        if (S.empty()) {
            return result;
        }
        
        int beg = 0;
        int i = beg + 1;
        while (beg < S.size() && i < S.size()) {
            if (S[i] == S[beg]) {
                ++i;
                continue;
            } else {
                result.emplace_back(make_pair(S[beg], i - beg));
                beg = i;
                ++i;
            }
        }
        
        result.emplace_back(make_pair(S[beg], S.size() - beg));
        
        return result;
    }
    
    bool match(vector<pair<char, int>>& left, vector<pair<char, int>>& right) {
        if (left.size() != right.size()) {
            return false;
        }

        for (int i = 0; i < left.size(); ++i) {
            auto lp = left[i];
            auto rp = right[i];
            if (lp.first == rp.first) {
                if (lp.second == rp.second || (lp.second > rp.second && lp.second >= 3)) {
                    continue;
                }
            }
            return false;
        }

        return true;
    }

    int expressiveWords(string S, vector<string>& words) {
        vector<pair<char, int>> left = split(S);

        int result = 0;
        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            vector<pair<char, int>> right = split(word);
            if (match(left, right)) {
                ++result;
            }
        }

        return result;
    }
};