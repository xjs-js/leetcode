/**
 * @date: 2021-04-05 11:43
 * @note: 这题真的好复杂的样子
 */

#include "../headers.h"

/* 交易结构体体 */ 
struct Transaction {
    string name;        // 交易名称
    int time;           // 交易时间
    int amount;         // 交易金额
    string city;        // 交易城市
    int index;          // 在原来数组中的下标
};


class Solution {
public:
    Transaction toTransaction(const string& str, int index, bool& isValid) {
        string delim = ",";
        size_t beg = 0;
        size_t end = str.find(delim);
        int i = 0;
        Transaction trans;
        trans.index = index;
        while (end != string::npos) {
            string subStr = str.substr(beg, end - beg);
            if (i == 0) {
                trans.name = subStr;
            } else if (i == 1) {
                trans.time = atoi(subStr.c_str());
            } else if (i == 2) {
                trans.amount = atoi(subStr.c_str());
                if (trans.amount > 1000) {
                    isValid = false;
                }
            }
            ++i;
            beg = end + delim.size();
            end = str.find(delim, beg);
        }
        string subStr = str.substr(beg);
        trans.city = subStr;
        return trans;
    }

    vector<string> invalidTransactions(vector<string>& transactions) {
        // 先将每个交易的string，转换成交易的结构体
        int N = transactions.size();
        unordered_set<int> invalid; // 存储invalid的下标
        unordered_map<string, vector<Transaction>> transMap;    // key: 交易名称，value: 交易结构体
        for (int i = 0; i < N; ++i) {
            bool isValid = true;
            Transaction trans = toTransaction(transactions[i], i, isValid);
            if (!isValid) {
                invalid.insert(i);
            }
            transMap[trans.name].emplace_back(trans);
        }

        auto it = transMap.begin();
        while (it != transMap.end()) {
            string name = it->first;
            vector<Transaction>& transArr = it->second;
            sort(transArr.begin(), transArr.end(), [](const Transaction& left, const Transaction& right){
                return left.time < right.time;
            });

            int M = transArr.size();
            for (int i = 0; i < M; ++i) {
                Transaction curTran = transArr[i];
                bool isFind = false;
                for (int j = i-1; j >=0; --j) {
                    Transaction prevTran = transArr[j];
                    if (curTran.time - prevTran.time > 60) {
                        break;
                    }

                    if (curTran.city != prevTran.city) {
                        isFind = true;
                        invalid.insert(prevTran.index);
                    }
                }

                if (isFind) {
                    invalid.insert(curTran.index);
                }
            }

            ++it;
        }

        vector<string> result;
        auto iter = invalid.begin();
        while (iter != invalid.end()) {
            int index = *iter;
            result.emplace_back(transactions[index]);
            ++iter;
        }
        return result;
    }
};
