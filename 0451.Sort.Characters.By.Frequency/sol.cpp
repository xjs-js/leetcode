class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        vector<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (count.find(s[i]) != count.end()) {
                ++count[s[i]];
            } else {
                st.push_back(s[i]);
                ++count[s[i]];
            }
        }

        sort(st.begin(), st.end(), [&](char lhs, char rhs) {
            return count[lhs] > count[rhs];
        });

        string relt;
        for (int i = 0; i < st.size(); i++) {
            int j = count[st[i]];
            for (int k = 0; k < j; ++k) {
                relt += st[i];
            }
        }

        return relt;

    }
};
