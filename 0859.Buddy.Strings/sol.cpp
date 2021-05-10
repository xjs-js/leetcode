class Solution {
public:
    bool buddyStrings(string a, string b) {
        if (a.size() != b.size()) { return false; }
        
        // a 和 b 相等
        if (a == b) {
            unordered_set<char> s;
            for (char c : a) {
                if (s.count(c)) {
                    return true;
                } else {
                    s.insert(c);
                }
            }
            return false;
        }
        
        // a和b不等
        vector<int> arr;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                arr.push_back(i);
            }
        }
        
        if (arr.size() != 2) { return false; }
        
        return a[arr[0]] == b[arr[1]] && a[arr[1]] == b[arr[0]];
    }
};
