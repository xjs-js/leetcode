struct MP {
    int _diff;
    int _profit;
    
    MP(int diff, int profit) : _diff(diff), _profit(profit) {}
};

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

        vector<MP> allMissions;
        int n = difficulty.size();
        for (int i = 0; i < n; ++i) {
            MP mp(difficulty[i], profit[i]);
            allMissions.emplace_back(mp);
        }
        sort(allMissions.begin(), allMissions.end(), [&](const MP& lhs, const MP& rhs){
            return lhs._diff < rhs._diff; 
        });
        
        int m = worker.size();
        int maxCap = 0;
        for (int i = 0; i < m; ++i) {
            maxCap = max(maxCap, worker[i]);
        }
        
        vector<int> maxProfit(maxCap + 1, 0);
        for (int i = 0; i < n; ++i) {
            MP& mp = allMissions[i];
            if (mp._diff > maxCap) {
                break;
            } else {
                maxProfit[mp._diff] = max(maxProfit[mp._diff], mp._profit);
            }
        }
        
        int curMax = -1;
        for (int i = 0; i <= maxCap; ++i) {
            
            if (curMax == -1) {
                curMax = maxProfit[0];
            }
            
            curMax = max(curMax, maxProfit[i]);
            maxProfit[i] = curMax;
            // cout << i << " => " << maxProfit[i] << endl;
        }
        
        int relt = 0;
        for (int i = 0; i < m; ++i) {
            // cout << worker[i] << endl;  
            relt += maxProfit[worker[i]];
        }
        return relt;
    }
};
