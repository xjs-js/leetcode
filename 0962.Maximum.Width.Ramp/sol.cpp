struct Node {
    int _val;
    int _idx;
    Node(int idx, int val) : _idx(idx), _val(val) {}
};

/* 套归并排序的模板 */
class Solution {
public:
    vector<Node> _tmp;
    vector<int> _rightMax;
    int _relt;
    void mergeSort(vector<Node>& arr, int l, int r) {
        if (l >= r) {
            return ;
        }

        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);

        int i = l, j = mid + 1;
        int k = 0;

        _rightMax[r] = arr[r]._idx;
        for (int z = r-1; z >= mid+1; --z) {
            _rightMax[z] = max(_rightMax[z+1], arr[z]._idx);
        }


        while (i <= mid && j <= r) {
            if (arr[i]._val <= arr[j]._val) {
                _relt = max(_relt, _rightMax[j] - arr[i]._idx);
                _tmp[k++] = arr[i++];
                
            } else {
                _tmp[k++] = arr[j++];
            }
        }

        while (i <= mid)    _tmp[k++] = arr[i++];
        while (j <= r)      _tmp[k++] = arr[j++];

        for (k = 0; k < r-l+1; ++k) {
            arr[l + k] = _tmp[k]; 
        }
    }

    int maxWidthRamp(vector<int>& nums) {
        _relt = 0;
        int n = nums.size();
        vector<Node> arr;
        for (int i = 0; i < n; ++i) {
            Node node(i, nums[i]);
            arr.push_back(node);
        }
        _tmp.resize(n, Node(0,0));
        _rightMax.resize(n, 0);

        mergeSort(arr, 0, n-1);
        return _relt;
    }
};
