class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[1] < rhs[1];
        });
        
        int relt = 0;
        int curTotalTime = 0;
        
        priority_queue<int> pq;
        for (int i = 0; i < courses.size(); ++i) {
            vector<int>& cur_p = courses[i];
            if (curTotalTime + cur_p[0] <= cur_p[1]) {
                curTotalTime += cur_p[0];
                pq.push(cur_p[0]);
                ++relt;
            } else {
                if (pq.empty()) {
                    continue;
                } else {
                    if (cur_p[0] < pq.top()) {
                        curTotalTime = curTotalTime - pq.top() + cur_p[0];
                        pq.pop();
                        pq.push(cur_p[0]);
                    }
                }
            }
        }
        
        return relt;
    }
};
