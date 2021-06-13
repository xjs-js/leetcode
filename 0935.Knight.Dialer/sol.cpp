typedef long long LL;
constexpr int MOD = 1e9 + 7;
class Solution {
public:
    int knightDialer(int n) {
        if (n == 1) return 10;

        int count[10] = {1,1,1,1,1,1,1,1,1,1};
        int newCount[10];
        memset(newCount, 0, sizeof newCount);

        vector<vector<int>> dict = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};
        for (int i = 1; i < n; ++i) {
            memset(newCount, 0, sizeof newCount);
            for (int j = 0; j < 10; ++j) {
                int c = count[j];
                for (int next : dict[j]) {
                    newCount[next] = (newCount[next] + c) % MOD; 
                }
            }
            for (int j = 0; j < 10; ++j) {
                count[j] = newCount[j];
            }
        }

        LL relt = 0;
        for (int i = 0; i < 10; ++i) {
            relt = (relt + count[i]) % MOD;
        }
        return relt;
    }
};
