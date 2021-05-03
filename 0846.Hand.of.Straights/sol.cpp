class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if (W == 1) return true;
        
        int n = hand.size();
        if (n % W != 0) {
            return false;
        }
        
        map<int, int> count;
        
        for (int i = 0; i < hand.size(); ++i) {
            ++count[hand[i]];
        }
        
        do {
            int firstNum = -1;
            auto it = count.begin();
            while (it != count.end()) {
                if (it->second > 0) {
                    firstNum = it->first;
                    break;
                } else {
                    ++it;
                }
            }
            if (firstNum == -1) {
                return false;
            }

            int curNum = W;
            while (curNum--) {
                if (count[firstNum] <= 0) {
                    return false;
                } else {
                    --count[firstNum];
                }
                ++firstNum;
            }
            
            n -= W;
        } while (n);

        
        return true;
    }
};
