// 2023.11.21 21:10
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); ++i) {
            count[nums[i]]++;
        }

        vector<int> newNum;
        for (auto it = count.begin(); it != count.end(); ++it) {
            if (it->second == 1) {
                newNum.push_back(it->first);
            }
            if (it->second == 2) {
                newNum.push_back(it->first);
                newNum.push_back(it->first);
            }
            if (it->second >= 3) {
                if (it->first == 0) {
                    newNum.push_back(it->first);
                    newNum.push_back(it->first);
                    newNum.push_back(it->first);
                } else {
                    newNum.push_back(it->first);
                    newNum.push_back(it->first);
                }
            }
        }

        unordered_map<int, vector<int>> dic;
        sort(newNum.begin(), newNum.end());
        int N = newNum.size();
        for (int i = 0; i < N; ++i) {
            int num = newNum[i];
            dic[num].push_back(i);
        }

        vector<vector<int>> relt;
        set<tuple<int, int, int>> isExist;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                int target = 0 - newNum[i] - newNum[j];

                if (dic.count(target)) {
                    vector<int>& candidate = dic[target];
                    auto it = upper_bound(candidate.begin(), candidate.end(), j);
                    while (it != candidate.end()) {
                        int k = *it;
                        if (!isExist.count(make_tuple(newNum[i], newNum[j], target))) {
                            isExist.insert(make_tuple(newNum[i], newNum[j], target));
                            relt.push_back({newNum[i], newNum[j], target});
                        }
                        ++it;
                    }
                }
            }
        }

        return relt;
    }
};


/**
 * @url: https://leetcode.com/problems/3sum/
 * @date: 2021-03-23
 * @status: Accepted
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 要return的
        vector<vector<int>> result;
        /* nums中元素的个数不满足，直接pass */
        if (nums.size() < 3)
            return result;

        /* 对nums进行排序 */
        std::sort(nums.begin(), nums.end());

        /* 记录数组中每个元素出现的次数 */
        unordered_map<int, int> times;
        for (int i = 0; i < nums.size(); ++i) {
            ++times[nums[i]];
        }

        /* 固定住a，开始寻找 */
        int preNum = 0; // 上一轮a的值
        for (int i = 0; i < nums.size(); ++i) {
            // 相当与 a = firstNum
            int firstNum = nums[i];

            /* 如果是第二次之后，并且当前的a和上一轮的a相同，也pass */
            if (i > 0 && preNum == firstNum)
                continue;

            /* 将这一轮的a更新到preNum中 */
            preNum = firstNum;

            /** 
             * 如果a>0，且（b >= a && c >= a)，那么 a + b + c > 0 
             * 所以pass
             */
            if (firstNum > 0) {
                break;
            }

            /* 表示 b+c = leftTotal */
            int leftTotal = 0 - firstNum;

            /* 开始寻找b和c */ 
            int preInnerNum = 0;
            for (int j = i + 1; j < nums.size() - 1; ++j) {
                int secNum = nums[j];

                /* 表示b在之前的一轮出现过 */ 
                if (j > i + 1 && preInnerNum == secNum)
                    continue;

                /* 更新这一轮的b */
                preInnerNum = secNum;

                /**
                 * 如果 b + b > leftTotal, 且 c > b
                 * 那么 b + c > leftToal，直接pass
                 */
                if (secNum + secNum > leftTotal) {
                    break;
                }

                /* 表示c */
                int left = 0 - firstNum - secNum;
                /* 当前的tuple */
                std::vector<int> v {firstNum, secNum, left};
                /* 如果c == b， 且 c != a */
                if (left == secNum && left != firstNum) {
                    /* c必须出现两次 */
                    if (times[left] >= 2) {
                        /* 检查是否重复插入 */
                        if (result.size() == 0) {
                            result.emplace_back(v);
                        } else {
                            vector<int>& last = result[result.size()-1];
                            if (v != last) {
                                result.emplace_back(v);
                            }
                        }
                    }
                }
                /* 如果 a == b == c */ 
                else if (left == secNum && left == firstNum) {
                    /* 必须出现三次 */
                    if (times[left] >= 3) {
                        /* 检查是否重复插入 */
                        if (result.size() == 0) {
                            result.emplace_back(v);
                        } else {
                            vector<int>& last = result[result.size()-1];
                            if (v != last) {
                                result.emplace_back(v);
                            }
                        }
                    }
                }
                /* a != b 且 a != c 且 b != c， 直接插入 */
                else if (times.find(left) != times.end()) {
                    result.emplace_back(v);
                }
            }
        }

        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    vector<int> nums{1,-1,-1,0};
    vector<vector<int>> result = sol.threeSum(nums);
    for (int i = 0; i < result.size(); ++i) {
        vector<int>& inner = result[i];
        for (int j = 0; j < inner.size(); ++j) {
            std::cout << inner[j] << " ";
        }
        std:;cout << std::endl;
    }
    return 0;
}
