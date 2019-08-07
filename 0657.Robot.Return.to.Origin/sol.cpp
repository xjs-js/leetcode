//  Created by js on 2019/8/8.
//  Copyright © 2019 js. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        map<char, int> m;
        m['U'] = m['D'] = m['L'] = m['R'] = 0;
        
        for (auto c : moves)
        {
            ++m[c];
        }
        
        return (m['U'] == m['D']) && (m['L'] == m['R']);
    }
};
