class Solution {
public:
    string greater(string left, string right) {
        if (left.size() < right.size()) {
            return right;
        } else if (left.size() > right.size()) {
            return left;
        } else {
            return max(left, right);
        }
    }

    string largestNumber(vector<int>& cost, int target) {

        vector<vector<string>> dp(10, vector<string>(target+1, "0"));
        for (int i = 0; i <= 9; ++i) {
            dp[i][0] = "0";
        }
        
        for (int i = 1; i <= 9; ++i) {
            int cur = cost[i-1];

            for (int j = 0; j <= target; ++j) {
                dp[i][j] = dp[i-1][j];

                if (j >= cur) {
                    string prev = dp[i][j-cur];
                    
                    if (prev == "0") {
                        if (j == cur) {
                            dp[i][j] = greater(dp[i][j], to_string(i));
                        }
                    } else {
                        string first = to_string(i) + prev;
                        string second = prev + to_string(i);

                        dp[i][j] = greater(dp[i][j], greater(first, second));
                    }
                }
            }
        }

        return dp[9][target];
    }
};

