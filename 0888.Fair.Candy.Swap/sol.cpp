/**
 * @date: 2021-04-02 14:02
 */


class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector<int> result;

        unordered_set<int> set_A;

        int total_A = 0;
        for (int i = 0; i < A.size(); ++i) {
            int val = A[i];
            set_A.insert(val);
            total_A += val;
        }

        int total_B = 0;
        for (int i = 0; i < B.size(); ++i) {
            total_B += B[i];
        }

        int half = (total_A + total_B) / 2;

        int delta = total_B - half;

        for (int i = 0; i < B.size(); ++i) {
            int target = B[i] - delta;
            if (set_A.count(target) != 0) {
                result.emplace_back(target);
                result.emplace_back(B[i]);
                return result;
            }
        }

        return result;
    }
};
