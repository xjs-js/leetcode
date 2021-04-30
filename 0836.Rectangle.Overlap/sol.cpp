class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int a1 = rec1[0], b1 = rec1[1], a2 = rec1[2], b2 = rec1[3];
        int x1 = rec2[0], y1 = rec2[1], x2 = rec2[2], y2 = rec2[3];
        
        if (a1 == a2 || b1 == b2 || x1 == x2 || y1 == y2) {
            return false;
        }
        
        
        // rec2 is left to rec1
        if (x2 <= a1 || x1 >= a2 || y1 >= b2 || y2 <= b1) {
            return false;
        }
        
        return true;
    }
};
