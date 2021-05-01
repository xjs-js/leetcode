class Solution {
public:
    void doShift(string& S, int num, int i) {
        S[i] = 97 + (S[i] - 97 + num) % 26;
    }
    
    string shiftingLetters(string S, vector<int>& shifts) {
        int n = shifts.size();
        
        int suffix = 0;
        for (int i = n-1; i >= 0; --i) {
            suffix = ((suffix % 26) + (shifts[i] % 26)) % 26;
            doShift(S, suffix, i);
        }
        
        return S;
    }
};
