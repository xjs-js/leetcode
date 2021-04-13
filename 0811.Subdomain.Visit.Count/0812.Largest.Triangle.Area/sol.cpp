/**
 * @date: 2021-04-13 11:32 Tue
 * @note: brute force
 */

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double area = 0;
        
        for (int i = 0; i < points.size(); ++i) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < points.size(); ++j) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                for (int k = j + 1; k < points.size(); ++k) {
                    int x3 = points[k][0];
                    int y3 = points[k][1];
                    
                    double S = 0.5* fabs( (x2 - x1)*(y3 - y1) - (x3-x1) * (y2-y1) );
                    area = max(area, S);
                }
            }
        }
        return area;
    }
};