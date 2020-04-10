class Solution {
private:
    string getOutput(string input) {
        string result = "";
        for (int i = 0; i < input.size(); ++i) {
            char current_char = input[i];
            if (current_char == '#') {
                if (result.size() > 0)
                    result.pop_back();
            } else {
                result += current_char;
            }
        }
        return result;
    }
public:
    bool backspaceCompare(string S, string T) {
        return getOutput(S) == getOutput(T);
    }
};