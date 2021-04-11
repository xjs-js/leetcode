/**
 * @date: 2021-04-11 Sun.
 */

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> people(n);
        vector<bool> hasLeave(n);

        // 场上剩余人数
        int onPeople = n;
        int begIndex = 0;
        while (onPeople != 1) {
            
            int count = 1;
            while (count != k) {
                int nextIndex = (begIndex + 1) % n;
                while (hasLeave[nextIndex]) {
                    nextIndex = (nextIndex + 1) % n;
                }
                begIndex = nextIndex;
                ++count;
            }
            hasLeave[begIndex] = true;

            int nextIndex = (begIndex + 1) % n;
            while (hasLeave[nextIndex]) {
                nextIndex = (nextIndex + 1) % n;
            }
            begIndex = nextIndex;
            
            --onPeople;
        }

        return begIndex + 1;
    }
};