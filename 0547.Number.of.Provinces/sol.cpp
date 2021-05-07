class UF {
private:
    int _count;
    int* _id;
    
    
public:
    UF(int n) {
        _count = n;
        _id = new int[n];
        for (int i = 0; i < n; ++i) {
            _id[i] = i;
        }
    }
    
    int count() {
        return _count;
    }
    
    int find(int p) {
        while (p != _id[p]) p = _id[p];
        return p;
    }
    
    void join(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        
        if (pRoot == qRoot) return;
        
        _id[pRoot] = qRoot;
        --_count;
    }
    
};




class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UF* uf = new UF(n);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && isConnected[i][j]) {
                    uf->join(i, j);
                }
            }
        }
        return uf->count();
    }
};
