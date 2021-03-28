#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> count;

        for (size_t i = 0; i < s.size(); ++i) {
            char c = s[i];
            ++count[c];
        }

        string result;

        // 8
        if (count.find('g') != count.end() && count['g'] > 0) {
            int num = count['g'];
            count['g'] = 0;
            count['e'] -= num;
            count['i'] -= num;
            count['h'] -= num;
            count['t'] -= num;
            result.append(num, '8');
        }

        // 6
        if (count.find('x') != count.end() && count['x'] > 0) {
            int num = count['x'];
            count['s'] -= num;
            count['i'] -= num;
            count['x'] = 0;
            result.append(num, '6');
        }

        // 4
        if (count.find('u') != count.end() && count['u'] > 0) {
            int num = count['u'];
            count['f'] -= num;
            count['o'] -= num;
            count['u'] = 0;
            count['r'] -= num;
            result.append(num, '4');
        }


        // 0
        if (count.find('z') != count.end() && count['z'] > 0) {
            int num = count['z'];
            count['z'] = 0;
            count['e'] -= num;
            count['o'] -= num;
            count['r'] -= num;
            result.append(num, '0');
        }

        // 2
        if (count.find('w') != count.end() && count['w'] > 0) {
            int num = count['w'];
            count['t'] -= num;
            count['w'] = 0;
            count['o'] -= num;
            result.append(num, '2');
        }

        // 5
        if (count.find('f') != count.end() && count['f'] > 0) {
            int num = count['f'];
            count['f'] = 0;
            count['i'] -= num;
            count['v'] -= num;
            count['e'] -= num;
            result.append(num, '5');
        }

        // 7
        if (count.find('s') != count.end() && count['s'] > 0) {
            int num = count['s'];
            count['s'] = 0;
            count['e'] -= 2 * num;
            count['v'] -= num;
            count['n'] -= num;
            result.append(num, '7');
        }

        // 1
        if (count.find('o') != count.end() && count['o'] > 0) {
            int num = count['o'];
            count['o'] = 0;
            count['n'] -= num;
            count['e'] -= num;
            result.append(num, '1');
        }

        // 3
        if (count.find('r') != count.end() && count['r'] > 0) {
            int num = count['r'];
            count['t'] -= num;
            count['h'] -= num;
            count['r'] = 0;
            count['e'] -= 2 * num;
            result.append(num, '3');
        }

        // 9
        if (count.find('n') != count.end() && count['n'] > 0) {
            int num = count['n'] / 2;
            count['n'] -= 0;
            count['i'] -= num;
            count['e'] -= num;
            result.append(num, '9');
        }

        std::sort(result.begin(), result.end());
        
        return result;
    }
};


int main(int argc, char* argv[]) {
    Solution sol;
    std::cout << sol.originalDigits("nnei") << std::endl;
    return 0;
}