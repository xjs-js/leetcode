//  Created by js on 2019/8/7.
//  Copyright © 2019 js. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;


class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int N = deck.size();
        deque<int> d;
        // 原始数组排序，从小到大
        sort(deck.begin(), deck.end());
        
        // 第一轮，增加最大的数到末尾
        d.push_back(deck[N-1]);
        // 剩下的N-1轮
        for (int i = deck.size()-2; i >= 0; --i)
        {
            // 移到开头
            if ( d.size() >= 2 )
            {
                // 在最前面添加最后的数，删除最后的数
                d.push_front(d.back());
                d.pop_back();
            }
            // 增加一个数
            d.push_front(deck[i]);
        }
        
        vector<int> result;
        for (int i = 0; i < d.size(); ++i)
        {
            result.push_back(d[i]);
        }
        return result;
    }
    
};
