const int MOD = 1e9 + 7;
typedef long long LL;
class Solution {
public:
    int check(unordered_map<int, int>& count, unordered_set<int>& curSet, unordered_set<int>& avail, int curNum) {
        LL relt = 0;
        for (auto it = avail.begin(); it != avail.end(); ++it) {
            int delta = *it - curNum;
            if (curSet.count(delta)) {
                relt = (relt % MOD + ((LL)count[delta] * (LL)count[curNum]) % MOD) % MOD;
            }
        }
        return relt % MOD;
    }

    int countPairs(vector<int>& d) {
        unordered_map<int, int> count;
        set<int> s;
        for (int i = 0; i < d.size(); i++) {
            s.insert(d[i]);
            count[d[i]] += 1;
        }

        auto it = s.begin();
        unordered_set<int> curSet;
        curSet.insert(*it);

        unordered_set<int> avail;
        for (int i = 0; i <= 21; ++i) {
            avail.insert(pow(2, i));
        }

        LL relt = 0;
        
        if (avail.count(*it + *it)) {
            LL n = count[*it];
            relt = (relt % MOD + ((n * (n - 1)) / 2) % MOD) % MOD;
        }
        ++it;

        while (it != s.end()) {
            int curNum = *it;

            relt = (check(count, curSet, avail, curNum) + relt % MOD) %MOD;
            if (avail.count(*it + *it)) {
                LL n = count[*it];
                relt = (relt % MOD + ((n * (n - 1)) / 2) % MOD) % MOD;
            }

            curSet.insert(curNum);
            ++it;
        }
        return relt;
    }
};
