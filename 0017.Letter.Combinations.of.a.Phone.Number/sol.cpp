#include <bits/stdc++.h>
#include <vector>
#include <map>
using namespace std;

class Solution {
private:
    map<int, string> dict;
    vector<string> relt;
public:
    Solution() {
        dict.insert(pair<int, string>(2, "abc"));
        dict.insert(pair<int, string>(3, "def"));
        dict.insert(pair<int, string>(4, "ghi"));
        dict.insert(pair<int, string>(5, "jkl"));
        dict.insert(pair<int, string>(6, "mno"));
        dict.insert(pair<int, string>(7, "pqrs"));
        dict.insert(pair<int, string>(8, "tuv"));
        dict.insert(pair<int, string>(9, "wxyz"));
    }
    vector<string> letterCombinations(string digits) {
        for (char& d : digits) {
            insert(d - '0');
        }
        return relt;
    }

    void insert(int d) {
        if (relt.size() == 0) {
            for (char& c : dict[d]) {
                string s(1, c);
                relt.push_back(s);
            }
        }
        else {
            vector<string> temp;
            for (char& c : dict[d]) {
                for (int i = 0; i < relt.size(); i++) {
                    string s(1, c);
                    temp.push_back(relt[i] + s);
                }
            }
            relt = temp;
        }
    }

};

int main()
{
    Solution sol;
    vector<string> ans = sol.letterCombinations("23");
    for (vector<string>::iterator it = ans.begin(); it != ans.end();
        it++)
        cout << *it << endl;
}