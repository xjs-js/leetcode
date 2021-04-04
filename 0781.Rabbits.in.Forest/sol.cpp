/**
 * @date: 2021-04-04 10:02
 * @note: 清明节第二天
 */


class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int result = 0;

        unordered_map<int, int> count;
        for (int i = 0; i < answers.size(); ++i) {
            if (answers[i] != 0) {
                ++count[answers[i]];    
            }
        }

        auto it = count.begin();
        while (it != count.end()) {
            int x = it->second;
            int num = it->first;

            if (x == num) {
                result += 1;
            } else if ( x < num ) {
                result += (num - x + 1);
            } else {  // x > num
                x = x % (num + 1);
                if ( x > 0 ) {
                   result += (num - x + 1);
                }
            }
            
            ++it;
        }

        return result + answers.size();
    }
};
