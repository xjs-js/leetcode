#include <algorithm>
#include <unordered_map>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > anagramMap;
        
        auto it = strs.begin();
        while (it != strs.end()) {
            string sortedStr = getSorted(*it);
            if (anagramMap.find(sortedStr) != anagramMap.end())
            {
                anagramMap.at(sortedStr).push_back(*it);
            }
            else
            {
                vector<string> vec;
                vec.push_back(*it);
                anagramMap.insert(std::make_pair(sortedStr, vec));
            }

            ++it;
        }

        vector<vector<string> > result;
        auto it2 = anagramMap.begin();
        while (it2 != anagramMap.end()) {
            result.push_back(it2->second);
            ++it2;
        }

        return result;
    }
private:
    string getSorted(string str) {
        std::sort(str.begin(), str.end());
        return str;
    }
};