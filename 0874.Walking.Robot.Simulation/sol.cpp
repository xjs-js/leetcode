class Solution {
public:
    int _relt;      // 答案
    int _X, _Y;     // 当前坐标
    int _curDire;   // 方向
    set<pair<int, int>> _obs; // 障碍
    void walk(int dist) {
        if (_curDire == 0) { // north
            while (dist--) {
                if (!_obs.count({_X, _Y + 1})) {
                    ++_Y;
                    _relt = max(_relt, _X * _X + _Y * _Y);
                } else {
                    break;
                }
            }
        } else if (_curDire == 1) { // east
            while (dist--) {
                if (!_obs.count({_X + 1, _Y})) {
                    ++_X;
                    _relt = max(_relt, _X * _X + _Y * _Y);                    
                } else {
                    break;
                }
            }
        } else if (_curDire == 2) { // south
            while (dist--) {
                if (!_obs.count({_X, _Y - 1})) {
                    --_Y;
                    _relt = max(_relt, _X * _X + _Y * _Y);                    
                } else {
                    break;
                }
            }
        } else if (_curDire == 3) { // west
            while (dist--) {
                if (!_obs.count({_X - 1, _Y})) {
                    --_X;
                    _relt = max(_relt, _X * _X + _Y * _Y);
                } else {
                    break;
                }
            }
        }
    }
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        _relt = 0;
        _X = _Y = 0;    
        _curDire = 0;
        
        for (auto& v : obstacles) {
            _obs.insert({v[0], v[1]});
        }
        
        for (int c : commands) {
            if (c == -2) {
                _curDire = (_curDire + 4 - 1) % 4;
            } else if (c == -1) {
                _curDire = (_curDire + 1) % 4;
            } else {
                walk(c);
            }
        }
        
        return _relt;
    }
};
