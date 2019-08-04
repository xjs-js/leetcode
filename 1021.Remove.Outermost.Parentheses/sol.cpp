//  Created by js on 2019/8/5.
//  Copyright © 2019 js. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    string removeOuterParentheses(string S) {
        vector<char>   stack;               // 用到的数据结构
        string         result = "";         // 存放最终返回的结果
        string         roundResult = "";    // 每一轮的结果
        
        // 遍历输入的字符串
        for (int i = 0; i < S.length(); ++i) {
            char c = S[i];       // 取出得到的字符
            roundResult += c;    // 累加到每轮的结果
            if ( c == '(' ) {    // 遇到左括号入栈，又括号出栈
                stack.push_back(c); // 入栈
            }
            else {
                stack.pop_back();   // 出栈
            }
            
            // 栈里括号的个数为0，说明这一轮结束
            if ( stack.size() == 0 ) {
                // 处理结果，存储到最终结果
                result += roundResult.substr(1, roundResult.length()-2);
                // 重制每一轮使用到的变量
                roundResult = "";
            }
        }
        
        return result;
    }
};
