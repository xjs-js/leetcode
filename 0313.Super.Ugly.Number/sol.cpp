typedef long long LL;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<LL, vector<LL>, greater<LL>> pq;
        unordered_set<LL> st;
        pq.push(1);
        st.insert(1);
        while(--n) {
            for (int i = 0; i < primes.size(); ++i) {
                LL cand = primes[i] * pq.top();
                if (!st.count(cand)) {
                    st.insert(cand);
                    pq.push(cand);
                }
            }
            pq.pop();
        }
        return pq.top();
    }
};
