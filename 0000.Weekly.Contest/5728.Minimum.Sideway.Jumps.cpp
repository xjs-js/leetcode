class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int N = obstacles.size();

        int curIndex = 1;
        int cur_1 = -1, cur_2 = -1, cur_3 = -1;
        if (obstacles[curIndex] == 0) {
            cur_2 = 0;
            cur_1 = cur_3 = 1;
        } else if (obstacles[curIndex] == 1) {
            cur_2 = 0;
            cur_3 = 1;
        } else if (obstacles[curIndex] == 2) {
            cur_1 = cur_3 = 1;
        } else if (obstacles[curIndex] == 3) {
            cur_2 = 0;
            cur_1 = 1;
        }

        while (curIndex != N-1) {
            int prevIndex = curIndex;
            ++curIndex;
            int prev_1 = cur_1, prev_2 = cur_2, prev_3 = cur_3;

            if (obstacles[prevIndex] == 0) {
                if (obstacles[curIndex] == 1) {
                    cur_1 = -1;
                } else if (obstacles[curIndex] == 2) {
                    cur_2 = -1;
                } else if (obstacles[curIndex] == 3) {
                    cur_3 = -1;
                }
            } else if (obstacles[prevIndex] == 1) {
                if (obstacles[curIndex] == 0) {
                    cur_1 = min(cur_2, cur_3) + 1;
                } else if (obstacles[curIndex] == 1) {
                    cur_1 = -1;
                } else if (obstacles[curIndex] == 2) {
                    cur_2 = -1;
                    cur_3 = prev_3;
                    cur_1 = cur_3 + 1;
                } else if (obstacles[curIndex] == 3) {
                    cur_3 = -1;
                    cur_2 = prev_2;
                    cur_1 = cur_2 + 1;
                }
            } else if (obstacles[prevIndex] == 2) {
                if (obstacles[curIndex] == 0) {
                    cur_2 = min(cur_1, cur_3) + 1;
                } else if (obstacles[curIndex] == 1) {
                    cur_1 = -1;
                    cur_2 = cur_3 + 1;
                } else if (obstacles[curIndex] == 2) {
                    cur_2 = -1;
                } else if (obstacles[curIndex] == 3) {
                    cur_3 = -1;
                    cur_2 = cur_1 + 1;
                }
            } else if (obstacles[prevIndex] == 3) {
                if (obstacles[curIndex] == 0) {
                    cur_3 = min(cur_1, cur_2) + 1;
                } else if (obstacles[curIndex] == 1) {
                    cur_1 = -1;
                    cur_3 = cur_2 + 1;
                } else if (obstacles[curIndex] == 2) {
                    cur_2 = -1;
                    cur_3 = cur_1 + 1;
                } else if (obstacles[curIndex] == 3) {
                    cur_3 = -1;
                }
            }
        }

        return min(min(cur_1, cur_2), cur_3);
    }
};