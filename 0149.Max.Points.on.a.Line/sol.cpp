class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        map<pair<double, double>, set<pair<int, int>>> count;
        map<int, set<pair<int, int>>> x;
        map<int, set<pair<int, int>>> y;

        for (int i = 0; i < points.size(); ++i) {
            int i_x = points[i][0];
            int i_y = points[i][1];

            x[i_x].insert({i_x, i_y});
            y[i_y].insert({i_x, i_y});

            for (int j = i-1; j >= 0; --j) {
                int j_x = points[j][0];
                int j_y = points[j][1];

                if (i_x == j_x || i_y == j_y) {
                    continue;
                }

                double k = (i_y - j_y) * 1.0 / (i_x - j_x);
                double b = (i_y) - k * i_x;

                count[{k, b}].insert({i_x, i_y});
                count[{k, b}].insert({j_x, j_y});
            }
        }

        int maxCount = 1;
        auto it = count.begin();
        while (it != count.end()) {
            maxCount = max(maxCount, (int)(it->second).size());
            ++it;
        }

        auto it2 = x.begin();
        while(it2 != x.end()) {
            maxCount = max(maxCount, (int)(it2->second).size());
            ++it2;
        }

        auto it3 = y.begin();
        while (it3 != y.end()) {
            maxCount = max(maxCount, (int)(it3->second).size());
            ++it3;
        }

        return maxCount;
    }
};
