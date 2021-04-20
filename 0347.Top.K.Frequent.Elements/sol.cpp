struct Compare {
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second < rhs.second;
    }  
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); ++i) {
            ++count[nums[i]];
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        auto it = count.begin();
        while (it != count.end()) {
            pq.push({it->first, it->second});
            ++it;
        }
        
        vector<int> result;
        while (k--) {
            auto top = pq.top();
            result.emplace_back(top.first);
            pq.pop();
        }
        return result;
    }
};