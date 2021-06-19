class Solution {
public:
    int halfQuestions(vector<int>& questions) {
        int n_2 = questions.size();
        int n = n_2 / 2;
        
        unordered_map<int, int> count;
        vector<int> index;
        for (int i = 0; i < questions.size(); ++i) {
            if (count.find(questions[i]) == count.end()) {
                index.push_back(questions[i]);
            }
            ++count[questions[i]];
        }
        
        sort(index.begin(), index.end(), [&](int lhs, int rhs) {
            return count[lhs] > count[rhs];
        });
        
        int i = 0;
        while (n > 0) {
            if (n >= count[index[i]]) {
                n -= count[index[i]];
                ++i;
            } else {
                ++i;
                n = 0;
                break;
            }
        }
        return i;
    }
};

