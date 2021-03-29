#include <vector>

using namespace std;


class Solution {
public:
    int findNumbers(vector<int>& nums) {
		int result = 0;
		
		auto start = nums.begin();
		auto end = nums.end();
		while (start != end) {
			int num = *start;
			if (num_digits(num) % 2 == 0) {
				++result;
			}
			++start;
		}
		return result;
    }
private:
	int num_digits(int num)
	{
		if (num == 0)
			return 1;

		int digits = 0;
		while (num != 0) {
			num /= 10;
			++digits;
		}
		return digits;
	}
};



