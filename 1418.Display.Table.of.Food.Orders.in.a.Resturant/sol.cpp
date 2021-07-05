class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        // Key: table, Value: <name: num>
        map<int, map<string, int>> dict;
        set<string> allName;
        for (auto& order : orders) {
            int table = atoi(order[1].c_str());
            string name = order[2];
            dict[table][name] += 1;
            allName.insert(name);
        }

        vector<vector<string>> relt;
        relt.push_back({"Table"});
        for (auto name : allName) relt[0].push_back(name);

        vector<string> curRelt(allName.size() + 1);

        for (auto it = dict.begin(); it != dict.end(); it++) {
            int table = it->first;
            auto& curOrder = it->second;

            curRelt[0] = to_string(table);
            for (int i = 1; i < relt[0].size(); ++i) {
                curRelt[i] = to_string(curOrder[relt[0][i]]);
            }
            
            relt.push_back(curRelt);
        }

        return relt;
    }
};
