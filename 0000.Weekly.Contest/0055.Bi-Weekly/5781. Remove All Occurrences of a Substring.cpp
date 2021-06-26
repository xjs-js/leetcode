class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        while (s.find(part) != string::npos) {
            size_t index = s.find(part);
            
            s = s.substr(0, index) + s.substr(index + part.size());
        }
        return s;
        
    }
};