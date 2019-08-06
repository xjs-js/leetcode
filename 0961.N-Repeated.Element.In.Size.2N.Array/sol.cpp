//  Created by js on 2019/8/6.
//  Copyright © 2019 js. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        map<int, int> m;
        
        for (int i = 0; i < A.size(); ++i)
        {
            // A[i] is in map
            if (m.count(A[i]))
            {
                return A[i];
            }
            else
            {
                m[A[i]] = 1;
            }
        }
        
        return -1;
    }
};

