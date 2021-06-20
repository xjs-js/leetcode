class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> count;
        for (int i : arr) {
            ++count[i];
        }

        auto it = count.begin();
        while (it != count.end()) {
            int i = it->first;
            int left = it->second;

            if (left > 0) {
                int d_i;
                if (i >= 0) {
                    d_i = i * 2;
                } else {
                    d_i = i / 2;
                    if (d_i + d_i != i) {
                        return false;
                    }
                }

                int d_left = count[d_i];

                if (d_left < left) {
                    return false;
                } else {
                    count[d_i] -= left;
                }
            }

            ++it;
        }
        return true;
    }
};
