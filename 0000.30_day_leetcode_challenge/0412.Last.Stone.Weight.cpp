class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 0) {
            return 0;
        }
        if (stones.size() == 1) {
            return stones[0];
        }
        
        priority_queue<int> q;
        for (int i : stones) {
            q.push(i);
        }

        while (q.size() > 1) {
            int first = q.top();
            q.pop();
            int second = q.top();
            q.pop();

            if (first != second) {
                q.push(first - second);
            }
        }

        if (q.size() == 0) {
            return 0;
        } else {
            return q.top();
        }
    }
};