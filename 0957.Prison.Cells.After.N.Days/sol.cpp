class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        int a = 0;
        for (int i = 0; i < 8; ++i) {
            a += cells[i] * pow(2, 7 - i);
        }
        int relt = 0;
        unordered_set<int> st;
        vector<int> res;
        while (true) {
            relt = ~((a << 1) ^ (a >> 1));
            relt = ((relt >> 1) & 0x3f) << 1;
            a = relt;
            if (st.count(relt)) {
                break;
            } else {
                st.insert(relt);
                res.push_back(relt);
            }
        }

        int len = st.size();
        relt = res[(n -1) % len];


        vector<int> arr;
        for (int i = 0; i < 8; ++i) {
            arr.push_back((relt >> (7-i)) & 0x01);
        }
        return arr;
    }
};
