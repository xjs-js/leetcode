class FindSumPairs {
public:
    vector<int> _nums1;
    vector<int> _nums2;
    
    unordered_map<int, int> _dict2;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        _nums1 = nums1;
        _nums2 = nums2;
        
        for (int i = 0; i < nums2.size(); ++i) {
            ++_dict2[nums2[i]];
        }
    }
    
    void add(int index, int val) {
        int before = _nums2[index];
        --_dict2[before];
        _nums2[index] += val;
        ++_dict2[before + val];
    }
    
    int count(int tot) {
        int relt = 0;
        for (int i = 0; i < _nums1.size(); ++i) {
            int first = _nums1[i];
            if (_dict2.find(tot - first) != _dict2.end()) {
                relt += _dict2[tot-first];
            }
        }
        return relt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
