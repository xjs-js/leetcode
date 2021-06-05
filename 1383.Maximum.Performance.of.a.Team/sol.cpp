typedef long long int ll;

constexpr int MOD = 1e9 + 7;
struct Engineer {
    int speed;
    int effic;
    Engineer(int speed, int effic) : speed(speed), effic(effic) {}
};

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<Engineer> arr;
        for (int i = 0; i < n; ++i) {
            Engineer e(speed[i], efficiency[i]);
            arr.emplace_back(e);
        }

        sort(arr.begin(), arr.end(), [](const Engineer& lhs, const Engineer& rhs) {
            return lhs.effic > rhs.effic;
        });


        ll relt = -1;
        priority_queue<int, vector<int>, greater<int>> pq;
        ll sum = 0;
        for (int i = 0; i < k-1; ++i) {
            Engineer& eng = arr[i];
            int e = eng.effic;
            int s = eng.speed;
            ll curRelt = ((ll)e * (ll)(sum + s));
            relt = max(relt, curRelt);
            sum += s;
            pq.push(s);
        }
        
        for (int i = k-1; i < n; ++i) {
            Engineer& eng = arr[i];
            int e = eng.effic;
            int s = eng.speed;
            ll curRelt = ((ll)e * (ll)(sum + s));
            relt = max(relt, curRelt);
            
            if (!pq.empty()) {
                int topS = pq.top();
                if (s > topS) {
                    sum += (s - topS);
                    pq.pop();
                    pq.push(s);
                }
            }
        }
        return relt % MOD;
    }
};
