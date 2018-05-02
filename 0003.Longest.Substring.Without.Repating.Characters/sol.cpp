#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring1(string s) { // brute force(Time Limit Exceeded)
        int maxLength = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (allUnique(s, i, j)) maxLength = max(maxLength, j - i);
                else break;
            }
        }

        return maxLength;
    }   

    bool allUnique(string s, int i, int j) { // s[i,j)
        set<char> charSet;
        for (int k = i; k < j; k++) {
            if (charSet.find(s[k]) != charSet.end()) return false;
            else                                     charSet.insert(s[k]);
        }
        return true;
    }

    int lengthOfLongestSubstring2(string s) { // brute force(Accept)
        set<string> ans;
        for (int i = 0; i < s.size(); i++) {
            string relt(1, s[i]);
            int j = 0;
            for (j = i + 1; j < s.size(); j++) {
                if (relt.find(s[j]) == string::npos) {
                    relt += s[j]; // cout << relt << endl;
                }
                else
                {
                    ans.insert(relt); break;
                }
            }
            if (j == s.size()) ans.insert(relt);
        }
        int maxLength = 0;
        string last;
        //cout << ans.size() << endl;
        for (set<string>::iterator it = ans.begin(); it != ans.end(); it++) {
            if ((int)it->size() > maxLength) {
                maxLength = it->size();
                last = *it;
            }
        }
        return maxLength;
    }

    int lengthOfLongestSubstring3(string s) { // 15ms
        int maxLength = 0;
        int startIndex = 0;
        int j = 0;
        while (j < s.size()) {
            string subStr = s.substr(startIndex, j-startIndex);
            if (subStr.find(s[j]) == string::npos) maxLength = max(maxLength, j - startIndex + 1);
            else {
                startIndex = startIndex + subStr.find(s[j]) + 1;
            }
            j++;
        }
        return maxLength;
    }

    int lengthOfLongestSubstring4(string s) { // 32ms
        vector<int> hashMap(128, -1);
        int n = s.size(), start = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (hashMap[s[i]] != -1)
                start = max(start, hashMap[s[i]]);
            ans = max(ans, i - start + 1);
            hashMap[s[i]] = i + 1;
        }
        return ans;
    }

};
int main()
{
    string s;
    cin >> s;
    Solution solution;
    cout << solution.lengthOfLongestSubstring3(s)<<endl;

}
