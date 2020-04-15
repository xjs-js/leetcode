class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        string result = "";
        int head = 0;  // head pointer
        int length = s.size();
        for (auto it = shift.begin(); it != shift.end(); ++it) {
            int direction = (*it)[0];
            int amount = (*it)[1];

            switch(direction) {
                case 0:
                    head = (head + amount) % length;
                    break;
                case 1: 
                    head = (head + length - amount) % length;
                    break;
                default: 
                    break;
            }
        }

        return s.substr(head) + s.substr(0, head);
    }
};