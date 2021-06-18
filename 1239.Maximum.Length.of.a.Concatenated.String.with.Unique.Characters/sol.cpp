class Solution {
private:
    int _relt;

    bool isSelf(string& str) {
        unordered_set<char> st;
        for (char c : str) {
            if (st.count(c)) {
                return false;
            } else {
                st.insert(c);
            }
        }
        return true;
    }

    void search(vector<string>& arr, int k, unordered_set<char> st) {
        int n = arr.size();
        if (n == k) {
            _relt = max(_relt, (int)st.size());
        } else {
            string& cur = arr[k];
            bool canInsert = isSelf(cur);
            if (canInsert) {
                for (char c : cur) {
                    if (st.count(c)) {
                        canInsert = false;
                        break;
                    }
                }
            }


            search(arr, k+1, st);
            if (canInsert) {
                for (char c : cur) {
                    st.insert(c);
                }
                search(arr, k + 1, st);
            }
        }
    }

public:
    int maxLength(vector<string>& arr) {
        _relt = 0;
        unordered_set<char> st;
        search(arr, 0, st);

        return _relt;
    }
};
