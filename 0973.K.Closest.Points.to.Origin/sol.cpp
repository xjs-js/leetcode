class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](pair<int, int> lhs, pair<int, int> rhs){
            return lhs.first * lhs.first + lhs.second * lhs.second < rhs.first * rhs.first + rhs.second * rhs.second;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < points.size(); i++) {
            pair<int, int> curPoint = { points[i][0], points[i][1] };

            if (pq.size() < k) {
                pq.push(curPoint);
            } else {
                pair<int, int> top = pq.top();
                if (top.first * top.first + top.second * top.second > curPoint.first * curPoint.first + curPoint.second * curPoint.second) {
                    pq.pop();
                    pq.push(curPoint);
                }
            }
        }

        vector<vector<int>> relt;
        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            pq.pop();
            relt.push_back({top.first, top.second});
        }
        return relt;
    }
};
