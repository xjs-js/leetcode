class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int s1 = abs(A-C) * abs(B-D);
        int s2 = abs(E-G) * abs(F-H);
        
         // 两个矩形不重叠
        if (C <= E || A >= G || B >= H || D <= F) {
            return s1 + s2;
        }
        
        // 有重叠部分
        int over = abs(max(A,E)-min(C,G)) * abs(min(D,H) - max(B,F));
        return s1 + s2 - over;
    }
};
