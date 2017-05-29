// 2017-05-29

#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<vector<int>> relt;
        int org_r = nums.size();
        int org_c = nums[0].size();
        if (org_r * org_c != r * c) {
            return nums;
        }
        
        if (org_r * org_c == r * c) {
            int cnt = 0;
            for (int i = 0; i < r; i++) {
                vector<int> temp;
                for (int j = 0; j < c; j++) {
                    temp.push_back(nums[cnt / org_c][cnt % org_c]);
                    ++cnt;
                }
                relt.push_back(temp);
            }
        }
        return relt;
    }

    static void print(vector<vector<int>>& nums, int r, int c) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << nums[i][j] << ' ';
            }
            cout << endl;
        }
    }
};


int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> nums;
    for (int i = 0; i < m; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            int t;
            cin >> t;
            temp.push_back(t);
        }
        nums.push_back(temp);
    }
    Solution s;
    vector<vector<int>> ans = s.matrixReshape(nums, 1, 4);
    Solution::print(ans, 1, 4);
}