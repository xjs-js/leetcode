#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int result = 0;
        for (string word : words)
        {
            if (helpFunc(word, chars))
            {
                result += word.size();
            }
        }
        return result;
    }

    bool helpFunc(string word, string chars)
    {
        for (char c : word)
            if (count(word.begin(), word.end(), c) > count(chars.begin(), chars.end(), c))
                return false;
        
        return true;
    }
};