class Solution {
    vector<string> getHour(int n) {
        vector<string> relt;
        for (int i = 0; i <= 11; ++i) {
            bitset<4> bs(i);
            if (bs.count() == n) {
                relt.push_back(to_string(i));
            }
        }
        return relt;
    }

    vector<string> getMin(int n) {
        vector<string> relt;
        for (int i = 0; i <= 59; ++i) {
            bitset<6> bs(i);
            if (bs.count() == n) {
                if (i >= 0 && i <= 9) {
                    relt.push_back("0" + to_string(i));
                } else {
                    relt.push_back(to_string(i));
                }
            }
        }
        return relt;
    }

public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> relt;
        for (int hour = 0; hour <= turnedOn; ++hour) {
            int mint = turnedOn - hour;
            auto left = getHour(hour);
            auto right = getMin(mint);
            for (string& lhs : left) {
                for (string& rhs: right) {
                    relt.push_back(lhs + ":" + rhs);
                }
            }
        }
        return relt;
    }
};
