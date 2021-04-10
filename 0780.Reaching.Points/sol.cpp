/**
 * @date: 2021-04-10 15:34 Sat
 * @name: 到达终点
 * @url: https://leetcode-cn.com/problems/reaching-points/
 */

#include "../headers.h"

class Solution {
public:
    /** 
     * 一开始用dfs得到stackoverflow
     * 
     * (tx, ty) 它 一定由 (tx-ty, ty) 或者 (tx, ty-tx) 得到
     * tx-ty 和 ty-tx 都不能小于 0，它们始终在第一象限，可以根据这个条件来舍弃
     * 然而，还是超时，所以要减的大一点，幅度大一点
     * 即 (tx, ty)的上一个状态为 (tx - n*ty, ty) 或 (tx, ty - n*tx), 其中 n >= 1
     * 
     * 再由 (tx - n * ty) >= sx 得到， n <= (tx - sx)/ty；同理可得 n <= (ty - sy) / tx
     */
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (sx == tx && sy == ty) {
                return true;
            }
            
            if (tx < ty) {
                int n = max((ty - sy) / tx, 1);
                ty = ty - n * tx;
            } else {    // tx > ty
                int n = max((tx - sx) / ty, 1);
                tx = tx - n * ty;
            }
        }

        return false;
    }
};

int main(int argc, char* argv[]) {
    Solution sol;
    cout << boolalpha << sol.reachingPoints(1, 1, 2, 2) << endl;
    return 0;
}