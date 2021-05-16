class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        vector<int> relt;
        int i = 1;
        for (;i <= max(memory1, memory2); ++i) {
            if (memory1 < memory2) {
                memory2 -= i;   
            } else {
                memory1 -= i;
            }
        }
        
        return {i, memory1, memory2};
    }
};
