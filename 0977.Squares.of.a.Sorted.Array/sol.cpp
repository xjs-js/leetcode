//  Created by js on 2019/8/8.
//  Copyright © 2019 js. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> result;
        
        for (int i = 0; i < A.size(); ++i)
        {
            int square = A[i] * A[i];
            result.push_back(square);
        }
        
        sort(result.begin(), result.end());
        
        return result;
    }
};

