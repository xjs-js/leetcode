class Solution {
public:    
    void search(string& s, int beg, uint64_t target, bool& relt) {
        if (!relt) {
            if (beg == s.size()) {
                relt = true;
            } else {
                if (target < 0) {
                    relt = false;
                    return ;
                } else if (target == 0) {
                    for (int i = beg; i < s.size(); ++i) {
                        if (s[i] != '0') {
                            relt = false;
                            return ;
                        }
                    }
                    
                    relt = true;
                    return ;
                } else {
                    int i = beg;
                    while (i < s.size() && s[i] == '0') {
                        ++i;
                    }
                    if (i == s.size()) {
                        relt = false;
                        return;
                    }
                    string targetStr = to_string(target);
                    int targetLen = targetStr.size();
                    
                    string curSub = s.substr(i, targetLen);
                    if (stoull(curSub.c_str()) == target) {
                        for (int k = 0; i + targetLen + k - 1 < s.size(); ++k) {
                            int newLen = targetLen + k;
                            curSub = s.substr(i, newLen);
                            if (stoull(curSub.c_str()) == target) {
                                if (target > 0) {
                                    search(s, i + newLen, target - 1, relt);
                                    if (relt == true) {
                                        return;
                                    }
                                }
                            } else {
                                relt = false;
                                return;
                            }
                        }     
                    } else {
                        relt = false;
                        return ;
                    }
                } 
                
            }
        }
    }
    
    bool splitString(string s) {
        int i = 0;
        int n = s.size();
        while (i < n && s[i] == '0') ++i;
        
        if (i == s.size() - 1) {
            return false;
        }
        
        bool relt = false;
        for (int k = 0; i + k <= n-2; ++k) {
            string curStr = s.substr(i, k+1);
            uint64_t curNum = stoull(curStr.c_str());
            if (curNum > 0) {
                search(s, i+k+1, curNum-1, relt);
                if (relt) {
                    return true;
                }
            }
        }
        return false;
    }
};
