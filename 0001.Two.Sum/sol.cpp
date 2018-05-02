#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) { // Brute Force (213ms)
		vector<int> ans;
		
		for (int i = 0; i < nums.size(); i++) { // ���ڵ�ǰ���� nums[i] 
			for (int j = i + 1; j < nums.size(); j++) { // ���Ѱ�Ҷ�Ӧ�Ĳ���
				if (nums[i] + nums[j] == target) { // �ҵ���
					ans.push_back(i);
					ans.push_back(j);
					return ans;
				}
			}
		}
	}

	vector<int> twoSum1(vector<int>& nums, int target) { // Two-pass Hash Table (13ms)
		vector<int> ans;
		map<int, int> hash;
		
		for (int i = 0; i < nums.size(); i++) { // ���� hash table
			// hash.insert(pair<int, int>(nums[i], i));
			hash[nums[i]] = i;
		}

		for (int i = 0; i < nums.size(); i++) { // ���ڵ�ǰ���� nums[i]
			int toFind = target - nums[i];

			if (hash.find(toFind) != hash.end() && hash[toFind] != i) { // Ѱ�����Ĳ�������ΧΪ����nums����
				ans.push_back(i);
				ans.push_back(hash[toFind]);
				return ans;
			}
		}
	}

	vector<int> twoSum2(vector<int>& nums, int target) { // One-pass Hash Table (13ms)
		vector<int> ans;
		map<int, int> hash;

		for (int i = 0; i < nums.size(); i++) { // ���ڵ�ǰ���� nums[i]
			int toFind = target - nums[i];

			if (hash.find(toFind) != hash.end()) { // Ѱ�����Ĳ�������ΧΪ nums[0:i]
				ans.push_back(hash[toFind]);
				ans.push_back(i);
				return ans;
			}

			hash.insert(pair<int, int>(nums[i], i)); // �õ�ǰ���� nums[i] ��������
			// hash[nums[i]] = i;
		}
	}
};

int main()
{
	vector<int> nums = { 2, 7, 11, 15 };
	
	Solution s;
	vector<int> ans = s.twoSum(nums, 9);
	
	for (vector<int>::iterator it=ans.begin(); it != ans.end(); it++) {
		cout << *it << endl;
	}

}