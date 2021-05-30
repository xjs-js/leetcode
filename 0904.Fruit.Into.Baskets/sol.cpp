class Solution {
public:
    // 滑动窗口
    int totalFruit(vector<int>& tree) {
        int i = 0, j = 0;
        int n = tree.size();
        int relt = 1;

        while (i < n && j < n) {
            unordered_set<int> us;
            us.insert(tree[i]);
            us.insert(tree[j]);

            while (j < n && (us.size() == 2 && us.count(tree[j]) || us.size() < 2)) {
                us.insert(tree[j]);
                ++j;
            }
            relt = max(relt, j - i);

            if (j == n) {
                break;
            }

            i = j - 1;
            while (i >= 0 && tree[i] == tree[j-1]) {
                --i;
            }
            ++i;
        }

        return relt;
    }
};
