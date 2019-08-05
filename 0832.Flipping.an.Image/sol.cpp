//  Created by js on 2019/8/5.
//  Copyright © 2019 js. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        // Flip & Inverse
        for (int j = 0; j < A.size(); ++j)
        {
            vector<int> & row = A[j];
            for (int i = 0; i < row.size() / 2; ++i)
            {
                Swap(row[i], row[row.size()-1-i]);
                row[i] = (row[i] == 1) ? 0 : 1;
                row[row.size()-1-i] = (row[row.size()-1-i] == 1) ? 0 : 1;
            }
            if ( row.size() % 2 != 0 )
            {
                row[row.size()/2] = (row[row.size()/2] == 1) ? 0 : 1;
            }
        }
        
        return A;
    }
    
    void Swap(int & a, int & b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    
};
