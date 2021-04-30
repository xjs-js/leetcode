class Solution {
public:
    void changeStr(string& str, int beg, int end, char c) {
        for (int i = beg; i <= end; ++i) { 
            str[i] = c;
        }
    }
    
    string pushDominoes(string str) {
        str = str + "R";
        char prevState = '$'; // beg
        int prevIndex = -1;
        int i = 0;
        int n = str.size();
        while (i < n) {
            char curState = str[i];
            if (curState == '.') {
                ++i;
                continue;
            } else if (curState == 'L') {
                if (prevState == '$' || prevState == 'L') {
                    changeStr(str, prevIndex+1, i-1, 'L');
                } else if (prevState == 'R') {
                    int gapNum = i - prevIndex - 1;
                    if (gapNum > 0) {
                        if (gapNum % 2 == 0) {
                            int half = gapNum / 2;
                            changeStr(str, prevIndex+1, prevIndex+half, 'R');
                            changeStr(str, prevIndex+half+1, i-1, 'L');
                        } else {
                            int half = gapNum / 2;
                            changeStr(str, prevIndex+1, prevIndex+half, 'R');
                            changeStr(str, prevIndex+half+2, i-1, 'L');
                        }
                    }
                }
                
            } else if (curState == 'R') {
                if (prevState == 'R') {
                    changeStr(str, prevIndex+1, i-1, 'R');
                }
            }

            prevState = curState;
            prevIndex = i;
            ++i;
        }
        
        return str.substr(0, n-1);
    }
};
