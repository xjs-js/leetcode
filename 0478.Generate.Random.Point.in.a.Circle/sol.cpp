class Solution {
private:
    double _radius;
    double _x_center;
    double _y_center;
public:
    Solution(double radius, double x_center, double y_center) {
        _radius = radius;
        _x_center = x_center;
        _y_center = y_center;
    }
    
    vector<double> randPoint() {
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_real_distribution<double> dist_1(0, 1);
        std::uniform_real_distribution<double> dist_2(0, 360);
        double r = sqrt(dist_1(eng)) * _radius;
        double angle = dist_2(eng) / 180 * 3.14159265359;
        return {_x_center + r * cos(angle), _y_center + r * sin(angle)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */