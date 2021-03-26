#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <chrono>

using namespace std;

struct Item {
    int index;
    int value;

    Item(int index, int value) : index(index), value(value) {}
};

bool Compare(const Item& a, const Item& b) {
    return a.value < b.value;
}

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        vector<int> B_copy(B.begin(),B.end());

        vector<Item> B_index;
        for (int i = 0; i < B.size(); ++i) {
            B_index.emplace_back(Item(i, B[i]));
        }
        sort(B_index.begin(), B_index.end(), Compare);

        unordered_map<int, int> indexDict;
        unordered_map<int, int> B_Dict;

        for (int i = 0; i < B_index.size(); ++i) {
            B_Dict[i] = B_index[i].index;
        }

        sort(B.begin(), B.end());

        int N_A = A.size();
        int N_B = B.size();

        int j = N_B - 1;        
        int i = 0;
        for (i = N_A - 1; i >= 0; --i) {
            int num_A = A[i];

            while (j >= 0 && B[j] >= num_A) {
                --j;
            }

            if (j == -1) {
                break;
            } else {
                indexDict[B_Dict[j]] = i;
            }
            --j;
        }

        vector<int> result;
        for (int k = 0; k < N_B; k++) {
            if (indexDict.find(k) == indexDict.end()) {
                result.push_back(A[i--]);
            }
            else {
                result.push_back(A[indexDict[k]]);
            }
        }

        return result;
    }
};