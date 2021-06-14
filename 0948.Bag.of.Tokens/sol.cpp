class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int i = 0; int j = tokens.size()-1;
        int relt = 0;
        int maxRelt = 0;
        while (i <= j) {
            while (i <= j && power >= tokens[i]) {
                relt += 1;
                power -= tokens[i];
                ++i;
            }
            maxRelt = max(maxRelt, relt);
            if (relt == 0) {
                return 0;
            } else {
                power += tokens[j];
                --j;
                --relt;
            }
        }
        return maxRelt;
    }
};
