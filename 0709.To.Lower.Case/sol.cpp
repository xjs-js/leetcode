class Solution {
public:
    string toLowerCase(string str) {
        string result;
        for (auto s : str) {
            if (65 <= s && s <= 90) 
                s = s + 32;
            result.push_back(s);
        }
        return result;
    }

    // nice solution from discuss
    string toLowerCase(string str) {
        for (auto &s : str) {
            if (65 <= s && s <= 90)
                s = s + 32;
        }
        return str;
    }
};  
