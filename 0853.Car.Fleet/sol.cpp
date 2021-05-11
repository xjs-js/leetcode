struct Car {
    int _pos;
    int _speed;
    Car(int pos, int speed) {
        _pos = pos;
        _speed = speed;
    }
};


class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) {
            return 0;
        }
        
        
        vector<Car> cars;
        for (int i = 0; i < n; ++i) {
            Car c(position[i], speed[i]);
            cars.emplace_back(c);
        }
        // 按位置以降序排序
        sort(cars.begin(), cars.end(), [](const Car& lhs, const Car& rhs){
            return lhs._pos > rhs._pos;
        });
        
        int count = 1;
        vector<double> seconds(n);
        seconds[0] = (target - cars[0]._pos) * 1.0 / cars[0]._speed;
        for (int i = 1; i < n; ++i) {
            seconds[i] = (target - cars[i]._pos) * 1.0 / cars[i]._speed;
            if (seconds[i] <= seconds[i-1]) {
                seconds[i] = seconds[i-1];
            } else {
                ++count;
            }
        }
        
        return count;
    }
};
