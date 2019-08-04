//  Created by js on 2019/8/4.
//  Copyright © 2019 js. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <string>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        // 待返回的结果
        string result = "";
        
        // 遍历输入的参数
        for (int i = 0; i < address.length(); ++i) {
            // 取出char
            char c = address[i];
            // 数字
            if ( isdigit(c) ) {
                result += c;
            } else {
                result += "[.]";
            }
        }
        
        // 计算结束，返回结果
        return result;
    }
};
