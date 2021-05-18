class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> _pq;
    int _k;
    
    void insertQueue(int num) {
        if (_pq.size() < _k) {
            _pq.push(num);
        } else {
            
            if (num > _pq.top()) {
                _pq.pop();
                _pq.push(num);
            }
        }
    }
    

    
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        _k = k;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0) {
                    if (j == 0) {
                        matrix[i][j] = matrix[i][j];
                    } else {
                        matrix[i][j] = matrix[i][j] ^ matrix[i][j-1];
                    }
                } else if (j == 0) {
                    matrix[i][j] ^= matrix[i-1][j];
                } else {
                    matrix[i][j] = matrix[i][j] ^ matrix[i][j-1] ^ matrix[i-1][j] ^ matrix[i-1][j-1];
                }
                
                insertQueue(matrix[i][j]);
            }
        }
        
        
        return _pq.top();
    }
};
