// 2017-6-1

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }

    // Brute Force
    // Time limt exceeded
    int maxArea_0(vector<int>& height) {
        int max_area = INT_MIN;
        int n = height.size();
        int val;

        for (int step = n - 1; step >= 1; --step) {
            for (int beg = 0, end = beg+step; end <= n-1; ++beg, ++end) {
                val = min(height[beg], height[end]) * step;
                max_area = max(val, max_area);
            }
        }

        return max_area;
    }

    static int maxArea(vector<int>& height) {
        // init
        int n = height.size();
        int max_area = INT_MIN;
        // build pair(height, i) vector
        vector<pair<int,int>> pHeight;
        for (int i = 0; i < n; i++) {
            pHeight.push_back(make_pair(height[i], i));
        }

        // sort pair vector
        sort(pHeight.begin(), pHeight.end(), cmp);

        cout << endl;
        // build index_set
        set<int> myset;
        for (int i = 0; i < n; i++){
            myset.insert(i);
        }

        // from min to max
        // get their index
        // calc the algorithm
        for (int i = 0; i < n-1; i++) {
            int val = pHeight[i].first;
            int index = pHeight[i].second;

            int min_ind = *(myset.begin());
            int min_val = height[min_ind];
        
            int max_ind = *(myset.rbegin());
            int max_val = height[max_ind];

            int val_1 = min(val, min_val) * (index - min_ind);
            int val_2 = min(val, max_val) * (max_ind - index);

            max_area = max(max_area, max(val_1, val_2));
            myset.erase(index);
        }

        // return the answer
        return max_area;
    }
};

int main() {
    vector<int> height({2,3,4,5,18,17,6});
    cout << Solution::maxArea(height) << endl;
}
