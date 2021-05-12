class Solution {
public:
    pair<double, double> shoot(pair<double, double> beg, pair<double, double> end, double p) {
        double a = beg.first;
        double b = beg.second;
        double c = end.first;
        double d = end.second;
        
        if ( b == 0 && c == p ) {
            double y = -d * (-2*p + a) / (p - a);
            if (y > p) {
                double x = 2 * p - a - p * (p - a) / d;
                return {x, p};
            } else {
                return {0, y};
            }
        }
        
        if (a == p && d == p) {
            double y = -c * (p - b) / (p - c) + p;
            if (y < 0) {
                double x = -p * (p - c) / (p - b) + c;
                return {x, 0};
            } else {
                return {0, y};
            }
        }
        
        if (b == p && c == 0) {
            double x = d * a / ( p - d );
            if (x > p) {
                double y = (d - p) * p / a + d;
                return {p, y};
            } else {
                return {x, 0};
            }
        }
        
        if (a == 0 && d == 0) {
            double y = (b * p) / c - b;
            if (y > p) {
                double x = (p + b) * c / b;
                return {x, p};
            } else {
                return {p, y};
            }
        }
        
        if (b == 0 && c == 0) {
            double y = (d * p) / a + d;
            if (y > p) {
                double x = (p - d) * a / d;
                return {x, p};
            } else {
                return {p, y};
            }
        }
        
        if (a == 0 && d == p) {
            double y = (b - p) * p / c + 2 * p - b;
            if (y < 0) {
                double x = (b - 2 * p) * c / (b - p);
                return {x, 0};
            } else {
                return {p, y};
            }
        }
        
        if (b == p && c == p) {
            double y = (p - d) / (p - a) * (-p) + d;
            if (y < 0) {
                double x = p - d * (p - a) / (p - d);
                return {x, 0};
            } else {
                return {0, y};
            }
        }
        
        if (a == p && d == 0) {
            double y = c * b / ( p - c );
            if (y > p) {
                double x = p * (c - p) / b + c;
                return {x, p};
            } else {
                return {0, y};
            }
        }
        
        if (a == 0 && c == p) {
            if (d > b) {
                double y = 2 * d - b;
                if (y > p) {
                    double x = (p - d) * p / (b - d) + p;
                    return {x, p};
                } else {
                    return {0, y};
                }
            } else if (d < b) {
                double y = 2 * d - b;
                if (y < 0) {
                    double x = p - d * p / (b - d);
                    return {x, 0};
                } else {
                    return {0, y};
                }
            }
        }
        
        if (a == p && c == 0) {
            if (d > b) {
                double y = 2 * d - b;
                if (y > p) {
                    double x = (p - d) * p / (d - b);
                    return {x, p};
                } else {
                    return {p, y};
                }
            } else if (d < b) {
                double y = 2 * d - b;
                if (y < 0) {
                    double x = - d * p / ( d - b );
                    return {x, 0};
                } else {
                    return {p, y};
                }
            }
        }
        
        if (b == 0 && d == p) {
            if (c > a) {
                double x = 2 * c - a;
                if (x > p) {
                    double y = p * (p - c) / (a - c) + p;
                    return {p, y};
                } else {
                    return {x, 0};
                }
            } else {
                double x = 2 * c - a;
                if (x < 0) {
                    double y = (-p * c) / (a - c) + p;
                    return {0, y};
                } else {
                    return {x, 0};
                }
            }
        }
        
        if (b == p && d == 0) {
            if (c < a) {
                double x = 2 * c - a;
                if (x < 0) {
                    double y = p * c / (a - c);
                    return {0, y};
                } else {
                    return {x, p};
                }
            } else if (c > a) {
                double x = 2 * c - a;
                if (x > p) {
                    double y = p * (p - c) / (c - a);
                    return {p, y};
                } else {
                    return {x, p};
                }
            }
        }
        
        return {p, p};
    }
    
    bool isValid(pair<double, double> point, int p, int& relt) {
        double a = point.first;
        double b = point.second;
        
        if (fabs(a - p) < 1e-6 && fabs(b - 0) < 1e-6) {
            relt = 0;
            return true;
        }
        
        if (fabs(a - p) < 1e-6 && fabs(b - p) < 1e-6) {
            relt = 1;
            return true;
        }
        
        if (fabs(a - 0) < 1e-6 && fabs(b - p) < 1e-6) {
            relt = 2;
            return true;
        }
        
        return false;
    }
    
    int mirrorReflection(int p, int q) {
        pair<double, double> beg(0, 0);
        pair<double, double> end(p, q);
        int relt;
        
        if (isValid(end, p, relt)) {
            return relt;
        }
        
        while (true) {
            pair<double, double> point = shoot(beg, end, p);
            
            if (isValid(point, p, relt)) {
                return relt;
            } else {
                beg = end;
                end = point;
            }
        }
        
        return -1;
    }
};
