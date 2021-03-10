#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string result;

        int forth_digit = num / 1000;
        num -= forth_digit * 1000;
        int third_digit = num / 100;
        num -= third_digit * 100;
        int second_digit = num / 10;
        num -= second_digit * 10;
        int first_digit = num;

        for (int i = 0; i < forth_digit; ++i)
            result += "M";
        
        if (third_digit == 4)
            result += "CD";
        else if (third_digit == 9)
            result += "CM";
        else {
            if (third_digit >= 5) {
                third_digit -= 5;
                result += "D";
            }

            for (int i = 0; i < third_digit; ++i)
                result += "C";
        }

        if (second_digit == 4)
            result += "XL";
        else if (second_digit == 9)
            result += "XC";
        else {
            if (second_digit >= 5) {
                second_digit -= 5;
                result += "L";
            }

            for (int i = 0; i < second_digit; ++i)
                result += "X";
        }

        if (first_digit == 4)
            result += "IV";
        else if (first_digit == 9)
            result += "IX";
        else {
            if (first_digit >= 5) {
                result += "V";
                first_digit -= 5;
            }

            for (int i = 0; i < first_digit; ++i)
                result += "I";
        }
        
        return result;
    }
};


int main(int argc, char* argv[])
{
    Solution sol;
    std::cout << sol.intToRoman(3) << std::endl;
    std::cout << sol.intToRoman(4) << std::endl;
    std::cout << sol.intToRoman(9) << std::endl;
    std::cout << sol.intToRoman(58) << std::endl;
    std::cout << sol.intToRoman(1994) << std::endl;
    return 0;
}