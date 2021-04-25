class Solution {
public:
    int findNextChar(string word, int beg, char c) {
        while (beg < word.size() && word[beg] != c) {
            ++beg;
        }
        return beg;
    }

    int findNextNotChar(string word, int beg, char c) {
        while (beg < word.size() && word[beg] == c) {
            ++beg;
        }
        return beg;
    }

    int longestBeautifulSubstring(string word) {
        int i = 0;
        int n = word.size();
        int res = 0;

        while (i < n) {
            int aPos = findNextChar(word, i, 'a');
            int ePos = findNextNotChar(word, aPos+1, 'a');
            if (ePos < word.size() && word[ePos] == 'e') {
                int iPos = findNextNotChar(word, ePos+1, 'e');
                if (iPos < word.size() && word[iPos] == 'i') {
                    int oPos = findNextNotChar(word, iPos+1, 'i');
                    if (oPos < word.size() && word[oPos] == 'o') {
                        int uPos = findNextNotChar(word, oPos+1, 'o');
                        if (uPos < word.size() && word[uPos] == 'u') {
                            int j = findNextNotChar(word, uPos+1, 'u');
                            res = max(res, j - aPos);
                            i = j;
                        } else {
                            i = uPos;
                        }
                    }
                    else {
                        i = oPos;
                    }
                }
                else {
                    i = iPos;
                }
            }
            else {
                i = ePos;
            }
        }
        return res;
    }

};