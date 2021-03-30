/**
 * @date: 2020-03-30 18:07
 * @follow: 写完就去吃饭，吃杨国福
 */


class Solution {
private:
    bool isDigit(const char& c) {
        return c >= '0' && c <= '9';
    }
public:
    /**
     * 分割后存到set里面，set的类型不能为int，会溢出
     */
    int numDifferentIntegers(string word) {
        unordered_set<string> result;

        int N = word.size();
        int index = 0;
        while (index < N) {
            char c = word[index];
            if (isDigit(c)) {
                int i = index + 1;
                while (i < N && isDigit(word[i]))
                    ++i;
                string subStr = word.substr(index, i - index);
                
                int j = 0;
                while(j < subStr.size() && subStr[j] == '0')
                    ++j;
                if (j == subStr.size()) {
                    result.insert("0");
                } else {
                    result.insert(subStr.substr(j, subStr.size() - j));
                }
                
                index = i;
            } else {
                ++index;
            }
        }

        return result.size();
    }
};