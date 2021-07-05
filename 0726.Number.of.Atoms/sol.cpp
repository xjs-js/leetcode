class Solution {
public:
    bool isUp(char c) {
        return (c >= 'A' && c <= 'Z');
    }

    bool isLo(char c) {
        return (c >= 'a' && c <= 'z');
    }

    bool isNum(char c) {
        return (c >= '0' && c <= '9');
    }

    int getNum(string& formula, int& beg) {
        int n = formula.size();
        int i = beg + 1;
        for (; i < n; ++i) {
            if (isNum(formula[i])) {
                continue;
            } else {
                break;
            }
        }

        string substr = formula.substr(beg, i - beg);
        beg = i;
        return atoi(substr.c_str());
    }

    pair<string, int> getToken(string& formula, int& beg) {
        int n = formula.size();
        int i = beg + 1;
        for (; i < n; ++i) {
            if (isLo(formula[i])) {
                continue;
            } else {
                break;
            }
        }

        string atom = formula.substr(beg, i - beg);
        if (i == n) {
            beg = i;
            return {atom, 1};
        } else {
            if (isNum(formula[i])) {
                int num = getNum(formula, i);
                beg = i;
                return {atom, num};
            } else {
                beg = i;
                return {atom, 1};
            }
        }
    }

    string countOfAtoms(string formula) {
        map<string, int> count;

        int n = formula.size();
        stack<map<string, int>> sk;
        int i = 0;
        while (i < n) {
            char c = formula[i];
            if (isUp(c)) {
                pair<string, int> token = getToken(formula, i);
                if (sk.size() > 0) {
                    auto& dict = sk.top();
                    dict[token.first] += token.second;
                } else {
                    count[token.first] += token.second;
                }
            } else if (c == '(') {
                map<string, int> dict;
                sk.push(dict);
                ++i;
            } else if (c == ')') {
                auto dict = sk.top();
                sk.pop();
                int num = 1;
                if (i + 1 < n && isNum(formula[i+1])) {
                    i += 1;
                    num = getNum(formula, i);
                } else {
                    ++i;
                }

                if (sk.size() == 0) {
                    for (auto it = dict.begin(); it != dict.end(); ++it) {
                        count[it->first] += it->second * num;
                    }
                } else {
                    auto& top = sk.top();
                    for (auto it = dict.begin(); it != dict.end(); ++it) {
                        top[it->first] += it->second * num;
                    }
                }
            }
        }

        string relt;
        for (auto it = count.begin(); it != count.end(); it++) {
            relt += it->first;
            if (it->second > 1)
                relt += to_string(it->second);
        }
        return relt;
    }
};

