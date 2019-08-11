//
//  890.cpp
//  LeetCode
//
//  Created by js on 2019/8/10.
//  Copyright © 2019 js. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;  // 最终函数返回的结果
        
        // 遍历words字符串数组里每一个字符串
        vector<string>::iterator it;
        for (it = words.begin(); it != words.end(); ++it)
        {
            // 匹配，则添加到最后返回的数组
            if (match(*it, pattern))
            {
                result.push_back(*it);
            }
        }

        return result;
    }
    
    /*  用_map设置绑定关系，key:word里的字符，value:pattern里的字符
     *  用hasSet设置pattern里的字符是否被绑定
     *  word[i]绑定过  |  _map[word[i]] != pattern[i] --> false
     *                |  else                        --> 更新pattern[i] = word[i]
     *  wrod[i]没绑定过 | pattern[i] 被绑定过  --> 和word[i]不同 --> 返回false
     *                 |pattern[i] 没被绑定过 --> 更新绑定关系
     *
     */
    bool match(string word, string pattern)
    {
        // 一个map
        map<char, char> _map;
        
        // 设置标志位 - pattern[i]是否已经设置过
        vector<bool> hasSet(26, false);
        
        // 长度不等，直接返回false
        if (word.length() != pattern.length())
        {
            return false;
        }
        else
        {
           for (int i = 0; i < pattern.length(); ++i)
           {
               // word[i]已经绑定过pattern中的某个字符
               if (_map.count(word[i]))
               {
                   // 当前字符和绑定的那个字符不匹配，直接返回false
                   if (_map[word[i]] != pattern[i])
                   {
                       return false;
                   }
                   // 匹配，更新pattern为word[i]
                   else if (_map[word[i]] == pattern[i])
                   {
                       pattern[i] = word[i];
                   }
               }
               // word[i]没有绑定过字符，让它绑定pattern[i]
               else if (_map.count(word[i]) == 0)
               {
                   // pattern[i]被绑定过，但是和word[i]不同，直接返回false
                   if (hasSet[pattern[i]-'a'] == true)
                   {
                       if (pattern[i] != word[i])
                       {
                           return false;
                       }
                   }
                   // pattern[i]没被绑定过，绑定，设置标识位
                   else if (hasSet[pattern[i] - 'a'] == false)
                   {
                        _map.insert(std::pair<char, char>(word[i], pattern[i]));
                       hasSet[pattern[i] - 'a'] = 1;
                       pattern[i] = word[i];
                   }

                  
               }
           }
        }

        return (pattern == word);
    }
};

