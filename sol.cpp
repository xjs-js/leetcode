class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        
        // left distance
        vector<int> left(n, -1);
        int prevPerson = seats[0] == 1 ? 0 : -1;
        
        for (int i = 1; i < n; ++i) {
            if (seats[i] == 1) {
                prevPerson = i;
            } else {
                if (prevPerson != -1) {
                    left[i] = i - prevPerson;
                }
            }
        }
        
        int relt = 0;
        vector<int> right(n, -1);
        int lastPerson = seats[n-1] == 1 ? n-1 : -1;
        for (int i = n-2; i >= 0; --i) {
            if (seats[i] == 1) {
                lastPerson = i;
            } else {
                if (lastPerson != -1) {
                    right[i] = lastPerson - i;
                }
            }
            
            if (seats[i] == 0) {
                if (right[i] == -1) {
                    relt = max(relt, left[i]);
                } else if (left[i] == -1) {
                    relt = max(relt, right[i]);
                } else {
                    relt = max(relt, min(left[i], right[i]));
                }
            }
        }
        
        // n-1
        if (seats[n-1] == 0) {
            relt = max(relt, left[n-1]);
        }
        
        return relt;
    }
};
