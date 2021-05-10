class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // 手里的零钱
        unordered_map<int, int> hands;
        hands[5] = 0;
        hands[10] = 0;
        
        for (int i = 0; i < bills.size(); ++i) {
            // 5块钱，直接入账
            if (bills[i] == 5) {
                ++hands[5];
            } else if (bills[i] == 10) { // 10块钱，找零5块钱
                if (hands[5] > 0) {
                    --hands[5];
                    ++hands[10];
                } else {
                    return false;
                }
            } else if (bills[i] == 20) { // 20块钱，找零15块，先把10块的找掉
                int needChange = 15;
                if (hands[10] > 0) {
                    needChange -= 10;
                    --hands[10];
                }
                
                int numOf5 = needChange / 5;
                if (hands[5] >= numOf5) {
                    hands[5] -= numOf5;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
