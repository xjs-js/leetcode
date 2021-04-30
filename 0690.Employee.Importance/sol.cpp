/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int allImp = 0;
        
        unordered_map<int, Employee*> dict;
        for (int i = 0; i < employees.size(); ++i) {
            Employee* cur = employees[i];
            dict[cur->id] = cur;
        }
        
        queue<int> sub;
        sub.push(id);
        int relt = 0;
        while (!sub.empty()) {
            int front = sub.front();
            sub.pop();
            Employee* cur = dict[front];
            relt += cur->importance;
            
            vector<int>& curSub = cur->subordinates;
            for (int s : curSub) {
                sub.push(s);
            }
        }
        return relt;
    }
};
