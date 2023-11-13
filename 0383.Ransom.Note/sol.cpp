class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> noteArr(26, 0);
        vector<int> magaArr(26, 0);

        for (int i = 0; i < ransomNote.size(); ++i) {
            ++noteArr[ransomNote[i] - 'a'];
        }
        for (int i = 0; i < magazine.size(); ++i) {
            ++magaArr[magazine[i] - 'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (noteArr[i] != 0 && noteArr[i] > magaArr[i]) {
                return false;
            }
        }

        return true;
    }
};