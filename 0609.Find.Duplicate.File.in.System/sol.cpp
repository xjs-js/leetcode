vector<string> split(string str, string delim) {
    size_t beg = 0;
    size_t end = str.find(delim);
    vector<string> relt;
    while (end != string::npos) {
        string substr = str.substr(beg, end-beg);
        relt.push_back(substr);
        beg = end + 1;
        end = str.find(delim, beg);
    }
    string substr = str.substr(beg);
    relt.push_back(substr);
    return relt;
}


void getNameContent(string& str, string& name, string& content) {
    size_t left = str.find("(");
    size_t right = str.find(")");
    
    name = str.substr(0, left);
    content = str.substr(left+1, right - 1 - left);
}

class Solution {
public:
    unordered_map<string, int> _relt;
    vector<vector<string>> _arr;
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        int n = paths.size();
        for (int i = 0; i < n; ++i) {
            vector<string> tokens = split(paths[i], " ");
            string dir = tokens[0];
            
            for (int j = 1; j < tokens.size(); ++j) {
                string name, content;
                getNameContent(tokens[j], name, content);
                string fullPath = dir + "/" + name;
                if (_relt.find(content) != _relt.end()) {
                    int idx = _relt[content];
                    
                    _arr[idx].push_back(fullPath);
                } else {
                    _relt[content] = _arr.size();
                    _arr.push_back({fullPath});
                }
            }
        }
        
        vector<vector<string>> returnRelt;
        for (int i = 0; i < _arr.size(); ++i) {
            if (_arr[i].size() > 1) {
                returnRelt.push_back(_arr[i]);
            }
        }
        return returnRelt;
    }
};
