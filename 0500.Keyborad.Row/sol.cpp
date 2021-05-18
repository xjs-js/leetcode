class Solution {
public:
    bool match(string str, string s) {
        int firstChar = tolower(s[0]);
        bool isMatch = true;
        if (str.find(firstChar) != string::npos) {
            for (int i = 1; i < s.size(); ++i) {
                if (str.find(tolower(s[i])) == string::npos) {
                    isMatch = false;
                    break;
                }
            }
        } else {
            isMatch = false;
        }
        return isMatch;
    }
    
    
    vector<string> findWords(vector<string>& words) {
        string firstStr = "qwertyuiop";
        string secondStr = "asdfghjkl";
        string thirdStr = "zxcvbnm";
        
        vector<string> relt;
        for (auto& s : words) {
            if (match(firstStr, s) || match(secondStr, s) || match(thirdStr, s)) {
                relt.push_back(s);
            }
           
        }
        
        return relt;
    }
};
