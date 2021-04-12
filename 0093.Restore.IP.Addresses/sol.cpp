/**
 * @date: 2021-04-13 00:16 Tue.
 * @cat: dfs
 */
 
class Solution {
private:
    vector<string> _result;
public:
    void dfs(string& s, int beg, vector<string> cur) {
        if (cur.size() == 4) {
            string str;
            for (int i = 0; i < 3; ++i) {
                str += cur[i];
                str += ".";
            }
            str += cur[3];
            _result.push_back(str);
        } else {
            int N = s.size();
            int leftLen = N - beg;
            if (cur.size() == 3) {
                if (leftLen > 3) {
                    return;
                } else {
                    string ava = s.substr(beg);
                    if (leftLen > 1) {
                        if (atoi(ava.c_str()) <= 255 && ava[0] != '0') {
                            cur.push_back(s.substr(beg));
                            dfs(s, N, cur);
                        }
                    } else {
                        if (atoi(ava.c_str()) <= 255 ) {
                            cur.push_back(s.substr(beg));
                            dfs(s, N, cur);
                        }
                    }

                }
            } else if (cur.size() == 2) {
                if (leftLen < 2 || leftLen > 6) {
                    return ;
                } else {
                    if (2 <= leftLen && leftLen <= 4) {
                        string ava = s.substr(beg, 1);
                        if (atoi(ava.c_str()) <= 255) {
                            cur.push_back(ava);
                            dfs(s, beg+1, cur);
                            cur.pop_back();
                        }
                    }
                    
                    if (3 <= leftLen && leftLen <= 5) {
                        string ava = s.substr(beg, 2);
                        if (atoi(ava.c_str()) <= 255 && ava[0] != '0') {
                            cur.push_back(ava);
                            dfs(s, beg+2, cur);
                            cur.pop_back();
                        }
                    }

                    if (4 <= leftLen && leftLen <= 6) {
                        string ava = s.substr(beg, 3);
                        if (atoi(ava.c_str()) <= 255 && ava[0] != '0') {
                            cur.push_back(s.substr(beg, 3));
                            dfs(s, beg+3, cur);
                            cur.pop_back();
                        }
                    }
                }
            } else if (cur.size() == 1) {
                if (leftLen < 3 || leftLen > 9) {
                    return ;
                } else {
                    if (3 <= leftLen && leftLen <= 7) {
                        string ava = s.substr(beg, 1);
                        if (atoi(ava.c_str()) <= 255) {
                            cur.push_back(ava);
                            dfs(s, beg+1, cur);
                            cur.pop_back();
                        }
                    }
                    
                    if (4 <= leftLen && leftLen <= 8) {
                        string ava = s.substr(beg, 2);
                        if (atoi(ava.c_str()) <= 255 && ava[0] != '0') {
                            cur.push_back(ava);
                            dfs(s, beg+2, cur);
                            cur.pop_back();
                        }
                    }
                    
                    if (5 <= leftLen && leftLen <= 9) {
                        string ava = s.substr(beg, 3);
                        if (atoi(ava.c_str()) <= 255 && ava[0] != '0') {
                            cur.push_back(s.substr(beg, 3));
                            dfs(s, beg+3, cur);
                            cur.pop_back();
                        }
                    }
                }
            }
            
        }
        
    }
    
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12) {
            return {};
        }

        string ava = s.substr(0, 1);
        if (atoi(ava.c_str()) <= 255) {
            dfs(s, 1, {ava});
        }

        ava = s.substr(0, 2);
        if (atoi(ava.c_str()) <= 255) {
            if (ava[0] != '0') {
                dfs(s, 2, {ava});
            }
        }

        ava = s.substr(0, 3);
        if (atoi(ava.c_str()) <= 255) {
            if (ava[0] != '0') {
                dfs(s, 3, {ava});
            }
        }
        
        return _result;
    }
};