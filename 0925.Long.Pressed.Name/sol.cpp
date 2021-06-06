class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        // 双指针
        int i = 0;
        int j = 0;

        char prev = '$';
        while (i < name.size() && j < typed.size()) {
            if (name[i] == typed[j]) {
                prev = name[i];
                ++i; ++j;
            } else {
                while (j < typed.size() && typed[j] == prev) {
                    ++j;
                }
                if (j < typed.size() && name[i] == typed[j]) {
                    prev = name[i];
                    ++i; ++j;
                } else {
                    return false;
                }
            }
        }

        while (j < typed.size() && typed[j] == prev) {
            ++j;
        }

        return i == name.size() && j == typed.size();
    }
};
