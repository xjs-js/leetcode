class Solution {
public:
    vector<int> split(string& version) {
        string delim = ".";
        size_t begin = 0;
        size_t end = version.find(delim, begin);
        vector<int> relt;
        while (end != string::npos) {
            string token = version.substr(begin, end-begin);
            if (token.size() > 0) {
                relt.push_back(atoi(token.c_str()));
            }
            begin = end + 1;
            end = version.find(delim, begin);
        }
        string token = version.substr(begin);
        if (token.size() > 0) {
            relt.push_back(atoi(token.c_str()));
        }
        return relt;
    }

    int compareVersion(string version1, string version2) {
        vector<int> v1 = split(version1);
        vector<int> v2 = split(version2);


        int i = 0; int j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (v1[i] == v2[j]) {
                ++i;
                ++j;
                continue;
            } else if (v1[i] < v2[j]) {
                return -1;
            } else {
                return 1;
            }
        }

        while (i < v1.size()) {
            if (v1[i] > 0) {
                return 1;
            }
            ++i;
        }

        while (j < v2.size()) {
            if (v2[j] > 0) {
                return -1;
            }
            ++j;
        }

        return 0;
    }
};
