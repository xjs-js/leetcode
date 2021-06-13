class Solution {
public:
    // 分治，将每个下标为奇数和偶数的分开来

    void merge(vector<int>& arr) {
        if (arr.size() < 3) {
            return ;
        }

        if (arr.size() == 3) {
            swap(arr[1], arr[2]);
            return;
        }

        vector<int> lhs;
        vector<int> rhs;
        for (int i = 0; i < arr.size(); ++i) {
            if (i % 2 == 0) lhs.push_back(arr[i]);
            else            rhs.push_back(arr[i]);
        }

        merge(lhs);
        merge(rhs);
        
        int k = 0;
        for (int i = 0; i < lhs.size(); ++i) arr[k++] = lhs[i];
        for (int i = 0; i < rhs.size(); ++i) arr[k++] = rhs[i];
    }


    vector<int> beautifulArray(int n) {
        vector<int> arr(n);
        for (int i = 1; i <= n; ++i) {
            arr[i-1] = i;
        }

        merge(arr);
        return arr;
    }
};
