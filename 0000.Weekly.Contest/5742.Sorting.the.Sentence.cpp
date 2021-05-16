class Solution {
public:
    string sortSentence(string s) {
        vector<string> arr(10);
        
        
        string delim = " ";
        size_t beg = 0;
        size_t end = s.find(delim);
        while (end != string::npos) {
            string token = s.substr(beg, end - beg);
            if (token.size() > 0) {
                int num = token[token.size()-1] - '0';
                arr[num] = token.substr(0, token.size() - 1);
            }
            beg = end + 1;
            end = s.find(delim, beg);
        }
        
        string token = s.substr(beg);
        if (token.size() > 0) {
            int num = token[token.size()-1] - '0';
            arr[num] = token.substr(0, token.size() - 1);
        }
        
        
        string relt;
        for (int i = 0; i < arr.size(); ++i) {
            string& s = arr[i];
            if (s.size() > 0) {
                relt += s;
                relt += " ";
            }
        }
        
        return relt.substr(0, relt.size() - 1);
    }
};
