class Solution {
public:
    set<pair<double, double>> _points;

    double calc(pair<int,int> pk1, set<double>& cluster1, pair<int,int> pk2, set<double>& cluster2, bool& isFind) {
        double relt;

        double k1 = pk1.first == 0 ? 0 : pk1.first * 1.0 / pk1.second;
        double k2 = pk2.first == 0 ? 0 : pk2.first * 1.0 / pk2.second;
        for (auto i = cluster1.begin(); i != cluster1.end(); ++i) {
            double b1 = *i;
            auto j = i;
            std:advance(j, 1);

            for (; j != cluster1.end(); ++j) {
                double b2 = *j;

                for (auto m = cluster2.begin(); m != cluster2.end(); ++m) {
                    double b3 = *m;


                    double x_1_f = k1 == 0 ? b3 : (b3 - b1)  * k1 / (k1 * k1 + 1);
                    double y_1_f = k1 == 0 ? b1 : k1 * x_1_f + b1;

                    double x_2_f = k1 == 0 ? b3 : (b3 - b2) * k1 / (k1 * k1 + 1);
                    double y_2_f = k1 == 0 ? b2 : k1 * x_2_f + b2;


                    int x_1 = (int) round(x_1_f);
                    int y_1 = (int) round(y_1_f);
                    int x_2 = (int) round(x_2_f);
                    int y_2 = (int) round(y_2_f);

                    if (abs(x_1_f - x_1) < 1e-5 && abs(y_1_f - y_1) < 1e-5
                     && abs(x_2_f - x_2) < 1e-5 && abs(y_2_f - y_2) < 1e-5) {
                        if (!_points.count({x_1, y_1}) || !_points.count({x_2, y_2})) {
                            continue;
                        }
                        auto n = m;
                        std::advance(n, 1);
                        for (; n != cluster2.end(); ++n) {
                            double b4 = *n;

                            double x_3_f = k1 == 0 ? b4 : (b4 - b1) * k1 / (k1 * k1 + 1);
                            double y_3_f = k1 == 0 ? b1 : k1 * x_3_f + b1;

                            double x_4_f = k1 == 0 ? b4 : (b4 - b2) * k1 / (k1 * k1 + 1);
                            double y_4_f = k1 == 0 ? b2 :  k1 * x_4_f + b2;

                            int x_3 = (int) round(x_3_f);
                            int y_3 = (int) round(y_3_f);

                            int x_4 = (int) round(x_4_f);
                            int y_4 = (int) round(y_4_f);

                            if (abs(x_3_f - x_3) < 1e-5 && abs(y_3_f - y_3) < 1e-5 &&
                            abs(x_4 - x_4_f) < 1e-5 && abs(y_4 - y_4_f) < 1e-5) {
                                if (!_points.count({x_3, y_3}) || !_points.count({x_4, y_4})) {
                                    continue;
                                }

                                double a = abs(b2 - b1) / sqrt(k1 * k1 + 1);
                                double b = abs(b3 - b4) / sqrt(k2 * k2 + 1);

                                relt = isFind ? min(relt, a*b) : a*b;
                                isFind = true;
                            }

                        }
                    }


                }
            }
        }

        return relt;
    }

    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();

        // {斜率K，[B]}
        // 存储斜率相同的直线簇
        map<pair<int,int>, set<double>> dict;

        // 垂直于x轴的直线
        set<double> x;

        for (int i = 0; i < n; ++i) {
            int i_x = points[i][0];
            int i_y = points[i][1];
            _points.insert({i_x, i_y});
            for (int j = i + 1; j < n; ++j) {
                int j_x = points[j][0];
                int j_y = points[j][1];

                if (i_x == j_x) {
                    x.insert(i_x);
                } else {
                    int left = j_y - i_y;
                    int right = j_x - i_x;
                    bool isNeg = (left > 0 && right < 0) || (left <0 && right > 0);
                    int g = std::gcd(abs(left), abs(right));
                    pair<int, int> pk;
                    double k = left * 1.0 / right;
                    if (isNeg) {
                        pk = {-abs(left) / g, abs(right) / g};
                    } else {
                        pk = {abs(left) / g, abs(right)/ g};
                    }
                    double b = j_y - k * j_x;
                    dict[pk].insert(b);
                }
            }
        }


        double relt = -1;
        for (auto it = dict.begin(); it != dict.end(); ++it) {
            pair<int,int> pk1 = it->first;
            auto& cluster = it->second;
            if (cluster.size() > 1) {
                set<double> cluster2;
                pair<int, int> pk2;
                if (pk1.first != 0) {
                    if (pk1.first < 0) {
                        pk2 = {abs(pk1.second), abs(pk1.first)};
                    } else {
                        pk2 = {-abs(pk1.second), abs(pk1.first)};
                    }

                    auto it2 = dict.find(pk2);
                    if (it2 != dict.end()) {
                        cluster2 = it2->second;
                    }
                } else {
                    pk2.first = 0;
                    cluster2 = x;
                }
                if (cluster2.size() > 1) {
                    bool isFind = false;
                    double curRelt = calc(pk1, cluster, pk2, cluster2, isFind);

                    if (isFind) {
                        if (relt < 0) {
                            relt = curRelt;
                        } else {
                            relt = min(relt, curRelt);
                        }
                    }
                }
            }
        }

        if (relt < 0) {
            return 0;
        } else {
            return relt;
        }
    }
};
