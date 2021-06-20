// https://leetcode-cn.com/problems/the-number-of-full-rounds-you-have-played/

class Solution {
public:
    int remain(int m) {
        if (m == 0) {
            return 4;
        } else if (m > 0 && m <= 15) {
            return 3;
        } else if (m > 15 && m <= 30) {
            return 2;
        } else if (m > 30 && m <= 45) {
            return 1;
        } else {
            return 0;
        }
    }
    
    int remain(int start, int finish) {
        int relt = 0;
        
        if (start <= 0 && finish >= 15) {
            ++relt;
        }
        
        if (start <= 15 && finish >= 30) {
            ++relt;
        }
        
        if (start <= 30 && finish >= 45) {
            ++relt;
        }
        
        return relt;
    }
    
    int endRemain(int m) {
        if (m >= 45) {
            return 3;
        } else if (m >= 30) {
            return 2;
        } else if (m >= 15) {
            return 1;
        } else {
            return 0;
        }
    }
    
    int numberOfRounds(string startTime, string finishTime) {
        string hour_str_1 = startTime.substr(0, 2);
        string min_str_1 = startTime.substr(3, 2);
        
        string hour_str_2 = finishTime.substr(0, 2);
        string min_str_2 = finishTime.substr(3,2);
        
        int hour_1 = atoi(hour_str_1.c_str());
        int min_1 = atoi(min_str_1.c_str());
        int hour_2 = atoi(hour_str_2.c_str());
        int min_2 = atoi(min_str_2.c_str());
        
        if (hour_1 == hour_2) {
            if (min_1 < min_2) {
                return remain(min_1, min_2);
            } else if (min_1 > min_2) {
                int relt_1 = 23 * 4;
                relt_1 += endRemain(min_2);
                relt_1 += remain(min_1);
                return relt_1;
            }
        } else if (hour_1 < hour_2) {
            int relt = remain(min_1);
            relt += endRemain(min_2);
            relt += (hour_2- hour_1 - 1) * 4;
            return relt;
        } else if (hour_1 > hour_2) {
            int relt = remain(min_1);
            relt += endRemain(min_2);
            relt += (24-1-hour_1 + hour_2) * 4;
            return relt;
        }
        return 0;
    }
};