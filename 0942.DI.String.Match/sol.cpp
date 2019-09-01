#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> result;

        // first step
        if (S[0] == 'I')
        {
            result.push_back(0);
            result.push_back(1);
        }
        else if (S[0] == 'D')
        {
            result.push_back(1);
            result.push_back(0);
        }

        for (int i = 1; i < S.size(); ++i)
        {
            int num = i + 1;
            if (S[i] == 'I')
            {
                result.push_back(num);
            }
            else if (S[i] == 'D')
            {
                vector<int>::iterator it;
                it = find(result.begin(), result.end(), num-1);
                if (it != result.end())
                {
                    result.insert(it, num);
                }
            }
        }

        return result;
    }
};