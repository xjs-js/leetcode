//  Created by js on 2019/8/11.
//  Copyright © 2019 js. All rights reserved.
//

#include <stdio.h>
#include <bitset>

class Solution {
public:
    int hammingDistance(int x, int y) {
        std::bitset<32> xBits(x);
        std::bitset<32> yBits(y);
        
        std::bitset<32> result = xBits ^ yBits;
        
        return (int)result.count();
    }
};

