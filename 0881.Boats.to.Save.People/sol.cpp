class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end(), greater<int>());
        
        // 双指针
        int beg = 0, end = people.size() - 1;
        
        int relt = 0;
        while (beg <= end) {
            if (beg == end) {
                ++relt;
                break;
            } else {
                int first = people[beg];
                int left = limit-first;
                if (people[end] <= left) {
                    --end;
                }
                ++relt;
                ++beg;
            }
        }
        
        return relt;
    }
};
