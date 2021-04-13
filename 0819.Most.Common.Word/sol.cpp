/**
 * @date: 2021-04-13 22:23
 */

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> count;
        string token;
        string maxStr;
        int maxOcc = 0;
        paragraph += "\n";
        for (int i = 0; i < paragraph.size(); ++i) {
            char c = paragraph[i];
            if (isalpha(c)) {
                token += tolower(c);
            } else {
                if (!token.empty() && !ban.count(token)) {
                    ++count[token];
                    if (count[token] > maxOcc) {
                        maxOcc = count[token];
                        maxStr = token;
                    }   
                }
                token = "";
            }
        }
    
        
        return maxStr;
    }
};