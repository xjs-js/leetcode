class TopVotedCandidate {
private:
    vector<int> _relt;
    vector<int> _times;

public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int maxCount = 0;
        int curRelt = 0;

        _times = times;
        map<int, int> count; // 统计候选人票数
        for (int i = 0; i < times.size(); ++i) {
            ++count[persons[i]];
            if (count[persons[i]] >= maxCount) {
                maxCount = count[persons[i]];
                curRelt = persons[i];
            }
            _relt.push_back(curRelt);
        }
    }
    
    int q(int t) {
        auto it = upper_bound(_times.begin(), _times.end(), t);
        int n = _times.size();

        if (it == _times.end()) {
            return _relt[n-1];
        } else {
            if (it == _times.begin()) {
                return _relt[0];
            } else {
                return _relt[it - _times.begin() - 1];
            }
        }
        return 0;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
