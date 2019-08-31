//  Created by js on 2019/8/11.
//  Copyright © 2019 js. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        
        for (int num = left; num <= right; ++num)
        {
            if (isSelfDividing(num))
            {
                result.push_back(num);
            }
        }
        
        return result;
    }
    
    bool isSelfDividing(int num)
    {
        int copyNum = num;
        while (num != 0)
        {
            int n = num % 10; // 最后一位数
            if (n == 0)
            {
                return false;
            }
            
            if ( copyNum % n != 0 )
            {
                return false;
            }
            
            num = num / 10;
        }
        
        return true;
    }
};
