/**
 * @date: 2021-04-04 20:06
 * @note: 今天晚上有两场bo3，想看詹老师了
 */


class Solution {
public:
    /**
     *  从前到后把分出的字符串存到deque中
     *  遇到/： 直接跳过
     *  遇到.:  表示当前路径，直接跳过
     *  遇到..: 表示上级路径，从deque中pop_back
     *  遇到...: 表示文件，存到deque中
     *  遇到其他: 表示文件
     */
    string simplifyPath(string path) {
        vector<string> tokens;
        string delim = "/";
        size_t beg = 0;
        size_t end = path.find(delim);
        while (end != string::npos) {
            string sub = path.substr(beg, end - beg);
            if (!sub.empty()) {
                tokens.emplace_back(sub);
            }
            beg = end + delim.length();
            end = path.find(delim, beg);
        }

        string sub = path.substr(beg);
        if (!sub.empty()) {
            tokens.emplace_back(sub);
        }
        PrintArray(tokens);

        deque<string> dq; 
        for (int i = 0; i < tokens.size(); ++i) {
            string token = tokens[i];
            if (token == ".") {
                continue;
            } else if (token == "..") {
                if (!dq.empty()) {
                    dq.pop_back();
                }
            } else {
                dq.push_back(token);
            }
        }

        string result = "";
        while (!dq.empty()) {
            result += "/";
            string str = dq.front();
            dq.pop_front();
            result += str;
        }

        if (result.empty()) {
            return "/";
        } else {
            return result;
        }
    }
};
