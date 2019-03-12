// 2019-03-12
// https://leetcode.com/problems/jewels-and-stones/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        unordered_set<char> s;
        int count=0;

        for (auto c : J)
            s.insert(c);
        
        for (auto c : S)
            if (s.count(c) == 1)
                count = count + 1;
        
        return count;
    }
};