class UndergroundSystem {
private:
    unordered_map<int, string> _inStation;  // 入站的地点
    unordered_map<int, int>    _inTime;     // 入站的时间
    map<pair<string, string>, pair<int, int>> _query; // Key: <入站地点，出战地点> Value <总时间，次数>
    
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        _inStation[id] = stationName;
        _inTime[id] = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        string inName = _inStation[id];
        int inTime = _inTime[id];
        
        if (_query.find({inName, stationName}) != _query.end()) {
            pair<int, int>& relt = _query[{inName, stationName}];
            relt.first += t - inTime;
            relt.second += 1;
        } else {
            _query[{inName, stationName}] = {t - inTime, 1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        const pair<int, int>& relt = _query[{startStation, endStation}];
        return (relt.first) * 1.0 / relt.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
