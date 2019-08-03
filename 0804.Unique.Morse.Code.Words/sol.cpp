//  Created by js on 2019/8/3.
//  Copyright © 2019 js. All rights reserved.
//

#include <set>
#include <stdio.h>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        // 代码表
        string table[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        // 集合，每个单词转换成摩斯码之后存到这个集合中
        set<string> resultSet;
        
        // 遍历函数的参数--单词数组
        for (int i = 0; i < words.size(); ++i) {
            // 取出每个单词
            string word = words[i];
            // 取出每个单词中的char，得到morse代码结果，存到morseResult中
            string morseResult = "";
            for (int j=0; j < word.length(); ++j) {
                morseResult += table[word[j] - 'a'];
            }
            resultSet.insert(morseResult);
        }
        
        // 返回结果
        return resultSet.size();
    }
};
