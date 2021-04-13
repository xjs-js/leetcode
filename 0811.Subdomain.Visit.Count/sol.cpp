/**
 * @date: 2021-04-13 11:09 Tue
 * @cat: easy
 */

class Solution {
public:
    unordered_map<string, int> _cnt;

    void split(string& str) {
        size_t npos = str.find(" ");
        int times = atoi(str.substr(0, npos).c_str());
        string address = str.substr(npos+1);
        _cnt[address] += times;

        size_t end = address.find(".");
        while (end != string::npos) {
            string domain = address.substr(end+1);
            _cnt[domain] += times;
            end = address.find(".", end+1);
        }
    }

    vector<string> subdomainVisits(vector<string>& cpdomains) {
        for (size_t i = 0; i < cpdomains.size(); ++i) {
            string token = cpdomains[i];
            split(token);
        }

        vector<string> result;

        auto it = _cnt.begin();
        while (it != _cnt.end()) {
            int times = it->second;
            string domain = it->first;

            string rlt = to_string(times);
            rlt += " ";
            rlt += domain;

            result.emplace_back(rlt);

            ++it;
        }

        return result;
    }
};